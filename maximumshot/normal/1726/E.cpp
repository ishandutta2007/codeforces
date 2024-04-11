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

const int MAXN = 3e5 + 5;

vector<int> F, G, pw2;
vector<int> fact, rfact;

int CNK(int n, int k) {
    if (n < k || k < 0) return 0;
    return mul_(fact[n], mul_(rfact[k], rfact[n - k]));
}

void precalc() {
    F.resize(MAXN);
    F[0] = 1;
    for (int n = 1; n < MAXN; n++) {
        F[n] = (F[n - 1] + 1ll * (n - 1) * F[n - 2]) % mod;
    }
    fact.resize(MAXN);
    rfact.resize(MAXN);
    fact[0] = 1;
    for (int n = 1; n < MAXN; n++)
        fact[n] = mul_(fact[n - 1], n);
    rfact[MAXN - 1] = binpow_(fact[MAXN - 1], mod - 2);
    for (int n = MAXN - 2; n >= 0; n--)
        rfact[n] = mul_(rfact[n + 1], n + 1);
    G.resize(MAXN);
    G[0] = 1;
    for (int n = 1; n < MAXN; n++) {
        // 2 * n elements -> choose n pairs
        G[n] = mul_(G[n - 1], 2 * n - 1);
    }
    pw2.resize(MAXN);
    pw2[0] = 1;
    for (int n = 1; n < MAXN; n++)
        pw2[n] = mul_(pw2[n - 1], 2);
}

struct input {
    int n;

    input() = default;

    void read() {
        cin >> n;
    }

    void print() {
    }

    void gen() {
    }

    void gen_max_test() {

    }

    output fast() {
        int res = 0;
        for (int k = 0; 2 * k <= n; k += 2) {
            int c = CNK(n - k, k);
            c = mul_(c, G[k / 2]);
            c = mul_(c, pw2[k / 2]);
            inc_(res, mul_(c, F[n - 2 * k]));
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        int res = 0;
        do {
            int ok = 1;
            for (int i = 0; i < n; i++) {
                int j = p[i];
                int k = p[j];
                if (abs(i - k) > 1) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                inc_(res, 1);
                set<int> lens;
                vector<int> used(n);
                for (int i = 0; i < n; i++) {
                    if (used[i]) continue;
                    int len = 0;
                    for (int j = i; !used[j]; j = p[j])
                        used[j] = 1, len++;
                    lens.insert(len);
                }
            }
        } while (next_permutation(p.begin(), p.end()));
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