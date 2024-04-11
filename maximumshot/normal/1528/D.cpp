#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pii>> g(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
    }

    for (int s = 0; s < n; s++) {
        vector<ll> dist(n, inf64), used(n);
        dist[s] = 0;
        for (int iter = 0; iter < n - 1; iter++) {
            int best = -1;
            for (int v = 0; v < n; v++) {
                if (used[v])
                    continue;
                if (best == -1 || dist[v] < dist[best])
                    best = v;
            }
            if (best == -1)
                break;
            used[best] = 1;
            vector<ll> f(n, inf64);
            for (auto [to, w] : g[best]) {
                int now = (dist[best] % n + to) % n;
                int sep = n - now;
                int rem = n - sep;
                ll C = dist[best] - now + w;
//                for (int real_to = now; real_to < n; real_to++) {
//                    int cost = C + real_to;
//                    if (dist[real_to] > cost) {
//                        dist[real_to] = cost;
//                    }
//                }
                f[now] = min(f[now], C);
                now = 0;
                C = dist[best] + w + sep;
                f[now] = min(f[now], C);
//                for (int real_to = 0; real_to < n; real_to++) {
//                    int cost = C + real_to;
//                    if (dist[real_to] > cost) {
//                        dist[real_to] = cost;
//                    }
//                }
            }
            for (int i = 0; i + 1 < n; i++)
                f[i + 1] = min(f[i + 1], f[i]);
            for (int i = 0; i < n; i++)
                dist[i] = min(dist[i], f[i] + i);
        }
        for (int t = 0; t < n; t++)
            cout << dist[t] << " ";
        cout << "\n";
    }

    return 0;
}