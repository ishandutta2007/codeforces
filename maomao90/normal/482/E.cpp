
// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define RREP(i, s, e) for (int i = (s); i >= (e); i--)
template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
typedef long long ll;
typedef long double ld;
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define SZ(_a) (int) _a.size()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

const int INF = 1000000005;
const ll LINF = 1000000000000000005ll;
const int MAXN = 50005;
const int BLK = 1000000;

int n;
int p[MAXN];
int w[MAXN];
int q;

vi adj[MAXN];
int pre[MAXN], pst[MAXN], mp[MAXN], ptr;
int sub[MAXN];
set<ii> parts;
void dfs(int u) {
    sub[u] = 1;
    ii mx = {-1, -1};
    REP (i, 0, SZ(adj[u])) {
        int v = adj[u][i];
        dfs(v);
        sub[u] += sub[v];
        mxto(mx, {sub[v], i});
    }
    if (mx.SE > 0) {
        swap(adj[u][0], adj[u][mx.SE]);
    }
}
int hld(int u, bool head) {
    pre[u] = ptr++;
    mp[pre[u]] = u;
    if (adj[u].empty()) {
        if (head) {
            parts.insert({pre[u], pre[u]});
        }
        return pre[u];
    }
    int res = hld(adj[u][0], 0);
    if (head) {
        parts.insert({pre[u], res});
    }
    REP (i, 1, SZ(adj[u])) {
        hld(adj[u][i], 1);
    }
    pst[u] = ptr;
    return res;
}

struct mat {
    ll a, b, c;
    mat() {
        a = b = c = 0;
    }
    mat(ll a, ll b, ll c): a(a), b(b), c(c) {}
    mat& operator+= (ll x) {
        c += x * x * a + 2 * x * b;
        b += x * a;
        return *this;
    }
    mat& operator+= (const mat &o) {
        a += o.a;
        b += o.b;
        c += o.c;
        return *this;
    }
    mat operator+ (const mat &o) const {
        mat res = *this;
        res += o;
        return res;
    }
    mat& operator/= (ll x) {
        assert(a % x == 0 && b % x == 0 && c % x == 0);
        a /= x; b /= x; c /= x;
        return *this;
    }
    mat& operator*= (ll x) {
        a *= x; b *= x; c *= x;
        return *this;
    }
    friend ostream& operator<< (ostream &os, const mat &o) {
        return os << o.a << ' ' << o.b << ' ' << o.c;
    }
};

#define MLR int mid = lo + hi >> 1, lc = u << 1, rc = u << 1 ^ 1
struct MatSt {
    mat st[MAXN * 4];
    int lz[MAXN * 4];
    void init(vector<mat> &vec, int u = 1, int lo = 1, int hi = n) {
        lz[u] = 0;
        if (lo == hi) {
            st[u] = vec[lo];
        } else {
            MLR;
            init(vec, lc, lo, mid);
            init(vec, rc, mid + 1, hi);
            st[u] = st[lc] + st[rc];
        }
        cerr << lo << ", " << hi << ": " << st[u] << '\n';
    }
    void propo(int u, int lo, int hi) {
        if (lz[u] == 0 || lo == hi) return;
        MLR;
        st[lc] += lz[u];
        st[rc] += lz[u];
        lz[lc] += lz[u];
        lz[rc] += lz[u];
        lz[u] = 0;
    }
    void incre(int s, int e, ll x, int u = 1, int lo = 1, int hi = n) {
        if (lo >= s && hi <= e) {
            lz[u] += x;
            st[u] += x;
            cerr << lo << ", " << hi << ": " << st[u] << '\n';
            return;
        }
        MLR;
        propo(u, lo, hi);
        if (s <= mid) {
            incre(s, e, x, lc, lo, mid);
        }
        if (e > mid) {
            incre(s, e, x, rc, mid + 1, hi);
        }
        st[u] = st[lc] + st[rc];
        cerr << lo << ", " << hi << ": " << st[u] << '\n';
    }
    void changew(int p, int ow, int nw, int u = 1, int lo = 1, int hi = n) {
        if (lo == hi) {
            st[u] /= ow;
            st[u] *= nw;
            return;
        }
        MLR;
        propo(u, lo, hi);
        if (p <= mid) {
            changew(p, ow, nw, lc, lo, mid);
        } else {
            changew(p, ow, nw, rc, mid + 1, hi);
        }
        st[u] = st[lc] + st[rc];
    }
} matu, matv;
struct St {
    ll st[MAXN * 4], lz[MAXN * 4];
    void init(vll &vec, int u = 1, int lo = 1, int hi = n) {
        lz[u] = 0;
        if (lo == hi) {
            st[u] = vec[lo];
        } else {
            MLR;
            init(vec, lc, lo, mid);
            init(vec, rc, mid + 1, hi);
            st[u] = st[lc] + st[rc];
        }
        cerr << lo << ", " << hi << ", " << u << ": " << st[u] << '\n';
    }
    void propo(int u, int lo, int hi) {
        if (lz[u] == 0 || lo == hi) return;
        MLR;
        st[lc] += lz[u];
        st[rc] += lz[u];
        lz[lc] += lz[u];
        lz[rc] += lz[u];
        lz[u] = 0;
    }
    void incre(int s, int e, ll x, int u = 1, int lo = 1, int hi = n) {
        if (lo >= s && hi <= e) {
            st[u] += x;
            lz[u] += x;
            cerr << lo << ", " << hi << ": " << st[u] << '\n';
            return;
        }
        MLR;
        propo(u, lo, hi);
        if (s <= mid) {
            incre(s, e, x, lc, lo, mid);
        }
        if (e > mid) {
            incre(s, e, x, rc, mid + 1, hi);
        }
        st[u] = st[lc] + st[rc];
        cerr << lo << ", " << hi << ": " << st[u] << '\n';
    }
    void changew(int p, int ow, int nw, int u = 1, int lo = 1, int hi = n) {
        if (lo == hi) {
            assert(st[u] % ow == 0);
            st[u] /= ow;
            st[u] *= nw;
            return;
        }
        MLR;
        propo(u, lo, hi);
        if (p <= mid) {
            changew(p, ow, nw, lc, lo, mid);
        } else {
            changew(p, ow, nw, rc, mid + 1, hi);
        }
        st[u] = st[lc] + st[rc];
    }
    int qry(int p, int u = 1, int lo = 1, int hi = n) {
        if (lo == hi) {
            return st[u];
        }
        MLR;
        propo(u, lo, hi);
        if (p <= mid) {
            return qry(p, lc, lo, mid);
        } else {
            return qry(p, rc, mid + 1, hi);
        }
    }
} stov, stsub;

void rebuild() {
    REP (i, 1, n + 1) {
        adj[i].clear();
    }
    REP (i, 2, n + 1) {
        adj[p[i]].pb(i);
    }
    ptr = 1;
    dfs(1);
    hld(1, 1);
    vector<mat> vmatu(n + 1), vmatv(n + 1);
    vll vov(n + 1), vsub(n + 1);
    REP (i, 1, n + 1) {
        vmatu[pre[i]] = mat(w[i], (ll) w[i] * sub[i],
                (ll) w[i] * sub[i] * sub[i]);
        if (!adj[i].empty()) {
            vmatv[pre[i]] = mat(w[i], (ll) w[i] * sub[adj[i][0]],
                    (ll) w[i] * sub[adj[i][0]] * sub[adj[i][0]]);
        } else {
            vmatv[pre[i]] = mat(w[i], 0, 0);
        }
        ll sm = 0;
        REP (j, 1, SZ(adj[i])) {
            sm += (ll) sub[adj[i][j]] * sub[adj[i][j]];
        }
        vov[pre[i]] = sm * w[i];
        vsub[pre[i]] = sub[i];
    }
    matu.init(vmatu);
    matv.init(vmatv);
    stov.init(vov);
    stsub.init(vsub);
}

void detach(int u) {
    int hd = prev(parts.upper_bound({pre[u], INF})) -> FI;
    int ou = u;
    if (hd != pre[u]) { // split hld into more parts
        auto ptr = prev(parts.upper_bound({pre[u], INF}));
        auto [l, r] = *ptr;
        parts.erase(ptr);
        cerr << " erase " << l << ' ' << r << '\n';
        parts.insert({pre[u], r});
        parts.insert({l, pre[u] - 1});
        cerr << " insert " << pre[u] << ' ' << r << '\n';
        cerr << " insert " << l << ' ' << pre[u] - 1 << '\n';
    }
    int sub = stsub.qry(pre[u]);
    if (hd != pre[u]) {
        cerr << "matu: " << hd << ' ' << pre[u] - 1 << ' ' << -sub << '\n';
        matu.incre(hd, pre[u] - 1, -sub);
        cerr << "matv: " << hd << ' ' << pre[u] - 1 << ' ' << -sub << '\n';
        matv.incre(hd, pre[u] - 1, -sub);
        cerr << "stsub: " << hd << ' ' << pre[u] - 1 << ' ' << -sub << '\n';
        stsub.incre(hd, pre[u] - 1, -sub);
        u = mp[hd];
    }
    while (u != 1) {
        int cp = p[u];
        int csub = u == ou ? 0 : stsub.qry(pre[u]);
        int osub = csub + sub;
        cerr << ' ' << csub << ' ' << osub << '\n';
        cerr << "stov: " << pre[cp] << ' ' << pre[cp] << ' ' << (ll) w[cp] * ((ll) csub * csub - (ll) osub * osub) << '\n';
        stov.incre(pre[cp], pre[cp], (ll) w[cp] * 
                ((ll) csub * csub - (ll) osub * osub));
        int hd = prev(parts.upper_bound({pre[cp], INF})) -> FI;
        cerr << "matu: " << hd << ' ' << pre[cp] << ' ' << -sub << '\n';
        matu.incre(hd, pre[cp], -sub);
        cerr << "stsub: " << hd << ' ' << pre[cp] << ' ' << -sub << '\n';
        stsub.incre(hd, pre[cp], -sub);
        if (hd != pre[cp]) {
            cerr << "matv: " << hd << ' ' << pre[cp] - 1 << ' ' << -sub << '\n';
            matv.incre(hd, pre[cp] - 1, -sub);
        }
        u = mp[hd];
    }
}
void attach(int u) {
    int sub = stsub.qry(pre[u]);
    while (u != 1) {
        int cp = p[u];
        int csub = stsub.qry(pre[u]);
        int osub = csub - sub;
        stov.incre(pre[cp], pre[cp], (ll) w[cp] * 
                ((ll) csub * csub - (ll) osub * osub));
        int hd = prev(parts.upper_bound({pre[cp], INF})) -> FI;
        matu.incre(hd, pre[cp], sub);
        stsub.incre(hd, pre[cp], sub);
        if (hd != pre[cp]) {
            matv.incre(hd, pre[cp] - 1, sub);
        }
        u = mp[hd];
    }
}

bool isSub(int u, int v) {
    int hd = prev(parts.upper_bound({pre[u], INF})) -> FI;
    if (hd <= pre[v] && pre[v] <= pre[u]) {
        return 1;
    }
    while (u != 1) {
        int cp = p[u];
        int hd = prev(parts.upper_bound({pre[cp], INF})) -> FI;
        if (hd <= pre[v] && pre[v] <= pre[cp]) {
            return 1;
        }
        u = mp[hd];
    }
    return 0;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n;
    REP (i, 2, n + 1) {
        cin >> p[i];
    }
    REP (i, 1, n + 1) {
        cin >> w[i];
    }
    cin >> q;
    rebuild();
    ll ans = matu.st[1].c - matv.st[1].c - stov.st[1];
    ld res = (ld) ans / ((ll) n * n);
    cout << setprecision(10) << res << '\n';
    int blk = BLK;
    while (q--) {
        char t; cin >> t;
        if (t == 'P') {
            int v, u; cin >> v >> u;
            if (!isSub(u, v)) {
                detach(v);
                p[v] = u;
                attach(v);
            } else {
                detach(u);
                p[u] = v;
                attach(u);
            }
            if (--blk <= 0) {
                rebuild();
                blk = BLK;
            }
        } else {
            int v, x; cin >> v >> x;
            matu.changew(pre[v], w[v], x);
            matv.changew(pre[v], w[v], x);
            stov.changew(pre[v], w[v], x);
            w[v] = x;
        }
        ll ans = matu.st[1].c - matv.st[1].c - stov.st[1];
        ld res = (ld) ans / ((ll) n * n);
        cout << setprecision(10) << res << '\n';
    }
    return 0;
}

/*
5
1 2 2 1
1 2 3 4 5
1
P 3 4
*/