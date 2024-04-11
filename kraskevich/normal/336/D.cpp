#include <algorithm>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>

using namespace std;

#define PII pair<int, int>
#define PLL pair<long long, long long>
#define PIL pair<int, long long>
#define PLI pair<long long, int>
#define F first
#define S second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define div __dv__
#define hash __hash__
#define prev __prev__
#define left __left__
#define right __right__
#define link __link__
#define next __next__
#define y0 y100500_0
#define y1 y100500_1
#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long ULL;
typedef long double LD;

const int N = 200 * 1000 + 10;
const LL MOD = 1000 * 1000 * 1000 + 7;

LL fact[N];

LL bin_pow(LL b, LL n)
{
    LL res = 1;
    while (n)
    {
        if (n % 2)
            res *= b, res %= MOD;
        b *= b, b %= MOD;
        n /= 2;
    }
    return res;
}

LL cnk(int n, int k)
{
    if (k > n || n < 0 || k < 0)
        return 0;
    LL res = fact[n];
    res *= bin_pow(fact[n - k], MOD - 2);
    res %= MOD;
    res *= bin_pow(fact[k], MOD - 2);
    res %= MOD;
    return res;
}

map<PII, LL> dp;

LL get_dp(int zeroes, int ones, int want)
{
    if (zeroes < 0 || ones < 0)
        return 0;
    if (zeroes + ones == 1)
        return want ? ones : zeroes;
    if (dp.count(PII(zeroes, ones)))
        return dp[PII(zeroes, ones)];
    LL &res = dp[PII(zeroes, ones)];
    if (want == 1)
        res = get_dp(zeroes - 1, ones, 0);
    else
        res = get_dp(zeroes - 1, ones, 1) + cnk(zeroes + ones - 1, ones - 1);
    res %= MOD;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
    #endif


    fact[0] = fact[1] = 1;
    for (LL i = 2; i < N; i++)
        fact[i] = fact[i - 1] * i % MOD;

    int n, m, want;
    cin >> n >> m >> want;
    cout << get_dp(n, m, want);

    return 0;
}