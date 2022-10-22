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
    vector<int> res;

    void print() {
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

vector<int> subset_conv(vector<int> a) {
    int n = (int) a.size();
    vector<int> f = a;
    for (int j = 1; j < n; j <<= 1) {
        for (int i = 0; i < n; i++) {
            if (i & j) f[i] ^= f[i ^ j];
        }
    }
    return f;
}

vector<int> calc_g(vector<int> a) {
    cout << "a = "; for (auto x : a) cout << x << " "; cout << "\n";
    int n = (int) a.size() - 1;
    int sz = 1;
    while (sz <= n + 1) sz <<= 1;
    vector<int> g(n);
    reverse(a.begin(), a.end());
    cout << "a = "; for (auto x : a) cout << x << " "; cout << "\n";
    a.resize(sz);
    cout << "a = "; for (auto x : a) cout << x << " "; cout << "\n";
    g.resize(sz);
    vector<int> A = subset_conv(a);
    cout << "A = "; for (auto x : A) cout << x << " "; cout << "\n";
    for (int i = 0; i < sz; i++) {
        g[i] = A[(sz - 1) ^ i];
    }
    cout << "g = "; for (auto x : g) cout << x << " "; cout << "\n";
    g.insert(g.begin(), 0);
    cout << "g = "; for (auto x : g) cout << x << " "; cout << "\n";
    g.resize(n + 1);
    cout << "g = "; for (auto x : g) cout << x << " "; cout << "\n";
    return g;
}

struct input {
    int n;
    vector<int> g;

    input() = default;

    void read() {
        cin >> n;
        g.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> g[i];
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        int sz = 1;
        while (sz < n) sz <<= 1;
        g.resize(sz + 1);
        g.erase(g.begin());
        vector<int> b = subset_conv(g);
        for (int i = n; i < sz; i++) b[i] = 0;
        reverse(b.begin(), b.end());
        b = subset_conv(b);
        reverse(b.begin(), b.end());
        reverse(b.begin(), b.begin() + n);
        vector<int> a(b.begin(), b.begin() + n);
        return output{a};
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