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
    vector<ll> res;

    void print() {
        for (auto x : res)
            cout << x << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, m;
    vector<int> a;
    vector<pii> qs;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n);
        for (auto& x : a) cin >> x;
        qs.resize(m);
        for (auto& [i, x] : qs) {
            cin >> i >> x;
            i--;
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<ll> res;
        set<int> Q = {n, n + 1, -1};
        a.push_back(-1);
        for (int i = 0; i < n; i++) {
            if (i == 0 || a[i] != a[i - 1])
                Q.insert(i);
        }
        auto calc = [&](int len) -> ll {
            return 1ll * len * (len + 1) / 2;
        };
        auto query = [&](int bl, int br) -> ll {
            if (br < 0 || bl >= n) return 0;
            return calc(n) - calc(bl) - calc(n - br - 1);
        };
        ll cur = 0;
        for (auto it = Q.begin(); *it < n;) {
            auto nit = next(it);
            cur += query(*it, *nit - 1);
            it = nit;
        }
        for (auto [i, x] : qs) {
            if (a[i] != x) {
                auto it = --Q.upper_bound(i);
                int ql = *it;
                auto nit = next(it);
                int qr = *nit - 1;
                Q.erase(it);
                cur -= query(ql, qr);
                if (ql < i) Q.insert(ql), cur += query(ql, i - 1);
                if (i < qr) Q.insert(i + 1), cur += query(i + 1, qr);

                it = --Q.upper_bound(i);
                nit = next(it);

                int l1 = *it;
                int r1 = i - 1;
                int l2 = i + 1;
                int r2 = *next(nit) - 1;

                if (a[l1] != x) {
                    if (a[l2] != x) {
                        Q.insert(i);
                        cur += query(i, i);
                    } else {
                        Q.erase(l2);
                        Q.insert(i);
                        cur -= query(l2, r2);
                        cur += query(i, r2);
                    }
                } else {
                    if (a[l2] != x) {
                        cur -= query(l1, r1);
                        cur += query(l1, i);
                    } else {
                        Q.erase(l2);
                        cur -= query(l1, r1);
                        cur -= query(l2, r2);
                        cur += query(l1, r2);
                    }
                }

                a[i] = x;
            }
            res.push_back(cur);
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