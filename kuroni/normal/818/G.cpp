#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 6005, MX = 1E5 + 5, INF = 1E8 + 7;

int n, u, ind = 0, pot[N], dst[N], lv[MX], lm[7];
int s, t, ans = 0, pa[MX], we[MX], co[MX], tr[MX];
vector<pair<int, int>> adj[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void add_edge(int u, int v, int w, int c) {
    we[ind] = w; co[ind] = c; pa[ind] = u ^ v;
    adj[u].push_back({v, ind++});
    we[ind] = 0; co[ind] = -c; pa[ind] = u ^ v;
    adj[v].push_back({u, ind++});
    pot[v] = min(pot[v], pot[u] + c);
}

void dijkstra() {
    fill(dst + 1, dst + t + 1, INF);
    pq.push({dst[s] = 0, 0});
    while (!pq.empty()) {
        pair<int, int> u = pq.top(); pq.pop();
        if (u.fi > dst[u.se]) {
            continue;
        }
        for (pair<int, int> &v : adj[u.se]) {
            int cur = u.fi + co[v.se] + pot[u.se] - pot[v.fi];
            if (cur < dst[v.fi] && we[v.se] > 0) {
                tr[v.fi] = v.se;
                pq.push({dst[v.fi] = cur, v.fi});
            }
        }
    }
}

void trace() {
    int u = t, mx = INF;
    while (u != s) {
        int ind = tr[u];
        mx = min(mx, we[ind]);
        u = u ^ pa[ind];
    }
    u = t;
    while (u != s) {
        int ind = tr[u];
        we[ind] -= mx;
        we[ind ^ 1] += mx;
        ans += mx * co[ind];
        u = u ^ pa[ind];
    }
    for (int i = 0; i <= t; i++) {
        pot[i] += dst[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    s = 0, t = 2 * n + 1;
    fill(pot + 1, pot + t + 1, INF);
    for (int i = 1; i <= n; i++) {
        cin >> u;
        if (lm[u % 7] != 0) {
            add_edge(lm[u % 7] + n, i, 1, 0);
            add_edge(lm[u % 7], i, INF, 0);
        }
        lm[u % 7] = i;
        if (lv[u - 1] != 0) {
            add_edge(lv[u - 1] + n, i, 1, 0);
        }
        if (lv[u + 1] != 0) {
            add_edge(lv[u + 1] + n, i, 1, 0);
        }
        if (lv[u] != 0) {
            add_edge(lv[u], i, INF, 0);
        }
        lv[u] = i;
        add_edge(s, i, 1, 0);
        add_edge(i, i + n, 1, -1);
        add_edge(i + n, t, 1, 0);
    }
    for (int i = 0; i < 4; i++) {
        dijkstra();
        trace();
    }
    cout << -ans;
}