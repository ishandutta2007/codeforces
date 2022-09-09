#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

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
        //cerr << testNum << endl;
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
        ++testNumber;
        //++timer;
    }

    /*while (true) {
        solve(false);
    }*/

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

void precalc() {

}

//#define int li

int TIMER = 1;
int dp[1000500];
int tin[1000500];

void solve(bool read) {
    int n, k;
    cin >> n >> k;
    /*n = 1000000;
    k = rand() % n + 1;*/
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        //p[i] = i + 1;
        --p[i];
    }
    //random_shuffle(p.begin(), p.end());
    vector<int> sizes;
    vector<char> used(n, false);
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            continue;
        }
        int cur = i;
        int cnt = 0;
        while (!used[cur]) {
            used[cur] = true;
            ++cnt;
            cur = p[cur];
        }
        sizes.push_back(cnt);
    }

    int max_not = 0;
    int odd = 0;
    int have = k;
    for (int x : sizes) {
        int add = min(x / 2, have);
        have -= add;
        max_not += 2 * add;
        if (x % 2 == 1) {
            ++odd;
        }
    }
    if (have > 0) {
        max_not += min(have, odd);
    }

    sort(all(sizes));
    vector<pair<int, int>> cycles;
    for (int i = 0; i < sizes.size(); ) {
        int j = i;
        while (j < sizes.size() && sizes[j] == sizes[i]) {
            ++j;
        }
        cycles.push_back({sizes[i], j - i});
        i = j;
    }
    sort(all(cycles), [&](const pair<int, int>& q, const pair<int, int>& w) {
       return q.first * q.second < w.first * w.second;
    });

    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    int sum = 0;
    for (auto item : cycles) {
        ++TIMER;
        int x = item.first;
        int cnt = item.second;
        sum += x * cnt;
        for (int cur = 0; cur <= sum; ++cur) {
            if (dp[cur] == -1) {
                continue;
            }
            if (tin[cur] != TIMER) {
                dp[cur] = 0;
            }
            if (cur + x <= n && dp[cur] < cnt && dp[cur + x] == -1) {
                dp[cur + x] = dp[cur] + 1;
                tin[cur + x] = TIMER;
            }
        }
    }
    int min_not = k + 1;
    if (dp[k] != -1) {
        min_not = k;
    }

    cout << min_not << " " << max_not << "\n";

}