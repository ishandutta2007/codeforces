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

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    vector <int> ps;
    for (int t = 0; t < 2; t++)
    {
        int x = a[t];
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i != 0)
                continue;
            ps.push_back(i);
            while (x % i == 0)
                x /= i;
        }
        if (x != 1)
            ps.push_back(x);
    }
    sort(ps.begin(), ps.end());
    ps.resize(unique(ps.begin(), ps.end()) - ps.begin());

    long long ans = 1;
    for (int d : ps)
    {
        vector <int> mn = {100, 100, 100};
        for (int i = 0; i < n; i++)
        {
            int x = a[i];
            int cnt = 0;
            while (x % d == 0)
            {
                x /= d;
                cnt++;
            }
            mn.push_back(cnt);
            sort(mn.begin(), mn.end());
            mn.pop_back();
        }
        int deg = mn[1];
        for (int i = 0; i < deg; i++)
            ans *= d;
    }
    printf("%lld\n", ans);


	return 0;
}