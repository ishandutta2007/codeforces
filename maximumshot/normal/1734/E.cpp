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
    vector<vector<int>> res;

    void print() {
        for (auto row : res) {
            for (auto x : row)
                cout << x << " ";
            cout << "\n";
        }
        cout << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    vector<int> b;

    input() = default;

    void read() {
        cin >> n;
        b.resize(n);
        for (auto& x : b)
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
        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = (i * j) % n;
            }
            int x = (b[i] - res[i][i] + n) % n;
            for (int j = 0; j < n; j++) {
                res[i][j] = (res[i][j] + x) % n;
            }
        }
//        for (int r1 = 0; r1 < n; r1++) {
//            for (int r2 = r1 + 1; r2 < n; r2++) {
//                for (int c1 = 0; c1 < n; c1++) {
//                    for (int c2 = c1 + 1; c2 < n; c2++) {
//                        if ((res[r1][c1] + res[r2][c2]) % n == (res[r1][c2] + res[r2][c1]) % n) {
//                            cout << "WA\n";
//                            exit(0);
//                        }
//                    }
//                }
//            }
//        }
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
//#ifdef DEBUG
//    cin >> t;
//#endif
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