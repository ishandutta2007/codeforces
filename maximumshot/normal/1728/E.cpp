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

int gcd(int a, int b, int& x, int& y) {
    if (!a) {
        x = 0;
        y = 1;
        return b;
    }
    int g, x1, y1;
    g = gcd(b % a, a, x1, y1);
    // (b % a) * x1 + a * y1 = g
    // (b - (b/a)*a) * x1 + a * y1 = g
    // a * (y1 - x1 * (b/a)) + b * x1 = g
    x = y1 - x1 * (b / a);
    y = x1;
    return g;
}

struct input {
    int n, m;
    vector<pii> d, s;

    input() = default;

    void read() {
        cin >> n;
        d.resize(n);
        for (auto& [a, b] : d)
            cin >> a >> b;
        cin >> m;
        s.resize(m);
        for (auto& [x, y] : s)
            cin >> x >> y;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        ll B = 0;
        vector<int> delta;
        for (auto& [a, b] : d) {
            B += b;
            delta.push_back(a - b);
        }
        sort(delta.rbegin(), delta.rend());
        int k = 0;
        while (k < n && delta[k] >= 0) k++;
        vector<ll> pref(n + 1);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + delta[i];
        vector<ll> res;
        for (auto [x, y] : s) {
            ll tmp = -1;

            {
                // 0 <= K <= n / x
                // K * x + T * y = n
                // K * x ~ k
                int g, k0, t0;
                g = gcd(x, y, k0, t0);
                // k0 * x + t0 * y = g
                if (n % g) {
                    res.push_back(-1);
                    continue;
                }
                // k = k0 * (n/g) + z * (y/g)
                // t = t0 * (n/g) - z * (x/g)
                int lk = 0, rk = n / x;
                // lk <= k0 * (n/g) + z * (y/g) <= rk
                // lk - k0 * (n/g) <= z * (y/g) <= rk - k0 * (n/g)
                // (lk - k0 * (n/g))/((y/g)) <= z <= (rk - k0 * (n/g))/((y/g))
                int lz = ceil(ld(lk - ld(k0) * ld(n/g)) / ld(ld(y)/g));
                int rz = floor(ld(rk - k0 * ld(n/g)) / ld(y/g));
                if (lz > rz) {
                    res.push_back(-1);
                    continue;
                }
                vector<int> zs;

                zs.push_back(lz);
                zs.push_back(rz);

                // (k0 * (n/g) + z * (y/g)) * x = k
                // z = (k/x - k0 * (n/g))/(y/g)
                ld z0 = (ld(k)/ld(x) - ld(k0) * ld(n/g))/ld(y/g);
                zs.push_back(int(z0));
                zs.push_back(int(z0) - 1);
                zs.push_back(int(z0) + 1);

                for (int z : zs) {
                    if (z < lz || z > rz) continue;
                    int K = k0 * (n / g) + z * (y / g);
                    tmp = max(tmp, B + pref[K * x]);
                }
            }

//            set<int> ks;
//            for (int K = 0; K * x <= n; K++) {
//                if (n % y == (K * x) % y)
//                    ks.insert(K);
//            }
//            for (int K : ks) {
//                ll hlp = B + pref[K * x];
//                tmp = max(tmp, hlp);
//            }
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
//    cin >> t;
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