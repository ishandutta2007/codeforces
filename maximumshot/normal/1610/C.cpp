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
    int n;
    vector<int> a, b;
    vector<vector<int>> as, bs;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n + 1);
        b.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i] >> b[i];
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    bool check(int k) {
//        set<int> Q;
        int last = -1;
        vector<int> in(n + 1);
        for (int cura = n - 1, it = 1; it <= k; it++) {
            // a[i] >= k - it
            // b[i] >= it - 1
            while (cura >= k - it) {
                for (int i : as[cura]) {
                    if (b[i] >= it - 1 && i > last)
                        in[i] = 1;
                }
                cura--;
            }
            if (it > 1) {
                for (int i : bs[it - 2]) {
                    if (i > last)
                        in[i] = 0;
                }
            }
            int i = last + 1;
            while (i <= n && !in[i]) i++;
            if (i > n) return false;
            last = i;
        }
        return true;
    }

    output fast() {
        as.resize(n);
        bs.resize(n);
        for (int i = 1; i <= n; i++) {
            as[a[i]].push_back(i);
            bs[b[i]].push_back(i);
        }
        int bl = 1, br = n + 1, bm;
        while (br - bl > 1) {
            bm = bl + (br - bl) / 2;
            if (check(bm)) bl = bm;
            else br = bm;
        }
        return output{bl};
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