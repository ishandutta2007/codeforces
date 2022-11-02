#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>
#include <stdlib.h>

using namespace std;



long long dp[1000 * 1000];
long long k;
long long period = 1;

void calcDp() {
    dp[0] = 0;
    for (long long i = 1; i < period; ++i) {
        dp[i] = dp[i - 1] + 1;
        for (long long mod = 2; mod <= k; ++mod) {
            long long prev = i - (i % mod);
            if (prev >= 0)
                dp[i] = min(dp[prev] + 1, dp[i]);
        }
    }
}

long long calcDp2(long long start, long long border) {
    dp[0] = 0;
    for (long long i = 1; i < period; ++i) {
        dp[i] = dp[i - 1] + 1;
        for (long long mod = 2; mod <= k; ++mod) {
            long long prev = i - (i + start) % mod;
            if (prev >= 0)
                dp[i] = min(dp[i], dp[prev] + 1);
        }
    }
    return dp[border - start];
} 

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    
    long long a, b;
    cin >> a >> b >> k;
    
    for (int i = 2; i <= k; ++i)
        period = period * i / gcd(period, i) ;
    //cout << period << endl;
    
    calcDp();
    long long borderB = b - b % period;
    if (borderB < b)
        borderB += period;
    long long borderA = a - a % period;
    long long res;
    if (borderA >= b)
        res = dp[a - borderA];
    else
        res = 0;
    //cout << dp[period - 1] << endl;
    res += max(0ll, (borderA - borderB) / period * (dp[period - 1] + 1));
   // cout << a << " " << borderA << " " << b << " " << borderB << endl;
    if (borderB > a)
        borderB = a;
    res += calcDp2(b, borderB);
    
    cout << res;
    
    return 0;
}