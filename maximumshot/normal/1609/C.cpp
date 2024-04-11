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
    ll res = 0;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

const int MAXX = 1e6 + 5;

int pr[MAXX];

void precalc() {
    fill(pr, pr + MAXX, 1);
    pr[0] = pr[1] = 0;
    for (int p = 2; p * p < MAXX; p++) {
        if (!pr[p])
            continue;
        for (int x = p * p; x < MAXX; x += p)
            pr[x] = 0;
    }
}

struct input {
    int n, e;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n >> e;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        vector<int> L(n + 1), R(n + 1);
        for (int i = 1; i <= n; i++) {
            if (i > e && a[i - e] == 1)
                L[i] = L[i - e] + 1;
        }
        for (int i = n; i >= 1; i--) {
            if (i + e <= n && a[i + e] == 1)
                R[i] = R[i + e] + 1;
        }
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            if (!pr[a[i]])
                continue;
            res += 1ll * (L[i] + 1) * (R[i] + 1) - 1;
        }
        return output{res};
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

    precalc();
    work();
//    test();

    return 0;
}