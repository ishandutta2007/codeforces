#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
const int maxN = (1 << 20) + 10;
int a[maxN];
int bits[maxN];
int who[maxN];
int par[maxN];
int prv[maxN];
int dist[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[i];
    }
    for (int i = 1; i < (1 << n); i++) {
        bits[i] = bits[i >> 1] + (i & 1);
    }
    set<pair<int,int>> tt;
    for (int i = 0; i < (1 << n); i++) {
        if (bits[i] % 2 == 0) {
            int d = -1;
            for (int z = 0; z < n; z++) {
                int ti = (i ^ (1 << z));
                if (d == -1 || a[ti] > a[d]) d = ti;
            }
            who[i] = d;
            tt.insert(make_pair(a[who[i]] + a[i], i));
        }
    }
    memset(par, -1, sizeof par);
    vector<int> all;
    for (int step = 1; step <= k; step++) {
        vector<int> verts;
        for (int v : all) {
            for (int z = 0; z < n; z++) {
                verts.emplace_back(v ^ (1 << z));
            }
        }
        sort(verts.begin(), verts.end());
        verts.erase(unique(verts.begin(), verts.end()), verts.end());
        priority_queue<pair<int,int>> pq;
        for (int u : verts) {
            dist[u] = -1e9;
            prv[u] = u;
            if (par[u] == -1) {
                dist[u] = a[u];
                pq.push(make_pair(dist[u], u));
            }
        }
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int v = it.second;
            int d = it.first;
            if (dist[v] != d) continue;
            for (int z = 0; z < n; z++) {
                if (par[v ^ (1 << z)] == v) continue;
                if (par[v ^ (1 << z)] != -1) {
                    if (dist[par[v ^ (1 << z)]] < dist[v]) {
                        dist[par[v ^ (1 << z)]] = dist[v];
                        pq.push(make_pair(dist[par[v ^ (1 << z)]], par[v ^ (1 << z)]));
                        prv[par[v ^ (1 << z)]] = v;
                    }
                }
            }
        }
        pair<int,int> best = make_pair(-1, -1);
        if (!tt.empty()) {
            auto it = --tt.end();
            while (true) {
                if (par[it->second] == -1) {
                    best = *it;
                    break;
                }
                if (it == tt.begin()) break;
                it--;
            }
        }
        auto mem = best;
        for (int u : verts) {
            if (who[u] != -1) {
                best = max(best, make_pair(dist[u] + a[who[u]], u));
            }
        }
        if (best.first < 0) break;
        int vert = best.second;
        vector<int> path;
        path.emplace_back(who[vert]);
        if (mem != best) {
            while (prv[vert] != vert) {
                path.emplace_back(vert);
                path.emplace_back(par[vert]);
                vert = prv[vert];
            }
            path.emplace_back(vert);
        }
        else {
            path.emplace_back(vert);
        }
        reverse(path.begin(), path.end());
        assert(path.size() % 2 == 0);
        for (int z = 0; z < (int)path.size(); z += 2) {
            par[path[z]] = path[z + 1];
            par[path[z + 1]] = path[z];
        }
        all.emplace_back(path.back());
        int c = path.back();
        for (int x = 0; x < n; x++) {
            int nc = c ^ (1 << x);
            if (who[nc] == c) {
                tt.erase(make_pair(a[nc] + a[c], nc));
                who[nc] = -1;
                for (int p = 0; p < n; p++) {
                    if (par[nc ^ (1 << p)] != -1) continue;
                    if (who[nc] == -1 || a[nc ^ (1 << p)] > a[who[nc]]) who[nc] = nc ^ (1 << p);
                }
                if (who[nc] != -1) tt.insert({a[nc] + a[who[nc]], nc});
            }
        }
    }
    int cost = 0;
    for (int z : all) {
        cost += a[z];
        cost += a[par[z]];
    }
    cout << cost << '\n';
    return 0;
}