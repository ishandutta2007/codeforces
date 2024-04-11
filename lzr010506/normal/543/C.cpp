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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int maxn = 22;
char f[maxn][maxn];
int a[maxn][maxn];

vector <pair <int, int> > st;
const int inf = (int) 1e9;
int dp[(1 << 20)];

int mn[maxn];

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		mn[i] = inf;
		scanf("%s", f[i] );
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j] );
		}
	int start = 0;
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			mn[i] = min(mn[i], a[i][j] );
		}
		for (int ch = 'a'; ch <= 'z'; ch++)
		{
			int cnt = 0;
			int msk = 0, mx = 0, sum = 0;
			for (int i = 0; i < n; i++)
			{
				if (f[i][j] != ch)
					continue;
				cnt++;
				msk |= (1 << i);
				mx = max(mx, a[i][j] );
				sum += a[i][j];
			}
			if (cnt == 0)
				continue;
			if (cnt == 1)
			{
				start |= msk;
				continue;
			}
			st.push_back(make_pair(msk, sum - mx) );
		}
	}
	for (int i = 0; i < n; i++)
		st.push_back(make_pair(1 << i, mn[i] ) );
	for (int i = 0; i < (1 << n); i++)
		dp[i] = inf;

	dp[start] = 0;
	int sz = (int) st.size();
	for (int i = 0; i < sz; i++)
	{
		int msk = st[i].first;
		int add = st[i].second;
		for (int j = 0; j < (1 << n); j++)
		{
			dp[j | msk] = min(dp[j | msk], dp[j] + add);
		}
	}
	printf("%d\n", dp[ (1 << n) - 1] );

	return 0;
}