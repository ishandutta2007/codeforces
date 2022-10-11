#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void Main();

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    Main();
#ifdef LOCAL
    cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

int n, m;
vector<vector<int>> G;
const int INF = 1e9;
vector<vector<int>> dist;
int s, b, k, h;
vector<array<int, 2>> base;
vector<array<int, 3>> bad;
vector<vector<int>> G_khun;
int used_num = 0;
vector<int> used, matched;

bool try_khun(int v) {
    if (used[v] == used_num) {
        return false;
    }
    used[v] = used_num;
    for (auto u : G_khun[v]) {
        if (matched[u] == -1) {
            matched[u] = v;
            return true;
        }
    }
    for (auto u : G_khun[v]) {
        if (try_khun(matched[u])) {
            matched[u] = v;
            return true;
        }
    }
    return false;
}

void Main() {
    cin >> n >> m;
    G.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    dist.resize(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
        for (auto j : G[i]) {
            dist[i][j] = dist[j][i] = 1;
        }
    }
    for (int w = 0; w < n; w++) {
        for (int v = 0; v < n; v++) {
            for (int u = 0; u < n; u++) {
                if (dist[v][w] != INF && dist[w][u] != INF) {
                    dist[v][u] = min(dist[v][u], dist[v][w] + dist[w][u]);
                }
            }
        }
    }
    cin >> s >> b >> k >> h;
    bad.resize(s);
    for (auto &el : bad) {
        cin >> el[0] >> el[1] >> el[2];
        el[0]--;
    }
    base.resize(b);
    for (auto &el : base) {
        cin >> el[0] >> el[1];
        el[0]--;
    }
    G_khun.resize(b);
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < s; j++) {
            if (bad[j][1] >= base[i][1] && dist[base[i][0]][bad[j][0]] <= bad[j][2]) {
                G_khun[i].push_back(j);
            }
        }
    }
    used.assign(b, -1);
    matched.assign(s, -1);
    int cnt = 0;
    for (int i = 0; i < b; i++) {
        cnt += try_khun(i);
        used_num++;
    }
    ll ans = 1ll * cnt * k;
    for (int i = 1; i <= s; i++) {
        ll cur_cost = 0;
        cur_cost += 1ll * i * h;
        cur_cost += 1ll * (cnt - max(0, min(cnt, i - (s - cnt)))) * k;
        ans = min(ans, cur_cost);
    }
    cout << ans << '\n';
}