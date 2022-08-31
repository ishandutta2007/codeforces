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
int x[N];

int main(int,  char **)
{
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);

    vector <int> v;
    for (int i = 0; i < n - 1; i++)
        v.push_back(x[i + 1] - x[i] - 1);
    sort(v.begin(), v.end());
    
    int ans = n;
    int need = n - k;
    for (int i = 0; i < need; i++)
        ans += v[i];

    printf("%d\n", ans);


	return 0;
}