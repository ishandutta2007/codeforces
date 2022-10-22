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

const int mod = inf + 7;

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
    vector<int> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& x : a) cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[a[i]] = i;
        int l = pos[0], r = pos[0];
        int res = 1;
        vector<int> f(n);
        auto set = [&](int i) {
            for (int cur = i; cur < n; cur |= (cur + 1))
                f[cur]++;
        };
        auto get = [&](int l, int r) -> int {
            int res = 0;
            for (int cur = r; cur >= 0; cur = (cur & (cur + 1)) - 1) res += f[cur];
            for (int cur = l - 1; cur >= 0; cur = (cur & (cur + 1)) - 1) res -= f[cur];
            return res;
        };
        set(pos[0]);
        for (int x = 1; x < n; x++) {
            int i = pos[x];
            if (l <= i && i <= r) {
                int cn = r - l + 1;
//                for (int j = l; j <= r; j++)
//                    cn += f[j];
                cn -= get(l, r);
                res = (1ll * res * cn) % mod;
            } else {
                l = min(l, i);
                r = max(r, i);
            }
//            f[i] = 1;
            set(i);
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