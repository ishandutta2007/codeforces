#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
struct Matching {
    int n;
    vector<int> matchL, matchR, dist;
    vector<bool> seen;
    vector< vector<int> > ke;

    Matching(int n) : n(n), matchL(n+1), matchR(n+1), dist(n+1), seen(n+1, false), ke(n+1) {}

    void addEdge(int u, int v) {
        ke[u].push_back(v);
    }

    bool bfs() {
        queue<int> qu;
        for(int u = 1; u <= n; ++u)
            if (!matchL[u]) {
                dist[u] = 0;
                qu.push(u);
            } else dist[u] = inf;
        dist[0] = inf;

        while (!qu.empty()) {
            int u = qu.front(); qu.pop();
            for(__typeof(ke[u].begin()) v = ke[u].begin(); v != ke[u].end(); ++v) {
                if (dist[matchR[*v]] == inf) {
                    dist[matchR[*v]] = dist[u] + 1;
                    qu.push(matchR[*v]);
                }
            }
        }
        return dist[0] != inf;
    }

    bool dfs(int u) {
        if (u) {
            for(__typeof(ke[u].begin()) v = ke[u].begin(); v != ke[u].end(); ++v)
                if (dist[matchR[*v]] == dist[u] + 1 && dfs(matchR[*v])) {
                    matchL[u] = *v;
                    matchR[*v] = u;
                    return true;
                }
            dist[u] = inf;
            return false;
        }
        return true;
    }

    int match() {
        int res = 0;
        while (bfs()) {
            for(int u = 1; u <= n; ++u)
                if (!matchL[u])
                    if (dfs(u)) ++res;
        }
        return res;
    }
};

int n, m, k;
int from[605], to[605];
int need[605], sneed;
int ans[605];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i) need[i] = 0;
        for (int i = 1; i <= m; ++i) {
            cin >> from[i] >> to[i];
            ++need[from[i]];
            ++need[to[i]];
        }
        sneed = 0;
        for (int i = 1; i <= n; ++i) {
            need[i] = 2 * max(0, need[i] - k);
            sneed += need[i];
        }
        if (sneed > m) {
            for (int i = 1; i <= m; ++i) cout << 0 << ' ';
            cout << '\n';
            continue;
        }
        Matching G(m);
        for (int i = 1; i <= n; ++i) need[i] += need[i-1];
        for (int i = 1; i <= m; ++i) {
            int u = from[i], v = to[i];
            for (int j = need[u-1] + 1; j <= need[u]; ++j) G.addEdge(i, j);
            for (int j = need[v-1] + 1; j <= need[v]; ++j) G.addEdge(i, j);
        }
        int cnt = G.match();
        if (cnt < sneed) {
            for (int i = 1; i <= m; ++i) cout << 0 << ' ';
            cout << '\n';
            continue;
        }
        for (int i = 1; i <= m; ++i) ans[i] = 0;
        int cur = 1;
        vector <int> vec(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = need[i-1] + 1; j <= need[i]; ++j) {
                int id = G.matchR[j];
                if (vec[i]) {
                    ans[id] = ans[vec[i]] = cur++;
                    vec[i] = 0;
                }
                else vec[i] = id;
            }
        }
        for (int i = 1; i <= m; ++i) if (!ans[i]) ans[i] = cur++;
        for (int i = 1; i <= m; ++i) cout << ans[i] << ' '; cout << '\n';
    }
    return 0;
}