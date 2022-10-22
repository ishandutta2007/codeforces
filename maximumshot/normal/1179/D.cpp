#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

struct Line {
    ll k, b;
    ll f(ll x) {
        return k * x + b;
    }
};

struct CHT {
    vector<Line> st;
    void add_line(ll k, ll b) {
        st.push_back({k, b});
        return;
        if (!st.empty() && st.back().k == k) {
            st.pop_back();
            st.push_back({k, b});
            return;
        }
        Line l = {k, b};
        while ((int)st.size() > 1) {
            Line l1 = st[(int)st.size() - 2];
            Line l2 = st[(int)st.size() - 1];
            if ((l2.b - l1.b) * (l2.k - l.k) < (l.b - l2.b) * (l1.k - l2.k)) {
                break;
            }
            st.pop_back();
        }
        st.push_back(l);
    }
    ll get_min(ll x) {
        if (st.empty()) return inf64;
        if ((int)st.size() <= 2) {
            ll res = inf64;
            for (auto l : st) {
                res = min(res, l.f(x));
            }
            return res;
        }
        int bl = 0;
        int br = (int)st.size() - 2;
        int bm;
        while (br - bl > 1) {
            bm = (bl + br) >> 1;
            if ((st[bm + 1].b - st[bm].b) < x * (st[bm].k - st[bm + 1].k)) {
                bl = bm + 1;
            } else {
                br = bm;
            }
        }
        bl = max(0, bl - 20);
        br = min((int)st.size() - 1, br + 20);
        ll res = inf64;
        for (int i = bl; i <= br; i++) {
            res = min(res, st[i].f(x));
        }
        return res;
    }
};

const int N = 5e5 + 5;

int n;
vector<int> g[N];
int sz[N];

void dfs(int v, int par = -1) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to == par) continue;
        dfs(to, v);
        sz[v] += sz[to];
    }
}

ll f[N];
ll mn[N];

ll sqr(ll x) {
    return x * x;
}

void calc(int v, ll value = 0, int par = -1) {
    if ((int)g[v].size() == 1) {
        f[v] = value + 1;
        mn[v] = f[v];
        return;
    }
    f[v] = value;
    mn[v] = inf64;
    for (int to : g[v]) {
        if (to == par) continue;
        calc(to, value + sqr(sz[v] - sz[to]), v);
        mn[v] = min(mn[v], mn[to]);
    }
}

ll result = inf64;

void go(int v, int par = -1) {
    for (int i = 0; i < (int) g[v].size(); i++) {
        if (g[v][i] == par) {
            swap(g[v][i], g[v][(int) g[v].size() - 1]);
            g[v].pop_back();
            break;
        }
    }
    sort(g[v].begin(), g[v].end(), [&](int to1, int to2){
        return sz[to1] > sz[to2] || (sz[to1] == sz[to2] && mn[to1] > mn[to2]);
    });
    CHT cht;
    for (int j = 0; j < (int)g[v].size(); j++) {
        int J = g[v][j];
        ll hlp = 0;
        hlp += mn[J] + sqr(n - sz[J]) - 2ll * f[v] - sqr(sz[v]) - sqr(sz[v] - sz[J]);
        ll tmp = cht.get_min(2ll * (sz[v] + sz[J] - n));
        if (tmp == inf64) hlp = inf64;
        else hlp += tmp;
        result = min(result, hlp);
        cht.add_line(sz[J], mn[J]);
    }
//    for (int i = 0; i < (int) g[v].size(); i++) {
//        int I = g[v][i];
//        for (int j = 0; j < i; j++) {
//            int J = g[v][j];
//            result = min(result,
//                mn[J] + sqr(n - sz[J]) - 2 * f[v] - sqr(sz[v]) - sqr(sz[v] - sz[J])
//                + mn[I] + sz[I] * (-2 * n + 2 * sz[J] + 2 * sz[v])
//            );
//        }
//    }
    for (int to : g[v]) {
        go(to, v);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;

    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n == 2) {
        cout << "2\n";
        return 0;
    }

    int root = 1;
    while ((int) g[root].size() == 1) root++;

    dfs(root);
    calc(root);
    go(root);

//    cout << "root = " << root << "\n";
//
//    for (int v = 1; v <= n; v++) {
//        cout << sz[v] << " " << f[v] << " " << mn[v] << "\n";
//    }

    result = (sqr(n) - result) / 2 + 1ll * n * (n - 1) / 2;

    cout << result << "\n";

    return 0;
}