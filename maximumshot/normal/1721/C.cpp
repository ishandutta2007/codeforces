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
    vector<int> mn, mx;

    void print() {
        for (auto x : mn) cout << x << " "; cout << "\n";
        for (auto x : mx) cout << x << " "; cout << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    vector<int> a, b;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        b.resize(n);
        for (auto& x : a) cin >> x;
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
        vector<int> L(n), R(n);
        iota(L.begin(), L.end(), 0);
        R = L;
        for (int i = 0; i < n; i++) {
            int j = i;
            if (i) j = max(j, R[i - 1]);
            while (j + 1 < n && a[j + 1] <= b[j]) j++;
            R[i] = j;
        }
        for (int i = n - 1; i >= 0; i--) {
            int j = i;
            if (i + 1 < n) j = min(j, L[i + 1]);
            while (j > 0 && a[j - 1] <= b[j] && a[i] <= b[j - 1]) j--;
            L[i] = j;
        }
        vector<int> mn(n), mx(n);
        for (int i = 0; i < n; i++) {
            mx[i] = b[R[i]] - a[i];
            mn[i] = max(0, b[L[i]] - a[i]);
        }
        return output{mn, mx};
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