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

struct input {
    int n;
    vector<ll> h, a;

    input() = default;

    void read() {
        cin >> n;
        h.resize(n);
        for (auto& x : h)
            cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    bool check(int lb) {
        a.assign(n, 0);
        for (int i = n - 1; i >= 2; i--) {
            ll D = h[i] / 3;
            // a[i] + h[i] - 3 * d >= lb
            // 3 * d <= a[i] + h[i] - lb
            // 0 <= d <= D
            ll rd = a[i] + h[i] - lb;
            if (rd < 0)
                return false;
            rd /= 3;
            rd = min(rd, D);
            a[i] += h[i] - 3 * rd;
            a[i - 1] += rd;
            a[i - 2] += 2 * rd;
        }
        a[0] += h[0];
        a[1] += h[1];
        for (int i = 0; i < n; i++) {
            if (a[i] < lb)
                return false;
        }
        return true;
    }

    output fast() {
        int bl = 0, br = inf + 10, bm;
        while (br - bl > 1) {
            bm = bl + (br - bl) / 2;
            if (check(bm)) bl = bm;
            else br = bm;
        }
        return output{bl};
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