#include <bits/stdc++.h>
#define int long long

using namespace std;

const int inf = 1ll * 1000000000 * 10000000;
int N, M;
vector <pair <int, int> > adj[500005];
int num[500005], low[500005], Time;
stack <int> st;
vector <int> cc;
int ans[500005];
int label[500005];
int id[500005], cur = 0;

void bfs(void) {
    queue <int> q;
    q.push(cc.back());
    label[cc.back()] = 0;
    int gcd = inf + 7, u, v, w;
    while (!q.empty()) {
        u = q.front(); q.pop();
        label[u] %= gcd;
        for (int i = 0; i < adj[u].size(); ++i) {
            v = adj[u][i].first, w = adj[u][i].second;
            label[v] %= gcd;
            if (id[v] != cur) continue;
            if (label[v] < 0) {
                label[v] = (label[u] + w) % gcd;
                q.push(v);
            }
            else if (label[v] != (label[u] + w) % gcd) {
                if (gcd > inf) gcd = abs((label[u] + w) % gcd - label[v]);
                else gcd = __gcd(gcd, abs((label[u] + w) % gcd - label[v]));
                q.push(v);
            }
        }
    }
    if (gcd > inf) gcd = -1;
    for (auto x: cc) ans[x] = gcd;
}

void dfs(int u) {
    num[u] = low[u] = ++Time;
    st.push(u);
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i].first;
        if (num[v]) low[u] = min(low[u], num[v]);
        else dfs(v), low[u] = min(low[u], low[v]);
    }
    if (num[u] == low[u]) {
        ++cur;
        cc.clear();
        int v;
        do {
            v = st.top(); st.pop();
            cc.push_back(v);
            id[v] = cur;
            num[v] = low[v] = inf + 7;
        } while (v != u);
        bfs();
    }
}

signed main(void) {
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    int u, v, c;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v >> c;
        adj[u].push_back(make_pair(v, c));
    }
    for (int i = 1; i <= N; ++i) label[i] = -1;
    for (int i = 1; i <= N; ++i) if (!num[i]) dfs(i);

    int Q;
    cin >> Q;
    while (Q--) {
        int s, t;
        cin >> u >> s >> t;
        if (s == 0) cout << "YES\n";
        else if (ans[u] != -1 && s % __gcd(ans[u], t) == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}