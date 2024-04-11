#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, q, s, d;
const int maxN = 2e5 + 10;
int a[maxN];
vector<pair<int,int>> g[maxN];
int p[maxN];
vector<int> by_cmp[maxN];
int get(int x) {
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
}
mt19937 rnd(228);
bool unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return false;
    if (rnd() & 1) swap(a, b);
    p[b] = a;
    return true;
}
int mx[maxN];
void dfs(int v, int p) {
    for (auto& it : g[v]) {
        if (p == it.second) continue;
        mx[it.second] = max(mx[v], it.first);
        dfs(it.second, v);
    }
}
int main() {
//     freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> q >> s >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = i;
    }
    int edges = 0;
    auto get_len = [&](int x, int y) ->int{
        if (x > y) swap(x, y);
        int z = y - x;
        if (z >= d) return z - d;
        else return d - z;
    };
    for (int iter = 0; ; iter++) {
        if (edges == n - 1) break;
        for (int i = 1; i <= n; i++) {
            by_cmp[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            by_cmp[get(i)].emplace_back(i);
        }
        set<pair<int,int>> by_cord;
        for (int i = 1; i <= n; i++) by_cord.insert({a[i], i});
        vector<pair<int,pair<int,int>>> add_edges;
        for (int i = 1; i <= n; i++) {
            if (by_cmp[i].empty()) continue;
            for (int v : by_cmp[i]) {
                by_cord.erase(make_pair(a[v], v));
            }

            pair<int,pair<int,int>> p1 = make_pair(1e9, make_pair(1e9, 1e9));
            for (int v : by_cmp[i]) {
                auto it = by_cord.lower_bound({a[v] + d, -1});
                if (it != by_cord.end()) p1 = min(p1, make_pair(get_len(it->first, a[v]), make_pair(it->second, v)));
                if (it != by_cord.begin()) {
                    --it;
                    p1 = min(p1, make_pair(get_len(it->first, a[v]), make_pair(it->second, v)));
                }
                it = by_cord.lower_bound({a[v] - d, -1});
                if (it != by_cord.end()) p1 = min(p1, make_pair(get_len(it->first, a[v]), make_pair(it->second, v)));
                if (it != by_cord.begin()) {
                    --it;
                    p1 = min(p1, make_pair(get_len(it->first, a[v]), make_pair(it->second, v)));
                }
            }
            add_edges.emplace_back(p1);
            for (int v : by_cmp[i]) {
                by_cord.insert(make_pair(a[v], v));
            }
        }
        for (auto& it : add_edges) {
            if (unite(it.second.first, it.second.second)) {
                edges++;
                g[it.second.first].emplace_back(it.first, it.second.second);
                g[it.second.second].emplace_back(it.first, it.second.first);
            }
        }
        if (edges == n - 1) break;
    }
    dfs(s, -1);
    while (q--) {
        int i, k;
        cin >> i >> k;
        if (mx[i] <= k) cout << "Yes\n";
        else cout << "No\n";
    }
}