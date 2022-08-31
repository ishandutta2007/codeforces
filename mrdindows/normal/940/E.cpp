//
// Created by Andrey Shanin on 1/19/18.
//
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <set>
#include <map>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
#include <unordered_set>
#include <chrono>
#include <zconf.h>
#include <stack>

#define F first
#define S second

using namespace std;
typedef long long ll;
typedef long double ld;

const ll max_n = 100011, mod = 1000000007;
const ll inf = 1000111222;

int n, c, a[max_n];
ll dp[max_n];

int main() {
    cin >> n >> c;
    if (c == 1) {
        cout << 0 << endl;
        return 0;
    }
    for ( int i = 0 ; i < n; ++i) scanf("%d", &a[i]);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    ll sum = a[0];
    for (int i = 1; i < n; ++i) {
        sum += a[i];
        dp[i] = dp[i - 1];
        if (i >= c - 1) {
            int mn = inf;
            auto ap = a + i - c + 1;
            for (int j = 0; j < c; ++j) {
                mn = mn < ap[j] ? mn : ap[j];
            }
            dp[i] = max(dp[i], (i >= c ? dp[i - c] : 0) + mn);
        }
    }
    cout << sum - dp[n - 1] << endl;
    return 0;
}