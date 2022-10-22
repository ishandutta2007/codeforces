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

int mul(int x, int y) {
    return (1ll * x * y) % mod;
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

vector<int> get_divisors(int n) {
    vector<int> res;
    for (int x = 1; x * x <= n; x++) {
        if (n % x == 0) {
            res.push_back(x);
            res.push_back(n / x);
        }
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}

int gcd(int x, int y) {
    return !x ? y : gcd(y % x, x);
}

ll lcm(int x, int y) {
    return 1ll * (x / gcd(x, y)) * y;
}

struct Ar {
    int st = 0;
    int d = 0;
    int n = 0;

    void read() {
        cin >> st >> d >> n;
    }

    ll get(int i) const {
        return st + 1ll * i * d;
    }
};

struct input {
    Ar B, C;

    input() = default;

    void read() {
        B.read();
        C.read();
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        if (C.d % B.d)
            return output{0};
        if (C.st < B.st)
            return output{0};
        if ((C.st - B.st) % B.d)
            return output{0};
        if (C.get(C.n - 1) > B.get(B.n - 1))
            return output{0};
        if (C.get(-1) < B.get(0))
            return output{-1};
        if (C.get(C.n) > B.get(B.n - 1))
            return output{-1};
        vector<int> das = get_divisors(C.d);
        int res = 0;
        for (int da : das) {
            if (lcm(da, B.d) != C.d)
                continue;
            add(res, mul(C.d / da, C.d / da));
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