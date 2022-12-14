#include <bits/stdc++.h>
using namespace std;
const int magic = 100;
int n, m, ans, w[111111], ll, a[111111][6], cnt, id[111111], arr[555555], occ[555555], crt, fuck[555555];
bool u[555555], can[111111];
map<int, int> mp;
bitset<111111> b[5555], B, res;
vector<int> pos[555555];
bool cmp(int x, int y)
{
	return w[x] < w[y];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			arr[++cnt] = a[i][j];
		}
		scanf("%d", &w[i]);
		id[i] = i;
	}
	sort(id + 1, id + n + 1, cmp);
	sort(arr + 1, arr + cnt + 1);
	cnt = unique(arr + 1, arr + cnt + 1) - arr - 1;
	for (int i = 1; i <= cnt; i++) mp[arr[i]] = i;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			a[i][j] = mp[a[i][j]];
			occ[a[i][j]] ++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		can[i] = 1;
		for (int j = 1; j <= m; j++)
		{
			if (u[a[i][j]]) can[i] = 0;
			u[a[i][j]] = 1;
		}
		for (int j = 1; j <= m; j++) u[a[i][j]] = 0;
	}
	for (int i = 1; i <= cnt; i++)
	{
		if (occ[i] > magic)
		{
			++crt;
			fuck[i] = crt;
		}
	}
	for (int i = 1; i <= crt; i++) b[i].set();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			pos[a[id[i]][j]].push_back(i);
			if (fuck[a[id[i]][j]]) b[fuck[a[id[i]][j]]].reset(i);
		}
	}
	B.reset();
	for (int i = 1; i <= n; i++) 
	{
		if (can[id[i]]) B[i] = 1;
	}
	ans = 2e9 + 10;
	for (int i = 1; i <= n; i++)
	{
		if (!can[id[i]]) continue;
		res = B;
		for (int j = 1; j <= m; j++)
		{
			if (fuck[a[id[i]][j]]) res &= b[fuck[a[id[i]][j]]];
			else 
			{
				for (int k = 0; k < pos[a[id[i]][j]].size(); k++) res[pos[a[id[i]][j]][k]] = 0;
			}
		}
		ll = res._Find_first();
		if (ll >= 1 && ll <= n) ans = min(ans, w[id[i]] + w[id[ll]]);
	}
	if (ans > 2e9) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}