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

const int mod = inf + 7;

void add(int& x, int y) {
    if ((x += y) >= mod)
        x -= mod;
}

struct output {
    int res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

const int MAXN = 4e4 + 5;

int dp[MAXN];

bool is_pal(int x) {
    string a = to_string(x);
    string b = a;
    reverse(b.begin(), b.end());
    int y = atoi(b.c_str());
    return x == y;
}

void precalc() {
    dp[0] = 1;
    for (int x = 1; x < MAXN; x++) {
        if (is_pal(x)) {
            for (int y = x; y < MAXN; y++)
                add(dp[y], dp[y - x]);
        }
    }
}

struct input {
    int n;

    input() = default;

    void read() {
        cin >> n;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        return output{dp[n]};
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

    precalc();
    work();
//    test();
//    max_test();

    return 0;
}