#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 2e5 + 10;
vector<int> g[maxN];
int p[maxN];
int sz[maxN];
int get(int x) {
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
}
bool unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
    return true;
}
vector<int> tr[maxN];
int A[maxN], B[maxN], C[maxN];
int le[maxN];
int ri[maxN];
int nxt_we[maxN];
int nxt[maxN];
const int LOG = 20;
int mx[LOG][maxN];
int pos[maxN];
int lg[maxN];
int get(int l, int r) {
    if (l > r) swap(l, r);
    if (l == r) return -1;
    assert(r > l);
    r--;
    int k = lg[r - l + 1];
    return max(mx[k][l], mx[k][r - (1 << k) + 1]);
}
int clr[maxN];
int prv_e[maxN];
int nxt_e[maxN];
int id[maxN];
pair<int,pair<int,int>> min_by[maxN];
bool ban[maxN];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        le[i] = ri[i] = i;
        p[i] = i;
        sz[i] = 1;
        clr[i] = i;
        g[i].clear();
    }
    vector<pair<int, pair<int,int>>> ed;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        A[i] = a;
        B[i] = b;
        C[i] = c;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        ed.emplace_back(c, make_pair(a, b));
    }
    sort(ed.begin(), ed.end());
    for (auto& it : ed) {
        int u = it.second.first;
        int v = it.second.second;
        u = get(u);
        v = get(v);
        if (u == v) continue;
        if (sz[u] > sz[v]) {
            swap(u, v);
        }
        sz[v] += sz[u];
        p[u] = v;
        nxt[ri[u]] = le[v];
        nxt_we[ri[u]] = it.first;
        le[v] = le[u];
    }
    int c = le[get(1)];
    for (int i = 1; i <= n; i++) {
//        cout << c << " " << nxt_we[c] << endl;
        pos[c] = i;
//        cout << c << " " << nxt_we[c] << endl;
        id[i] = c;
        mx[0][i] = nxt_we[c];
        c = nxt[c];
    }
    lg[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i - 1];
        if (!(i & (i - 1))) lg[i]++;
    }
    for (int k = 0; k + 1 < LOG; k++) {
        for (int i = 1; i + (1 << (k + 1)) - 1 <= n; i++) {
            mx[k + 1][i] = max(mx[k][i], mx[k][i + (1 << k)]);
        }
    }
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }


    ed.clear();
    for (int iter = 0; ;iter++) {
        if (sz[get(1)] == n) break;
//        cout << " hi " << endl;
        prv_e[0] = 0;
        for (int i = 1; i <= n; i++) {
            clr[i] = get(id[i]);
            if (i == 1) prv_e[i] = 0;
            else {
                if (clr[i] == clr[i - 1]) {
                    prv_e[i] = prv_e[i - 1];
                }
                else {
                    prv_e[i] = i - 1;
                }
            }

        }
        nxt_e[n + 1] = n + 1;
        for (int i = n; i >= 1; i--) {
            if (i == n) {
                nxt_e[i] = i + 1;
            }
            else {
                if (clr[i] == clr[i + 1]) nxt_e[i] = nxt_e[i + 1];
                else nxt_e[i] = i + 1;
            }
        }
        const int INF = 2e9;
        for (int i = 1; i <= n; i++) {
            min_by[i] = make_pair(INF, make_pair(-1, -1));
        }
        for (int i = 1; i <= n; i++) {
            for (int z : g[id[i]]) {
                ban[z] = true;
            }

            int c = i - 1;
            while (c != 0) {
                if (clr[c] == clr[i]) {
                    c = prv_e[c];
                    continue;
                }
                if (ban[id[c]]) {
                    c--;
                    continue;
                }
                min_by[clr[i]] = min(min_by[clr[i]], make_pair(get(c, i), make_pair(i, c)));
                break;
            }
            c = i + 1;
            while (c != n + 1) {
                if (clr[c] == clr[i]) {
                    c = nxt_e[c];
                    continue;
                }
                if (ban[id[c]]) {
                    c++;
                    continue;
                }
                min_by[clr[i]] = min(min_by[clr[i]], make_pair(get(i, c), make_pair(i, c)));
                break;
            }
            for (int z : g[id[i]]) {
                ban[z] = false;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (id[i] == get(id[i])) {
                auto he = min_by[clr[i]];
                assert(he.second.first != -1);
                if (unite(id[he.second.first], id[he.second.second])) {
                    ed.emplace_back(he.first, make_pair(id[he.second.first], id[he.second.second]));
                }
            }
        }
    }
    sort(ed.begin(), ed.end());
    for (int i = 1; i <= n; i++) {
        le[i] = ri[i] = i;
        p[i] = i;
        sz[i] = 1;
        clr[i] = i;
    }
    sort(ed.begin(), ed.end());
    for (auto& it : ed) {
        int u = it.second.first;
        int v = it.second.second;
        u = get(u);
        v = get(v);
        if (sz[u] > sz[v]) {
            swap(u, v);
        }
        sz[v] += sz[u];
        p[u] = v;
        nxt[ri[u]] = le[v];
        nxt_we[ri[u]] = it.first;
        le[v] = le[u];
    }
    c = le[get(1)];
    for (int i = 1; i <= n; i++) {
//        cout << c << " " << nxt_we[c] << endl;
        pos[c] = i;
        id[i] = c;
        mx[0][i] = nxt_we[c];
        c = nxt[c];
    }
    lg[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i - 1];
        if (!(i & (i - 1))) lg[i]++;
    }
    for (int k = 0; k + 1 < LOG; k++) {
        for (int i = 1; i + (1 << (k + 1)) - 1 <= n; i++) {
            mx[k + 1][i] = max(mx[k][i], mx[k][i + (1 << k)]);
        }
    }
    for (int i = 1; i <= m; i++) {
        int x = pos[A[i]];
        int y = pos[B[i]];
        if (x > y) swap(x, y);
        cout << get(x, y) << " ";
    }
    cout << '\n';
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