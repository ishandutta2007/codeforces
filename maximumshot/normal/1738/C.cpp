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

const int N = 1e3 + 5;
int f[N][N][2];

void precalc() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int t = 0; t < 2; t++) {
                if (i == 0 && j == 0) {
                    f[i][j][t] = t == 0;
                    continue;
                }
                if (i > 0) {
                    f[i][j][t] |= f[i - 1][j][t ^ 1 ^ (j % 2)] == 0;
                }
                if (j > 0) {
                    f[i][j][t] |= f[i][j - 1][t ^ ((j - 1) % 2)] == 0;
                }
            }
        }
    }
}

struct output {
    int res;

    void print() {
        cout << (res ? "Alice" : "Bob") << "\n";
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
        for (auto& x : a)
            x = (x % 2 + 2) % 2;
        vector<int> cc(2);
        for (auto x : a)
            cc[x]++;
        int x = cc[0], y = cc[1];
        int res = f[x][y][0];
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
    cin >> t;
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

    precalc();
    work();
//    test();
//    max_test();

    return 0;
}