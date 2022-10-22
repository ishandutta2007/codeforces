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
        return res == o.res;
    }
};

int lis(vector<int> a) {
    int n = (int) a.size();
    int res = 0;
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    return res;
}

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
        cout << n << "\n";
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int N = 8;
        n = rnd() % N + 1;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % N;
    }

    void gen_max_test() {

    }

    output fast() {
        sort(a.begin(), a.end());
        vector<int> crd = a;
        crd.erase(unique(crd.begin(), crd.end()), crd.end());
        for (auto& x : a)
            x = lower_bound(crd.begin(), crd.end(), x) - crd.begin();
        vector<int> cnt(n);
        for (auto x : a)
            cnt[x]++;
        int c1 = 0, c2 = 0;
        for (int x = 0; x < n; x++) {
            if (cnt[x] > 0) {
                c1++;
                cnt[x]--;
            }
        }
        for (int x = 0; x < n; x++) {
            if (cnt[x] > 0) {
                c2++;
                cnt[x]--;
            }
        }
        if (c2 == 0) {
            return output{(c1 + 1) / 2};
        }
        while (c1 > c2 + 1) {
            c1--;
            c2++;
        }
        if (c1 == c2) return output{c1};
        else return output{min(c1, c2) + 1};
    }

#ifdef DEBUG
    output slow() {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        int res = 0;
        do {
            vector<int> aa = a;
            for (int i = 0; i < n; i++)
                aa[i] = a[p[i]];
            int x = lis(aa);
            reverse(aa.begin(), aa.end());
            int y = lis(aa);
            res = max(res, min(x, y));
        } while (next_permutation(p.begin(), p.end()));
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