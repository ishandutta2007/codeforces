#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (int)1e6 + 10;
int lp[maxN];
const int maxK = 180;
const int INF = (int)1e9;
const int LIM = 1001;
vector < int > g[maxN];
int dist[maxN];
int par[maxN];
int id[maxN], bck[maxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);

    cin >> n;
    int sz = 1;
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            id[i] = sz;
            bck[sz] = i;
            sz++;
            for (int j = 2 * i; j < maxN; j += i) lp[j] = i;
        }
    }
    int best = INF;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        vector < int > f;
        while (x > 1) {
            int p = lp[x];
            int c = 0;
            while (x % p == 0) {
                x /= p;
                c ^= 1;
            }
            if (!c) continue;
            f.emplace_back(p);
        }
        if (f.empty()) {
            cout << 1;
            return 0;
        }
        if (f.size() == 1) {
            f.emplace_back(1);
        }
        assert(f.size() == 2);
        if (f[0] > f[1]) swap(f[0], f[1]);
        g[id[f[0]]].emplace_back(id[f[1]]);
        g[id[f[1]]].emplace_back(id[f[0]]);
    }

    for (int i = 0; i < sz; i++) {
        if (g[i].empty()) continue;
        sort(g[i].begin(), g[i].end());
        int was = g[i].size();
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());

        if (g[i].size() != was) {
            cout << 2;
            return 0;
        }
    }

    for (int a = 0; a < sz; a++) {
        if (bck[a] >= LIM) break;
        queue < int > q;
        for (int b = 0; b < sz; b++) {
            dist[b] = -1;
            par[b] = b;
        }
        dist[a] = 0;
        par[a] = -1;
        q.push(a);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : g[v]) {
                if (dist[u] == -1) {
                    dist[u] = dist[v] + 1;
                    if (par[v] != -1) par[u] = par[v];
                    q.push(u);
                }
                else if (par[u] != par[v] && par[u] != -1 && par[v] != -1) {
                    best = min(best, dist[u] + dist[v] + 1);
                }
            }
        }
    }
    if (best > n) cout << -1 << '\n';
    else cout << best << '\n';
    return 0;
}