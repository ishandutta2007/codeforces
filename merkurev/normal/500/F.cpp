#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


const int maxn = 4005;
const int maxq = 20500;
const int maxt = 20500;

int c[maxn], h[maxn], t[maxn];
int a[maxq], b[maxq];
vector <int> q[maxt];
int ans[maxq];
int p;
int dp[25][maxn];

void getAns(int x, int pos)
{
	if (q[x].empty() )
		return;
	for (int i = 0; i < maxn - 1; i++)
	{
		dp[pos][i + 1] = max(dp[pos][i], dp[pos][i + 1] );
	}
	for (int i = 0; i < (int) q[x].size(); i++)
	{
		int id = q[x][i];
		ans[id] = dp[pos][b[id] ];
	}
}

void solve(int l, int r, vector <int> &goods, int pos)
{
	if (r - l == 1)
	{
		getAns(l, pos);
		return;
	}
	int m = (l + r) / 2;


	vector <int> tol;

	for (int i = 0; i < maxn; i++)
		dp[pos + 1][i] = dp[pos][i];

	for (int i = 0; i < (int) goods.size(); i++)
	{
		int id = goods[i];
		if (t[id] <= l && t[id] + p >= m)
		{
			for (int j = maxn - 1 - c[id]; j >= 0; j--)
			{
				dp[pos + 1][j + c[id] ] = max(dp[pos + 1][j + c[id] ], dp[pos + 1][j] + h[id] );
			}
		}
		else
			tol.push_back(id);
	}
	solve(l, m, tol, pos + 1);




	vector <int> tor;

	for (int i = 0; i < maxn; i++)
		dp[pos + 1][i] = dp[pos][i];

	for (int i = 0; i < (int) goods.size(); i++)
	{
		int id = goods[i];
		if (t[id] <= m && t[id] + p >= r)
		{
			for (int j = maxn - 1 - c[id]; j >= 0; j--)
			{
				dp[pos + 1][j + c[id] ] = max(dp[pos + 1][j + c[id] ], dp[pos + 1][j] + h[id] );
			}
		}
		else
			tor.push_back(id);
	}
	solve(m, r, tor, pos + 1);
}



int main()
{
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("input.txt", "w", stdout);
#endif
	int n;
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &c[i], &h[i], &t[i] );
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d", &a[i], &b[i] );
		q[a[i] ].push_back(i);
	}
	vector <int> goods;
	for (int i = 0; i < n; i++)
		goods.push_back(i);
	solve(0, maxt, goods, 0);

	for (int i = 0; i < k; i++)
		printf("%d\n", ans[i] );

	return 0;
}