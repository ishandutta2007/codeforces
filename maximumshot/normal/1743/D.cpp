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
    string res;

    void print() {
        reverse(res.begin(), res.end());
        while ((int) res.size() > 1 && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    string s;

    input() = default;

    void read() {
        cin >> n >> s;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        int l = 0;
        while (l < n && s[l] == '0') l++;
        if (l == n) return output{s};
        int r = l;
        while (r < n && s[r] == '1') r++;
        if (r == n) return output{s};
        string res = s;
        for (int i = l; i < r; i++) {
            string tmp(n, '0');
            for (int j = r; j < n; j++) {
                tmp[j] = s[j - (r - i)];
            }
            for (int j = 0; j < n; j++)
                tmp[j] = max(tmp[j], s[j]);
            res = max(res, tmp);
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
#ifdef DEBUG
    cin >> t;
#endif
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