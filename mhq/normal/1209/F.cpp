//#define _GLIBCXX_DEBUG
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int mult(int a, int b) {
    return (1LL * a * b) %  mod;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
const int maxN = 6e5 + 10;
vector<pair<int,int>> start_edge[maxN];
int x[maxN], y[maxN];
int n, m;
int dist[maxN];
vector<int> by_dig[maxN][10];
int ans[maxN];
bool used[maxN];
void dfs(vector<int>& p) {
    for (int z = 0; z < 10; z++) {
        vector<int> add;
        for (int v : p) {
            for (auto& it : by_dig[v][z]) {
                if (!used[it]) {
                    ans[it] = sum(z, mult(ans[v], 10));
                    used[it] = true;
                    add.emplace_back(it);
                }
            }
        }
        if (!add.empty()) {
            dfs(add);
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >>  y[i];
        int sz = 0;
        int t = i;
        while (t) {
            sz++;
            t /= 10;
        }
        start_edge[x[i]].emplace_back(y[i], sz);
        start_edge[y[i]].emplace_back(x[i], sz);
    }
    priority_queue<pair<int,int>> pq;
    for (int i = 1; i <= n; i++) dist[i] = 1e9;
    dist[1] = 0;
    pq.push(make_pair(-dist[1], 1));
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int v = it.second;
        int d = -it.first;
        if (dist[v] != d) continue;
        for (auto& pit : start_edge[v]) {
            if (dist[pit.first] > dist[v] + pit.second) {
                dist[pit.first] = dist[v] + pit.second;
                pq.push(make_pair(-dist[pit.first], pit.first));
            }
        }
    }
    int sz = n;
    auto add_edge = [&](int from, int to, int edge) {
        int cur = to;
        while (edge > 0) {
            if (edge < 10) {
                by_dig[from][edge].emplace_back(cur);
                edge /= 10;
            }
            else {
                int ncur = ++sz;
                by_dig[ncur][edge % 10].emplace_back(cur);
                cur = ncur;
                edge /= 10;
            }
        }
    };
    for (int i = 1; i <= m; i++) {
        int dig_sz = 0;
        int t = i;
        while (t) {
            dig_sz++;
            t /= 10;
        }
        if (dist[y[i]] == dist[x[i]] + dig_sz) {
            add_edge(x[i], y[i], i);
        }
        if (dist[x[i]] == dist[y[i]] + dig_sz) {
            add_edge(y[i], x[i], i);
        }
    }
    used[1] = true;
    vector<int> cur = {1};
    dfs(cur);
    for (int i = 2; i <= n; i++) cout << ans[i] << '\n';
    return 0;
}