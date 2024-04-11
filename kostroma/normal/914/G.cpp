#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
/*#if !defined(YCM) && 0
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
#include <stdio.h>
#endif*/
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
    //freopen("/home/alexandero/ClionProjects/ACM/output.txt", "w", stdout);
    //freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        //cerr << testNum << endl;
        solve(true);
        //cerr << testNum - 1 << endl;
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

template <typename T>
void make_unique(vector<T>& a) {
    sort(all(a));
    a.erase(unique(all(a)), a.end());
}

template<typename T>
void relax_min(T& cur, T val) {
    cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
    cur = max(cur, val);
}

void precalc() {}

#define int li
const int mod = 1000000007;

const int k = 17;
const int C = (1 << 17);

void add(int& cur, int val) {
    cur += val;
    cur %= mod;
}

vector<int> mult(const vector<int>& q, const vector<int>& w) {
    vector<int> res(q.size());
    for (int i = 0; i < res.size(); ++i) {
        res[i] = q[i] * w[i] % mod;
    }
    return res;
}

void norm(vector<int>& q) {
    for (int& x: q) {
        x %= mod;
        if (x < 0) {
            x += mod;
        }
    }
}

vector<int> xor_fft(vector<int> q, bool reversed) {
    for (int b = 0; b < k; ++b) {
        for (int i = 0; i < C; ++i) {
            if (!(i & (1 << b))) {
                int u = q[i], v = q[i + (1 << b)];
                q[i] = (u + v) % mod;
                q[i + (1 << b)] = (u - v) % mod;
            }
        }
    }
    int rev_n = binpow((int)q.size(), mod - 2, mod);
    if (reversed) {
        for (int& x : q) {
            x = x * rev_n % mod;
        }
        norm(q);
    }
    norm(q);
    return q;
}

vector<int> subset_conv(vector<int> a, bool reversed) {
    for (int b = 0; b < k; ++b) {
        for (int i = 0; i < C; ++i) {
            if (!(i & (1 << b))) {
                if (reversed) {
                    a[i + (1 << b)] -= a[i];
                    a[i + (1 << b)] %= mod;
                } else {
                    a[i + (1 << b)] += a[i];
                    a[i + (1 << b)] %= mod;
                }
            }
        }
    }
    norm(a);
    return a;
}

void solve(bool read) {
    vector<int> fib(C, 1);
    fib[0] = 0;
    for (int i = 2; i < fib.size(); ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    }
    vector<int> num(C);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int cur;
        cin >> cur;
        ++num[cur];
    }
    n = C;

    vector<int> common(C, 0);
    for (int mask = 1; mask < n; ++mask) {
        for (int s = mask; ; s = (s - 1) & mask) {
            add(common[mask], num[s] * num[mask ^ s]);
            if (s == 0) {
                break;
            }
        }
    }

    auto cur_xor = xor_fft(num, false);
    auto xorred = xor_fft(mult(cur_xor, cur_xor), true);

    /*for (int i = 0; i < 4; ++i) {
        cout << xorred[i] << " \n"[i + 1 == 4];
    }*/

    for (int i = 0; i < C; ++i) {
        num[i] = num[i] * fib[i] % mod;
        xorred[i] = xorred[i] * fib[i] % mod;
        common[i] = common[i] * fib[i] % mod;
    }
    reverse(all(num));
    reverse(all(xorred));
    reverse(all(common));

    num = subset_conv(num, false);
    xorred = subset_conv(xorred, false);
    common = subset_conv(common, false);

    /*reverse(all(num));
    reverse(all(xorred));
    reverse(all(common));
    for (int i = 0; i < 4; ++i)
    if (i < 4)
        cout << num[i] << " " << xorred[i] << " " << common[i] << endl;
    reverse(all(num));
    reverse(all(xorred));
    reverse(all(common));*/

    auto res = mult(num, mult(xorred, common));

    /*reverse(all(res));
    for (int i = 0; i < 4; ++i) {
        cout << res[i] << " \n"[i == 3];
    }
    reverse(all(res));*/

    res = subset_conv(res, true);
    reverse(all(res));
    int ans = 0;
    for (int b = 0; b < k; ++b) {
        add(ans, res[1 << b]);
    }
    cout << ans << endl;

}