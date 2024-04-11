#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
using namespace std;



const int maxn = 105;
pair <int, int> a[maxn];


bool isP(int x)
{
	for (int i = 2; i < x; i++)
		if (x % i == 0)
			return false;
	return true;
}

vector <int> p;
int dp[maxn][1 << 18];
int prv[maxn][1 << 18];
const int inf = 1e9;
int answer[maxn];
int b[maxn];
int msk[maxn];




int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = make_pair(x, i);
	}
	sort(a, a + n);
	reverse(a, a + n);

	for (int i = 2; i <= 58; i++)
		if (isP(i) )
			p.push_back(i);
	for (int i = 2; i <= 58; i++)
	{
		for (int j = 0; j < (int) p.size(); j++)
		{
			if (i % p[j] == 0)
				msk[i] |= (1 << j);
		}
	}
	int m = p.size();

	int _n = n;
	n = min(n, 18);
	for (int i = 18; i < _n; i++)
		b[i] = 1;

	for (int i = 0; i < 105; i++)
		for (int j = 0; j < (1 << 18); j++)
			dp[i][j] = inf;
	
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
	{
		int val = a[i].first;
		for (int mask = 0; mask < (1 << m); mask++)
		{
			int cur = dp[i][mask];
			if (cur == inf)
				continue;
			for (int nx = 1; nx <= 58; nx++)
			{
				int cm = msk[nx];
				if (cm & mask)
					continue;
				int nmask = (mask | cm);
				int ndp = cur + abs(nx - val);
				if (dp[i + 1][nmask] > ndp)
				{
					dp[i + 1][nmask] = ndp;
					prv[i + 1][nmask] = nx;
				}
			}
		}
	}
	int ans = inf;
	int amask = 0;
	for (int i = 0; i < (1 << m); i++)
	{
		if (dp[n][i] < ans)
		{
			ans = dp[n][i];
			amask = i;
		}
	}
	for (int cur = n; cur > 0; cur--)
	{
		int val = prv[cur][amask];
		b[cur - 1] = val;
		amask ^= msk[val];
	}
	n = _n;
	for (int i = 0; i < n; i++)
	{
		answer[a[i].second] = b[i];
	}
	for (int i = 0; i < n; i++)
		printf("%d ", answer[i] );



	return 0;
}