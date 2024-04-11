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
long long a[N], b[N], t[N];

set <pair <long long, int>> setFirst, setA, setT;


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld%lld%lld", &a[i], &b[i], &t[i]);

    for (int i = 0; i < n; i++)
    {
        setFirst.insert(make_pair(a[i] + t[i], i));
        setA.insert(make_pair(a[i], i));
    }

    long long ans = 0;
    long long curt = 0;
    while (true)
    {
        //eprintf("curt = %lld, ans = %lld\n", curt, ans);
        int cur = -1;
        while (!setT.empty())
        {
            int id = setT.begin()->second;
            if (curt + t[id] > b[id])
            {
                setT.erase(setT.begin());
                continue;
            }
            cur = id;
            break;
        }
        eprintf("cur = %d\n", cur);
        if (cur == -1)
        {
            if (setFirst.empty())
                break;
            cur = setFirst.begin()->second;
        }
        else if (!setFirst.empty())
        {
            long long alt = setFirst.begin()->first;
            if (alt < curt + t[cur])
                cur = setFirst.begin()->second;
        }

        curt = max(curt, a[cur]);
        long long cnt = (b[cur] - curt) / t[cur];
        if (!setA.empty())
            cnt = min(cnt, (setA.begin()->first - curt) / t[cur]);
        cnt = max(cnt, 1LL);

        ans += cnt;
        curt += t[cur] * cnt;

        while (!setA.empty() && setA.begin()->first <= curt)
        {
            int id = setA.begin()->second;
            setA.erase(setA.begin());
            setFirst.erase(make_pair(a[id] + t[id], id));
            setT.insert(make_pair(t[id], id));
        }
    }

    printf("%lld\n", ans);


	return 0;
}