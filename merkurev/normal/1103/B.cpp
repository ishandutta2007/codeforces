#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
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

const int LEN = 105;
char str[LEN];

long long a;

bool ask(long long x, long long y)
{
#ifdef LOCAL
    return x % a >= y % a;
#endif
    printf("? %lld %lld\n", x, y);
    fflush(stdout);
    scanf("%s", str);
    return string(str) == "x";
}

void answer(long long x)
{
#ifdef LOCAL
    eprintf("! %lld vs %lld\n", x, a);
    if (a != x) throw;
#endif
    printf("! %lld\n", x);
    fflush(stdout);
}

void solve()
{
    long long x = 1;
    while (!ask(x, 2 * x))
        x *= 2;
    if (x == 1)
    {
        if (ask(0, 1))
        {
            answer(1);
            return;
        }
        answer(2);
        return;
    }

    long long l = x / 2, r = x;
    while (r - l > 1)
    {
        long long m = (l + r) / 2;
        if (ask(m, 2 * m))
            r = m;
        else
            l = m;
    }
    if (ask(2 * l, 2 * l + 1))
        answer(2 * l + 1);
    else
        answer(2 * l + 2);
}


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int cnt = 1000;
    while (true)
    {
#ifdef LOCAL
        cnt--;
        if (cnt == 0) break;
        a = rand() + 1;
#else
        scanf("%s", str);
        if (string(str) == "end")
            break;
#endif
        solve();
    }

	return 0;
}