#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1005;
int h[maxN];
vector < int > g[maxN];
bool mark[maxN];
int up[maxN];
void dfs(int v, int p) {
    for (int to : g[v]) {
        if (to == p) continue;
        up[to] = v;
        h[to] = h[v] + 1;
        dfs(to, v);
    }
}
pair < int, int > ask(vector < int >& c) {
    cout << "? " << c.size() << " ";
    for (int v : c) cout << v << " ";
    cout << endl;
    int a, d;
    cin >> a >> d;
    return make_pair(a, d);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            h[i] = 0;
            up[i] = 0;
        }
        memset(mark, 0, sizeof mark);
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        vector < int > f(n);
        iota(f.begin(), f.end(), 1);
        auto t = ask(f);
        int len = t.second;
        int v = t.first;
        up[v] = 0;
        dfs(v, -1);
        int mx = 0;
        for (int i = 1; i <= n; i++) mx = max(mx, h[i]);
        int l = (len + 1) / 2 - 1;
        int r = min(mx, len) + 1;
        //r is bad
        //l is ok
        pair < int, int > mx_vert = make_pair(-1, -1);
        while (r - l > 1) {
            int mid = (l + r) / 2;
            vector < int > gg;
            for (int i = 1; i <= n; i++) {
                if (h[i] == mid) gg.emplace_back(i);
            }
            assert(!gg.empty());
            auto td = ask(gg);
            if (td.second > len) {
                r = mid;
            }
            else {
                l = mid;
                mx_vert = max(mx_vert, make_pair(mid, td.first));
            }
        }
        assert(mx_vert.first != -1);
        int s = mx_vert.second;
        int he = mx_vert.first;
        int lft = len - he;
        assert(he >= lft);
        int ns = s;
        while (ns != v) {
            mark[ns] = true;
            ns = up[ns];
        }
        vector < int > gg;
        for (int i = 1; i <= n; i++) {
            if (h[i] == lft && !mark[i]) gg.emplace_back(i);
        }
        assert(!gg.empty());
        auto tt = ask(gg);
        cout << "! " << s << " " << tt.first << endl;
        string resp;
        cin >> resp;
        if (resp == "Incorrect") exit(0);
    }
    return 0;
}