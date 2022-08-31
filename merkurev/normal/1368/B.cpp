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




int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    long long k;
    scanf("%lld", &k);

    string s = "codeforces";
    int len = (int) s.length();

    long long x = 1;
    while (true)
    {
        long long cur = 1;
        for (int i = 0; i < len; i++)
            cur = min(k, cur * x);
        if (cur == k)
            break;
        x++;
    }

    if (x == 1)
    {
        printf("%s\n", s.c_str());
        return 0;
    }

    int cnt = 1;
    while (true)
    {
        long long cur = 1;
        for (int i = 0; i < cnt; i++)
            cur = min(k, cur * x);
        for (int i = cnt; i < len; i++)
            cur = min(k, cur * (x - 1));
        if (cur == k)
            break;
        cnt++;
    }
    for (int i = 0; i < len; i++)
    {
        int cur = x;
        if (i >= cnt)
            cur--;
        for (int j = 0; j < cur; j++)
            printf("%c", s[i]);
    }
    printf("\n");


	return 0;
}