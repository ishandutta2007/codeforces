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
    int n, a, b;
    vector<int> xs;

    input() = default;

    void read() {
        cin >> n >> a >> b;
        xs.resize(n);
        for (auto& x : xs)
            cin >> x;
        xs.insert(xs.begin(), 0);
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        ll res = 5 * inf64;
        ll pref = 0, sm = 0;
        for (int i = 0; i <= n; i++)
            sm += xs[i];
        for (int i = 0; i <= n; i++) {
            ll tmp = 0;
            sm -= xs[i];
//            for (int j = i + 1; j <= n; j++)
//                tmp += xs[j] - xs[i];
            tmp += sm - 1ll * (n - i) * xs[i];
            tmp = b * tmp + pref;
            res = min(res, tmp);
            if (i < n) {
                pref += 1ll * b * (xs[i + 1] - xs[i]);
                pref += 1ll * a * (xs[i + 1] - xs[i]);
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