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

vector<vector<int>> rotate(vector<vector<int>> a) {
    int n = (int) a.size();
    int m = (int) a[0].size();
    vector<vector<int>> res(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[j][n - 1 - i] = a[i][j];
        }
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
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
                a[i][j] = s[j] == '1';
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
        n = (int) a.size();
        m = (int) a[0].size();
        int s = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                s += a[i][j] == 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i + 1 < n && a[i][j] == 0 && a[i + 1][j] == 0) return output{s};
                if (j + 1 < m && a[i][j] == 0 && a[i][j + 1] == 0) return output{s};
            }
        }
        int res = 0;
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j + 1 < m; j++) {
                int c = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
                if (c == 4) {
                    res = max(res, s - 3 + 1);
                } else if (c == 3) {
                    res = max(res, s - 2 + 1);
                } else if (c == 2) {
                    res = max(res, s - 1 + 1);
                }
            }
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