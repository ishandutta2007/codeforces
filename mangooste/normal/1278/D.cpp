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

vector<vector<int>> G;
vector<pair<int, int>> tree;
vector<char> used;

void build(int v, int vl, int vr) {
    if (vr - vl == 1) {
        tree[v] = {-1, vr - vl};
        return;
    }
    int vm = (vl + vr) / 2;
    build(2 * v, vl, vm);
    build(2 * v + 1, vm, vr);
    tree[v] = {-1, vr - vl};
}

int get_cnt(int v, int vl, int vr, int L, int R) {
    if (R <= vl || vr <= L)
        return 0;
    if (L <= vl && vr <= R)
        return vr - vl - (tree[v].first == -1 ? tree[v].second : 0);
    int vm = (vl + vr) / 2;
    return get_cnt(2 * v, vl, vm, L, R) + get_cnt(2 * v + 1, vm, vr, L, R);
}

void make_graph(int v, int vl, int vr, int cur, int L, int R) {
    if (R <= vl || vr <= L)
        return;
    if (tree[v].second == vr - vl)
        return;
    if (vr - vl == 1) {
        G[cur].push_back(tree[v].first);
        G[tree[v].first].push_back(cur);
        return;
    }
    int vm = (vl + vr) / 2;
    make_graph(2 * v, vl, vm, cur, L, R);
    make_graph(2 * v + 1, vm, vr, cur, L, R);
}

void update(int v, int vl, int vr, int pos, int new_val) {
    if (pos < vl || vr <= pos)
        return;
    if (vr - vl == 1) {
        tree[v].first = new_val;
        tree[v].second = 0;
        return;
    }
    int vm = (vl + vr) / 2;
    update(2 * v, vl, vm, pos, new_val);
    update(2 * v + 1, vm, vr, pos, new_val);
    tree[v].second = tree[2 * v].second + tree[2 * v + 1].second;
}

void dfs(int v) {
    used[v] = 1;
    for (auto u : G[v])
        if (!used[u])
            dfs(u);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &i : a)
        cin >> i.first >> i.second, i.first--, i.second--;
    sort(all(a), [](pair<int, int> &a, pair<int, int> &b) {
        return a.first < b.first || a.first == b.first && a.second > b.second;
    });
    tree.resize(8 * n);
    build(1, 0, 2 * n);
    int m = 0;
    G.resize(n);
    for (int i = 0; i < n; i++) {
        m += get_cnt(1, 0, 2 * n, a[i].first, a[i].second);
        make_graph(1, 0, 2 * n, i, a[i].first, a[i].second);
        if (m > n - 1)
            return cout << "NO\n", 0;
        update(1, 0, 2 * n, a[i].second, i);
    }
    if (m != n - 1)
        return cout << "NO\n", 0;
    used.resize(n);
    dfs(0);
    for (int i = 0; i < n; i++)
        if (!used[i])
            return cout << "NO\n", 0;
    cout << "YES\n";
}