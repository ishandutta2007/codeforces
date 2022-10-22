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
    vector<vector<int>> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n, vector<int>(5));
        for (int i = 0; i < n; i++) for (int j = 0; j < 5; j++) cin >> a[i][j];
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        int best = 0;
        for (int i = 1; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < 5; j++) {
                if (a[i][j] < a[best][j])
                    cnt++;
            }
            if (cnt >= 3) best = i;
        }
        int ok = 1;
        for (int i = 0; i < n; i++) {
            if (i == best) continue;
            int cnt = 0;
            for (int j = 0; j < 5; j++) {
                if (a[best][j] < a[i][j])
                    cnt++;
            }
            ok &= cnt >= 3;
        }
        if (ok) return output{best + 1};
        else return output{-1};
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
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();
//    max_test();

    return 0;
}