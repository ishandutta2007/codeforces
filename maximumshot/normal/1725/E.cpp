#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = 998'244'353;

void inc(int& x, int y) {
    if ((x += y) >= mod)
        x -= mod;
}

void dec(int& x, int y) {
    if ((x -= y) < 0)
        x += mod;
}

int mul(int x, int y) {
    return (1ll * x * y) % mod;
}

int mul(const vector<int>& a) {
    int res = 1;
    for (auto x : a)
        res = mul(res, x);
    return res;
}

int sum(int x, int y) {
    return x + y < mod ? x + y : x + y - mod;
}

int binpow(int x, int pw) {
    int res = 1;
    for (int tmp = x; pw > 0; pw >>= 1, tmp = mul(tmp, tmp))
        if (pw & 1) res = mul(res, tmp);
    return res;
}

struct output {
    int res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

const int X = 2e5 + 5;

int pr[X];
vector<int> prs[X], ds[X];
int F[X];

void precalc() {
    fill(pr, pr + X, 1);
    pr[0] = pr[1] = 0;
    for (int p = 2; p * p < X; p++) {
        if (!pr[p]) continue;
        for (int x = p * p; x < X; x += p)
            pr[x] = 0;
    }
    fill(F, F + X, 1);
    for (int p = 2; p < X; p++) {
        if (!pr[p]) continue;
        for (int x = p; x < X; x += p) {
            prs[x].push_back(p);
            F[x] *= p;
        }
    }
    for (int x = 1; x < X; x++) {
        for (int y = x; y < X; y += x)
            ds[y].push_back(x);
    }
}

struct input {
    int n;
    vector<int> a;
    vector<pii> es;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& x : a) cin >> x;
        es.resize(n - 1);
        for (auto& [u, v] : es) {
            cin >> u >> v;
            u--, v--;
        }
    }

    void print() {
        cout << n << "\n";
        for (auto x : a) cout << x << " "; cout << "\n";
        for (auto [u, v] : es) {
            cout << u + 1 << " " << v + 1 << "\n";
        }
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 10;
        const int MAXX = 200;
        n = rnd() % MAXN + 1;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % MAXX + 1;
        es.reserve(n - 1);
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        shuffle(p.begin(), p.end(), rnd);
        for (int i = 1; i < n; i++) {
            int j = max(0, i - 1 - int(rnd() % 3));
            es.emplace_back(p[i], p[j]);
        }
    }

    void gen_max_test() {

    }

    output fast() {
//        vector<vector<int>> dist(n, vector<int>(n, inf));
//        for (auto [u, v] : es) dist[u][v] = dist[v][u] = 1;
//        for (int v = 0; v < n; v++) dist[v][v] = 0;
//        for (int w = 0; w < n; w++) {
//            for (int u = 0; u < n; u++) {
//                for (int v = 0; v < n; v++) {
//                    dist[u][v] = min(dist[u][v], dist[u][w] + dist[w][v]);
//                }
//            }
//        }
        int mx = *max_element(a.begin(), a.end());
        vector<vector<int>> vs(mx + 1);
        for (int v = 0; v < n; v++) {
            int x = F[a[v]];
            for (int y : ds[x])
                vs[y].push_back(v);
        }
        int r2 = binpow(2, mod - 2);
        int r4 = binpow(4, mod - 2);
        int res = 0;
        vector<int> dp(mx + 1);
//        for (int g = 1; g <= mx; g++) {
//            int sm = 0;
//            for (int u : vs[g]) {
//                for (int v : vs[g]) {
//                    inc(sm, dist[u][v]);
//                }
//            }
//            dp[g] = sm;
//        }
        vector<int> sz(n), used(n);
        vector<vector<int>> h(n);
        for (auto [u, v] : es) {
            h[u].push_back(v);
            h[v].push_back(u);
        }
        function<void(int, int)> calc_sz = [&](int v, int par) {
            sz[v] = 1;
            for (int to : h[v]) {
                if (to == par || used[to]) continue;
                calc_sz(to, v);
                sz[v] += sz[to];
            }
        };
        function<void(int, int, int, int&)> find_c = [&](int v, int par, int Size, int& centroid) {
            int mx = Size - sz[v];
            for (int to : h[v]) {
                if (to == par || used[to]) continue;
                find_c(to, v, Size, centroid);
                if (centroid != -1) return;
                mx = max(mx, sz[to]);
            }
            if ((mx << 1) <= Size)
                centroid = v;
        };
        vector<int> sm(mx + 1), cn(mx + 1);
        function<void(int, int, int, int)> go = [&](int v, int par, int depth, int ty) {
            for (int y : ds[F[a[v]]]) {
                if (ty == 0) { // update res
                    inc(dp[y], sum(sm[y], mul(depth, cn[y])));
                } else if (ty == +1) { // add
                    inc(sm[y], depth);
                    cn[y]++;
                } else { // remove
                    assert(ty == -1);
                    sm[y] = cn[y] = 0;
                }
            }
            for (int to : h[v]) {
                if (to == par || used[to]) continue;
                go(to, v, depth + 1, ty);
            }
        };
        function<void(int)> work = [&](int v) {
            calc_sz(v, -1);
            int Size = sz[v];
            int centroid = -1;
            find_c(v, -1, Size, centroid);
            assert(centroid != -1);
            used[centroid] = 1;

            for (int y : ds[F[a[centroid]]]) {
                sm[y] = 0;
                cn[y] = 1;
            }

            for (int to : h[centroid]) {
                if (used[to]) continue;
                go(to, centroid, 1, 0); // update res
                go(to, centroid, 1, +1); // add
            }

            for (int to : h[centroid]) {
                if (used[to]) continue;
                go(to, centroid, 1, -1); // remove
            }

            for (int y : ds[F[a[centroid]]]) {
                sm[y] = 0;
                cn[y] = 0;
            }

            for (int to : h[centroid]) {
                if (used[to]) continue;
                work(to);
            }
        };
        work(0);
        for (int g = 1; g <= mx; g++) {
            if (g != F[g]) continue;
            dp[g] = mul({dp[g], r2, max(0, (int) vs[g].size() - 2)});
//            cout << g << " : " << dp[g] << "\n";
        }
        for (int x = 1; x <= mx; x++) {
            if (x == F[x]) {
                int tmp = 0;
                for (int y = x; y <= mx; y += x) {
                    if (y != F[y]) continue;
                    int sign = (int) prs[x].size() % 2 == (int) prs[y].size() % 2 ? 1 : mod - 1;
                    inc(tmp, mul(sign, dp[y]));
                }
                inc(res, mul(tmp, (int) prs[x].size()));
            }
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        vector<vector<int>> dist(n, vector<int>(n, inf));
        for (auto [u, v] : es) dist[u][v] = dist[v][u] = 1;
        for (int v = 0; v < n; v++) dist[v][v] = 0;
        for (int w = 0; w < n; w++) {
            for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                    dist[u][v] = min(dist[u][v], dist[u][w] + dist[w][v]);
                }
            }
        }
        int res = 0;
        for (int x = 0; x < n; x++) {
            for (int y = x + 1; y < n; y++) {
                for (int z = y + 1; z < n; z++) {
                    int f = dist[x][y] + dist[y][z] + dist[z][x];
                    assert(f % 2 == 0);
                    f /= 2;
                    int g = (int) prs[__gcd(a[x], __gcd(a[y], a[z]))].size();
                    inc(res, mul(f, g));
                }
            }
        }
        return output{res};
    }
#endif
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t = 1;
    while (t--)
        test_case();
}

#ifdef DEBUG
void test() {
    for (int t = 1;;t++) {
        input in;
        in.gen();
        input in_fs = in;
        input in_sl = in;
        output fs = in_fs.fast();
        output sl = in_sl.slow();
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA " << t << "\n";
            cout << "exp\n";
            sl.print();
            cout << "\n=========\n";
            cout << "fnd\n";
            fs.print();
            cout << "\n=========\n";
            in.print();
            break;
        }
    }
}
#endif

#ifdef DEBUG
void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}
#endif

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precalc();
    work();
//    test();
//    max_test();

    return 0;
}