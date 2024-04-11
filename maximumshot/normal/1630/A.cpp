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
    vector<pii> res;

    void print() {
        if (res.empty()) {
            cout << "-1\n";
        } else {
            for (auto [x, y] : res)
                cout << x << " " << y << "\n";
        }
    }

    bool operator == (const output& o) const {
        return res.empty() == o.res.empty();
    }
};

struct input {
    int n, k;

    input() = default;

    void read() {
        cin >> n >> k;
    }

    void print() {

    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 5;
//        n = rnd() % MAXN + 2;
//        n = 1 << n;
        n = 8;
        k = rnd() % n;
    }

    void gen_max_test() {

    }

    output fast() {
        vector<pii> res;
        if (k == n - 1) {
            if (n == 4)
                return output{{}};
            set<int> used;
            res.emplace_back(n - 2, n - 1);
            res.emplace_back(0, 1);
            res.emplace_back(3, n - 3);
            res.emplace_back(2, n - 4);
            for (auto [x, y] : res)
                used.insert(x), used.insert(y);
            for (int i = 0; i < n; i++) {
                int j = i ^ (n - 1);
                if (i < j && !used.count(i) && !used.count(j))
                    res.emplace_back(i, j);
            }
        } else {
            for (int i = 0; i < n; i++) {
                int j = i ^ (n - 1);
                if (i < j)
                    res.emplace_back(i, j);
            }
            if (k > 0) {
                pii x = {min(k, (n - 1) ^ k), max(k, (n - 1) ^ k)};
                pii y = {0, n - 1};
                int px = -1, py = -1;
                for (int i = 0; i < (int) res.size(); i++) {
                    if (res[i] == x) px = i;
                    if (res[i] == y) py = i;
                }
                if (px > py) swap(px, py);
                res.erase(res.begin() + py);
                res.erase(res.begin() + px);
                res.emplace_back(k, n - 1);
                res.emplace_back(0, (n - 1) ^ k);
            }
        }
        int value = 0;
        for (auto[x, y]: res)
            value += x & y;
        assert(value == k);
        assert((int) res.size() == n / 2);
        return output{res};
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
        vector<int> a(n);
        iota(a.begin(), a.end(), 0);
        do {
            int val = 0;
            for (int i = 0; i < n; i += 2)
                val += a[i] & a[i + 1];
            if (val == k) {
                vector<pii> res;
                for (int i = 0; i < n; i += 2)
                    res.emplace_back(a[i], a[i + 1]);
                return output{res};
            }
        } while (next_permutation(a.begin(), a.end()));
        return output{{}};
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