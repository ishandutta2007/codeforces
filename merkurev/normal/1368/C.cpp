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
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    vector <pair <int, int>> ans;

    ans.emplace_back(0, 0);
    ans.emplace_back(0, 1);
    ans.emplace_back(1, 0);
    ans.emplace_back(1, 1);
    for (int i = 0; i < n; i++)
    {
        ans.emplace_back(i + 1, i + 2);
        ans.emplace_back(i + 2, i + 2);
        ans.emplace_back(i + 2, i + 1);
    }

    printf("%d\n", (int) ans.size());
    for (auto p : ans)
        printf("%d %d\n", p.first, p.second);


	return 0;
}