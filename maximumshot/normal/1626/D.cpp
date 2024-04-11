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
        sort(a.begin(), a.end());
        vector<int> b;
        for (int i = 0; i < n; i++) {
            if (i == 0 || a[i] > a[i - 1]) {
                b.push_back(1);
            } else {
                b.back() += 1;
            }
        }
        int sz = (int) b.size();
        for (int i = 1; i < sz; i++)
            b[i] += b[i - 1];
        int res = inf;
        for (int lx = 0; lx < 20; lx++) {
            for (int ly = 0; ly < 20; ly++) {
                {
                    int x = 1 << lx;
                    int y = 1 << ly;
                    int ptr = upper_bound(b.begin(), b.end(), x) - b.begin() - 1;
                    int take_x = ptr < 0 ? 0 : b[ptr];
                    ptr = upper_bound(b.begin(), b.end(), take_x + y) - b.begin() - 1;
                    int take_y = ptr < 0 ? 0 : b[ptr];
                    take_y -= take_x;
                    int take_z = n - take_x - take_y;
                    int z = 1;
                    while (z < take_z) z <<= 1;
                    res = min(res, x - take_x + y - take_y + z - take_z);
                }
            }
        }
        return output{res};
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
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