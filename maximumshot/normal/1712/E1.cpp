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
    vector<ll> res;

    void print() {
        for (auto x : res)
            cout << x << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

const int MAXX = 2e5 + 5;

vector<int> d[MAXX], f[MAXX], g[MAXX];

void precalc() {
    for (int x = 1; x < MAXX; x++) {
        for (int y = x; y < MAXX; y += x) {
            d[y].push_back(x);
            if (y % (2 * x)) f[y].push_back(2 * x);
        }
    }
    for (int x = 1; x < MAXX; x++) {
        g[x] = d[x];
        for (auto t : f[x]) g[x].push_back(t);
        sort(g[x].begin(), g[x].end());
    }
#ifdef DEBUG
    cout << "OK" << endl;
#endif
}

int gcd(int x, int y) {
    return !x ? y : gcd(y % x, x);
}

int lcm(int x, int y) {
    return (x / gcd(x, y)) * y;
}

struct input {
    int q;
    vector<pii> a;

    input() = default;

    void read() {
        cin >> q;
        a.resize(q);
        for (auto& [l, r] : a)
            cin >> l >> r;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<ll> res;
        for (auto [l, r] : a) {
            ll tmp = 0;
            for (int k = l + 2; k <= r; k++) {
//                for (int j : d[k]) {
//                    for (int i : d[k]) {
//                        if (l <= i && i < j && j < k) {
//                            tmp++;
//                        }
//                    }
//                }
                {
                    int cnt = d[k].end() - 1 - lower_bound(d[k].begin(), d[k].end(), l);
                    tmp += 1ll * cnt * (cnt - 1) / 2;
                }
                for (int i = 0, j = 0; j < (int) g[k].size() && g[k][j] < k; j++) {
                    while (i < (int) g[k].size() && (g[k][i] < l || g[k][i] <= k - g[k][j])) i++;
                    while (i > 0 && g[k][i - 1] >= l && g[k][i - 1] > k - g[k][j]) i--;
                    tmp += max(0, j - i);
                }
                for (int i = 0, j = 0; j < (int) d[k].size() && d[k][j] < k; j++) {
                    while (i < (int) d[k].size() && (d[k][i] < l || d[k][i] <= k - d[k][j])) i++;
                    while (i > 0 && d[k][i - 1] >= l && d[k][i - 1] > k - d[k][j]) i--;
                    tmp -= max(0, j - i);
                }
//                for (int j : d[k]) {
//                    for (int i : d[k]) {
//                        if (l <= i && i < j && j < k && i + j > k) {
//                            tmp--;
//                        }
//                    }
//                }
            }
            tmp = 1ll * (r - l + 1) * (r - l) * (r - l - 1) / 6 - tmp;
            res.push_back(tmp);
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

    precalc();
    work();
//    test();
//    max_test();

//    const int MAXN = 100;
//    for (int x = 1; x <= MAXN; x++) {
//        for (int y = x + 1; y <= MAXN; y++) {
//            for (int z = y + 1; z <= MAXN; z++) {
//                int L = x * y / __gcd(x, y);
//                L = L * z / __gcd(L, z);
////                if (L == x + y + z) {
////                    cout << x << " " << y << " " << z << "\n";
////                }
//                if (L < x + y + z) {
//                    if (!(z % x == 0 || (x % 2 == 0 && z % (x / 2) == 0)) ||
//                        !(z % y == 0 || (y % 2 == 0 && z % (y / 2) == 0))) {
//                        cout << x << " " << y << " " << z << "\n";
//                    }
//                } else {
//                    int ok = 1;
//                    ok &= (z % x == 0 || (x % 2 == 0 && z % (x / 2) == 0));
//                    ok &= (z % y == 0 || (y % 2 == 0 && z % (y / 2) == 0));
//                    if (y == 2 * x && z == 3 * x) ok = 0;
//                    if (ok) {
//                        cout << x << " " << y << " " << z << ", sm = " <<
//                            x + y + z << ", lcm = " << L << "\n";
//                    }
//                }
//            }
//        }
//    }

    return 0;
}