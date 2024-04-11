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

const int INF = 1e9;

const int N = (int) 5e5 + 100;
char str[N];

int readStr()
{
    scanf("%s", str);
    int n = strlen(str);
    int bal = 0, minBal = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
            bal++;
        else
            bal--;
        minBal = min(minBal, bal);
    }
    if (minBal < min(bal, 0))
        return -INF;
    return bal;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    map <int, int> m;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x = readStr();
        if (x != -INF)
            m[x]++;
    }

    int ans = 0;
    for (auto p : m)
    {
        int x = p.first;
        int val = p.second;
        if (x == 0)
        {
            ans += val / 2;
        }
        else if (x > 0)
        {
            ans += min(val, m[-x]);
        }
        else continue;
    }

    printf("%d\n", ans);

	return 0;
}