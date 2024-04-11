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
    int n, k;
    vector<vector<int>> a;

    input() = default;

    void read() {
        cin >> n >> k;
        a.resize(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
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
        vector<vector<int>> f(n, vector<int>(n, -1));
        vector<int> cnt(n);
        map<vector<int>, int> where;
        for (int i = 0; i < n; i++)
            where[a[i]] = i;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<int> need(k);
                for (int q = 0; q < k; q++) {
                    if (a[i][q] == a[j][q]) need[q] = a[i][q];
                    else need[q] = a[i][q] ^ a[j][q] ^ 3;
                }
                auto it = where.find(need);
                if (it != where.end()) {
                    f[i][j] = it->second;
                    cnt[f[i][j]]++;
                }
            }
        }
        ll res = 0;
        for (int i = 0; i < n; i++) {
            res += 1ll * cnt[i] * (cnt[i] - 1) / 2;
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
#ifdef DEBUG
    cin >> t;
#endif
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