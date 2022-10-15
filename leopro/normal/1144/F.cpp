#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

enum State {
    hedgehog, target, unknown
};

State notState(State s) {
    return s == target ? hedgehog : target;
}

struct Vertex {
    State state = unknown;
    vector<Vertex *> children;
    vector<int> number;

    Vertex() : children(0), number(0) {}
};

bool solve(Vertex *v, State h) {
    if (v->state == notState(h)) return false;
    if (v->state == h) return true;
    v->state = h;
    for (Vertex *w : v->children) {
        if (!solve(w, notState(h))) return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Vertex> tree1(n), tree2(n);
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        u--;
        v--;
        tree1[u].children.push_back(&tree1[v]);
        tree1[u].number.push_back(i);
        tree1[v].children.push_back(&tree1[u]);
        tree1[v].number.push_back(-1);
        tree2[u].children.push_back(&tree2[v]);
        tree2[u].number.push_back(i);
        tree2[v].children.push_back(&tree2[u]);
        tree2[v].number.push_back(-1);
    }
    vector<int> ans(m);
    if (solve(&tree1[0], hedgehog)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < tree1[i].children.size(); ++j) {
                if (tree1[i].number[j] == -1) continue;
                if (tree1[i].state == target) ans[tree1[i].number[j]] = 0;
                if (tree1[i].state == hedgehog) ans[tree1[i].number[j]] = 1;
            }
        }
        cout << "YES\n";
        for (int i = 0; i < m; ++i) {
            cout << ans[i];
        }
        cout << endl;
        return 0;
    }
    cout << "NO\n";
    return 0;
}