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


const int MOD = (int) 1e9 + 7;

void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}
int add(int a, int b)
{
    sadd(a, b);
    return a;
}
void ssub(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += MOD;
}
int sub(int a, int b)
{
    ssub(a, b);
    return a;
}
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}
int fpow(int x, int n)
{
    if (n == 0)
        return 1;
    int a = fpow(x, n >> 1);
    a = mul(a, a);
    if (n & 1)
        a = mul(a, x);
    return a;
}

const int N = (int) 1e6 + 100;

int fpowX(int x, int n)
{
    if (n == 0)
        return 1;
    long long a = fpowX(x, n >> 1);
    a = min((long long) N, a * a);
    if (n & 1)
        a = min((long long) N, a * x);
    return a;
}

int a[N];

void solve()
{
    int n, p;
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    
    int la = a[n - 1];
    long long diff = 0;
    int ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int ca = a[i];

        diff = min((long long)N, diff * fpowX(p, la - ca));
        ans = mul(ans, fpow(p, la - ca));
        la = ca;
        
        if (diff == 0)
        {
            diff = 1;
            sadd(ans, 1);
        }
        else
        {
            diff--;
            ssub(ans, 1);
        }
    }
    ans = mul(ans, fpow(p, la));
    printf("%d\n", ans);
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