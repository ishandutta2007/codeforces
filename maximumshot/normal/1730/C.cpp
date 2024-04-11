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
        vector<char> st;
        int n = (int) s.size();
        vector<int> mn(n + 1, -1);
        for (int i = n - 1; i >= 0; i--) {
            mn[i] = mn[i + 1];
            if (mn[i] == -1 || s[i] <= s[mn[i]]) mn[i] = i;
        }
        string a, b;
        for (int i = 0; i < n;) {
            int j = mn[i];
            assert(j != -1);
            while (i < j) {
                b.push_back(min('9', char(s[i] + 1)));
                i++;
            }
            a.push_back(s[i]);
            i++;
        }
        sort(b.begin(), b.end());
        string res;
        for (int i = 0, j = 0; i < (int) a.size() || j < (int) b.size();) {
            if (j == (int) b.size() || (i < (int) a.size() && a[i] < b[j])) {
                res.push_back(a[i++]);
            } else {
                res.push_back(b[j++]);
            }
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