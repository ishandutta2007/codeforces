#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 4;

int n, m, h;
vector<int> g[N], rev_g[N], top_sort;
bool used[N];
int which[N];
vector<vector<int>> comps;

inline void add_edge(int v, int u) {
    g[v].push_back(u);
    rev_g[u].push_back(v);
}

void dfs(int v) {
    used[v] = true;
    for (auto u : g[v])
        if (!used[u])
            dfs(u);
    top_sort.push_back(v);
}

void dfs2(int v) {
    which[v] = int(comps.size()) - 1;
    used[v] = true;
    comps.back().push_back(v);
    for (auto u : rev_g[v])
        if (!used[u])
            dfs2(u);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m >> h;
    vector<int> when(n);
    for (auto &x : when)
        cin >> x;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b, a--, b--;
        for (int rep = 0; rep < 2; rep++, swap(a, b))
            if ((when[a] + 1) % h == when[b])
                add_edge(a, b);
    }

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs(i);
    reverse(top_sort.begin(), top_sort.end());

    memset(used, false, sizeof(used));
    for (auto i : top_sort)
        if (!used[i]) {
            comps.push_back({});
            dfs2(i);
        }

    vector<int> out(comps.size());
    for (int i = 0; i < n; i++)
        for (auto j : g[i])
            if (which[i] != which[j])
                out[which[i]]++;

    vector<int> ans;
    for (int i = 0; i < int(comps.size()); i++)
        if (!out[i] && (ans.empty() || comps[i].size() < ans.size()))
            ans = comps[i];

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto x : ans)
        cout << x + 1 << ' ';
    cout << '\n';
}