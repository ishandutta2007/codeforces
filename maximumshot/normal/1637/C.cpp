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
        return res == o.res;
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
        cout << n << "\n";
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 6;
        const int MAXX = 6;
        n = rnd() % (MAXN - 2) + 3;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % MAXX + 1;
    }

    void gen_max_test() {

    }

    output fast() {
        vector<ll> pr(n);
        for (int i = 0; i < n; i++) {
            pr[i] = (i > 0 ? pr[i - 1] : 0) + a[i];
        }
        if (n == 3) {
            if (a[1] % 2)
                return output{-1};
            return output{a[1] / 2};
        }
        ll res = 0;
        ll mx = 0;
        for (int i = 1; i + 1 < n; i++) {
            res += a[i];
            if (a[i] % 2)
                res++;
            mx = max(mx, 0ll + a[i]);
        }
        if (mx == 1)
            return output{-1};
        res /= 2;
        return output{res};
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
        set<vector<int>> used;
        used.insert(a);
        queue<pair<vector<int>, int>> q;
        q.push({a, 0});
        while (!q.empty()) {
            auto [v, d] = q.front();
            q.pop();
            if (*max_element(v.begin() + 1, v.end() - 1) == 0)
                return output{d};
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {
                        if (v[j] >= 2) {
                            auto to = v;
                            to[j] -= 2;
                            to[i]++;
                            to[k]++;
                            if (!used.count(to)) {
                                used.insert(to);
                                q.push({to, d + 1});
                            }
                        }
                    }
                }
            }
        }
        return output{-1};
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