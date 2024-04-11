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
        return res == o.res;
    }
};

struct input {
    string s;

    input() = default;

    void read() {
        cin >> s;
    }

    void print() {
        cout << s << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 10;
        int n = rnd() % MAXN + 1, b;
        while (1) {
            s.clear();
            s.assign(n, '?');
            for (int i = 0; i < n; i++) {
                s[i] = rnd() % 2 ? '(' : ')';
            }
            int ok = 1;
            b = 0;
            for (auto x : s) {
                if (x == '(') b++;
                else b--;
                if (b < 0) ok = 0;
            }
            if (ok) break;
        }
        for (int i = 0; i < b; i++)
            s.push_back(')');
        for (auto& x : s) {
            if (rnd() % 2 == 0)
                x = '?';
        }
    }

    void gen_max_test() {

    }

    output fast() {
        int n = (int) s.size() / 2;
        string A = s, B = s;
        int op = 0, cl = 0;
        for (auto x : s) {
            if (x == '(') op++;
            else if (x == ')') cl++;
        }
        {
            int OP = op, CL = cl;
            for (auto& x : A) {
                if (x == '?') {
                    if (OP < n) {
                        x = '(';
                        OP++;
                    } else {
                        x = ')';
                        CL++;
                    }
                }
            }
        }
        vector<int> free;
        for (int i = 0; i < 2 * n; i++) {
            if (s[i] == '?')
                free.push_back(i);
        }
        if (op == n || cl == n || free.empty()) return output{1};
        auto check = [&](int pos) -> bool {
            string C = s;
            int OP = op;
            for (int i = 0; i < pos; i++)
                C[free[i]] = '(', OP++;
            if (OP > n) return false;
            C[free[pos]] = ')';
            for (auto& x : C) {
                if (x == '?') {
                    if (OP < n) OP++, x = '(';
                    else x = ')';
                }
            }
            if (OP != n) return false;
            int b = 0;
            for (auto x : C) {
                if (x == '(') b++;
                else b--;
                if (b < 0) return false;
            }
            return b == 0;
        };
        int bl = -1, br = min((int) free.size() - 1, n - op), bm;
        while (br - bl > 1) {
            bm = bl + (br - bl) / 2;
            if (check(bm)) br = bm;
            else bl = bm;
        }
        int pos = br;
        for (int i = 0; i < pos; i++)
            B[free[i]] = '(', op++;
        B[free[pos]] = ')', cl++;
        for (auto& x : B) {
            if (x == '?') {
                if (op < n) op++, x = '(';
                else x = ')';
            }
        }
//        cout << A << "\n" << B << "\n";
        return output{A == B};
    }

#ifdef DEBUG
    output slow() {
        int n = (int) s.size();
        int cnt = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            int ok = 1;
            int b = 0;
            for (int i = 0; i < n; i++) {
                if ((1 << i) & mask) {
                    if (s[i] != '?' && s[i] != '(') ok = 0;
                    b++;
                } else {
                    if (s[i] != '?' && s[i] != ')') ok = 0;
                    b--;
                }
                if (b < 0) ok = 0;
            }
            if (b != 0) ok = 0;
            if (ok) cnt++;
            if (cnt >= 2) break;
        }
        return output{cnt == 1};
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