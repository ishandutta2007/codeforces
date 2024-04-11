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
    int can;

    output() = default;

    void print() {
        cout << (can ? "YES" : "NO") << "\n";
    }

    bool operator == (const output& o) const {
        return true;
    }
};

struct input {
    int n;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        for (int i = 1; i <= n && i <= 1000; i++) {
            int fl = 1;
            for (int j = 1; j <= i; j++) {
                if (a[i] % (j + 1)) {
                    fl = 0;
                    break;
                }
            }
            if (fl)
                return output{0};
        }
        return output{1};
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