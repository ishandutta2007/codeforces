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

// using output = int;
struct output {
    vector<int> ans;

    void do_print() const {
        for (int u : ans) {
            print(u);
        }
    }

    bool operator==([[maybe_unused]] const output &other) const {
        TODO("output::operator==");
    }
};
template <> struct printer<output> {
    static bool print(const output &v) {
        v.do_print();
        return true;
    }
};

struct input {
    int n;
    vector<pair<int, int>> segs;
    int q;
    vector<int> w;

    void read() {
        cin >> n;
        segs.resize(n);
        forn(i, n) {
            cin >> segs[i].ff >> segs[i].ss;
        }
        cin >> q;
        w.resize(q);
        forn(i, q) {
            cin >> w[i];
        }
    }

    void do_print() const {
        TODO("input::do_print");
    }

    void gen() {
        // Use static rnd gen.
        TODO("input::gen");
    }

    int solve(vector<pair<int, int>> segs) {
        vector<pair<int, int>> evs;
        for (auto p : segs) {
            evs.emplace_back(p.ff, 1);
            evs.emplace_back(p.ss + 1, -1);
        }
        sort(all(evs));
        int ans = 0, cur = 0;
        for (auto [_, b] : evs) {
            cur += b;
            ans = max(ans, cur);
        }
        return ans;
    }

    output fast() {
        vector<int> answers(30);
        for (int i = 0; i < 30; i++) {
            vector<pair<int, int>> lsegs;
            forn(j, n) {
                if (segs[j].second - segs[j].first + 1 >= (1 << i)) {
                    answers[i]++;
                    continue;
                }
                int l = segs[j].first & ((1 << i) - 1);
                int r = l + (segs[j].second - segs[j].first);
                lsegs.emplace_back(l, r);
                if (r < l + (1 << i)) {
                    lsegs.emplace_back(l + (1 << i), r + (1 << i));
                }
            }
            answers[i] += solve(lsegs);
        }
        vector<int> ret(q);
        forn(i, q) {
            int j = __builtin_ctz(w[i]);
            ret[i] = answers[j];
        }
        return {ret};
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