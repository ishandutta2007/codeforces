#ifndef LOCAL
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <random>
#include <ctime>
#include <chrono>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif


typedef long long int int64;
typedef long long int ll;
typedef long long unsigned ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

const int N = (int) 1e5 + 100;
char s[N];
int n;
long long a, b, c;

int cnt[N][2];
int sz = 0;

int del0, del1;

long long solve_0()
{
    //first delete 0
    int x = min(del0, del1);
    if (del0 >= del1)
    {
        int rem0 = del0 - del1;
        int b0 = max(0, cnt[0][0] - 1) + max(0, cnt[sz - 1][0] - 1);
        rem0 -= b0;
        int k = 0;
        vector <int> v;
        for (int i = 1; i < sz - 1; i++)
            v.push_back(max(cnt[i][0] - 1, 0));
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        while (rem0 > 0)
            rem0 -= v[k++];
        int g0 = (int) v.size() - k;
        long long ans = x * 1LL * (a + b) + max(0LL, b - c) * 1LL * g0;
        if (del0 > del1)
            ans += a;
        eprintf("solve0 >=: ans = %lld\n", ans);
        return ans;
    }
    eprintf("sz = %d\n", sz);
    int rem0 = sz - 2;
    if (cnt[0][0])
        rem0++;
    if (cnt[sz - 1][0])
        rem0++;
    eprintf("del1 = %d, x = %d\n", del1, x);
    int rem1 = del1 - x + sz - 1 - 1;
    eprintf("rem0 = %d, rem1 = %d\n", rem0, rem1);
    long long ans = x * 1LL * (a + b) + max(0LL, b - c) * 1LL  * min(rem0, rem1);
    eprintf("solve0: ans = %lld\n", ans);
    return ans;
}

long long solve_1()
{
    //first delete 1
    int x = min(del0, del1 - 1);
    if (x == -1)
        return 0;
    if (del0 >= del1 - 1)
    {
        int rem0 = del0 - del1 + 1;
        int b0 = max(0, cnt[0][0] - 1) + max(0, cnt[sz - 1][0] - 1);
        rem0 -= b0;
        int k = 0;
        vector <int> v;
        for (int i = 1; i < sz - 1; i++)
            v.push_back(max(cnt[i][0] - 1, 0));
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        while (rem0 > 0)
            rem0 -= v[k++];
        int g0 = (int) v.size() - k;
        long long ans = x * 1LL * (a + b) + max(0LL, b - c) * 1LL * g0;
        // if (del1)
            ans += b;
        if (del0 > del1 - 1)
            ans += a;
        eprintf("solveOne >=: ans = %lld\n", ans);
        return ans;
    }
    int rem0 = sz - 2;
    if (cnt[0][0])
        rem0++;
    if (cnt[sz - 1][0])
        rem0++;
    eprintf("del1 = %d, x = %d\n", del1, x);
    int rem1 = del1 - x + sz - 1 - 1;
    eprintf("rem0 = %d, rem1 = %d\n", rem0, rem1);
    
    int y = min(rem1 - 1, rem0);
    long long ans = x * 1LL * (a + b) + max(0LL, b - c) * 1LL * y + b;
    eprintf("solveOne: ans = %lld\n", ans);
    return ans;
}

void solve()
{
    scanf("%d%lld%lld%lld", &n, &a, &b, &c);
    scanf("%s", s);

    sz = 0;
    int ptr = 0;
    while (ptr < n)
    {
        cnt[sz][0] = cnt[sz][1] = 0;
        while (s[ptr] == '0')
        {
            ptr++;
            cnt[sz][0]++;
        }
        while (s[ptr] == '1')
        {
            ptr++;
            cnt[sz][1]++;
        }
        sz++;
    }
    if (cnt[sz - 1][1])
    {
        cnt[sz][0] = cnt[sz][1] = 0;
        sz++;
    }
    if (sz == 1)
    {
        // TODO: simplify
        long long ans = 0;
        if(cnt[0][0] > 1)
            ans += a;
        printf("%lld\n", ans);
        return;
    }
    del0 = 0, del1 = 0;
    for (int i = 0; i < sz; i++)
    {
        del0 += max(0, cnt[i][0] - 1);
        del1 += max(0, cnt[i][1] - 1);
    }

    long long ans = max(solve_0(), solve_1());
    printf("%lld\n", ans);
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve();

	return 0;
}