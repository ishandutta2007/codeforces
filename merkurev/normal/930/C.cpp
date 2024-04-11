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

const int INF = (int) 1e9 + 100;
const int N = (int) 1e5 + 100;

int l2l[N];

void solve(int val[], int dp[], int m)
{
    for (int i = 1; i <= m; i++)
        l2l[i] = INF;
    for (int i = 0; i < m; i++)
    {
        int x = val[i];
        int pos = upper_bound(l2l, l2l + m, x) - l2l - 1;
        l2l[pos + 1] = min(l2l[pos + 1], x);
        dp[i] = pos + 1;
    }
}

    
int val[N];
int dp[N], dpr[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        val[l - 1]++;
        val[r]--;
    }
    for (int i = 0; i < m; i++)
        val[i + 1] += val[i];
    solve(val, dp, m);
    reverse(val, val + m);
    solve(val, dpr, m);
    reverse(dpr, dpr + m);
    int ans = 0;
    for (int i = 0; i < m; i++)
        ans = max(ans, dp[i] + dpr[i] - 1);
    printf("%d\n", ans);

	return 0;
}