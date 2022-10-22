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
    ll res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    vector<int> h;

    input() = default;

    void read() {
        cin >> n;
        h.resize(n);
        for (auto& x : h) cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        auto get = [&](vector<int> f) -> ll {
            ll res = 0;
            for (int i = 0; i < n; i++) {
                if (!f[i]) continue;
                int mx = max(h[i - 1], h[i + 1]);
                int need = max(0, mx - h[i] + 1);
                res += need;
            }
            return res;
        };
        vector<int> f(n);
        for (int i = 1; i + 1 < n; i += 2) f[i] = 1;
        ll res = get(f);
        if (n % 2 == 0) {
            f.assign(n, 0);
            for (int i = 2; i + 1 < n; i += 2) f[i] = 1;
            res = min(res, get(f));
            vector<ll> pref(n), suff(n);
            for (int i = 1; i + 1 < n; i += 2) {
                if (i >= 2) pref[i] = pref[i - 2];
                int mx = max(h[i - 1], h[i + 1]);
                int need = max(0, mx - h[i] + 1);
                pref[i] += need;
            }
            for (int i = n - 2; i > 0; i -= 2) {
                if (i + 2 < n) suff[i] = suff[i + 2];
                int mx = max(h[i - 1], h[i + 1]);
                int need = max(0, mx - h[i] + 1);
                suff[i] += need;
            }
            for (int i = 1; i + 3 < n - 1; i += 2) {
                ll tmp = pref[i] + suff[i + 3];
                res = min(res, tmp);
            }
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