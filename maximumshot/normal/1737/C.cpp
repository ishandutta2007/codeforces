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

struct input {
    int n;
    pii a[3];
    pii need;

    input() = default;

    void read() {
        cin >> n;
        for (int i = 0; i < 3; i++)
            cin >> a[i].first >> a[i].second;
        cin >> need.first >> need.second;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        int best = -1, best_deg = -inf;
        for (int i = 0; i < 3; i++) {
            int tmp_deg = 0;
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                if (abs(a[i].first - a[j].first) == 0 || abs(a[i].second - a[j].second) == 0) {
                    tmp_deg++;
                }
            }
            if (best == -1 || best_deg < tmp_deg) {
                best = i;
                best_deg = tmp_deg;
            }
        }
        auto [r, c] = a[best];
        auto [R, C] = need;
        int res = 0;
        if ((r == 1 && c == 1) || (r == 1 && c == n) || (r == n && c == 1) || (r == n && c == n)) {
            if (r == R || c == C) res = 1;
        } else {
            r++, c++;
            r = (r % 2 + 2) % 2;
            c = (c % 2 + 2) % 2;
            R %= 2;
            C %= 2;
            res = !(r == R && c == C);
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