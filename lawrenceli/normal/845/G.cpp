#include <bits/stdc++.h>

using namespace std;

struct edge {
    int v, w, i;
};

const int maxn = 100100;

int n, m;
vector<edge> adj[maxn];
int dist[maxn];
bool in[maxn];

int vs[30], sze;

void ins(int w) {
    if (!sze) {
        vs[sze++] = w;
        return;
    }

    for (int i = 0; i < sze; i++)
        w = min(w, w ^ vs[i]);

    if (w) {
        vs[sze++] = w;
        for (int i = sze - 1; i > 0; i--)
            if (vs[i] > vs[i - 1])
                swap(vs[i], vs[i - 1]);
    }
}

void dfs(int v, int w = 0) {
    dist[v] = w;
    for (edge e : adj[v]) {
        if (dist[e.v] != -1) {
            ins(dist[v] ^ dist[e.v] ^ e.w);
            continue;
        }
        in[e.i] = true;
        dfs(e.v, w ^ e.w);
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge e1 = edge(), e2 = edge();
        e1.v = b, e1.w = c, e1.i = i;
        e2.v = a, e2.w = c, e2.i = i;
        adj[a].push_back(e1);
        adj[b].push_back(e2);
    }

    memset(dist, -1, sizeof(dist));
    dfs(1);

    int ans = dist[n];
    for (int i = 0; i < sze; i++)
        ans = min(ans, ans ^ vs[i]);
    cout << ans << '\n';
}