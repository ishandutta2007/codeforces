#include <bits/stdc++.h>
using namespace std;

const int N = 100005, MX = 2E6 + 5, LG = 22, MOD = 1E9 + 7;

int n, m, u, v, cnt, h[MX], chr[MX], par[MX][LG], nxt[MX][10];
long long ans[N], val[MX];
bool vis[N];
vector<pair<int, int>> adj[N];

struct SNode {
    int u, nod, lst;

    SNode(int _u, int _nod) : u(_u), nod(_nod) {}

    inline bool operator>(const SNode &oth) const {
        if (h[nod] != h[oth.nod]) {
            return h[nod] > h[oth.nod];
        } else {
            int cu = nod, cv = oth.nod;
            for (int i = LG - 1; i >= 0; i--) {
                if (par[cu][i] != par[cv][i]) {
                    cu = par[cu][i];
                    cv = par[cv][i];
                }
            }
            return chr[cu] > chr[cv];
        }
    }
};
priority_queue<SNode, vector<SNode>, greater<SNode>> pq;

int process(int v, int lst) {
    int pw = 1;
    while (pw * 10 <= v) {
        pw *= 10;
    }
    while (pw > 0) {
        int d = v / pw; v %= pw;
        int cur = nxt[lst][d];
        if (cur == 0) {
            nxt[lst][d] = ++cnt;
            cur = cnt;
        }
        chr[cur] = d; val[cur] = (val[lst] * 10 + d) % MOD;
        par[cur][0] = lst; h[cur] = h[lst] + 1;
        for (int i = 1; i < LG; i++) {
            par[cur][i] = par[par[cur][i - 1]][i - 1];
        }
        lst = cur; pw /= 10;
    }
    return lst;
}

void dijkstra() {
    cnt = 1; val[1] = 0; h[1] = 0; chr[1] = 0;
    pq.push(SNode(1, 1));
    while (!pq.empty()) {
        SNode u = pq.top(); pq.pop();
        if (vis[u.u]) {
            continue;
        }
        vis[u.u] = true; ans[u.u] = val[u.nod];
        for (pair<int, int> &v : adj[u.u]) {
            if (!vis[v.first]) {
                pq.push(SNode(v.first, process(v.second, u.nod)));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    dijkstra();
    for (int i = 2; i <= n; i++) {
        cout << ans[i] << '\n';
    }
}