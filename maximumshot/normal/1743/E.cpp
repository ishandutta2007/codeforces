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
    ll res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int p1, p2;
    ll t1, t2;
    int h, s;

    input() = default;

    void read() {
        cin >> p1 >> t1 >> p2 >> t2;
        cin >> h >> s;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<ll> dp(h + 1, inf64);
        dp[0] = 0;
        for (int i = 0; i < h; i++) {
            for (int iter = 0; iter < 2; iter++) {
                for (int c1 = 1; c1 <= h; c1++) {
                    ll T = 1ll * c1 * t1;
                    ll c2 = (T / t2);
                    __int128 dmg = __int128(c1) * (p1 - s) + __int128(c2) * (p2 - s);
                    __int128 J = min(__int128(h), i + dmg);
                    int j = int(J);
                    dp[j] = min(dp[j], dp[i] + T);
                }

                for (int c1 = 1; c1 <= h; c1++) {
                    ll T = 1ll * c1 * t1;
                    ll c2 = (T / t2);
                    __int128 dmg = __int128(c1) * (p1 - s) + __int128(c2) * (p2 - s);
                    dmg += p1 + p2 - s;
                    ll T1 = T + t1;
                    ll T2 = T + t2 - T % t2;
                    __int128 J = min(__int128(h), i + dmg);
                    int j = int(J);
                    dp[j] = min(dp[j], dp[i] + max(T1, T2));
                }

                swap(p1, p2);
                swap(t1, t2);
            }
            {
                int j = min(h, i + p1 + p2 - s);
                dp[j] = min(dp[j], dp[i] + max(t1, t2));
            }
        }
        ll res = dp[h];
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
#ifdef DEBUG
    cin >> t;
#endif
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