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
    int a, b, c, d;
    string s;

    input() = default;

    void read() {
        cin >> a >> b >> c >> d >> s;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        int cnt[2] = {0, 0};
        for (char c : s)
            cnt[c - 'A']++;
        if (a + c + d != cnt[0] || b + c + d != cnt[1])
            return output{0};
        vector<int> ar[2];
        int n = (int) s.size();
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j + 1 < n && s[j] != s[j + 1]) j++;
            int val = j - i + 1;
            ar[s[i] - 'A'].push_back(val);
            i = j;
        }
        int universal = 0;
        int need[2] = {c, d};
        for (int i = 0; i < 2; i++) {
            sort(ar[i].begin(), ar[i].end());
            for (auto& x : ar[i]) {
                if (x % 2) {
                    universal += x / 2;
                    x = 0;
                } else {
                    while (need[i] > 0 && x >= 2) {
                        need[i]--;
                        x -= 2;
                    }
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            for (auto x : ar[i ^ 1]) {
                if (x > 0 && x % 2 == 0) {
                    x--;
                    while (x >= 2 && need[i] > 0) {
                        need[i]--;
                        x -= 2;
                    }
                }
            }
        }
        return output{need[0] + need[1] <= universal};
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

void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}

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