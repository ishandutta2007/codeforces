#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

const int Log = 12;
int n;
vector<vector<int>> G, jump;
vector<int> parent, tin, tout;
vector<char> can;

void dfs_calc(int v, int pr, int &timer) {
    parent[v] = pr;
    tin[v] = timer++;
    jump[v][0] = pr;
    for (int i = 1; i < Log; i++)
        jump[v][i] = jump[jump[v][i - 1]][i - 1];
    for (int u : G[v])
        if (u != pr)
            dfs_calc(u, v, timer);
    tout[v] = timer++;
}

bool is_parent(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int lca(int v, int u) {
    if (is_parent(v, u))
        return v;
    if (is_parent(u, v))
        return u;
    for (int i = Log - 1; i >= 0; i--)
        if (!is_parent(jump[v][i], u))
            v = jump[v][i];
    return parent[v];
}

void dfs_not_can(int v) {
    can[v] = 0;
    for (int u : G[v])
        if (u != parent[v])
            dfs_not_can(u);
}

void dfs_leaves(int v, vector<int> &leaves, vector<int> &norm) {
    norm.push_back(v);
    bool fnd = false;
    for (int u : G[v]) {
        if (u == parent[v] || !can[u])
            continue;
        fnd = true;
        dfs_leaves(u, leaves, norm);
    }
    if (!fnd)
        leaves.push_back(v);
}

int Ask(int v, int u) {
    cout << "? " << v + 1 << ' ' << u + 1 << endl;
    int w;
    cin >> w;
    return w - 1;
}

void Go(int v) {
    vector<int> leaves;
    vector<int> norm;
    dfs_leaves(v, leaves, norm);
    if (norm.size() == 1) {
        cout << "! " << norm[0] + 1 << endl;
        exit(0);
    }
    if (leaves.size() == 1) {
        int root = Ask(v, leaves[0]);
        cout << "! " << root + 1 << endl;
        exit(0);
    }
    int L1 = leaves[0], L2 = leaves[1];
    int w = lca(L1, L2);
    int real_w = Ask(L1, L2);
    if (w != real_w) {
        Go(real_w);
        return;
    }
    for (auto u : G[w])
        if (u != parent[w] && (is_parent(u, L1) || is_parent(u, L2)))
            can[u] = 0;
    Go(v);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    G.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    parent.resize(n);
    int timer = 0;
    tin.resize(n);
    tout.resize(n);
    jump.resize(n, vector<int>(Log));
    dfs_calc(0, 0, timer);
    can.resize(n, 1);
    Go(0);
}