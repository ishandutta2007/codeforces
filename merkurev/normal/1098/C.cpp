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


const int N = (int) 1e5 + 100;
long long cnt[N];
vector <int> vs[N];
int par[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    long long s;
    scanf("%d%lld", &n, &s);

    long long x = n * 1LL * (n + 1) / 2LL;
    if (s > x)
    {
        printf("No\n");
        return 0;
    }
    int k = 1;
    while (k <= n)
    {
        long long rem = n;
        long long cur = 1;
        long long mn = 0;
        int ch = 0;

        while (rem > 0)
        {
            ch++;
            long long cx = min(cur, rem);
            mn += cx * ch;
            rem -= cx;
            cur *= k;
        }

        if (mn <= s)
            break;
        k++;
    }
    if (k > n)
    {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");

    for (int i = 0; i < n; i++)
        cnt[i] = 1;
   
    int ptr = 1;
    for (int i = n - 1; i > 0; i--)
    {
        if (s == x) break;
        if (cnt[ptr] == cnt[ptr - 1] * k)
            ptr++;
        while (x - (i - ptr) < s)
            ptr++;
        x -= (i - ptr);
        cnt[ptr]++;
        cnt[i]--;
    }
    ptr = 0;
    for (int i = 0; i < n; i++)
    {
        if ((int) vs[ptr].size() == cnt[ptr])
            ptr++;
        vs[ptr].push_back(i);
    }
    for (int i = 1; i < n; i++)
        for (int j = 0; j < (int) vs[i].size(); j++)
        {
            par[vs[i][j]] = vs[i - 1][j % (int) vs[i - 1].size()];
        }
    for (int i = 1; i < n; i++)
        printf("%d ", par[i] + 1);


	return 0;
}