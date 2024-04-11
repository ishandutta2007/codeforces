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


const int N = (int) 2e5 + 100;
int a[N], t[N];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    vector <pair <int, int>> as;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        as.emplace_back(a[i], i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t[i]);
    }

    sort(as.begin(), as.end());

    int cur = 0;
    int ptr = 0;

    set <pair <int, int>> s;
    long long ans = 0;

    while (true)
    {
        while (ptr < (int) as.size() && as[ptr].first == cur)
        {
            int id = as[ptr].second;
            s.insert(make_pair(t[id], id));
            ptr++;
        }

        if (s.empty())
        {
            if (ptr == (int) as.size())
                break;
            cur = as[ptr].first;
            continue;
        }

        auto p = *s.rbegin();
        s.erase(p);
        int id = p.second;

        ans += (cur - a[id]) * 1LL * t[id];
        cur += 1;
    }

    printf("%lld\n", ans);

	return 0;
}