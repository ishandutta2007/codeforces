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
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    work();
//    test();
//    max_test();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int ub = ((1 << (n + 1)) + 2) / 3;
        auto ask = [&](int u, int v) {
            if (u == v) return 0;
            assert(ub > 0);
            ub--;
            cout << "? " << u + 1 << " " << v + 1 << endl;
            int res;
            cin >> res;
            if (res == 1) res = -1;
            else if (res == 2) res = +1;
            return res;
        };

        function<int(vector<int>)> dfs = [&](vector<int> a) -> int {
            if ((int) a.size() <= 4) {
                int best = a[0];
                for (int v : a) {
                    if (ask(best, v) > 0) best = v;
                }
                return best;
            }
            assert((int) a.size() % 4 == 0);
            vector<int> b;
            for (int i = 0; i < (int) a.size(); i += 4) {
                int x, y, z, w;
                x = a[i];
                y = a[i + 1];
                z = a[i + 2];
                w = a[i + 3];
                int ty = ask(x, z), best = -1;
                if (ty == 0) {
                    if (ask(y, w) > 0) best = w;
                    else best = y;
                } else if (ty < 0) {
                    if (ask(x, w) > 0) best = w;
                    else best = x;
                } else {
                    if (ask(z, y) > 0) best = y;
                    else best = z;
                }
                b.push_back(best);
            }
            return dfs(b);
        };
        vector<int> a(1 << n);
        iota(a.begin(), a.end(), 0);
        int best = dfs(a);
        cout << "! " << best + 1 << endl;
    }

    return 0;
}