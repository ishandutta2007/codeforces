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

ll SQRT(ll x) {
    ll bl = 0, br = inf + 10, bm;
    while (br - bl > 1) {
        bm = bl + (br - bl) / 2;
        if (bm * bm <= x) bl = bm;
        else br = bm;
    }
    return bl;
}

struct output {
    ll res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

ll calc(ll n) {
    if (n <= 0) return 0;
    ll res = 0;
    for (int x = 1; x <= 3; x++) {
        if (x <= n)
            res++;
    }
    {
        ll bl = 0, br = inf + 10, bm;
        while (br - bl > 1) {
            bm = bl + (br - bl) / 2;
            if (bm * bm <= n) bl = bm;
            else br = bm;
        }
        assert(bl * bl <= n);
        assert((bl + 1) * (bl + 1) > n);
        res += max(0ll, bl - 1);
    }
    {
        ll bl = 0, br = inf + 10, bm;
        while (br - bl > 1) {
            bm = bl + (br - bl) / 2;
            if (bm * bm + bm <= n) bl = bm;
            else br = bm;
        }
        assert(bl * bl + bl <= n);
        assert((bl + 1) * (bl + 1) + (bl + 1) > n);
        res += max(0ll, bl - 1);
    }
    {
        ll bl = 0, br = inf + 10, bm;
        while (br - bl > 1) {
            bm = bl + (br - bl) / 2;
            if (bm * bm + 2 * bm <= n) bl = bm;
            else br = bm;
        }
        assert(bl * bl + 2 * bl <= n);
        assert((bl + 1) * 2 * (bl + 1) + (bl + 1) > n);
        res += max(0ll, bl - 1);
    }
    return res;
}

struct input {
    ll l, r;

    input() = default;

    void read() {
        cin >> l >> r;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        ll res = calc(r) - calc(l - 1);
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

void help() {
    for (int x = 1; x <= 100; x++) {
        int k = SQRT(x);
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    help();
    work();
//    test();
//    max_test();

    return 0;
}