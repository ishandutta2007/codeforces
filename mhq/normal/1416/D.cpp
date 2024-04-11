//#ifdef DEBUG
//#define _GLIBCXX_DEBUG
//#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m, q;
const int maxN = 2e5 + 10;
int p[maxN];
int bck[maxN];
const int maxM = 3e5 + 10;
const int maxQ = 5e5 + 10;
int a[maxM], b[maxM];
bool mark[maxM];
int tp[maxQ], val[maxQ];
int par[maxN];
int sz[maxN];
vector<int> vert[maxN];
int from[maxQ], to[maxQ];
int get(int x) {
    if (x == par[x]) return x;
    return par[x] = get(par[x]);
}
bool unite(int x, int y, int id = -1) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    par[y] = x;
    sz[x] += sz[y];
    if (id != -1) {
        from[id] = x;
        to[id] = y;
    }
    for (int& c : vert[y]) vert[x].emplace_back(c);
    return true;
}
set<int> all[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        bck[p[i]] = i;
        sz[i] = 1;
        par[i] = i;
        vert[i].emplace_back(i);
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> tp[i] >> val[i];
        if (tp[i] == 2) mark[val[i]] = true;
    }
    for (int i = 1; i <= m; i++) {
        if (!mark[i]) {
            unite(a[i], b[i]);
        }
    }
    
    for (int i = q; i >= 1; i--) {
        if (tp[i] != 2) continue;
        if (!unite(a[val[i]], b[val[i]], i)) {
            tp[i] = -1;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        all[get(i)].insert(p[i]);
    }
    for (int i = 1; i <= q; i++) {
        if (tp[i] == -1) continue;
        if (tp[i] == 2) {
            int x = from[i];
            int y = to[i];
            for (int r : vert[y]) {
                par[r] = y;
                if (p[r] != 0) {
                    all[x].erase(p[r]);
                    all[y].insert(p[r]);
                }
            }
        }
        else {
            int root = get(par[val[i]]);
            if (all[root].empty()) {
                cout << 0 << '\n';
            }
            else {
                auto it = *(--all[root].end());
                cout << it << '\n';
                p[bck[it]] = 0;
                all[root].erase(it);
            }
        }
    }
    return 0;
}