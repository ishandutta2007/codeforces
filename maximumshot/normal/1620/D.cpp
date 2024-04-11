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

    bool check(int c1, int c2, int c3) {
        if (c1 < 0 || c2 < 0 || c3 < 0)
            return false;
        for (auto x : a) {
            int can = 0;
            for (int t1 = 0; t1 <= c1; t1++) {
                for (int t2 = 0; t2 <= c2; t2++) {
                    int rem = x - 1 * t1 - 2 * t2;
                    if (rem >= 0 && rem % 3 == 0 && rem / 3 <= c3)
                        can = 1;
                }
            }
            if (!can)
                return false;
        }
        return true;
    }

    output fast() {
        int mx = *max_element(a.begin(), a.end());
        int c3 = mx / 3;
        vector<int> md(3);
        for (auto x : a)
            md[x % 3] = 1;
        if (md[1] == 0 && md[2] == 0)
            return output{c3};
        if (md[1] == 0 || md[2] == 0)
            return output{c3 + 1};
        if (check(1, 1, c3 - 1) || check(0, 2, c3 - 1) || check(2, 0, c3 - 1))
            return output{c3 + 1};
        return output{c3 + 2};
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