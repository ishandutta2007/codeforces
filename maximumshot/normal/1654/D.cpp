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

const int mod = 998244353;

int binpow(int x, int pw) {
    int res = 1, tmp = x;
    while (pw > 0) {
        if (pw & 1) res = (1ll * res * tmp) % mod;
        tmp = (1ll * tmp * tmp) % mod;
        pw >>= 1;
    }
    return res;
}

struct output {
    int res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

const int MAXN = 2e5 + 5;

int pr[MAXN];
vector<int> dv[MAXN];

void precalc() {
    fill(pr, pr + MAXN, 1);
    pr[0] = pr[1] = 0;
    for (int p = 2; p * p < MAXN; p++) {
        if (!pr[p])
            continue;
        for (int x = p * p; x < MAXN; x += p)
            pr[x] = 0;
    }
    for (int p = 2; p < MAXN; p++) {
        if (!pr[p])
            continue;
        for (int x = p; x < MAXN; x += p) {
            int y = x;
            while (y % p == 0) {
                y /= p;
                dv[x].push_back(p);
            }
        }
    }
}

struct input {
    int n;
    vector<vector<tuple<int, int, int>>> g;
    vector<int> cnt, mx, coef;

    input() = default;

    void read() {
        cin >> n;
        g.resize(n);
        for (int u, v, x, y, i = 0; i < n - 1; i++) {
            cin >> u >> v >> x >> y;
            u--, v--;
            g[v].emplace_back(u, x, y);
            g[u].emplace_back(v, y, x);
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    void dfs(int v, int par) {
        for (auto [to, x, y] : g[v]) {
            if (to == par)
                continue;
            for (int p : dv[x]) cnt[p]--;
            for (int p : dv[y]) cnt[p]++;
            for (int p : dv[y]) mx[p] = max(mx[p], cnt[p]);
            coef[to] = (1ll * coef[v] * x) % mod;
            coef[to] = (1ll * coef[to] * binpow(y, mod - 2)) % mod;
            dfs(to, v);
            for (int p : dv[x]) cnt[p]++;
            for (int p : dv[y]) cnt[p]--;
        }
    }

    output fast() {
        cnt.assign(n + 1, 0);
        mx.assign(n + 1, 0);
        coef.assign(n, 1);
        dfs(0, -1);
        int res = 1;
        for (int p = 2; p <= n; p++) {
            res = (1ll * res * binpow(p, mx[p])) % mod;
        }
        int V = 0;
        for (int v = 0; v < n; v++) {
            V = (V + 1ll * res * coef[v]) % mod;
        }
        return output{V};
    }

#ifdef DEBUG
    output slow() {
        return output();
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
    int t;
    cin >> t;
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

void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}

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