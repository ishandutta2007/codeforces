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

const int ALP = 26;
int cnt[ALP][ALP];

const int N = (int) 1e5 + 100;
char a[N], b[N];

void solve()
{
    memset(cnt, 0, sizeof cnt);
    int n;
    scanf("%d", &n);
    scanf("%s%s", a, b);
    for (int i = 0; i < n; i++)
        cnt[a[i] - 'a'][b[i] - 'a']++;

    int ans = 0;
    for (int i = 0; i < ALP; i++)
        for (int j = 0; j < i; j++)
            if (cnt[i][j])
                ans = -1;
    if (ans == -1)
    {
        printf("-1\n");
        return;
    }

    while (true)
    {
        bool fnd = false;
        for (int j = 0; j < ALP && !fnd; j++)
            for (int i = 0; i < j; i++)
                if (cnt[i][j])
                {
                    ans++;
                    fnd = true;
                    for (int h = 0; h < ALP; h++)
                    {
                        cnt[j][h] += cnt[i][h];
                        cnt[i][h] = 0;
                    }
                }
        if (!fnd)
            break;
    }

    printf("%d\n", ans);
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