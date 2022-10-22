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
    vector<int> res;

    void print() {
        for (auto x : res)
            cout << x + 1 << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    vector<int> p;
    string s;

    input() = default;

    void read() {
        cin >> n;
        p.resize(n);
        for (auto& x : p) {
            cin >> x;
            x--;
        }
        cin >> s;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        vector<int> perm(n), pos(n);
        for (int i = 0; i < n; i++) {
            perm[i] = i;
            pos[perm[i]] = i;
        }
        sort(perm.begin(), perm.end(), [&](int i, int j) {
            return s[i] < s[j] || (s[i] == s[j] && p[i] < p[j]);
        });
        for (int i = 0; i < n; i++) {
            pos[perm[i]] = i;
        }
        return output{pos};
    }

    output slow() {
        return output();
    }
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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}