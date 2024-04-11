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
    int res = 0;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

const int MAXX = 2e5 + 5;
const int LOG = 20;

int cnt[LOG][MAXX];

void precalc() {
    for (int j = 0; j < LOG; j++) {
        for (int x = 0; x < MAXX; x++) {
            if (x > 0) cnt[j][x] = cnt[j][x - 1];
            if (!((1 << j) & x))
                cnt[j][x]++;
        }
    }
}

struct input {
    int l, r;

    input() = default;

    void read() {
        cin >> l >> r;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        int res = inf;
        for (int j = 0; j < 20; j++) {
            int cc = cnt[j][r] - cnt[j][l - 1];
            res = min(res, cc);
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