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

const int MAXN = 5e6 + 5;

struct input {
    int n, m;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n >> m;
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
        static mt19937 rnd(42);
        n = 1e5;
        m = 5e5;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % m + 1;
    }

    output fast() {
        int res = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());
        int X = 2 * m + 2;
        vector<int> f(m + 1, X - 1), used(m + 1);
        for (int x : a) used[x] = 1;
        vector<int> cc(X);
        for (int x = 1; x <= m; x++) {
            if (used[x])
                cc[f[x]]++;
        }
        for (int mx = X - 1, mn = m; mn >= 1; mn--) {
            if (used[mn]) cc[f[mn]]--;
            f[mn] = mn;
            if (used[mn]) cc[f[mn]]++;
            for (int z = 1, x = mn; x <= m; x += mn, z++) {
                if (used[x]) cc[f[x]]--;
                f[x] = min(f[x], f[z]);
                if (used[x]) cc[f[x]]++;
            }
            while (!cc[mx]) mx--;
            int tmp = mx - mn;
            res = min(res, tmp);
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