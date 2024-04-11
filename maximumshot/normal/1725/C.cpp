#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forrn(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define PYMOD(a, m) ((((a) % (m)) + (m)) % (m))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define ff first
#define ss second

const int mod = 998'244'353;

struct m_int {
    int value;

    m_int() {}
    m_int(int val) : value{val} {}
};

m_int operator+(m_int lhs, m_int rhs) {
    int ret = lhs.value + rhs.value;
    return m_int{ret >= mod ? ret - mod : ret};
}

m_int &operator+=(m_int &lhs, m_int rhs) { return lhs = (lhs + rhs); }

m_int operator-(m_int lhs, m_int rhs) {
    int ret = lhs.value - rhs.value;
    return m_int{ret < 0 ? ret + mod : ret};
}

m_int &operator-=(m_int &lhs, m_int rhs) { return lhs = (lhs - rhs); }

m_int operator*(m_int lhs, m_int rhs) {
    return m_int{(int)((1ll * lhs.value * rhs.value) % mod)};
}

m_int& operator*=(m_int& lhs, m_int rhs) { return lhs = (lhs * rhs); }

ostream& operator<<(ostream& os, const m_int& val) { return os << val.value; }

bool operator==(m_int lhs, m_int rhs) { return lhs.value == rhs.value; }
bool operator!=(m_int lhs, m_int rhs) { return lhs.value != rhs.value; }

template <typename T> struct printer {
    static bool print(const T &value) {
        cout << value << ' ';
        return false;
    }
};
template <typename T> struct printer<vector<T>> {
    static bool print(const vector<T> &v) {
        for (const auto &element : v) {
            cout << element << ' ';
        }
        return false;
    }
};
template <typename... Args> void print(const Args &...args) {
    if (!(printer<Args>::print(args), ...)) {
        cout << '\n';
    }
}
[[noreturn]] void TODO(const std::string &what = "") {
    if (what.empty()) {
        throw std::runtime_error{"TODO"};
    }
    throw std::runtime_error{"TODO: " + what};
}

using output = m_int;
// struct output {
//     void do_print() const {
//         TODO("output::do_print");
//     }

//     bool operator==([[maybe_unused]] const output &other) const {
//         TODO("output::operator==");
//     }
// };
// template <> struct printer<output> {
//     static bool print(const output &v) {
//         v.do_print();
//         return true;
//     }
// };

const int maxn = 300'179;
m_int fct[maxn];

m_int fpow(m_int a, int n) {
    m_int ret = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            ret *= a;
        }
        a *= a;
        n /= 2;
    }
    return ret;
}

m_int divm(m_int a, m_int b) {
    return a * fpow(b, mod - 2);
}

m_int cnk(int n, int k) {
    return divm(fct[n], fct[k] * fct[n - k]);
}

struct input {
    int n, m;
    vector<ll> d;

    void read() {
        cin >> n >> m;
        d.resize(n);
        forn(i, n) {
            cin >> d[i];
        }
    }

    void do_print() const {
        TODO("input::do_print");
    }

    void gen() {
        // Use static rnd gen.
        TODO("input::gen");
    }

    output fast() {
        vector<ll> cds(n);
        forn(i, n - 1) {
            cds[i + 1] = cds[i] + d[i];
        }
        ll S = cds[n - 1] + d[n - 1];
        int a = 0, b = n;
        vector<bool> used(n);
        if (S % 2 == 0) {
            forn(i, n) {
                ll j = (cds[i] + S / 2) % S;
                auto it = lower_bound(all(cds), j);
                if (it != cds.end() && *it == j) {
                    if (!used[i]) {
                        used[i] = true;
                        used[it - cds.begin()] = true;
                        a++;
                        b -= 2;
                    }
                }
            }
        }
        // print(a, b, m);
        m_int ans = 0;
        auto pw = [](m_int a, int n) -> m_int { if (a == 0 && n == 0) return 1; else return fpow(a, n); };
        forn(x, min(a, m) + 1) {
            ans += cnk(a, x) * cnk(m, x) * fct[x] * pw(m_int{m - x} * (m_int{m - x} - 1), a - x) * pw(m - x, b);
        }
        return ans;
    }

    output slow() {
        TODO("input::slow");
    }
};
template <> struct printer<input> {
    static bool print(const input &v) {
        v.do_print();
        return true;
    }
};

void test() {
    input in;
    in.read();
    output out = in.fast();
    print(out);
}

void multitest() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; t++) {
        test();
    }
}

void stress() {
    int TESTS = 10'000;
    for (int test = 1; test <= TESTS; test++) {
        input in;
        in.gen();
        input in_fast = in, in_slow = in;
        output ja = in_slow.slow();
        output ca = in_fast.fast();
        if (!(ja == ca)) {
            print("WA test", test);
            print(in);
            print("Expected:", ja);
            print("Found:", ca);
            return;
        }
    }
    print("OK");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // Code here:

    fct[0] = 1;
    forrn(i, 1, maxn) {
        fct[i] = i * fct[i - 1];
    }

    test();
    // multitest();
    // stress();

    return 0;
}