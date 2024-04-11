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
    ld res;

    void print() {
        cout.precision(20);
        cout << fixed;
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    vector<int> x, t;

    input() = default;

    void read() {
        cin >> n;
        x.resize(n);
        t.resize(n);
        for (auto& e : x) cin >> e;
        for (auto& e : t) cin >> e;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        const int ITER = 100;
        ld bl = *max_element(t.begin(), t.end()), br = 1e9, bm;
        for (int iter = 0; iter < ITER; iter++) {
            bm = (bl + br) / 2;
            ld L = -1e9, R = +1e9;
            for (int i = 0; i < n; i++) {
                ld delta = bm - t[i];
                ld ql = x[i] - delta;
                ld qr = x[i] + delta;
                L = max(L, ql);
                R = min(R, qr);
            }
            if (L <= R) br = bm;
            else bl = bm;
        }
        ld M = (bl + br) / 2;
        ld L = -1e9;
        for (int i = 0; i < n; i++) {
            ld delta = M - t[i];
            ld ql = x[i] - delta;
            L = max(L, ql);
        }
        ld res = L;
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
//#ifdef DEBUG
    cin >> t;
//#endif
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