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

    int n, m;
    scanf("%d%d", &n, &m);
    bool good = true;
    
    vector <int> v;
    long long sum = 0;
    for (int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);
        sum += x;
        v.push_back(x);
        if (x + i > n)
            good = false;
    }
    if (!good || sum < n)
    {
        printf("-1\n");
        return 0;
    }

    int lst = n;
    vector <int> ans(m);
    for (int i = m - 1; i >= 0; i--)
    {
        int pos = max(i, lst - v[i]);
        lst = pos;
        ans[i] = pos;
    }

    for (int x : ans)
        printf("%d ", x + 1);
    
    printf("\n");




	return 0;
}