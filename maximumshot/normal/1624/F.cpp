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
        cout << "! " << res << endl;
    }

    bool operator == (const output& o) const {
        return true;
    }
};

struct input {
    int n;
    int cnt = 0;
    int x = 1;

    input() = default;

    void read() {
        cin >> n;
    }

    void print() {
        cout << n << " " << x << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 1001;
        n = rnd() % (MAXN - 3) + 3;
        x = rnd() % (n - 1) + 1;
        cnt = 0;
    }

    void gen_max_test() {

    }

    int ask(int c) {
        assert(1 <= c && c < n);
        cnt++;
        assert(cnt <= 10);
        cout << "+ " << c << endl;
#ifndef DEBUG
        int res;
        cin >> res;
        return res;
#else
        x += c;
        return x / n;
#endif
    }

    output fast() {
        int pw = 1;
        while ((pw << 1) < n) pw <<= 1;
        int cur = 0;
        int sign = 1;
        int swp = 0;
        int last_sign = sign;
        for (; pw >= 1; pw >>= 1) {
            last_sign = sign;
            int c = pw * sign;
            c = (c % n + n) % n;;
            int nxt = ask(c);
            if ((sign == 1 && cur != nxt) || (sign == -1 && cur == nxt)) {
                sign = -sign;
                swp = 1;
            } else {
                swp = 0;
            }
            cur = nxt;
        }
        int res = cur * n;
        if (swp) {
            if (last_sign == +1) {

            } else {
                res += n - 1;
            }
        } else {
            if (last_sign == +1) {
                res += n - 1;
            } else {

            }
        }
#ifdef DEBUG
        assert(res == x);
#endif
        return output{res};
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
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
    int t = 1;
    while (t--)
        test_case();
}

void test() {
    for (int t = 1;;t++) {
        input in;
        in.gen();
        in.print();
        cout.flush();
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

//#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
//#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();
//    max_test();

    return 0;
}