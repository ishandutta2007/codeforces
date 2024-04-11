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

    void print() {

    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {

    input() = default;

    void read() {

    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        return output();
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
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> w(m);
    for (int i = 0; i < m; i++) {
        string s(m, '0');
        s[i] = '1';
        cout << "? " << s << endl;
        cin >> w[i];
    }

    vector<int> perm(m);
    iota(perm.begin(), perm.end(), 0);
    sort(perm.begin(), perm.end(), [&](int i, int j) {
        return w[i] < w[j];
    });

    ll res = 0;
    string cur(m, '0');
    for (int i : perm) {
        cur[i] = '1';
        cout << "? " << cur << endl;
        ll nxt;
        cin >> nxt;
        if (nxt == res + w[i]) {
            res = nxt;
        } else {
            cur[i] = '0';
        }
    }

    cout << "! " << res << endl;

    return 0;
}