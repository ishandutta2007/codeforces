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


const int N = (int) 2e6 + 100;
int cnt[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    vector <pair <int, int>> segs;
    int cntGood = 0, cntBad = 0;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        vector <int> v;
        int l;
        scanf("%d", &l);
        for (int j = 0; j < l; j++)
        {
            int x;
            scanf("%d", &x);
            v.push_back(x);
        }
        bool good = false;
        for (int j = 0; j < l - 1; j++)
            if (v[j + 1] > v[j])
                good = true;
        if (good)
        {
            cntGood++;
        }
        else
        {
            cntBad++;
            segs.emplace_back(v.back(), v[0]);
        }
    }

    long long ans = cntGood * 1LL * cntGood + 2LL * cntGood * cntBad;
    
    for (auto p : segs)
    {
        cnt[p.second]++;
    }

    for (int i = N - 1; i > 0; i--)
        cnt[i - 1] += cnt[i];

    for (auto p : segs)
        ans += cnt[p.first + 1];

    printf("%lld\n", ans);

	return 0;
}