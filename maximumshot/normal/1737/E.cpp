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

inline int sum_(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int mul_(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int sub_(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline void inc_(int &x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}

inline void dec_(int &x, int y) {
    if ((x -= y) < 0) {
        x += mod;
    }
}

inline int binpow_(int x, int pw) {
    if (x == 0)
        return 0;
    int res = 1;
    int tmp = x;
    while (pw > 0) {
        if (pw & 1) {
            res = mul_(res, tmp);
        }
        tmp = mul_(tmp, tmp);
        pw >>= 1;
    }
    return res;
}

inline int div_(int a, int b) {
    return mul_(a, binpow_(b, mod - 2));
}

struct output {
    vector<int> res;

    void print() {
        for (auto x : res) {
            cout << x << "\n";
//            string sx = to_string(x);
//            cout << string(5 - sx.size(), ' ') + sx << " ";
        }
//        cout << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;

    input() = default;

    void read() {
        cin >> n;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        int r2 = binpow_(2, mod - 2);
        vector<int> pw_r2(n + 1);
        pw_r2[0] = 1;
        for (int i = 1; i <= n; i++)
            pw_r2[i] = mul_(pw_r2[i - 1], r2);
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++)
            f[i] = pw_r2[(i + 1) / 2];
        f[n] = pw_r2[(n - 1) / 2];
        vector<int> g(n + 1), sm(n + 1);
        for (int i = n; i >= 1; i--) {
            int coef = 1;
            if (2 * i <= n)
                dec_(coef, sm[2 * i]);
//            for (int j = 2 * i; j <= n; j++)
//                dec_(coef, g[j]);
            g[i] = mul_(f[i], coef);
            sm[i] = g[i];
            if (i < n) inc_(sm[i], sm[i + 1]);
        }
        vector<int> res(g.begin() + 1, g.end());
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        vector<int> cnt(n);
        for (int mask = 0; mask < (1 << n); mask++) {
            struct Elem {
                int w = 1;
                int pos = 0;
                int dir = 0;
                int id = -1;
            };
            vector<Elem> ar;
            for (int i = 0; i < n; i++) {
                Elem e;
                e.pos = i + 1;
                e.w = 1;
                e.id = i;
                if ((1 << i) & mask) e.dir = -1;
                else e.dir = +1;
                ar.push_back(e);
            }
            while ((int) ar.size() > 1) {
                for (int i = (int) ar.size() - 1; i >= 0;) {
                    if (i > 0 && ar[i].dir == -1 && ar[i - 1].dir == +1 && ar[i].pos - ar[i - 1].pos <= 2) {
                        Elem ne;
                        ne.w = ar[i].w + ar[i - 1].w;
                        if (ar[i].w >= ar[i - 1].w) {
                            ne.pos = ar[i].pos - 1;
                            ne.dir = -1;
                            ne.id = ar[i].id;
                        } else {
                            ne.pos = ar[i - 1].pos + 1;
                            ne.dir = +1;
                            ne.id = ar[i - 1].id;
                        }
                        ar.erase(ar.begin() + i);
                        ar.erase(ar.begin() + i - 1);
                        ar.insert(ar.begin() + i - 1, ne);
                        i -= 2;
                    } else {
                        ar[i].pos += ar[i].dir;
                        i--;
                    }
                }
                for (auto& e : ar) {
                    if (e.pos == 0) e.dir = +1;
                    if (e.pos == n + 1) e.dir = -1;
                }
            }
            assert((int) ar.size() == 1);
            int win_id = ar.front().id;
            cnt[win_id]++;
//            for (int j = 0; j < n; j++)
//                cout << ((mask >> j) & 1);
//            cout << "\n";
            string s(n, ' ');
            s[win_id] = '*';
//            cout << s << "\n\n";
        }
        int total = binpow_(2, n);
        int denum = binpow_(total, mod - 2);
        vector<int> res(n);
        res = cnt;
//        for (int i = 0; i < n; i++)
//            res[i] = mul_(cnt[i], denum);
        return output{res};
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