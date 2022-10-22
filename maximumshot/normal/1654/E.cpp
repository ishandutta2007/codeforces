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

struct input {
    int n;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& x : a)
            cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        if (n <= 2)
            return output{0};
        int X = *max_element(a.begin(), a.end()) + 1;
        X = max(X, n + 1);
        int sq = sqrt(X) + 2;
        int res = 2;
        vector<ll> ar(n);
        for (int k = -sq; k <= sq; k++) {
            for (int i = 0; i < n; i++)
                ar[i] = a[i] - 1ll * i * k;
            sort(ar.begin(), ar.end());
            for (int i = 0; i < n; i++) {
                int j = i;
                while (j < n && ar[i] == ar[j]) j++;
                j--;
                res = max(res, j - i + 1);
                i = j;
            }
        }
        vector<unordered_map<ll, int>> dp(n);
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0 && i - j <= sq; j--) {
                int k = a[i] - a[j];
                if (k % (i - j))
                    continue;
                k /= i - j;
                int val = max({dp[i][k], dp[j][k] + 1});
                dp[i][k] = val;
                res = max(res, val + 1);
            }
        }
        return output{n - res};
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