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

void add(int& x, int y) {
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

int binpow(int x, int pw) {
    int res = 1, tmp = x;
    while (pw > 0) {
        if (pw & 1) res = mul(res, tmp);
        tmp = mul(tmp, tmp);
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
        return res == o.res;
    }
};

const int MAXN = 2e5 + 5;

int fact[MAXN];
int rfact[MAXN];

void precalc() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = mul(fact[i - 1], i);
    rfact[MAXN - 1] = binpow(fact[MAXN - 1], mod - 2);
    for (int i = MAXN - 2; i >= 0; i--) rfact[i] = mul(rfact[i + 1], i + 1);
}

int CNK(int n, int k) {
    if (n < k || k < 0) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

struct input {
    int n;
    vector<string> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& x : a)
            cin >> x;
    }

    void print() {
        cout << n << "\n";
        for (auto x : a)
            cout << x << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int N = 8;
        string ALPH = "WB?";
        n = rnd() % N + 1;
        a.resize(n);
        for (auto& x : a) {
            x.assign(2, '?');
            for (auto& c : x)
                c = ALPH[rnd() % (int) ALPH.size()];
        }
    }

    void gen_max_test() {

    }

    output fast() {
        int cw = 0, cb = 0;
        int full = 0, cqq = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == "WW" || a[i] == "BB") full = 1;
            if (a[i] == "??") cqq++;
            for (char c : a[i]) {
                if (c == 'W') cw++;
                if (c == 'B') cb++;
            }
        }
        if (cb > n || cw > n) return output{0};
        int res = CNK(n - cb + n - cw, n - cw);
        if (!full) {
            int tmp = 1;
            for (int i = 0; i < n; i++) {
                if (a[i] == "??") {
                    tmp = mul(tmp, 2);
                }
            }
            dec(res, tmp);

            int is_wb = 0, is_bw = 0;
            for (int i = 0; i < n; i++) {
                int cq = 0;
                for (char c : a[i]) cq += c == '?';
                if (cq == 2) {}
                else if (cq == 1) {
                    if (a[i][0] == '?') a[i][0] = a[i][1] ^ 'W' ^ 'B';
                    else a[i][1] = a[i][0] ^ 'W' ^ 'B';
                }
                if (a[i] == "WB") is_wb = 1;
                if (a[i] == "BW") is_bw = 1;
            }
            tmp = 0;
            if (is_wb && is_bw) {}
            else if (!is_wb && !is_bw) {
                if (cqq > 0) tmp = 2;
                else tmp = 1;
            } else {
                tmp = 1;
            }
            add(res, tmp);
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        vector<string> b = a;
        auto check = [&]() -> bool {
            vector<int> perm(n);
            iota(perm.begin(), perm.end(), 0);
            do {
                int ok = 1;
                for (int it = 0; it < n; it++) {
                    int i = perm[it];
                    int j = perm[(it + 1) % n];
                    if (b[i][1] == b[j][0]) {
                        ok = 0;
                        break;
                    }
                }
                if (ok)
                    return true;
            } while (next_permutation(perm.begin(), perm.end()));
            return false;
        };
        int res = 0;
        function<void(int)> rec = [&](int i) {
            if (i == n) {
                if (check())
                    add(res, 1);
            } else {
                for (string t : {"WW", "WB", "BB", "BW"}) {
                    int ok = 1;
                    for (int j = 0; j < 2; j++) {
                        if (a[i][j] != '?' && a[i][j] != t[j]) ok = 0;
                    }
                    if (ok) {
                        b[i] = t;
                        rec(i + 1);
                    }
                }
            }
        };
        rec(0);
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