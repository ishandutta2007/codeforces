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
    string res;

    void print() {
        cout << res << "\n";
    }

    int cnt() const {
        return count(res.begin(), res.end(), '1');
    }

    bool operator == (const output& o) const {
        return cnt() == o.cnt();
    }
};

struct input {
    int n, q;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n >> q;
        a.resize(n);
        for (auto& x : a)
            cin >> x;
    }

    void print() {
        cout << n << " " << q << "\n";
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 10;
        const int MAXX = 10;
        n = rnd() % MAXN + 1;
        q = rnd() % MAXX + 1;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % MAXX + 1;
    }

    void gen_max_test() {

    }

    output fast() {
        string res(n, '0');
        if (q >= n) {
            res.assign(n, '1');
            return output{res};
        }
        int i = n - 1;
        for (int it = 0; it < q; it++) {
            while (i >= 0 && a[i] <= it) {
                res[i] = '1';
                i--;
            }
            if (i < 0) break;
            res[i] = '1';
            i--;
        }
        while (i >= 0) {
            if (a[i] <= q)
                res[i] = '1';
            i--;
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        string res(n, '0');
        int mx = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            int qq = q;
            for (int i = 0; i < n; i++) {
                if ((1 << i) & mask) {
                    if (qq < a[i]) qq--;
                }
            }
            if (qq >= 0) {
                int cn = __builtin_popcount(mask);
                if (cn > mx) {
                    mx = cn;
                    for (int i = 0; i < n; i++) {
                        if ((1 << i) & mask) res[i] = '1';
                        else res[i] = '0';
                    }
                }
            }
        }
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
        in.print();
        cout.flush();
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