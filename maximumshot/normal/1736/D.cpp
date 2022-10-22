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
    vector<int> b, p;

    void print() {
        if (can) {
            cout << (int) b.size() << "\n";
            for (auto x : b)
                cout << x + 1 << " ";
            cout << "\n";
            for (auto x : p)
                cout << x + 1 << " ";
            cout << "\n\n";
        } else {
            cout << "-1\n";
        }
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
        n *= 2;
        a.resize(n);
        string buf;
        cin >> buf;
        for (int i = 0; i < n; i++)
            a[i] = buf[i] - '0';
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        int c0 = 0, c1 = 0;
        for (auto x : a) {
            if (x) c1++;
            else c0++;
        }
        if (c1 % 2) return output{0, {}, {}};
        int cur = 0;
        vector<int> b;
        for (int i = 0; i < n; i += 2) {
            if (a[i] == a[i + 1])
                continue;
            if (a[i] == cur) b.push_back(i);
            else b.push_back(i + 1);
            cur ^= 1;
        }
        vector<int> p;
        for (int i = 0; i < n; i += 2)
            p.push_back(i);
        return output{1, b, p};
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

    work();
//    test();
//    max_test();

    return 0;
}