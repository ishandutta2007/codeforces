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
    vector<int> res;

    void print() {
        for (auto x : res)
            cout << x << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, q;
    vector<int> a;
    vector<pii> qs;

    input() = default;

    void read() {
        cin >> n >> q;
        a.resize(n);
        for (auto& x : a) cin >> x, x--;
        qs.resize(q);
        for (auto& [i, k] : qs) {
            cin >> i >> k;
            i--;
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<vector<int>> wins(n);
        deque<int> d(n);
        iota(d.begin(), d.end(), 0);
        for (int it = 1; it <= n; it++) {
            int i = d.front(); d.pop_front();
            int j = d.front(); d.pop_front();
            if (a[i] < a[j]) swap(i, j);
            d.push_front(i);
            d.push_back(j);
            wins[i].push_back(it);
        }
        vector<int> res;
        for (auto [i, k] : qs) {
            int tmp = 0;
            tmp += upper_bound(wins[i].begin(), wins[i].end(), k) - wins[i].begin();
            if (i == d.front()) tmp += max(0, k - n);
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
    int t;
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