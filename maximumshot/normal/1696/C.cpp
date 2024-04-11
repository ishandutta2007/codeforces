#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using pil = pair<int, long long>;

const int inf = 1e9;
const ll inf64 = 1e18;

struct output {
    int res;

    void print() {
        cout << (res ? "Yes" : "No") << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

vector<pii> split(vector<int> a, int m) {
    vector<pii> res;
    for (auto x : a) {
        int was = x;
        while (x > 0 && x % m == 0) {
            x /= m;
        }
        res.emplace_back(x, was / x); // {x, cnt}
    }
    return res;
}

vector<pil> compress(vector<pii> a) {
    vector<pil> res;
    int n = (int) a.size();
    for (int i = 0; i < n; i++) {
        int j = i;
        ll sm = 0;
        while (j < n && a[i].first == a[j].first) {
            sm += a[j].second;
            j++;
        }
        res.emplace_back(a[i].first, sm);
        i = j - 1;
    }
    return res;
}

struct input {
    int n, m, k;
    vector<int> a, b;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n);
        for (auto& x : a) cin >> x;
        cin >> k;
        b.resize(k);
        for (auto& x : b) cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        auto sa = compress(split(a, m));
        auto sb = compress(split(b, m));
        int res = sa == sb;
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