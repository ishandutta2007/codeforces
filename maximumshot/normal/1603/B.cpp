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
    ll n;

    output() = default;

    void print() {
        cout << n << "\n";
    }

    bool operator == (const output& o) const {
        return true;
    }
};

struct input {
    ll x, y;

    input() = default;

    void read() {
        cin >> x >> y;
    }

    void print() {

    }

    void gen() {
        static mt19937 rnd(42);
        const ll MAXX = 10;
        x = rnd() % MAXX + 1;
        y = rnd() % MAXX + 1;
        x *= 2;
        y *= 2;
    }

    output fast() {
        if (x == y) return output{x};
        if (y < x) return {x + y};
        if (y % x == 0) return {x};
        ll n = y - (y % x) / 2;
        assert(n % x == y % n);
        return output{n};
    }

    output slow() {
        return output();
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
    while (1) {
        input in;
        in.gen();
        output fs = in.fast();
        output sl = in.slow();
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA\n";
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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}