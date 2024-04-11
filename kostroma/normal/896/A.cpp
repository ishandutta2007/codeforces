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
//const int mod = 1000000007;

void solve(bool read) {
    string first = "What are you doing at the end of the world? Are you busy? Will you save us?";
    string cur = "What are you doing while sending \"S\"? Are you busy? Will you send \"S\"?";
    const int INF = (int)2e18;
    vector<int> len(2 * 100000);
    len[0] = (int)first.length();
    for (int i = 1; i < len.size(); ++i) {
        len[i] = (int)cur.length() - 2 + 2 * len[i - 1];
        len[i] = min(len[i], INF);
        /*if (i < 10)
        cout << i << " " << len[i] << " " << cur.length() << endl;*/
    }
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        while (true) {
            if (k > len[n]) {
                cout << ".";
                break;
            }
            if (n == 0) {
                cout << first[k - 1];
                break;
            }
            if (k <= 34) {
                cout << cur[k - 1];
                break;
            }
            if (k <= 34 + len[n - 1]) {
                k -= 34;
                --n;
                continue;
            }
            if (k <= 34 + len[n - 1] + 32) {
                cout << cur[k - len[n - 1]];
                break;
            }
            if (k == len[n]) {
                cout << "?";
                break;
            }
            if (k == len[n] - 1) {
                cout << "\"";
                break;
            }
            k -= 34 + 32 + len[n - 1];
            --n;
        }
    }
    cout << endl;

    //What are you doing while sending "What are you doing at the end of the world? Are you busy? Will you save us?"? Are you busy? Will you send "What are you doing at the end of the world? Are you busy? Will you save us?"?

}