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
    vector<int> p;

    void print() {
        for (auto x : p)
            cout << x << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

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
        vector<int> res;
        if (n % 2 == 0) {
            for (int x = n - 2; x >= 1; x--)
                res.push_back(x);
            res.push_back(n - 1);
            res.push_back(n);
        } else {
            if (n == 1) {
                res = {1};
            } else if (n == 3) {
                res = {2, 1, 3};
            } else {
                for (int x = n - 2; x > 3; x--)
                    res.push_back(x);
                res.push_back(1);
                res.push_back(2);
                res.push_back(3);
                res.push_back(n - 1);
                res.push_back(n);
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
    int t = 1;
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