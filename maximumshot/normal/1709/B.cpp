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
    vector<ll> res;

    void print() {
        for (auto x : res)
            cout << x << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, m;
    vector<int> a;
    vector<pii> b;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n);
        for (auto& x : a)
            cin >> x;
        b.resize(m);
        for (auto& [s, t] : b)
            cin >> s >> t, s--, t--;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<ll> L(n), R(n);
        for (int i = 0; i + 1 < n; i++) {
            L[i] = max(0, a[i + 1] - a[i]);
            R[i] = max(0, a[i] - a[i + 1]);
            if (i) {
                L[i] += L[i - 1];
                R[i] += R[i - 1];
            }
        }
        vector<ll> res;
        res.reserve(m);
        for (auto [s, t] : b) {
            ll tmp = 0;
            if (s < t) {
                tmp = R[t - 1] - (s ? R[s - 1] : 0);
            } else {
                tmp = L[s - 1] - (t ? L[t - 1] : 0);
            }
            res.push_back(tmp);
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