#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

enum class Status {
    NOT_STARTED,
    IN_PROGRESS,
    COMPLETED
};

string statusToString(Status status) {
    switch(status) {
        case Status::NOT_STARTED: return "Not Started";
        case Status::IN_PROGRESS: return "In Progress";
        case Status::COMPLETED: return "Completed";
        default: return "Unknown";
    }
}

// Forward declarations
class Project;
class Task;
class TeamMember;
class Vendor;
class Client;

// Team Member class
class TeamMember {
private:
    string name;
    string role;
    string contactInfo;
    vector<Project*> projects;
    vector<Task*> tasks;

public:
    TeamMember(string name, string role, string contactInfo)
        : name(name), role(role), contactInfo(contactInfo) {}

    // Getters
    string getName() const { return name; }
    string getRole() const { return role; }
    string getContactInfo() const { return contactInfo; }
    const vector<Project*>& getProjects() const { return projects; }
    const vector<Task*>& getTasks() const { return tasks; }

    // Setters
    void setName(const string& newName) { name = newName; }
    void setRole(const string& newRole) { role = newRole; }
    void setContactInfo(const string& newContact) { contactInfo = newContact; }

    // Methods to manage projects and tasks
    void addProject(Project* project);
    void removeProject(Project* project);
    void addTask(Task* task);
    void removeTask(Task* task);
    void displayDetails() const;
};

// Vendor class
class Vendor {
private:
    string companyName;
    string companyType;
    string contactPerson;
    vector<Project*> projects;
    vector<Task*> tasks;

public:
    Vendor(string companyName, string companyType, string contactPerson)
        : companyName(companyName), companyType(companyType), contactPerson(contactPerson) {}

    // Getters
    string getCompanyName() const { return companyName; }
    string getCompanyType() const { return companyType; }
    string getContactPerson() const { return contactPerson; }
    const vector<Project*>& getProjects() const { return projects; }
    const vector<Task*>& getTasks() const { return tasks; }

    // Setters
    void setCompanyName(const string& newName) { companyName = newName; }
    void setCompanyType(const string& newType) { companyType = newType; }
    void setContactPerson(const string& newContact) { contactPerson = newContact; }

    // Methods to manage projects and tasks
    void addProject(Project* project);
    void removeProject(Project* project);
    void addTask(Task* task);
    void removeTask(Task* task);
    void displayDetails() const;
};

// Client class
class Client {
private:
    string companyName;
    string companyType;
    string contactPerson;
    vector<Project*> projects;

public:
    Client(string companyName, string companyType, string contactPerson)
        : companyName(companyName), companyType(companyType), contactPerson(contactPerson) {}

    // Getters
    string getCompanyName() const { return companyName; }
    string getCompanyType() const { return companyType; }
    string getContactPerson() const { return contactPerson; }
    const vector<Project*>& getProjects() const { return projects; }

    // Setters
    void setCompanyName(const string& newName) { companyName = newName; }
    void setCompanyType(const string& newType) { companyType = newType; }
    void setContactPerson(const string& newContact) { contactPerson = newContact; }

    // Methods to manage projects
    void addProject(Project* project);
    void removeProject(Project* project);
    void displayDetails() const;
};

// Task class
class Task {
private:
    string name;
    string description;
    string startDate;
    string endDate;
    Status status;
    Project* project;
    vector<Task*> subTasks;
    vector<TeamMember*> assignedMembers;
    vector<Vendor*> assignedVendors;

public:
    Task(string name, string description, string startDate, string endDate, Status status, Project* project)
        : name(name), description(description), startDate(startDate), endDate(endDate),
          status(status), project(project) {}

    // Getters
    string getName() const { return name; }
    string getDescription() const { return description; }
    string getStartDate() const { return startDate; }
    string getEndDate() const { return endDate; }
    Status getStatus() const { return status; }
    Project* getProject() const { return project; }
    const vector<Task*>& getSubTasks() const { return subTasks; }
    const vector<TeamMember*>& getAssignedMembers() const { return assignedMembers; }
    const vector<Vendor*>& getAssignedVendors() const { return assignedVendors; }

    // Setters
    void setName(const string& newName) { name = newName; }
    void setDescription(const string& newDesc) { description = newDesc; }
    void setStartDate(const string& newStart) { startDate = newStart; }
    void setEndDate(const string& newEnd) { endDate = newEnd; }
    void setStatus(Status newStatus) { status = newStatus; }
    void setProject(Project* newProject) { project = newProject; }

    // Methods to manage subtasks, members, and vendors
    void addSubTask(Task* task) { subTasks.push_back(task); }
    void removeSubTask(Task* task) {
        subTasks.erase(remove(subTasks.begin(), subTasks.end(), task), subTasks.end());
    }
    void assignMember(TeamMember* member) { assignedMembers.push_back(member); }
    void removeMember(TeamMember* member) {
        assignedMembers.erase(remove(assignedMembers.begin(), assignedMembers.end(), member),
                            assignedMembers.end());
    }
    void assignVendor(Vendor* vendor) { assignedVendors.push_back(vendor); }
    void removeVendor(Vendor* vendor) {
        assignedVendors.erase(remove(assignedVendors.begin(), assignedVendors.end(), vendor),
                            assignedVendors.end());
    }

    void displayDetails() const;
};

// Project class
class Project {
private:
    string name;
    string description;
    string startDate;
    string endDate;
    Status status;
    vector<Task*> tasks;
    vector<TeamMember*> teamMembers;
    vector<Vendor*> vendors;
    vector<Client*> clients;

public:
    Project(string name, string description, string startDate, string endDate, Status status)
        : name(name), description(description), startDate(startDate), endDate(endDate), status(status) {}

    // Getters
    string getName() const { return name; }
    string getDescription() const { return description; }
    string getStartDate() const { return startDate; }
    string getEndDate() const { return endDate; }
    Status getStatus() const { return status; }
    const vector<Task*>& getTasks() const { return tasks; }
    const vector<TeamMember*>& getTeamMembers() const { return teamMembers; }
    const vector<Vendor*>& getVendors() const { return vendors; }
    const vector<Client*>& getClients() const { return clients; }

    // Setters
    void setName(const string& newName) { name = newName; }
    void setDescription(const string& newDesc) { description = newDesc; }
    void setStartDate(const string& newStart) { startDate = newStart; }
    void setEndDate(const string& newEnd) { endDate = newEnd; }
    void setStatus(Status newStatus) { status = newStatus; }

    // Methods to manage tasks, members, vendors, and clients
    void addTask(Task* task) { tasks.push_back(task); }
    void removeTask(Task* task) {
        tasks.erase(remove(tasks.begin(), tasks.end(), task), tasks.end());
    }
    void addTeamMember(TeamMember* member) { teamMembers.push_back(member); }
    void removeTeamMember(TeamMember* member) {
        teamMembers.erase(remove(teamMembers.begin(), teamMembers.end(), member),
                        teamMembers.end());
    }
    void addVendor(Vendor* vendor) { vendors.push_back(vendor); }
    void removeVendor(Vendor* vendor) {
        vendors.erase(remove(vendors.begin(), vendors.end(), vendor), vendors.end());
    }
    void addClient(Client* client) { clients.push_back(client); }
    void removeClient(Client* client) {
        clients.erase(remove(clients.begin(), clients.end(), client), clients.end());
    }

    void displayDetails() const;
};

// Implementations of methods that were declared earlier
void TeamMember::addProject(Project* project) { projects.push_back(project); }
void TeamMember::removeProject(Project* project) {
    projects.erase(remove(projects.begin(), projects.end(), project), projects.end());
}
void TeamMember::addTask(Task* task) { tasks.push_back(task); }
void TeamMember::removeTask(Task* task) {
    tasks.erase(remove(tasks.begin(), tasks.end(), task), tasks.end());
}
void TeamMember::displayDetails() const {
    cout << "\nTeam Member Details:\n";
    cout << "Name: " << name << "\n";
    cout << "Role: " << role << "\n";
    cout << "Contact Info: " << contactInfo << "\n";
    cout << "\nProjects (" << projects.size() << "):\n";
    for (const auto& project : projects) {
        cout << "- " << project->getName() << "\n";
    }
    cout << "\nTasks (" << tasks.size() << "):\n";
    for (const auto& task : tasks) {
        cout << "- " << task->getName() << " (" << statusToString(task->getStatus()) << ")\n";
    }
}

void Vendor::addProject(Project* project) { projects.push_back(project); }
void Vendor::removeProject(Project* project) {
    projects.erase(remove(projects.begin(), projects.end(), project), projects.end());
}
void Vendor::addTask(Task* task) { tasks.push_back(task); }
void Vendor::removeTask(Task* task) {
    tasks.erase(remove(tasks.begin(), tasks.end(), task), tasks.end());
}
void Vendor::displayDetails() const {
    cout << "\nVendor Details:\n";
    cout << "Company Name: " << companyName << "\n";
    cout << "Company Type: " << companyType << "\n";
    cout << "Contact Person: " << contactPerson << "\n";
    cout << "\nProjects (" << projects.size() << "):\n";
    for (const auto& project : projects) {
        cout << "- " << project->getName() << "\n";
    }
    cout << "\nTasks (" << tasks.size() << "):\n";
    for (const auto& task : tasks) {
        cout << "- " << task->getName() << " (" << statusToString(task->getStatus()) << ")\n";
    }
}

void Client::addProject(Project* project) { projects.push_back(project); }
void Client::removeProject(Project* project) {
    projects.erase(remove(projects.begin(), projects.end(), project), projects.end());
}
void Client::displayDetails() const {
    cout << "\nClient Details:\n";
    cout << "Company Name: " << companyName << "\n";
    cout << "Company Type: " << companyType << "\n";
    cout << "Contact Person: " << contactPerson << "\n";
    cout << "\nProjects (" << projects.size() << "):\n";
    for (const auto& project : projects) {
        cout << "- " << project->getName() << "\n";
    }
}

void Task::displayDetails() const {
    cout << "\nTask Details:\n";
    cout << "Name: " << name << "\n";
    cout << "Description: " << description << "\n";
    cout << "Start Date: " << startDate << "\n";
    cout << "End Date: " << endDate << "\n";
    cout << "Status: " << statusToString(status) << "\n";
    cout << "Project: " << (project ? project->getName() : "None") << "\n";
    cout << "\nSubtasks (" << subTasks.size() << "):\n";
    for (const auto& task : subTasks) {
        cout << "- " << task->getName() << " (" << statusToString(task->getStatus()) << ")\n";
    }
    cout << "\nAssigned Team Members (" << assignedMembers.size() << "):\n";
    for (const auto& member : assignedMembers) {
        cout << "- " << member->getName() << " (" << member->getRole() << ")\n";
    }
    cout << "\nAssigned Vendors (" << assignedVendors.size() << "):\n";
    for (const auto& vendor : assignedVendors) {
        cout << "- " << vendor->getCompanyName() << " (" << vendor->getCompanyType() << ")\n";
    }
}

void Project::displayDetails() const {
    cout << "\nProject Details:\n";
    cout << "Name: " << name << "\n";
    cout << "Description: " << description << "\n";
    cout << "Start Date: " << startDate << "\n";
    cout << "End Date: " << endDate << "\n";
    cout << "Status: " << statusToString(status) << "\n";

    cout << "\nTasks (" << tasks.size() << "):\n";
    for (const auto& task : tasks) {
        cout << "- " << task->getName() << "\n";
    }

    cout << "\nTeam Members (" << teamMembers.size() << "):\n";
    for (const auto& member : teamMembers) {
        cout << "- " << member->getName() << "\n";
    }

    cout << "\nVendors (" << vendors.size() << "):\n";
    for (const auto& vendor : vendors) {
        cout << "- " << vendor->getCompanyName() << "\n";
    }

    cout << "\nClients (" << clients.size() << "):\n";
    for (const auto& client : clients) {
        cout << "- " << client->getCompanyName() << "\n";
    }
}

// Project Management System class
class ProjectManagementSystem {
private:
    vector<Project*> projects;
    vector<Task*> tasks;
    vector<TeamMember*> teamMembers;
    vector<Vendor*> vendors;
    vector<Client*> clients;

    // Helper function to clear input buffer
    void clearInputBuffer() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Helper function to get status from user
    Status getStatusFromUser() {
        int choice;
        cout << "Select status:\n";
        cout << "1. Not Started\n";
        cout << "2. In Progress\n";
        cout << "3. Completed\n";
        cout << "Enter choice (1-3) : ";
        cin >> choice;
        clearInputBuffer();

        switch (choice) {
            case 1: return Status::NOT_STARTED;
            case 2: return Status::IN_PROGRESS;
            case 3: return Status::COMPLETED;
            default:
                cout << "Invalid choice, Defaulting to Not Started.\n";
                return Status::NOT_STARTED;
        }
    }

    // Helper functions to display all entities
    void displayAllProjects() const {
        if (projects.empty()) {
            cout << "No projects available.\n";
            return;
        }
        cout << "\nAll Projects:\n";
        for (size_t i = 0; i < projects.size(); ++i) {
            cout << i + 1 << ". " << projects[i]->getName() << "\n";
        }
    }

    void displayAllTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }
        cout << "\nAll Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i]->getName() << " (Project: "
                 << (tasks[i]->getProject() ? tasks[i]->getProject()->getName() : "None") << ")\n";
        }
    }

    void displayAllTeamMembers() const {
        if (teamMembers.empty()) {
            cout << "No team members available.\n";
            return;
        }
        cout << "\nAll Team Members:\n";
        for (size_t i = 0; i < teamMembers.size(); ++i) {
            cout << i + 1 << ". " << teamMembers[i]->getName() << " (" << teamMembers[i]->getRole() << ")\n";
        }
    }

    void displayAllVendors() const {
        if (vendors.empty()) {
            cout << "No vendors available.\n";
            return;
        }
        cout << "\nAll Vendors:\n";
        for (size_t i = 0; i < vendors.size(); ++i) {
            cout << i + 1 << ". " << vendors[i]->getCompanyName() << " (" << vendors[i]->getCompanyType() << ")\n";
        }
    }

    void displayAllClients() const {
        if (clients.empty()) {
            cout << "No clients available.\n";
            return;
        }
        cout << "\nAll Clients:\n";
        for (size_t i = 0; i < clients.size(); ++i) {
            cout << i + 1 << ". " << clients[i]->getCompanyName() << " (" << clients[i]->getCompanyType() << ")\n";
        }
    }

    // Helper functions to select entities
    Project* selectProject() {
        displayAllProjects();
        if (projects.empty()) return nullptr;

        int choice;
        cout << "Enter project number: ";
        cin >> choice;
        clearInputBuffer();

        if (choice < 1 || choice > static_cast<int>(projects.size())) {
            cout << "Invalid project number.\n";
            return nullptr;
        }
        return projects[choice - 1];
    }

    Task* selectTask() {
        displayAllTasks();
        if (tasks.empty()) return nullptr;

        int choice;
        cout << "Enter task number: ";
        cin >> choice;
        clearInputBuffer();

        if (choice < 1 || choice > static_cast<int>(tasks.size())) {
            cout << "Invalid task number.\n";
            return nullptr;
        }
        return tasks[choice - 1];
    }

    TeamMember* selectTeamMember() {
        displayAllTeamMembers();
        if (teamMembers.empty()) return nullptr;

        int choice;
        cout << "Enter team member number: ";
        cin >> choice;
        clearInputBuffer();

        if (choice < 1 || choice > static_cast<int>(teamMembers.size())) {
            cout << "Invalid team member number.\n";
            return nullptr;
        }
        return teamMembers[choice - 1];
    }

    Vendor* selectVendor() {
        displayAllVendors();
        if (vendors.empty()) return nullptr;

        int choice;
        cout << "Enter vendor number: ";
        cin >> choice;
        clearInputBuffer();

        if (choice < 1 || choice > static_cast<int>(vendors.size())) {
            cout << "Invalid vendor number.\n";
            return nullptr;
        }
        return vendors[choice - 1];
    }

    Client* selectClient() {
        displayAllClients();
        if (clients.empty()) return nullptr;

        int choice;
        cout << "Enter client number: ";
        cin >> choice;
        clearInputBuffer();

        if (choice < 1 || choice > static_cast<int>(clients.size())) {
            cout << "Invalid client number.\n";
            return nullptr;
        }
        return clients[choice - 1];
    }

public:
    // Destructor to clean up memory
    ~ProjectManagementSystem() {
        for (auto project : projects) delete project;
        for (auto task : tasks) delete task;
        for (auto member : teamMembers) delete member;
        for (auto vendor : vendors) delete vendor;
        for (auto client : clients) delete client;
    }

    // Project management methods
    void addProject() {
        string name, description, startDate, endDate;
        cout << "\nEnter project name: ";
        getline(cin, name);
        cout << "Enter project description: ";
        getline(cin, description);
        cout << "Enter start date (YYYY-MM-DD): ";
        getline(cin, startDate);
        cout << "Enter end date (YYYY-MM-DD): ";
        getline(cin, endDate);
        Status status = getStatusFromUser();
        Project* project = new Project(name, description, startDate, endDate, status);
        projects.push_back(project);
        cout << "Project added successfully!\n";
    }

    void updateProject() {
        Project* project = selectProject();
        if (!project) return;

        string name, description, startDate, endDate;
        cout << "\nCurrent project name: " << project->getName() << "\n";
        cout << "Enter new project name (leave blank to keep current): ";
        getline(cin, name);
        if (!name.empty()) project->setName(name);

        cout << "\nCurrent project description: " << project->getDescription() << "\n";
        cout << "Enter new project description (leave blank to keep current): ";
        getline(cin, description);
        if (!description.empty()) project->setDescription(description);

        cout << "\nCurrent start date: " << project->getStartDate() << "\n";
        cout << "Enter new start date (YYYY-MM-DD, leave blank to keep current): ";
        getline(cin, startDate);
        if (!startDate.empty()) project->setStartDate(startDate);

        cout << "\nCurrent end date: " << project->getEndDate() << "\n";
        cout << "Enter new end date (YYYY-MM-DD, leave blank to keep current): ";
        getline(cin, endDate);
        if (!endDate.empty()) project->setEndDate(endDate);

        cout << "\nCurrent status: " << statusToString(project->getStatus()) << "\n";
        cout << "Do you want to change the status? (y/n): ";
        char choice;
        cin >> choice;
        clearInputBuffer();

        if (choice == 'y' || choice == 'Y') {
            Status newStatus = getStatusFromUser();
            project->setStatus(newStatus);
        }

        cout << "Project updated successfully!\n";
    }

    void deleteProject() {
        Project* project = selectProject();
        if (!project) return;

        // Remove project from all team members
        for (auto member : teamMembers) {
            member->removeProject(project);
        }

        // Remove project from all vendors
        for (auto vendor : vendors) {
            vendor->removeProject(project);
        }

        // Remove project from all clients
        for (auto client : clients) {
            client->removeProject(project);
        }

        // Delete all tasks associated with this project
        for (auto task : tasks) {
            if (task->getProject() == project) {
                // Remove task from all team members
                for (auto member : teamMembers) {
                    member->removeTask(task);
                }
                // Remove task from all vendors
                for (auto vendor : vendors) {
                    vendor->removeTask(task);
                }
                // Delete the task
                delete task;
            }
        }

        // Remove all tasks associated with this project from the tasks vector
        tasks.erase(remove_if(tasks.begin(), tasks.end(),
            [project](Task* task) { return task->getProject() == project; }), tasks.end());

        // Remove project from projects vector and delete it
        projects.erase(remove(projects.begin(), projects.end(), project), projects.end());
        delete project;
        cout << "Project deleted successfully!\n";
    }

    // Task management methods
    void addTask() {
        Project* project = selectProject();
        if (!project) return;

        string name, description, startDate, endDate;
        cout << "\nEnter task name: ";
        getline(cin, name);
        cout << "Enter task description: ";
        getline(cin, description);
        cout << "Enter start date (YYYY-MM-DD): ";
        getline(cin, startDate);
        cout << "Enter end date (YYYY-MM-DD): ";
        getline(cin, endDate);
        Status status = getStatusFromUser();
        Task* task = new Task(name, description, startDate, endDate, status, project);
        tasks.push_back(task);
        project->addTask(task);

        // Option to add as subtask
        cout << "Is this a subtask of another task? (y/n): ";
        char choice;
        cin >> choice;
        clearInputBuffer();

        if (choice == 'y' || choice == 'Y') {
            Task* parentTask = selectTask();
            if (parentTask && parentTask != task) {
                parentTask->addSubTask(task);
            } else {
                cout << "Invalid parent task selection.\n";
            }
        }

        cout << "Task added successfully!\n";
    }

    void updateTask() {
        Task* task = selectTask();
        if (!task) return;

        string name, description, startDate, endDate;

        cout << "\nCurrent task name: " << task->getName() << "\n";
        cout << "Enter new task name (leave blank to keep current): ";
        getline(cin, name);
        if (!name.empty()) task->setName(name);

        cout << "\nCurrent task description: " << task->getDescription() << "\n";
        cout << "Enter new task description (leave blank to keep current): ";
        getline(cin, description);
        if (!description.empty()) task->setDescription(description);

        cout << "\nCurrent start date: " << task->getStartDate() << "\n";
        cout << "Enter new start date (YYYY-MM-DD, leave blank to keep current): ";
        getline(cin, startDate);
        if (!startDate.empty()) task->setStartDate(startDate);

        cout << "\nCurrent end date: " << task->getEndDate() << "\n";
        cout << "Enter new end date (YYYY-MM-DD, leave blank to keep current): ";
        getline(cin, endDate);
        if (!endDate.empty()) task->setEndDate(endDate);

        cout << "\nCurrent status: " << statusToString(task->getStatus()) << "\n";
        cout << "Do you want to change the status? (y/n): ";
        char choice;
        cin >> choice;
        clearInputBuffer();

        if (choice == 'y' || choice == 'Y') {
            Status newStatus = getStatusFromUser();
            task->setStatus(newStatus);
        }
        cout << "Task updated successfully!\n";
    }

    void deleteTask() {
        Task* task = selectTask();
        if (!task) return;

        // Remove task from its project
        if (task->getProject()) {
            task->getProject()->removeTask(task);
        }

        // Remove task from all team members
        for (auto member : teamMembers) {
            member->removeTask(task);
        }

        // Remove task from all vendors
        for (auto vendor : vendors) {
            vendor->removeTask(task);
        }

        // Remove task from all parent tasks
        for (auto parentTask : tasks) {
            parentTask->removeSubTask(task);
        }

        // Remove the task from the tasks vector and delete it
        tasks.erase(remove(tasks.begin(), tasks.end(), task), tasks.end());
        delete task;
        cout << "Task deleted successfully!\n";
    }

    // Team member management methods
    void addTeamMember() {
        string name, role, contactInfo;

        cout << "\nEnter team member name: ";
        getline(cin, name);
        cout << "Enter role: ";
        getline(cin, role);
        cout << "Enter contact information: ";
        getline(cin, contactInfo);

        TeamMember* member = new TeamMember(name, role, contactInfo);
        teamMembers.push_back(member);

        // Option to assign to projects
        cout << "Do you want to assign this member to projects? (y/n): ";
        char choice;
        cin >> choice;
        clearInputBuffer();

        if (choice == 'y' || choice == 'Y') {
            while (true) {
                Project* project = selectProject();
                if (!project) break;
                member->addProject(project);
                project->addTeamMember(member);
                cout << "Assign to another project? (y/n): ";
                cin >> choice;
                clearInputBuffer();
                if (choice != 'y' && choice != 'Y') break;
            }
        }
        cout << "Team member added successfully!\n";
    }

    void updateTeamMember() {
        TeamMember* member = selectTeamMember();
        if (!member) return;

        string name, role, contactInfo;
        cout << "\nCurrent team member name: " << member->getName() << "\n";
        cout << "Enter new name (leave blank to keep current): ";
        getline(cin, name);
        if (!name.empty()) member->setName(name);

        cout << "\nCurrent role: " << member->getRole() << "\n";
        cout << "Enter new role (leave blank to keep current): ";
        getline(cin, role);
        if (!role.empty()) member->setRole(role);

        cout << "\nCurrent contact information: " << member->getContactInfo() << "\n";
        cout << "Enter new contact information (leave blank to keep current): ";
        getline(cin, contactInfo);
        if (!contactInfo.empty()) member->setContactInfo(contactInfo);

        cout << "Team member updated successfully!\n";
    }

    void deleteTeamMember() {
        TeamMember* member = selectTeamMember();
        if (!member) return;

        // Remove member from all projects
        for (auto project : projects) {
            project->removeTeamMember(member);
        }

        // Remove member from all tasks
        for (auto task : tasks) {
            task->removeMember(member);
        }

        // Remove the member from the teamMembers vector and delete it
        teamMembers.erase(remove(teamMembers.begin(), teamMembers.end(), member), teamMembers.end());
        delete member;
        cout << "Team member deleted successfully!\n";
    }

    // Vendor management methods
    void addVendor() {
        string companyName, companyType, contactPerson;

        cout << "\nEnter company name: ";
        getline(cin, companyName);
        cout << "Enter company type (e.g., IT services, cabling): ";
        getline(cin, companyType);
        cout << "Enter contact person: ";
        getline(cin, contactPerson);

        Vendor* vendor = new Vendor(companyName, companyType, contactPerson);
        vendors.push_back(vendor);

        // Option to assign to projects
        cout << "Do you want to assign this vendor to projects? (y/n): ";
        char choice;
        cin >> choice;
        clearInputBuffer();

        if (choice == 'y' || choice == 'Y') {
            while (true) {
                Project* project = selectProject();
                if (!project) break;
                vendor->addProject(project);
                project->addVendor(vendor);
                cout << "Assign to another project? (y/n): ";
                cin >> choice;
                clearInputBuffer();
                if (choice != 'y' && choice != 'Y') break;
            }
        }
        cout << "Vendor added successfully!\n";
    }

    void updateVendor() {
        Vendor* vendor = selectVendor();
        if (!vendor) return;

        string companyName, companyType, contactPerson;
        cout << "\nCurrent company name: " << vendor->getCompanyName() << "\n";
        cout << "Enter new company name (leave blank to keep current): ";
        getline(cin, companyName);
        if (!companyName.empty()) vendor->setCompanyName(companyName);

        cout << "\nCurrent company type: " << vendor->getCompanyType() << "\n";
        cout << "Enter new company type (leave blank to keep current): ";
        getline(cin, companyType);
        if (!companyType.empty()) vendor->setCompanyType(companyType);

        cout << "\nCurrent contact person: " << vendor->getContactPerson() << "\n";
        cout << "Enter new contact person (leave blank to keep current): ";
        getline(cin, contactPerson);
        if (!contactPerson.empty()) vendor->setContactPerson(contactPerson);

        cout << "Vendor updated successfully!\n";
    }

    void deleteVendor() {
        Vendor* vendor = selectVendor();
        if (!vendor) return;

        // Remove vendor from all projects
        for (auto project : projects) {
            project->removeVendor(vendor);
        }

        // Remove vendor from all tasks
        for (auto task : tasks) {
            task->removeVendor(vendor);
        }

        // Remove the vendor from the vendors vector and delete it
        vendors.erase(remove(vendors.begin(), vendors.end(), vendor), vendors.end());
        delete vendor;
        cout << "Vendor deleted successfully!\n";
    }

    // Client management methods
    void addClient() {
        string companyName, companyType, contactPerson;
        cout << "\nEnter company name: ";
        getline(cin, companyName);
        cout << "Enter company type (e.g., finance, IT, construction): ";
        getline(cin, companyType);
        cout << "Enter contact person: ";
        getline(cin, contactPerson);
        Client* client = new Client(companyName, companyType, contactPerson);
        clients.push_back(client);

        // Option to assign to projects
        cout << "Do you want to assign this client to projects? (y/n): ";
        char choice;
        cin >> choice;
        clearInputBuffer();

        if (choice == 'y' || choice == 'Y') {
            while (true) {
                Project* project = selectProject();
                if (!project) break;
                client->addProject(project);
                project->addClient(client);
                cout << "Assign to another project? (y/n): ";
                cin >> choice;
                clearInputBuffer();
                if (choice != 'y' && choice != 'Y') break;
            }
        }
        cout << "Client added successfully!\n";
    }

    void updateClient() {
        Client* client = selectClient();
        if (!client) return;

        string companyName, companyType, contactPerson;
        cout << "\nCurrent company name: " << client->getCompanyName() << "\n";
        cout << "Enter new company name (leave blank to keep current): ";
        getline(cin, companyName);
        if (!companyName.empty()) client->setCompanyName(companyName);

        cout << "\nCurrent company type: " << client->getCompanyType() << "\n";
        cout << "Enter new company type (leave blank to keep current): ";
        getline(cin, companyType);
        if (!companyType.empty()) client->setCompanyType(companyType);

        cout << "\nCurrent contact person: " << client->getContactPerson() << "\n";
        cout << "Enter new contact person (leave blank to keep current): ";
        getline(cin, contactPerson);
        if (!contactPerson.empty()) client->setContactPerson(contactPerson);

        cout << "Client updated successfully!\n";
    }

    void deleteClient() {
        Client* client = selectClient();
        if (!client) return;

        // Remove client from all projects
        for (auto project : projects) {
            project->removeClient(client);
        }

        // Remove the client from the clients vector and delete it
        clients.erase(remove(clients.begin(), clients.end(), client), clients.end());
        delete client;
        cout << "Client deleted successfully!\n";
    }

    // Task assignment methods
    void assignTaskToTeamMember() {
        Task* task = selectTask();
        if (!task) return;

        TeamMember* member = selectTeamMember();
        if (!member) return;

        task->assignMember(member);
        member->addTask(task);
        cout << "Task assigned to team member successfully!\n";
    }

    void assignVendorToTask() {
        Task* task = selectTask();
        if (!task) return;

        Vendor* vendor = selectVendor();
        if (!vendor) return;

        task->assignVendor(vendor);
        vendor->addTask(task);
        cout << "Vendor assigned to task successfully!\n";
    }

    // Display methods
    void displayProjectDetails() const {
        Project* project = const_cast<ProjectManagementSystem*>(this)->selectProject();
        if (!project) return;
        project->displayDetails();
    }

    void displayTaskDetails() const {
        Task* task = const_cast<ProjectManagementSystem*>(this)->selectTask();
        if (!task) return;
        task->displayDetails();
    }

    void displayTeamMemberDetails() const {
        TeamMember* member = const_cast<ProjectManagementSystem*>(this)->selectTeamMember();
        if (!member) return;
        member->displayDetails();
    }

    void displayVendorDetails() const {
        Vendor* vendor = const_cast<ProjectManagementSystem*>(this)->selectVendor();
        if (!vendor) return;
        vendor->displayDetails();
    }

    void displayClientDetails() const {
        Client* client = const_cast<ProjectManagementSystem*>(this)->selectClient();
        if (!client) return;
        client->displayDetails();
    }

    // Update task status
    void updateTaskStatus() {
        Task* task = selectTask();
        if (!task) return;
        Status newStatus = getStatusFromUser();
        task->setStatus(newStatus);
        cout << "Task status updated successfully!\n";
    }

    // Menu methods
    void projectManagementMenu() {
        while (true) {
            cout << "\nProject Management\n";
            cout << "1. Add Project\n";
            cout << "2. Update Project\n";
            cout << "3. Delete Project\n";
            cout << "4. Back to Main Menu\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            clearInputBuffer();

            switch (choice) {
                case 1: addProject(); break;
                case 2: updateProject(); break;
                case 3: deleteProject(); break;
                case 4: return;
                default: cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    void taskManagementMenu() {
        while (true) {
            cout << "\nTask Management\n";
            cout << "1. Add Task\n";
            cout << "2. Update Task\n";
            cout << "3. Delete Task\n";
            cout << "4. Back to Main Menu\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            clearInputBuffer();

            switch (choice) {
                case 1: addTask(); break;
                case 2: updateTask(); break;
                case 3: deleteTask(); break;
                case 4: return;
                default: cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    void teamMemberManagementMenu() {
        while (true) {
            cout << "\nTeam Member Management\n";
            cout << "1. Add Team Member\n";
            cout << "2. Update Team Member\n";
            cout << "3. Delete Team Member\n";
            cout << "4. Back to Main Menu\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            clearInputBuffer();

            switch (choice) {
                case 1: addTeamMember(); break;
                case 2: updateTeamMember(); break;
                case 3: deleteTeamMember(); break;
                case 4: return;
                default: cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    void vendorManagementMenu() {
        while (true) {
            cout << "\nVendor Management\n";
            cout << "1. Add Vendor\n";
            cout << "2. Update Vendor\n";
            cout << "3. Delete Vendor\n";
            cout << "4. Back to Main Menu\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            clearInputBuffer();

            switch (choice) {
                case 1: addVendor(); break;
                case 2: updateVendor(); break;
                case 3: deleteVendor(); break;
                case 4: return;
                default: cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    void clientManagementMenu() {
        while (true) {
            cout << "\nClient Management\n";
            cout << "1. Add Client\n";
            cout << "2. Update Client\n";
            cout << "3. Delete Client\n";
            cout << "4. Back to Main Menu\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            clearInputBuffer();

            switch (choice) {
                case 1: addClient(); break;
                case 2: updateClient(); break;
                case 3: deleteClient(); break;
                case 4: return;
                default: cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    void displayMenu() {
        while (true) {
            cout << "\nDisplay Options\n";
            cout << "1. Display Project Details\n";
            cout << "2. Display Task Details\n";
            cout << "3. Display Team Member Details\n";
            cout << "4. Display Vendor Details\n";
            cout << "5. Display Client Details\n";
            cout << "6. Back to Main Menu\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            clearInputBuffer();

            switch (choice) {
                case 1: displayProjectDetails(); break;
                case 2: displayTaskDetails(); break;
                case 3: displayTeamMemberDetails(); break;
                case 4: displayVendorDetails(); break;
                case 5: displayClientDetails(); break;
                case 6: return;
                default: cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    void showMenu() {
        while (true) {
            cout << "\nProject Management System\n";
            cout << "1. Project Management\n";
            cout << "2. Task Management\n";
            cout << "3. Team Member Management\n";
            cout << "4. Vendor Management\n";
            cout << "5. Client Management\n";
            cout << "6. Assign Task to Team Member\n";
            cout << "7. Assign Vendor to Task\n";
            cout << "8. Update Task Status\n";
            cout << "9. Display Details\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            clearInputBuffer();

            switch (choice) {
                case 1: projectManagementMenu(); break;
                case 2: taskManagementMenu(); break;
                case 3: teamMemberManagementMenu(); break;
                case 4: vendorManagementMenu(); break;
                case 5: clientManagementMenu(); break;
                case 6: assignTaskToTeamMember(); break;
                case 7: assignVendorToTask(); break;
                case 8: updateTaskStatus(); break;
                case 9: displayMenu(); break;
                case 0: return;
                default: cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};

int main() {
    ProjectManagementSystem pms;
    pms.showMenu();
    return 0;
}