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

struct output {
    int res;

    void print() {
        cout << (res ? "YES" : "NO") << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, m;
    vector<int> a, b;
    vector<pii> segs;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n);
        b.resize(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        segs.resize(m);
        for (auto& [l, r] : segs)
            cin >> l >> r, l--;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<ll> S(n + 1);
        for (int i = 0; i < n; i++)
            S[i + 1] = S[i] - a[i] + b[i];
        if (S[n]) return output{0};
        set<pii> good;
        set<int> Q;
        for (int i = 0; i <= n; i++) {
            if (S[i])
                Q.insert(i);
        }
        vector<vector<int>> g(n + 1);
        for (auto [l, r] : segs) {
            g[l].push_back(r);
            g[r].push_back(l);
            if (S[l] == 0 && S[r] == 0) {
                good.insert({l, r});
            }
        }
        while (!good.empty()) {
            auto [l, r] = *good.begin();
            good.erase(good.begin());
            for (auto it = Q.lower_bound(l); it != Q.end() && *it <= r;) {
                int i = *it;
                it = Q.erase(it);
                S[i] = 0;
                for (int j : g[i]) {
                    int ql = min(i, j);
                    int qr = max(i, j);
                    if (S[ql] == 0 && S[qr] == 0)
                        good.insert({ql, qr});
                }
            }
        }
        return output{Q.empty()};
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

    work();
//    test();
//    max_test();

    return 0;
}