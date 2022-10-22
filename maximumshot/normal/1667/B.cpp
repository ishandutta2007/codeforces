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
    vector<ll> crd;
    vector<int> t;

    RangeTree() = default;

    RangeTree(vector<ll> a) {
        crd = a;
        sort(crd.begin(), crd.end());
        crd.erase(unique(crd.begin(), crd.end()), crd.end());
        n = (int) crd.size();
        t.assign(2 * n, -inf);
    }

    void update(ll key, int val) {
        int pos = lower_bound(crd.begin(), crd.end(), key) - crd.begin();
        for (pos += n, t[pos] = max(t[pos], val), pos >>= 1; pos > 0; pos >>= 1)
            t[pos] = max(t[pos << 1], t[pos << 1 | 1]);
    }

    int get(ll lx, ll rx) {
        int l = lower_bound(crd.begin(), crd.end(), lx) - crd.begin();
        int r = upper_bound(crd.begin(), crd.end(), rx) - crd.begin() - 1;
        if (l > r)
            return -inf;
        int res = -inf;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, t[l++]);
            if (r & 1) res = max(res, t[--r]);
        }
        return res;
    }
};

struct input {
    int n;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    static int f(ll x) {
        return x > 0 ? +1 : x < 0 ? -1 : 0;
    }

    output fast() {
        vector<ll> A(n + 1);
        for (int i = 1; i <= n; i++)
            A[i] = A[i - 1] + a[i];
        vector<int> dp(n + 1, -inf);
        dp[0] = 0;
        RangeTree rt1(A), rt2(A), rt3(A);
        for (int i = 0; i <= n; i++) {
            if (i > 0) {
                dp[i] = max(dp[i], rt1.get(A[i], A[i]));
                dp[i] = max(dp[i], rt2.get(-inf64, A[i] - 1) + i);
                dp[i] = max(dp[i], rt3.get(A[i] + 1, inf64) - i);
            } else {
                dp[i] = 0;
            }

            rt1.update(A[i], dp[i]);
            rt2.update(A[i], dp[i] - i);
            rt3.update(A[i], dp[i] + i);

//            for (int j = 0; j < i; j++) {
//                if (A[i] == A[j]) {
//                    dp[i] = max(dp[i], dp[j]);
//                } else if (A[i] > A[j]) {
//                    dp[i] = max(dp[i], dp[j] + i - j);
//                } else {
//                    dp[i] = max(dp[i], dp[j] + j - i);
//                }
//            }
        }
        return output{dp[n]};
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