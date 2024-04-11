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

const string ALICE = "Alice";
const string BOB = "Bob";
const string DRAW = "Draw";

struct output {
    string res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    string s;

    input() = default;

    void read() {
        cin >> s;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        int n = (int) s.size();
        vector<vector<int>> dp(n, vector<int>(n, -2));
        for (int l = n - 1; l >= 0; l--) {
            for (int r = l + 1; r < n; r += 2) {
                if (l + 1 == r) {
                    if (s[l] == s[r]) dp[l][r] = 0; // draw
                    else dp[l][r] = +1; // win
                } else {
                    int le = -2, ri = -2, tmp;
                    char x, y;
                    { // left
                        le = inf;
                        tmp = inf;
                        // left
                        x = s[l];
                        y = s[l + 1];
                        if (dp[l + 2][r]) tmp = 1;
                        else tmp = x < y ? +1 : x > y ? -1 : 0;
                        le = min(le, tmp);

                        // right
                        x = s[l];
                        y = s[r];
                        tmp = inf;
                        if (dp[l + 1][r - 1]) tmp = 1;
                        else tmp = x < y ? +1 : x > y ? -1 : 0;
                        le = min(le, tmp);
                    }
                    { // right
                        ri = inf;

                        // left
                        tmp = inf;
                        x = s[r];
                        y = s[l];
                        if (dp[l + 1][r - 1]) tmp = 1;
                        else tmp = x < y ? +1 : x > y ? -1 : 0;
                        ri = min(ri, tmp);

                        // right
                        tmp = inf;
                        x = s[r];
                        y = s[r - 1];
                        if (dp[l][r - 2]) tmp = 1;
                        else tmp = x < y ? +1 : x > y ? -1 : 0;
                        ri = min(ri, tmp);
                    }
                    dp[l][r] = max(le, ri);
                }
            }
        }
        int x = dp[0][n - 1];
        string res;
        if (x > 0) res = ALICE;
        else if (x < 0) res = BOB;
        else res = DRAW;
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        function<int(string)> rec = [&](string t) -> int {
            if (t.empty()) return 0;
            int l = (int) t.size();
            assert(l % 2 == 0);
            return max({
                min(rec(t.substr(1, l - 2)), rec(t.substr(2, l - 2))),
                min(rec(t.substr(0, l - 2)), rec(t.substr(1, l - 2)))
            });
        };
        int x = rec(s);
        string res;
        if (x > 0) res = ALICE;
        else if (x < 0) res = BOB;
        else res = DRAW;
        return output{res};
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