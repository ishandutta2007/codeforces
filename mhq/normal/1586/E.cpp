#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 1e6 + 10;
int p[maxN];
int h[maxN];
vector<int> g[maxN];
bool used[maxN];
void dfs(int v) {
    used[v] = true;
    for (int to : g[v]) {
        if (used[to]) continue;
        h[to] = h[v] + 1;
        p[to] = v;
        dfs(to);
    }
}
int d[maxN];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    dfs(1);
    int q;
    cin >> q;
    vector<pair<int,int>> t;
    while (q--) {
        int a, b;
        cin >> a >> b;
       // assert(a != b);
        t.emplace_back(a, b);
        d[a] ^= 1;
        d[b] ^= 1;
    }
    bool hs = false;
    int f = 0;
    for (int i = 1; i <= n; i++) {
            hs |= d[i];
            f += d[i];
    }
    if (hs) {
        cout << "NO\n" << f / 2 << '\n';
        return 0;
    }
    cout << "YES\n";
    for (auto& it : t) {
        int a = it.first;
        int b = it.second;
        vector<int> p1, p2;
        while (a != b) {
            if (h[a] > h[b]) {
                p1.emplace_back(a);
                a = p[a];
            }
            else {
                p2.emplace_back(b);
                b = p[b];
            }
        }
      //  cout << p1.size() << " " << p2.size() << endl;
        reverse(p2.begin(), p2.end());
        vector<int> path;
        for (auto& it : p1) path.emplace_back(it);
        path.emplace_back(a);
        for (auto& it : p2) path.emplace_back(it);
        cout << path.size() << '\n';
        for (int v : path) cout << v << " ";
        cout << '\n';
    }
    return 0;
}