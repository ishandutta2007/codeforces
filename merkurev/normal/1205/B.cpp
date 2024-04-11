#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...)
#endif


const int N = (int) 1e5 + 100;
long long a[N];

const int LOG = 60;
vector <int> has[LOG];

const int K = 200;
vector <int> g[K];
int dp[K][K][K];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    int sz = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[sz]);
        if (a[sz] != 0)
            sz++;
    }
    n = sz;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < LOG; j++)
        {
            if (a[i] & (1LL << j))
            {
                has[j].push_back(i);
                if (has[j].size() >= 3)
                {
                    printf("3\n");
                    return 0;
                }
            }
        }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] & a[j])
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }

    vector <pair <int, pair <int, int>>> qu;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++)
    {
        qu.emplace_back(i, make_pair(i, i));
        dp[i][i][i] = 0;
    }
    for (int it = 0; it < (int) qu.size(); it++)
    {
        int i = qu[it].first;
        int st = qu[it].second.first;
        int par = qu[it].second.second;
        if (i == st && par != i)
        {
            printf("%d\n", dp[i][st][par]);
            return 0;
        }

        for (int j : g[i])
        {
            if (j == par) continue;
            if (dp[j][st][i] == -1)
            {
                dp[j][st][i] = dp[i][st][par] + 1;
                qu.emplace_back(j, make_pair(st, i));
            }
        }
    }
    printf("-1\n");

    return 0;
}