#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
const int D = 50;
const int V = N * D;

int n, m, d;
vector<int> g[N], rev_g[V];
vector<pair<int, int>> topsort;
bool used[N][D], open[N][D];

int st_i;
array<int, 3> st[V];

int which[N][D], take[V], timer, cur;
int cnt[V], dp[V];

void dfs() {
    st_i = 1;
    st[0] = {0, 0, 0};
    topsort.reserve(V);
    while (st_i) {
        auto [i, j, where] = st[--st_i];
        used[i][j] = true;
        if (where == int(g[i].size())) {
            topsort.emplace_back(i, j);
            continue;
        }
        st[st_i++] = {i, j, where + 1};
        if (!used[g[i][where]][(j + 1) % d])
            st[st_i++] = {g[i][where], (j + 1) % d};
    }
}

void dfs2(int i, int j) {
    timer++;
    st_i = 1;
    st[0] = {i, j, 0};
    while (st_i) {
        auto [i, j, where] = st[--st_i];
        which[i][j] = cur;
        if (where == int(rev_g[i].size())) {
            if (take[i] != timer && open[i][j])
                take[i] = timer, cnt[cur]++;
            continue;
        }
        st[st_i++] = {i, j, where + 1};
        int jj = (j - 1 + d) % d;
        if (which[rev_g[i][where]][jj] == -1 && used[rev_g[i][where]][jj])
            st[st_i++] = {rev_g[i][where], jj, 0};
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m >> d;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        g[v].push_back(u), rev_g[u].push_back(v);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < d; j++) {
            char c;
            cin >> c;
            open[i][j] = (c == '1');
        }

    dfs();
    reverse(topsort.begin(), topsort.end());

    memset(which, -1, sizeof(which));
    for (auto [i, j] : topsort)
        if (which[i][j] == -1)
            dfs2(i, j), cur++;

    for (int i = 0; i < n; i++)
        rev_g[i].clear();
    memset(take, 0, sizeof(take));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < d; j++)
            if (which[i][j] != -1) {
                for (auto ii : g[i]) {
                    int jj = (j + 1) % d;
                    if (which[ii][jj] != -1 && which[i][j] != which[ii][jj])
                        take[which[ii][jj]]++, rev_g[which[i][j]].push_back(which[ii][jj]);
                }
            }

    st_i = 1;
    st[0][0] = which[0][0];
    while (st_i) {
        int v = st[--st_i][0];
        dp[v] += cnt[v];
        for (auto u : rev_g[v]) {
            take[u]--, dp[u] = max(dp[u], dp[v]);
            if (!take[u])
                st[st_i++][0] = u;
        }
    }
    cout << *max_element(dp, dp + cur) << '\n';
}