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
    //read = false;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<pair<int, int>> free;
    vector<int> paired(n, -1);
    set<pair<int, int>> all_pairs;
    for (int i = n - 1; i >= 0; --i) {

        /*cout << "consider " << i << endl;
        for (auto item : all_pairs) {
            cout << a[item.second] << " " << a[paired[item.second]] << endl;
        }*/

        int can_update_free = 0, can_update_delete = 0;

        if (!free.empty() && free.rbegin()->first > a[i]) {
            can_update_free = free.rbegin()->first - a[i];
        }
        if (!all_pairs.empty() && all_pairs.rbegin()->first > a[i]) {
            can_update_delete = all_pairs.rbegin()->first - a[i];
        }

        if (can_update_delete == 0 && can_update_free == 0) {
            free.insert({a[i], i});
            continue;
        }

        if (can_update_free >= can_update_delete) {
            auto cur = free.rbegin()->second;
            free.erase(--free.end());
            paired[i] = cur;
            all_pairs.insert({a[i], i});
            continue;
        } else {
            int cur = all_pairs.rbegin()->second;
            all_pairs.erase(--all_pairs.end());
            paired[i] = paired[cur];
            paired[cur] = -1;
            all_pairs.insert({a[i], i});
            free.insert({a[cur], cur});
            continue;
        }
    }

    int ans = 0;
    for (auto item : all_pairs) {
        ans += a[paired[item.second]] - a[item.second];
    }

    cout << ans << endl;

}