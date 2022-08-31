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

long long prefG[N];
long long prefB[N];

vector <int> good, bad;

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, d, m;
    scanf("%d%d%d", &n, &d, &m);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x <= m)
            good.push_back(x);
        else
            bad.push_back(x);
    }
    sort(good.begin(), good.end());
    reverse(good.begin(), good.end());
    sort(bad.begin(), bad.end());
    reverse(bad.begin(), bad.end());

    for (int i = 0; i < (int) good.size(); i++)
        prefG[i + 1] = prefG[i] + good[i];
    for (int i = 0; i < (int) bad.size(); i++)
        prefB[i + 1] = prefB[i] + bad[i];

    long long ans = 0;
    for (int b = 0; b <= (int) bad.size(); b++)
    {
        long long spent = max(b - 1, 0) * 1LL * d + b;
        if (spent > n)
            continue;
        long long cur = prefB[b] + prefG[min((int) good.size(), n - (int) spent)];
        ans = max(ans, cur);
    }
    printf("%lld\n", ans);

	return 0;
}