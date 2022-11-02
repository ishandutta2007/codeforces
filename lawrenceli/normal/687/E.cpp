#include <bits/stdc++.h>

using namespace std;

const int maxn = 5005;
const int inf = 1e9;

int n, m;
vector<int> adj[maxn];

int dist[maxn];
bool vis[maxn];

void go(int st) {
    memset(vis, 0, sizeof(vis));
    queue<int> que;
    for (int i : adj[st]) que.push(i);
    
    for (int t = 1; !que.empty(); t++) {
        int sze = que.size();
        for (int i = 0; i < sze; i++) {
            int x = que.front(); que.pop();
            if (vis[x]) continue;
            vis[x] = 1;
            if (x == st) {
                dist[st] = t;
                return;
            }

            for (int j : adj[x]) que.push(j);
        }
    }

    dist[st] = inf;
}

int ans;

int ind[maxn], lowlink[maxn], cnt;
bool in[maxn];
int stk[maxn], stksze;

int V[maxn], vs;
bool U[maxn];

void dfs(int v) {
    ind[v] = lowlink[v] = cnt++;
    in[v] = 1;
    stk[stksze++] = v;

    for (int i : adj[v]) {
        if (ind[i] == -1) {
            dfs(i);
            lowlink[v] = min(lowlink[v], lowlink[i]);
        } else if (in[i]) lowlink[v] = min(lowlink[v], ind[i]);
    }

    if (ind[v] == lowlink[v]) {
        bool b = 1;
        memset(U, 0, sizeof(U));
        vs = 0;
        int d = inf;
        while (b) {
            if (stk[stksze - 1] == v) b = 0;
            int x = stk[stksze - 1];
            d = min(d, dist[x]);
            U[x] = 1;
            V[vs++] = x;
            stksze--;
            in[x] = 0;
        }

        if (vs == 1) return;

        b = 0;
        for (int i = 0; i < vs; i++) {
            for (int j : adj[V[i]])
                if (!U[j]) {
                    b = 1;
                    break;
                }

            if (b) break;
        }

        if (!b) ans += 998 * d + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) go(i);

    ans = n;
    memset(ind, -1, sizeof(ind));
    for (int i = 1; i <= n; i++)
        if (ind[i] == -1)
            dfs(i);

    cout << ans << '\n';
}