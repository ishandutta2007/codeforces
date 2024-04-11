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

using output = ll;
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

pair<ll, vector<ll>> count_inv(vector<ll> a) {
    if (a.size() < 2) {
        return {0, a};
    }
    int mid = a.size() / 2;
    vector<ll> l{a.begin(), a.begin() + mid}, r{a.begin() + mid, a.end()};
    auto [li, la] = count_inv(l);
    auto [ri, ra] = count_inv(r);
    ll ans = li + ri;
    int i = 0, j = 0;
    vector<ll> ret;
    while (i < (int)la.size() || j < (int)ra.size()) {
        if ((j == (int)ra.size()) || ((i < (int)la.size()) && la[i] <= ra[j])) {
            ans += j;
            ret.push_back(la[i++]);
        } else {
            ret.push_back(ra[j++]);
        }
    }
    return {ans, ret};
}

struct input {
    int n;
    vector<ll> a;

    void read() {
        cin >> n;
        a.resize(n);
        forn(i, n) {
            cin >> a[i];
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
        vector<ll> p;
        partial_sum(all(a), back_inserter(p));
        if (*min_element(all(p)) < 0) {
            return -1;
        }
        if (p.back() != *max_element(all(p))) {
            return -1;
        }
        return count_inv(p).first;
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

    test();
    // multitest();
    // stress();

    return 0;
}