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


long long solve(long long n, long long k)
{
    long long cnt = n / k;
    long long sum = 1 + (n - k + 1);
    return sum * cnt / 2;
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    vector <long long> ans;
    int n;
    scanf("%d", &n);
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i != 0)
            continue;
        ans.push_back(solve(n, i));
        ans.push_back(solve(n, n / i));
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    for (long long x : ans)
        printf("%lld ", x);
    printf("\n");


	return 0;
}