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


const int K = 15;
const int N = 5005;
const int MASK = (1 << K);

int n[K];
int a[K][N];
long long sumi[K];
int dp[MASK];

map <int, pair <int, int>> pos;

vector <pair <int, int>> maskv[MASK];

pair <int, int> ans[K];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int k;
    scanf("%d", &k);
    long long sum = 0;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &n[i]);
        for (int j = 0; j < n[i]; j++)
        {
            scanf("%d", &a[i][j]);
            sumi[i] += a[i][j];
            pos[a[i][j]] = make_pair(i, j);
        }
        sum += sumi[i];
    }

    if (sum % k != 0)
    {
        printf("No\n");
        return 0;
    }
    long long need = sum / k;

    for (int i = 0; i < k; i++)
        for (int j = 0; j < n[i]; j++)
        {
            int mask = 0;
            int ci = i;
            int cj = j;
            vector <pair <int, int>> v;
            while ((mask & (1 << ci)) == 0)
            {
                v.emplace_back(ci, a[ci][cj]);
                mask |= (1 << ci);
                long long rem = need - (sumi[ci] - a[ci][cj]);
                if (pos.count(rem) == 0)
                {
                    ci = -1;
                    cj = -1;
                    break;
                }
                auto p = pos[rem];
                ci = p.first;
                cj = p.second;
            }
            if (ci != i || cj != j)
                continue;
            maskv[mask] = v;
        }

    for (int mask = 0; mask < (1 << k); mask++)
    {
        if (!maskv[mask].empty())
        {
            dp[mask] = mask;
            continue;
        }
        for (int sub = mask; sub > 0; sub = (sub - 1) & mask)
        {
            int rem = mask ^ sub;
            if (!maskv[sub].empty() && dp[rem] != 0)
                dp[mask] = sub;
        }
    }
    
    if (dp[(1 << k) - 1] == 0)
    {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    int mask = (1 << k) - 1;
    while (mask > 0)
    {
        int cur = dp[mask];
        auto v = maskv[cur];
        for (int i = 0; i < (int) v.size(); i++)
        {
            int ni = (i + 1) % (int) v.size();
            ans[v[ni].first] = make_pair(v[ni].second, v[i].first);
        }
        mask ^= cur;
    }
    for (int i = 0; i < k; i++)
        printf("%d %d\n", ans[i].first, ans[i].second + 1);


	return 0;
}