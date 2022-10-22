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

inline int sum_(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int mul_(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int sub_(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline void inc_(int &x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}

inline void dec_(int &x, int y) {
    if ((x -= y) < 0) {
        x += mod;
    }
}

inline int binpow_(int x, int pw) {
    if (x == 0)
        return 0;
    int res = 1;
    int tmp = x;
    while (pw > 0) {
        if (pw & 1) {
            res = mul_(res, tmp);
        }
        tmp = mul_(tmp, tmp);
        pw >>= 1;
    }
    return res;
}

inline int div_(int a, int b) {
    return mul_(a, binpow_(b, mod - 2));
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

const int MAXX = 2e5 + 123;

int fact[MAXX];
int rfact[MAXX];

void precalc() {
    fact[0] = 1;
    for (int i = 1; i < MAXX; i++)
        fact[i] = mul_(fact[i - 1], i);
    rfact[MAXX - 1] = binpow_(fact[MAXX - 1], mod - 2);
    for (int i = MAXX - 2; i >= 0; i--)
        rfact[i] = mul_(rfact[i + 1], i + 1);
}

struct input {
    int n, m;
    vector<int> s, t;

    input() = default;

    void read() {
        cin >> n >> m;
        s.resize(n);
        t.resize(m);
        for (auto& x : s) cin >> x;
        for (auto& x : t) cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        int mm = m;
        if (t.size() < s.size()) t.resize(s.size());
        t.push_back(0);
        m = (int) t.size();
        vector<int> cs(MAXX), f(MAXX);
        for (auto x : s) {
            cs[x]++;
            for (int cur = x; cur < MAXX; cur |= (cur + 1))
                f[cur]++;
        }
        int res = 0;
        int C = 1;
        for (int x = 0; x < MAXX; x++)
            C = mul_(C, rfact[cs[x]]);
        for (int i = 0; i < m; i++) {
            int coef = mul_(C, fact[n - (i + 1)]);
            int sm = 0;
//            for (int val = 0; val < t[i]; val++) {
//                inc_(sm, cs[val]);
//            }
            for (int cur = t[i] - 1; cur >= 0; cur = (cur & (cur + 1)) - 1)
                inc_(sm, f[cur]);
            inc_(res, mul_(coef, sm));
            if (cs[t[i]] == 0)
                break;
            C = mul_(C, fact[cs[t[i]]]);
            cs[t[i]]--;
            for (int cur = t[i]; cur < MAXX; cur |= (cur + 1))
                f[cur]--;
            C = mul_(C, rfact[cs[t[i]]]);
            if (i + 1 == n && n < mm)
                inc_(res, 1);
        }
        return output{res};
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