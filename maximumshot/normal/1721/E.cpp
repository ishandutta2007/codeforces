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
    vector<vector<int>> res;

    void print() {
        for (auto row : res) {
            for (auto x : row)
               cout << x << " ";
            cout << "\n";
        }
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    string s;
    int q;
    vector<string> qs;

    input() = default;

    void read() {
        cin >> s >> q;
        qs.resize(q);
        for (auto& t : qs)
            cin >> t;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<vector<int>> res;
        res.reserve(q);
        int n = (int) s.size();
        vector<int> p(n + 10);
        for (int j, i = 1; i < n; i++) {
            j = p[i - 1];
            while (j > 0 && s[i] != s[j]) j = p[j - 1];
            if (s[i] == s[j]) j++;
            p[i] = j;
        }
        for (int i = 0; i < 10; i++)
            s.push_back('?');
        vector<vector<int>> f(26, vector<int>(n));
        for (int x = 0; x < 26; x++) {
            for (int j = 1; j < n; j++) {
                f[x][j] = j;
                if (j > 0 && x != s[j] - 'a')
                    f[x][j] = f[x][p[j - 1]];
            }
        }
        for (auto t : qs) {
            int m = (int) t.size();
            for (int j = 0; j < m; j++)
                s[n + j] = t[j];
            for (int j, i = n; i < n + m; i++) {
                j = p[i - 1];
                while (j > 0 && s[i] != s[j]) {
                    if (j >= n) j = p[j - 1];
                    else j = f[s[i] - 'a'][j];
                }
                if (s[i] == s[j]) j++;
                p[i] = j;
            }
            res.push_back(vector<int>(p.begin() + n, p.begin() + n + m));
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