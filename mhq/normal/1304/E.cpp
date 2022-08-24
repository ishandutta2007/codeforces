#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, q;
const int LG = 20;
const int maxN = (int)1e5 + 100;
vector < int > g[maxN];
struct DistanceSolver{
    int ti = 0;
    vector < int > fi;
    vector < int > lg;
    vector < int > h;
    vector < vector < int > > up;
    int n;

    void init(int _n) {
        n = _n;
        lg.resize(2 * n + 1);
        fi.resize(n);
        h.resize(n);
        lg[1] = 0;
        for (int i = 2; i <= 2 * n; i++) {
            lg[i] = lg[i - 1];
            if (!(i & (i - 1))) lg[i]++;
        }
        up.resize(LG);
        dfs(0, -1);
        for (int i = 1; i < LG; i++) {
            up[i].resize(up[0].size());
        }
        for (int i = 0; i + 1 < LG; i++) {
            for (int j = 0; j + (1 << (i + 1)) - 1 < up[0].size(); j++) {
                up[i + 1][j] = min(up[i][j], up[i][j + (1 << i)]);
            }
        }
    }

    void dfs(int v, int p) {
        fi[v] = ti;
        up[0].push_back(h[v]);
        ti++;
        for (int to : g[v]) {
            if (to == p) continue;
            up[0].push_back(h[v]);
            ti++;
            h[to] = h[v] + 1;
            dfs(to, v);
        }
    }

    int getDist(int u, int v) {
        if (u == v) return 0;
        int l = fi[u]; int r = fi[v];
        if (l > r) swap(l, r);
        int k = lg[r - l + 1];
        int h_lca = min(up[k][l], up[k][r - (1 << k) + 1]);
        return h[u] + h[v] - 2 * h_lca;
    }

}DS;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < (n - 1); i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    DS.init(n);
    cin >> q;
    while (q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        bool ok = false;
        --x; --y; --a; --b;
        int c = DS.getDist(a, b);
        if (c % 2 == k % 2 && c <= k) ok = true;
        for (int p : {x, y}) {
            int tot = DS.getDist(a, p) + 1 + DS.getDist(b, (p ^ x) ^ y);
            if (tot % 2 == k % 2 && tot <= k) ok = true;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}