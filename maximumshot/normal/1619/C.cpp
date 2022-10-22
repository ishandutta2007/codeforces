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
    ll a, s;

    input() = default;

    void read() {
        cin >> a >> s;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        string x = to_string(a);
        string y = to_string(s);
        int n = (int) x.size(), m = (int) y.size(), i, j;
        string z;
        for (i = n - 1, j = m - 1; i >= 0; i--) {
            if (j < 0)
                return output{-1};
            if (x[i] <= y[j]) {
                z.push_back(y[j] - x[i] + '0');
                j--;
            } else {
                if (j == 0)
                    return output{-1};
                int val = (y[j - 1] - '0') * 10 + y[j] - '0';
                val -= (x[i] - '0');
                if (val < 0 || val >= 10)
                    return output{-1};
                z.push_back(val + '0');
                j -= 2;
            }
        }
        while (j >= 0) z.push_back(y[j--]);
        reverse(z.begin(), z.end());
        ll res = 0;
        for (char c : z)
            res = res * 10 + c - '0';
        return output{res};
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