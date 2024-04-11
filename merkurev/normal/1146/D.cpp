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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

const int N = (int) 2e5 + 100;
bool used[N];
int n = 0;
int cur;
int a, b;

void dfs(int v)
{
    cur++;
    used[v] = true;
    eprintf("v = %d\n", v);
    if (v + a < n && !used[v + a])
        dfs(v + a);
    if (v - b >= 0 && !used[v - b])
        dfs(v - b);
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int m;
    scanf("%d%d%d", &m, &a, &b);
    m++;

    int rb = min(a + b, m);
    
    long long ans = 0;
    eprintf("rb = %d\n", rb);
    for (int i = 0; i < rb; i++)
    {
        n = i + 1;
        if (i == 0 || (i - a >= 0 && used[i - a]))
            dfs(i);
        eprintf("i = %d, cur = %d\n", i, cur);
        ans += cur;
    }
    eprintf("ans = %lld\n", ans);
    int g = gcd(a, b);
    
    while (rb < m && rb % g != 0)
    {
        ans += cur;
        rb++;
    }
    //eprintf("m = %d, rb = %d, ans = %lld\n", m, rb, ans);
    m -= rb;
    int full = m / g;
    //eprintf("g = %d, m = %d, full = %d\n", g, m, full);
    eprintf("cur = %d\n", cur);
    ans += cur * 1LL * full * 1LL * g;
    ans += full * 1LL * (full + 1) / 2 * 1LL * g;
    cur += full;
    m %= g;
    cur++;
    ans += cur * 1LL * m;
    printf("%lld\n", ans);

	return 0;
}