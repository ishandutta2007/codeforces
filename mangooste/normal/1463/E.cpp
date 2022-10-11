#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "/home/lesha/codes/Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, l, r) for (int i = int(l); i < int(r); i++)
#define free AHAHAHAHAHAHA

int n, k;
vector<int> par;
vector<vector<int>> tree;

vector<vector<int>> specialG;
vector<vector<int>> ways;
vector<int> wayNumber;

vector<int> st;
vector<vector<int>> g;

vector<char> used;
vector<int> topsort;

int free = 0;
vector<int> index;
vector<char> killed;

void dfs(int v) {
    if (wayNumber[v] != -1) {
        if (len(st)) g[st.back()].push_back(wayNumber[v]);
        st.push_back(wayNumber[v]);
    }
    for (auto u : tree[v]) {
        dfs(u);
    }
    if (wayNumber[v] != -1) st.pop_back();
}

void dfsTopsort(int v) {
    used[v] = 1;
    for (auto u : g[v]) {
        if (used[u]) continue;
        dfsTopsort(u);
    }
    topsort.push_back(v);
}

inline void insert(int v, bool addV) {
    assert(index[v] == -1);
    vector<int> wayUp;
    for (int u = (addV ? v : par[v]); u != -1 && !killed[u]; u = par[u]) {
        wayUp.push_back(u);
    }
    reverse(all(wayUp));
    for (auto u : wayUp) {
        killed[u] = 1;
        index[u] = free++;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    tree.resize(n);
    par.resize(n);
    forn (i, 0, n) {
        cin >> par[i];
        par[i]--;
        if (par[i] != -1) tree[par[i]].push_back(i);
    }
    assert(count(all(par), -1) == 1);

    specialG.resize(n);
    vector<int> inDeg(n);
    forn (i, 0, k) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        specialG[v].push_back(u);
        inDeg[u]++;
    }
    forn (i, 0, k) {
        if (len(specialG[i]) > 1 || inDeg[i] > 1) {
            return cout << "0\n", 0;
        }
    }

    wayNumber.resize(n, -1);
    int sum = 0;
    forn (i, 0, n) {
        if (inDeg[i] || !len(specialG[i])) continue;
        ways.push_back({});
        int v = i;
        for (; len(specialG[v]) == 1; v = specialG[v][0]) {
            ways.back().push_back(v);
        }
        ways.back().push_back(v);
        sum += len(ways.back()) - 1;
        for (auto v : ways.back()) {
            wayNumber[v] = len(ways) - 1;
        }
    }
    assert(sum <= k);
    if (sum != k) return cout << "0\n", 0;

    int root = int(find(all(par), -1) - par.begin());
    st.reserve(n);
    g.resize(len(ways));
    dfs(root);

    used.resize(n);
    forn (i, 0, len(ways)) {
        if (!used[i]) dfsTopsort(i);
    }
    reverse(all(topsort));

    index.resize(n, -1);
    killed.resize(n);

    for (auto id : topsort) {
        for (auto v : ways[id]) {
            if (killed[v]) return cout << "0\n", 0;
            insert(v, false);
        }
        for (auto v : ways[id]) {
            index[v] = free++;
            killed[v] = 1;
        }
    }
    forn (i, 0, n) {
        if (index[i] == -1) insert(i, true);
    }

    vector<int> ans(n);
    iota(all(ans), 0);
    sort(all(ans), [&](int i, int j) {
        return index[i] < index[j];
    });

    fill(all(inDeg), 0);
    forn (i, 0, n) {
        if (par[i] != -1) inDeg[i]++;
    }
    for (auto v : ans) {
        assert(inDeg[v] >= 0);
        if (inDeg[v] != 0) return cout << "0\n", 0;
        for (auto u : tree[v]) {
            inDeg[u]--;
        }
    }

    forn (i, 0, n) cout << ans[i] + 1 << " \n"[i == n - 1];
}