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
        return res == o.res;
    }
};

int weight(const vector<int>& a) {
    int n = (int) a.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if (a[i] != a[j])
            res++;
    }
    return res;
}

int gcd(int x, int y) {
    return !x ? y : gcd(y % x, x);
}

int find_min_period(vector<int> a) {
    int n = (int) a.size();
    for (int p = 1; p <= n; p++) {
        if (n % p) continue;
        int ok = 1;
        for (int i = 0; i < n - p; i++)
            ok &= a[i] == a[i + p];
        if (ok) return p;
    }
    return n;
}

int find_n_shifts(vector<int> a) {
    int n = (int) a.size();
    set<vector<int>> q;
    for (int i = 0; i < n; i++) {
        vector<int> b = a;
        rotate(b.begin(), b.begin() + i, b.end());
        q.insert(b);
    }
    return (int) q.size();
}

bool check_period(vector<int> a, int l) {
    int n = (int) a.size();
    if (n % l) return false;
    for (int i = 0; i + l < n; i++) {
        if (a[i] != a[i + l]) return false;
    }
    return true;
}

struct input {
    int n;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& x : a) cin >> x;
    }

    void print() {
        cout << n << "\n";
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 10;
        n = rnd() % MAXN + 1;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % n + 1;
    }

    void gen_max_test() {

    }

    output fast() {
        if (*min_element(a.begin(), a.end()) == *max_element(a.begin(), a.end()))
            return output{1};
        vector<int> cnt(n + 1);
        for (auto x : a) cnt[x]++;
        vector<int> xs;
        for (int x = 1; x <= n; x++) {
            if (cnt[x] > 0)
                xs.push_back(x);
        }
        int gcd_cnt = 0;
        for (int i = 0; i <= n; i++)
            gcd_cnt = gcd(gcd_cnt, cnt[i]);
        vector<int> fact(n + 1), rfact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = mul_(fact[i - 1], i);
        rfact[n] = div_(1, fact[n]);
        for (int i = n - 1; i >= 0; i--) rfact[i] = mul_(rfact[i + 1], i + 1);
        vector<int> F(n + 1);
        for (int k = 1; k <= n; k++) {
            if (gcd_cnt % k) continue;
            F[k] = fact[n / k];
            for (int x : xs)
                F[k] = mul_(F[k], rfact[cnt[x] / k]);
        }
        int A = 0;
        { // |A| = ?
            int rn = div_(1, n);
            for (int i = 0; i < n; i++) {
                int k = n / gcd(i, n);
                if (gcd_cnt % k == 0) {
                    inc_(A, F[k]);
                }
            }
            A = mul_(A, rn);
        }
        int rA = div_(1, A);
//        vector<vector<int>> all;
//        {
//            vector<int> perm = a;
//            sort(perm.begin(), perm.end());
//            do {
//                all.push_back(perm);
//            } while (next_permutation(perm.begin(), perm.end()));
//        }
        int sm = 0;
        vector<int> S(n + 1);
        for (int l = 2; l <= n; l++) {
            if (n % l) continue;
//            for (auto p : all) {
//                if (check_period(p, l))
//                    inc_(S[l], weight(p));
//            }
            if (gcd_cnt % (n / l) == 0) {
//                vector<int> perm;
                int tot = fact[l];
                int ml_rfacts = 1;
                for (int x : xs) {
                    int cc = cnt[x] / (n / l);
                    ml_rfacts = mul_(ml_rfacts, rfact[cc]);
//                    while (cc-- > 0) perm.push_back(x);
                }
                tot = mul_(tot, ml_rfacts);
                int tmp = tot;
//                do {
//                    dec_(tmp, int(perm[0] == perm[1]));
//                } while (next_permutation(perm.begin(), perm.end()));
                for (int x : xs) {
                    int cc = cnt[x] / (n / l);
                    if (cc >= 2) {
                        int ml = mul_(fact[l - 2], rfact[cc - 2]);
                        ml = mul_(ml, ml_rfacts);
                        ml = mul_(ml, fact[cc]);
                        dec_(tmp, ml);
                    }
                }
                tmp = mul_(tmp, l);
                inc_(S[l], mul_(tmp, n / l));
            }
            for (int nl = 2 * l; nl <= n; nl += l)
                dec_(S[nl], S[l]);
        }
//        for (int l = 1; l <= n; l++) {
//            if (n % l) continue;
//            for (auto p : all) {
//                if (find_min_period(p) == l)
//                    inc_(S[l], weight(p));
//            }
//        }
        for (int l = 1; l <= n; l++) {
            if (n % l == 0)
                inc_(sm, div_(S[l], l));
        }
//        for (const auto& p : all) {
//            int w = weight(p);
//            int f = find_min_period(p);
//            int rf = div_(1, f);
//            inc_(sm, mul_(w, rf));
//        }
        int res = mul_(sm, rA);
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        sort(a.begin(), a.end());
        if (a.back() == a.front()) return output{1};
        set<vector<int>> Q;
        do {
            vector<int> b = a;
            for (int i = 0; i < n; i++) {
                vector<int> c = a;
                rotate(c.begin(), c.begin() + i, c.end());
                b = min(b, c);
            }
            Q.insert(b);
        } while (next_permutation(a.begin(), a.end()));
        int sm = 0;
        int cn = 0;
        for (auto q : Q) {
            inc_(sm, weight(q));
            inc_(cn, 1);
        }
        int res = div_(sm, cn);
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

    work();
//    test();
//    max_test();

    return 0;
}