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
#ifndef AIM
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
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

//#define int li
//const int mod = 1000000007;

const int BORDER = 18;

int best_ans = (int)1e9;
vector<int> best_vals;
vector<int> cur_vals;

int its = 0;

void rec(int pos, vector<int> need) {
    ++its;
    /*if (its % 1000 == 0) {
        cout<<its << endl;
    }*/
    sort(all(need));
    need.erase(unique(all(need)), need.end());
    if (need.size() == 1 && need[0] == 0) {
        if (best_ans > cur_vals.size()) {
            best_ans = (int) cur_vals.size();
            best_vals = cur_vals;
        }
        return;
    }
    if (pos == BORDER) {
        return;
    }
    if (cur_vals.size() >= best_ans) {
        return;
    }
    vector<int> evens, odds;
    for (int x : need) {
        if (x & 1) {
            odds.push_back(x);
        } else {
            evens.push_back(x / 2);
        }
    }
    if (odds.empty()) {
        return rec(pos + 1, evens);
    }
    int val = (1 << pos);
    {
        cur_vals.push_back(val);
        vector<int> new_need = evens;
        for (int x : odds) {
            new_need.push_back((x - 1) / 2);
        }
        rec(pos + 1, new_need);
        cur_vals.pop_back();
    }
    {
        cur_vals.push_back(-val);
        vector<int> new_need = evens;
        for (int x : odds) {
            new_need.push_back((x + 1) / 2);
        }
        rec(pos + 1, new_need);
        cur_vals.pop_back();
    }
}

void solve(bool read) {
    int n;
    //read = false;
    if (read) {
        cin >> n;
    } else {
        n = 100000;
    }
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int cur;
        if (read) {
            cin >> cur;
        } else {
            cur = rand() % 200000 - 100000;
        }
        a.push_back(cur);
    }
    rec(0, a);

    cout << best_ans << "\n";
    for (int x : best_vals) {
        cout << x << " ";
    }
    cout << "\n";

}