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

ll calc(vector<int> a) {
    sort(a.begin(), a.end());
    ll res = 0;
    ll sm = 0;
    ll cn = 0;
    for (auto x : a) {
        res += cn * x - sm;
        cn++;
        sm += x;
    }
    return res;
}

struct input {
    int n, m;
    vector<vector<int>> a;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
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
        int C = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                C = max(C, a[i][j]);
            }
        }
        C++;
        vector<vector<int>> xs(C), ys(C);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int c = a[i][j];
                xs[c].push_back(i);
                ys[c].push_back(j);
            }
        }
        ll res = 0;
        for (int i = 0; i < C; i++) {
            res += calc(xs[i]);
            res += calc(ys[i]);
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