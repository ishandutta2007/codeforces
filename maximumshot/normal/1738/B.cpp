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
        cout << (res ? "Yes" : "No") << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct input {
    int n, k;
    vector<ll> s;

    input() = default;

    void read() {
        cin >> n >> k;
        s.resize(n);
        for (int i = n - k; i < n; i++)
            cin >> s[i];
    }

    void print() {
        cout << n << " " << k << "\n";
        for (int i = n - k; i < n; i++)
            cout << s[i] << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 8;
        const int MAXX = 4;
        n = rnd() % MAXN + 1;
        k = rnd() % n + 1;
        s.resize(n);
        for (int i = n - k; i < n; i++) {
            s[i] = int(rnd() % (2 * MAXX + 1)) - MAXX;
        }
    }

    void gen_max_test() {

    }

    output fast() {
        if (k == 1) return output{1};
        vector<ll> a(n);
        for (int i = n - k + 1; i < n; i++)
            a[i] = s[i] - s[i - 1];
        for (int i = n - k + 1; i + 1 < n; i++) {
            if (a[i] > a[i + 1])
                return output{0};
        }
        if (n == k && s[0] > a[1]) return output{0};
        if (n > k) {
            ll ub = a[n - k + 1];
            ll S = s[n -  k];
            // x[0] <= x[1] <= ... <= x[n - k] <= ub
            if (__int128(ub) * (n - k + 1) < s[n - k])
                return output{0};
        }
        return output{1};
    }

#ifdef DEBUG
    output slow() {
        vector<ll> a(n);
        int ok = 0;
        auto update = [&]() {
            vector<ll> ss(n);
            for (int i = 0; i < n; i++)
                ss[i] = (i > 0 ? ss[i - 1] : 0) + a[i];
            int tmp = 1;
            for (int i = n - k; i < n; i++) {
                if (ss[i] != s[i]) {
                    tmp = 0;
                    break;
                }
            }
            if (tmp) ok = 1;
        };
        const int X = 10;
        function<void(int)> rec = [&](int i) {
            if (i == n) {
                update();
            } else {
                int lb = i > 0 ? a[i - 1] : -X;
                int ub = X;
                for (a[i] = lb; a[i] <= ub; a[i]++) {
                    rec(i + 1);
                    if (ok) return;
                }
            }
        };
        rec(0);
        return output{ok};
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
    // test();
//    max_test();

    return 0;
}