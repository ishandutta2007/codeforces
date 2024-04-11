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
    ll res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    vector<int> k, h;

    input() = default;

    void read() {
        cin >> n;
        k.resize(n);
        h.resize(n);
        for (auto& x : k) cin >> x;
        for (auto& x : h) cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<pll> st; // [R, Hr]
        for (int i = 0; i < n; i++) {
            st.emplace_back(k[i], h[i]);
            while ((int) st.size() > 1) {
                auto [r1, h1] = st[(int) st.size() - 2];
                auto [r2, h2] = st[(int) st.size() - 1];
                if (r2 - h2 + 1 > r1) break;
                st.pop_back();
                st.pop_back();
                st.emplace_back(r2, max(h2, h1 + r2 - r1));
            }
        }
        ll res = 0;
        for (auto [r, hr] : st) {
            res += hr * (hr + 1) / 2;
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