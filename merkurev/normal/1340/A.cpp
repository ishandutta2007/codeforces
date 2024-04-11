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

const int N = (int) 1e5 + 100;
int a[N];
int ra[N];

void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        a[i]--;
    }
    for (int i = 0; i < n; i++)
        ra[a[i]] = i;

    set <int> s;
    multiset <int> diffs;
    s.insert(-1);
    for (int i = 0; i < n; i++)
    {
        s.insert(i);
        diffs.insert(1);
    }

    for (int i = 0; i < n; i++)
    {
        int x = ra[i];
        auto it = s.find(x);
        auto pit = it;
        pit--;
        int cd = x - *pit;
        auto nit = it;
        nit++;

        if (cd != *diffs.rbegin())
        {
            printf("No\n");
            return;
        }
        diffs.erase(diffs.find(cd));
        
        if (nit != s.end())
        {
            int nd = *nit - *pit;
            diffs.insert(nd);
        }
        s.erase(x);
    }

    printf("Yes\n");
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