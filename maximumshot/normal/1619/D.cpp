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
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int m, n;
    vector<vector<int>> p;

    input() = default;

    void read() {
        cin >> m >> n;
        p.resize(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                cin >> p[i][j];
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    bool check(int x) {
        int any2 = 0;
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (p[i][j] >= x)
                    cnt++;
            }
            if (cnt >= 2)
                any2 = 1;
        }
        if (!any2)
            return false;
        for (int j = 0; j < n; j++) {
            int any = 0;
            for (int i = 0; i < m; i++) {
                if (p[i][j] >= x)
                    any = 1;
            }
            if (!any)
                return false;
        }
        return true;
    }

    output fast() {
        if (m <= n - 1) {
            int res = inf + 10;
            for (int j = 0; j < n; j++) {
                int mx = 0;
                for (int i = 0; i < m; i++)
                    mx = max(mx, p[i][j]);
                res = min(res, mx);
            }
            return output{res};
        }
        int bl = 0, br = inf + 10, bm;
        while (br - bl > 1) {
            bm = (bl + br) >> 1;
            if (check(bm)) bl = bm;
            else br = bm;
        }
        return output{bl};
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