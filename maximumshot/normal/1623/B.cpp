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
    vector<tuple<int, int, int>> res;

    void print() {
        for (auto [l, r, d] : res)
            cout << l << " " << r << " " << d << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    vector<pii> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& [l, r] : a)
            cin >> l >> r;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        sort(a.begin(), a.end(), [&](pii p1, pii p2) {
            return p1.second - p1.first < p2.second - p2.first;
        });
        vector<int> is(n + 1);
        vector<tuple<int, int, int>> res;
        for (auto [l, r] : a) {
            int d = l;
            while (is[d]) d++;
            is[d] = 1;
            res.emplace_back(l, r, d);
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

    work();
//    test();

    return 0;
}