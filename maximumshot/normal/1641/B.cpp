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
    int can;
    vector<pii> ops;
    vector<int> s;

    void print() {
        if (can) {
            cout << (int) ops.size() << "\n";
            for (auto [p, c] : ops)
                cout << p << " " << c << "\n";
            cout << (int) s.size() << "\n";
            for (auto x : s)
                cout << x << " ";
            cout << "\n";
        } else {
            cout << "-1\n";
        }
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
        vector<int> crd = a;
        sort(crd.begin(), crd.end());
        crd.erase(unique(crd.begin(), crd.end()), crd.end());
        for (auto& x : a)
            x = lower_bound(crd.begin(), crd.end(), x) - crd.begin();
        int sz = (int) crd.size();
        {
            vector<int> cnt(sz);
            for (auto x : a)
                cnt[x]++;
            for (int i = 0; i < sz; i++) {
                if (cnt[i] % 2) {
                    return output{0, {}, {}};
                }
            }
        }
        vector<pii> ops;
        auto do_op = [&](int p, int x) {
            ops.emplace_back(p, crd[x]);
            a.insert(a.begin() + p, x);
            a.insert(a.begin() + p, x);
        };
        vector<int> s;
        for (int i = 0; i < (int) a.size();) {
            int j = i + 1;
            while (a[j] != a[i]) j++;
            int len = j - i;
            s.push_back(2 * len);
            for (int it = 0; it < len; it++) {
                if (j + it < (int) a.size() && a[i + it] == a[j + it])
                    continue;
                do_op(j + it, a[i + it]);
            }
            i += 2 * len;
        }
        return output{1, ops, s};
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