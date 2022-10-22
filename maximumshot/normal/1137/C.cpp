#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int inf = 1e9;
const int N = 1e5 + 5;
const int D = 55;

int n, m, d;
vector<int> g[N], gr[N];
vector<int> tops;
int used[N];
int color[N], curColor;
vector<int> component[N];
int score[N][D];
int can[N][D], canr[N][D];
char open[N][D];
int dp[N][D];
vector<int> h[N];

void dfs1(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs1(to);
        }
    }
    tops.push_back(v);
}

void dfs2(int v) {
    used[v] = 1;
    color[v] = curColor;
    for (int to : gr[v]) {
        if (!used[to]) {
            dfs2(to);
        }
    }
}

void calc(int c) {
    int sz = (int)component[c].size();
    int start = component[c].front();
    can[start][0] = 1;
    queue<pii> q;
    q.push({start, 0});
    while (!q.empty()) {
        int v, i;
        tie(v, i) = q.front();
        q.pop();
        i = (i + 1) % d;
        for (int to : g[v]) {
            if (color[to] != c) continue;
            if (!can[to][i]) {
                can[to][i] = 1;
                q.push({to, i});
            }
        }
    }
    canr[start][0] = 1;
    q.push({start, 0});
    while (!q.empty()) {
        int v, i;
        tie(v, i) = q.front();
        q.pop();
        i = (i + 1) % d;
        for (int to : gr[v]) {
            if (color[to] != c) continue;
            if (!canr[to][i]) {
                canr[to][i] = 1;
                q.push({to, i});
            }
        }
    }
    for (int i = 0; i < d; i++) {
        for (int v : component[c]) {
            for (int j = 0; j < d; j++) {
                if (open[v][j] == '0') continue;
                int need = (j - i + d) % d;
                if (can[v][need]) {
                    score[start][i]++;
                    break;
                }
            }
        }
    }
}

vector<int> htops;

void go(int c) {
    used[c] = 1;
    for (int to : h[c]) {
        if (!used[to]) {
            go(to);
        }
    }
    htops.push_back(c);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> d;

    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    for (int v = 1; v <= n; v++) {
        cin >> open[v];
    }

    fill(used + 1, used + n + 1, 0);
    for (int v = 1; v <= n; v++) {
        if (!used[v]) {
            dfs1(v);
        }
    }
    reverse(tops.begin(), tops.end());

    fill(used + 1, used + n + 1, 0);
    for (int v : tops) {
        if (!used[v]) {
            dfs2(v);
            curColor++;
        }
    }

    for (int v = 1; v <= n; v++) {
        component[color[v]].push_back(v);
    }

    for (int c = 0; c < curColor; c++) {
        calc(c);
    }

    for (int v = 1; v <= n; v++) {
        for (int to : g[v]) {
            if (color[v] == color[to]) {
                continue;
            }
            h[color[v]].push_back(color[to]);
        }
    }

    fill(used, used + curColor, 0);
    for (int c = 0; c < curColor; c++) {
        if (!used[c]) {
            go(c);
        }
    }

    for (int c : htops) {
        int v = component[c].front();
        for (int i = 0; i < d; i++) {
            for (int u : component[c]) {
                for (int j = 0; j < d; j++) {
                    int need = (j - i + d) % d;
                    if (!can[u][need]) continue;
                    for (int to : g[u]) {
                        if (color[to] == c) continue;
                        dp[v][i] = max(dp[v][i], dp[to][(j + 1) % d]);
                    }
                }
            }
            dp[v][i] += score[v][i];
        }
        for (int u : component[c]) {
            for (int i = 0; i < d; i++) {
                for (int j = 0; j < d; j++) {
                    int need = (j - i + d) % d;
                    if (!canr[u][need]) continue;
                    dp[u][i] = max(dp[u][i], dp[v][j]);
                }
            }
        }
    }


    {
        int start = component[color[1]].front();
        int res = 0;
        for (int i = 0; i < d; i++) {
            int need = (i - 0 + d) % d;
            if (!canr[1][need]) continue;
            res = max(res, dp[start][i]);
        }
        cout << res << "\n";
    }

    return 0;
}