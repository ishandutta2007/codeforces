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

const int SZ = 505;

struct Line {
    ld k, b;
};

struct CHT {

    Line lines[SZ];
    int sz = 0;

    CHT() = default;

    void add_line(ld k, ld b) {
        Line L = {k, b};
        while (sz >= 2) {
            Line L1 = lines[sz - 2];
            Line L2 = lines[sz - 1];
            if ((L2.k - L.k) * (L2.b - L1.b) >= (L1.k - L2.k) * (L.b - L2.b)) {
                sz--;
            } else {
                break;
            }
        }
        lines[sz++] = L;
    }

    ll get_min(ld x) {
        if (!sz) return inf64;
        ld res = 4e18;
        int bl = 0;
        int br = sz - 1;
        int bm;
        while (br - bl > 1) {
            bm = (bl + br) / 2;
            if ((lines[bm].k - lines[bm + 1].k) * x < (lines[bm + 1].b - lines[bm].b)) {
                br = bm;
            } else {
                bl = bm;
            }
        }
        bl = max(0, bl - 1);
        br = min(sz - 1, br + 1);
        for (int i = bl; i <= br; i++) {
            res = min(res, lines[i].k * x + lines[i].b);
        }
        return ll(res);
    }

    void clear() {
        sz = 0;
    }
};

struct SQRT {
    int n; // [0, n)
    vector<ll> cf, add_all, a;
    vector<vector<int>> sorted;
    vector<CHT> chts_mn, chts_mx;
    int bl;

    SQRT(const vector<ll>& _cf, const vector<ll>& _a) {
        cf = _cf;
        a = _a;
        n = (int) _cf.size();
        build();
    }

    void build() {
        bl = SZ - 5;
        add_all.resize((n - 1) / bl + 1);
        sorted.resize((n - 1) / bl + 1);
        for (int i = 0; i < n; i++) {
            sorted[i / bl].push_back(i);
        }
        for (auto & b : sorted) {
            sort(b.begin(), b.end(), [&](int i, int j) {
                return cf[i] < cf[j];
            });
        }
        chts_mn.resize((n - 1) / bl + 1);
        chts_mx.resize((n - 1) / bl + 1);
        for (int b = 0; b < (int) sorted.size(); b++) {
            for (int i = (int) sorted[b].size() - 1; i >= 0; i--) {
                int id = sorted[b][i];
                chts_mn[b].add_line(cf[id], 1ll * cf[id] * a[id]);
            }
            for (int i = 0; i < (int) sorted[b].size(); i++) {
                int id = sorted[b][i];
                chts_mx[b].add_line(-cf[id], -1ll * cf[id] * a[id]);
            }
        }
    }

    void update_small(int l, int r, ll x) {
        int b = l / bl;
        chts_mn[b].clear();
        chts_mx[b].clear();
        for (int i : sorted[b]) {
            a[i] += add_all[b];
            if (l <= i && i <= r) {
                a[i] += x;
            }
        }
        add_all[b] = 0;
        for (int i = (int) sorted[b].size() - 1; i >= 0; i--) {
            int id = sorted[b][i];
            chts_mn[b].add_line(cf[id], 1ll * cf[id] * a[id]);
        }
        for (int i = 0; i < (int) sorted[b].size(); i++) {
            int id = sorted[b][i];
            chts_mx[b].add_line(-cf[id], -1ll * cf[id] * a[id]);
        }
    }

    void update(int l, int r, ll x) {
        int L = l / bl;
        int R = r / bl;
        if (L == R) {
            update_small(l, r, x);
            return;
        }
        for (int j = L + 1; j < R; j++) {
            add_all[j] += x;
        }
        update_small(l, L * bl + bl - 1, x);
        update_small(R * bl, r, x);
    }

    ll get(int l, int r) {
        ll mn = +inf64;
        ll mx = -inf64;
        int L = l / bl;
        int R = r / bl;
        for (int b = L + 1; b < R; b++) {
            mn = min(mn, chts_mn[b].get_min(add_all[b]));
            mx = max(mx, -chts_mx[b].get_min(add_all[b]));
        }
        for (int i = l; i / bl == L && i <= r; i++) {
            ll hlp = 1ll * cf[i] * (a[i] + add_all[L]);
            mn = min(mn, hlp);
            mx = max(mx, hlp);
        }
        if (L < R) {
            for (int i = r; i / bl == R; i--) {
                ll hlp = 1ll * cf[i] * (a[i] + add_all[R]);
                mn = min(mn, hlp);
                mx = max(mx, hlp);
            }
        }
        return max(mx, -mn);
    }
};

struct Query {
    int t, v, x;
};

const int N = 2e5 + 5;

int n, q;
int parent[N];
int a[N], b[N];
Query qs[N];
int tin[N], tout[N], timer;
vector<int> g[N];
int B[N];
int euler[N];

void dfs(int v) {
    euler[timer] = v;
    tin[v] = timer++;
    B[v] = b[v] + (v > 1 ? B[parent[v]] : 0);
    for (int to : g[v]) {
        dfs(to);
    }
    tout[v] = timer;
}

vector<ll> fast() {
    for (int v = 1; v <= n; v++) {
        g[v].clear();
        B[v] = 0;
    }
    for (int v = 2; v <= n; v++) {
        g[parent[v]].push_back(v);
    }
    timer = 0;
    dfs(1);

    for (int v = 1; v <= n; v++) {
        if (B[v] < 0) {
            B[v] = -B[v];
        }
    }

    vector<ll> res, cf(n), aa(n);
    for (int i = 0; i < n; i++) {
        cf[i] = B[euler[i]];
    }

    for (int v = 1; v <= n; v++) {
        aa[tin[v]] += a[v];
        if (tout[v] < n) {
            aa[tout[v]] -= a[v];
        }
    }

    for (int i = 0; i + 1 < n; i++) {
        aa[i + 1] += aa[i];
    }

    SQRT data(cf, aa);

    for (int i = 0; i < q; i++) {
        int v = qs[i].v;
        if (qs[i].t == 1) {
            data.update(tin[v], tout[v] - 1, qs[i].x);
        } else {
            res.push_back(data.get(tin[v], tout[v] - 1));
        }
    }

    return res;
}

void gen(mt19937& rnd) {
//    n = rnd() % 1000 + 1;
//    q = rnd() % 100 + 1;
    n = 2e5;
    q = 1e5;
    for (int i = 2; i <= n; i++) {
        parent[i] = rnd() % (i - 1) + 1;
    }
    const int X = 5000;
    for (int i = 1; i <= n; i++) {
        a[i] = rnd() % (2 * X + 1) - X;
        b[i] = rnd() % (2 * X + 1) - X;
    }
    for (int i = 0; i < q; i++) {
        qs[i].t = rnd() % 2 + 1;
        qs[i].v = rnd() % n + 1;
        if (qs[i].t == 1) {
            qs[i].x = rnd() % (2 * X + 1) - X;
        }
    }
}

void read() {
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> qs[i].t >> qs[i].v;
        if (qs[i].t == 1) {
            cin >> qs[i].x;
        }
    }
}

vector<ll> slow() {
    vector<int> aa(n + 1), bb(n + 1);
    auto is_son = [&](int S, int P) -> bool {
        while (1) {
            if (S == P) return true;
            if (S == 1) break;
            S = parent[S];
        }
        return false;
    };
    auto upd = [&](int v, int x, int y) {
        for (int u = 1; u <= n; u++) {
            if (is_son(u, v)) {
                aa[u] += x;
                bb[u] += y;
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        upd(i, a[i], b[i]);
    }
    vector<ll> res;
    for (int i = 0; i < q; i++) {
        if (qs[i].t == 1) {
            upd(qs[i].v, qs[i].x, 0);
        } else {
            ll cost = 0;
            for (int u = 1; u <= n; u++) {
                if (is_son(u, qs[i].v)) {
                    cost = max(cost, 1ll * abs(aa[u]) * abs(bb[u]));
                }
            }
            res.push_back(cost);
        }
    }
    return res;
}

void WORK() {
    read();
//    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
//    gen(rnd);
//    vector<ll> res = slow();
    vector<ll> res = fast();
    for (ll x : res) {
        cout << x << "\n";
    }
}

void TEST() {
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

    while (1) {
        gen(rnd);

        vector<ll> sl = slow();
        vector<ll> fs = fast();

        if (sl == fs) {
            cout << "OK ( "; for (ll x : fs) cout << x << " "; cout << ")\n";
        } else {
            cout << "WA\n";
            cout << "exp = "; for (ll x : sl) cout << x << " "; cout << ")\n";
            cout << "fnd = "; for (ll x : fs) cout << x << " "; cout << ")\n";

            cout << "\n----\n";
            cout << n << " " << q << "\n";

            for (int v = 2; v <= n; v++) {
                cout << parent[v] << " ";
            }
            cout << "\n";

            for (int v = 1; v <= n; v++) {
                cout << a[v] << " ";
            }
            cout << "\n";

            for (int v = 1; v <= n; v++) {
                cout << b[v] << " ";
            }
            cout << "\n";

            for (int i = 0; i < q; i++) {
                cout << qs[i].t << " " << qs[i].v << " ";
                if (qs[i].t == 1) {
                    cout << qs[i].x << "\n";
                } else {
                    cout << "\n";
                }
            }

            break;
        }
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    TEST();
    WORK();

    return 0;
}