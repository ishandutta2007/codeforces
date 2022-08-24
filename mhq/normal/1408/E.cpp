#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
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
const int maxN = 1e5 + 10;
int a[maxN], b[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    dsu f(n + m + 2);
    ll tot = 0;
    vector<pair<int,pair<int,int>>> edges;
    for (int i = 1; i <= m; i++) {
        int sz;
        cin >> sz;
        for (int j = 0; j < sz; j++) {
            int x;
            cin >> x;
            edges.emplace_back(b[x] + a[i], make_pair(x, i + n));
            tot += b[x] + a[i];
        }
    }
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    for (auto& it : edges) {
        if (f.unite(it.second.first, it.second.second)) tot -= it.first;
    }
    cout << tot;
    return 0;
}