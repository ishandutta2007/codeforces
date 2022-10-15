#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Vertex {
    int n;
    int comp = -1;
    int time = -1;
    bool found = false;
    vector<Vertex *> children;
    const bool operator < (const Vertex &u) const{
        return n < u.n;
    }
};

struct Cmp{
    const bool operator ()(const Vertex *a, const Vertex *b){
        return *a < *b;
    }
};

struct Time{
    const bool operator ()(const Vertex &a, const Vertex &b){
        return a.time < b.time;
    }    
};

int set_time(Vertex *u, int time){
    u->found = true;
    for (auto w : u->children){
        if (!w->found) time = set_time(w, time);
    }
    return u->time = ++time;
}

void set_comp_dfs(Vertex *u, int c){
    u->comp = c;
    for (auto child : u->children){
        if (child->comp == -1) set_comp_dfs(child, c);
    }
}

void set_comp(vector<Vertex> &tree){
    vector<Vertex> antitree(tree.size());
    for (int i = 0; i < antitree.size(); ++i) antitree[i].n = i;
    for (auto &u : tree) {
        for (auto *child : u.children){
            antitree[child->n].children.push_back(&antitree[u.n]);
        }
    }
    for (auto &u : antitree){
        stable_sort(u.children.begin(), u.children.end(), Cmp());
    }
    int time = 0;
    for (auto &u : tree) {
        if (u.time == -1) time = set_time(&u, time);
    }

    stable_sort(tree.rbegin(), tree.rend(), Time());
    int c = 0;
    for (auto & u : tree) {
        if (antitree[u.n].comp == -1) set_comp_dfs(&antitree[u.n], c++);
    }
    for (auto & u : antitree) {
        tree[u.n].comp = u.comp;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Vertex> roads(n * 2);
    for (int i = 0; i < roads.size(); ++i) roads[i].n = i;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        if (c == 0){
            roads[a * 2 + 1].children.push_back(&roads[b * 2]);
            roads[b * 2 + 1].children.push_back(&roads[a * 2]);
            roads[a * 2].children.push_back(&roads[b * 2 + 1]);
            roads[b * 2].children.push_back(&roads[a * 2 + 1]);
        } else {
            roads[a * 2].children.push_back(&roads[b * 2]);
            roads[b * 2].children.push_back(&roads[a * 2]);
            roads[a * 2 + 1].children.push_back(&roads[b * 2 + 1]);
            roads[b * 2 + 1].children.push_back(&roads[a * 2 + 1]);
        }
    }
    for (auto & road : roads) {
        stable_sort(road.children.begin(), road.children.end(), Cmp());
        road.children.resize(unique(road.children.begin(), road.children.end()) - road.children.begin());
    }
    set_comp(roads);
    for (int i = 0; i < n; ++i) {
        if (roads[2 * i].comp == roads[2 * i + 1].comp){
            cout << "Impossible\n";
            return 0;
        }
    }
    vector<int> answer;
    answer.reserve(n);
    for (int i = 0; i < n; ++i) {
        if (roads[2 * i].comp < roads[2 * i + 1].comp) answer.push_back(i);
    }
    cout << answer.size() << "\n";
    for (int i : answer) {
        cout << i + 1 << " ";
    }
    cout << "\n";
    return 0;
}