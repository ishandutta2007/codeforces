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
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct RangeTree {
    int n = 0; // [0, n)
    vector<int> t;

    RangeTree() = default;

    RangeTree(int nn) {
        n = nn;
        t.resize(2 * n, inf);
    }

    void put(int i, int x) {
        for (i += n, t[i] = x, i >>= 1; i > 0; i >>= 1)
            t[i] = min(t[i << 1], t[i << 1 | 1]);
    }

    int get(int l, int r) {
        int res = inf;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(res, t[l++]);
            if (r & 1) res = min(res, t[--r]);
        }
        return res;
    }
};

struct input {
    int n;
    vector<int> a;
    int x;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
//        vector<int> dp(n + 2, inf);
//        dp[0] = 0;
        RangeTree rt(n + 2);
        rt.put(0, 0);
        for (int last = 0, i = 1; i <= n + 1; i++) {
            int mn = rt.get(last, i - 1);
//            for (int j = last; j < i; j++)
//                mn = min(mn, dp[j]);
//            dp[i] = mn + 1;
            rt.put(i, mn + 1);
            if (i <= n) {
                if (i >= 2 && a[i] + a[i - 1] < 2 * x)
                    last = max(last, i - 1);
                if (i >= 3 && a[i] + a[i - 1] + a[i - 2] < 3 * x)
                    last = max(last, i - 2);
            }
        }
        return output{n - rt.get(n + 1, n + 1) + 1};
    }

    output slow() {
        return output();
    }
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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}