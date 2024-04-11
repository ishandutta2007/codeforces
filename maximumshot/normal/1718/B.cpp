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
        cout << (res ? "YES" : "NO") << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

vector<ll> F;

void precalc() {
    F = {1, 1};
    while (F.back() < inf64) {
        ll x = F[(int) F.size() - 2];
        ll y = F[(int) F.size() - 1];
        F.push_back(x + y);
    }
}

struct input {
    int k;
    vector<int> c;

    input() = default;

    void read() {
        cin >> k;
        c.resize(k);
        for (auto& x : c) cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        ll S = 0;
        for (auto x : c) S += x;
        int m = 0;
        ll tmp = 0;
        while (m < (int) F.size() && tmp < S) {
            tmp += F[m];
            m++;
        }
        if (m == (int) F.size() || tmp != S) return output{0};
        int last = -1;
        while (m > 0) {
            m--;
            int cur = -1;
            for (int i = 0; i < k; i++) {
                if (i == last) continue;
                if (cur == -1 || c[cur] < c[i]) cur = i;
            }
            if (cur == -1 || c[cur] < F[m]) return output{0};
            c[cur] -= F[m];
            last = cur;
        }
        return output{1};
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

    precalc();
    work();
//    test();
//    max_test();

    return 0;
}