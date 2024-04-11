#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
struct dsu{
    vector < int > p;
    vector < int > sz;
    dsu(int n) {
        p.resize(n);
        sz.resize(n, 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int a) {
        if (a == p[a]) return a;
        return p[a] = find(p[a]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        p[b] = a;
        return true;
    }
    bool are_connected(int a, int b) {
        return find(a) == find(b);
    }
};
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> edges;
    vector<pair<int,pair<int,int>>> big;
    int small = 2e9;
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        small = min(small, abs(k - w));
        if (w < k) {
            edges.emplace_back(x, y);
        }
        else {
            big.emplace_back(w, make_pair(x, y));
        }
    }
    dsu P(n);
    for (auto& it : edges) {
        P.unite(it.first, it.second);
    }
    if (P.sz[P.find(0)] == n) {
        cout << small << '\n';
    }
    else {
        ll ans = 0;
        sort(big.begin(), big.end());
        for (auto& it : big) {
            if (P.unite(it.second.first, it.second.second)) ans += it.first - k;
        }
        cout << ans << '\n';
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}