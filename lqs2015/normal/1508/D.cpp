#include <bits/stdc++.h>
using namespace std;
int n, x[2222], y[2222], p[2222], id[2222], cnt, used[2222], num[2222], cur, pa[2222], arr[2222], ct, lp;
vector<pair<int, int> > ans;
int root(int x)
{
	if (pa[x] != x) pa[x] = root(pa[x]);
	return pa[x];
}
bool Union(int x, int y)
{
	int rx = root(x), ry = root(y);
	if (rx == ry) return 0;
	pa[rx] = ry;
	return 1;
}
long long cross(int i, int j)
{
	return 1ll * (x[i] - x[cur]) * (y[j] - y[cur]) - 1ll * (y[i] - y[cur]) * (x[j] - x[cur]);
}
int cc(int i)
{
	if (x[i] > x[cur]) 
	{
		if (y[i] > y[cur]) return 1;
		return 2;
	}
	else
	{
		if (y[i] > y[cur]) return 4;
		return 3;
	}
}
bool cmp(int i, int j)
{
	if (cc(i) != cc(j)) return cc(i) < cc(j);
	return cross(i, j) < 0;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &x[i], &y[i], &p[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (i != p[i]) cur = i;
		if (!used[i])
		{
			cnt++;
			for (int j = i; !used[j]; j = p[j])
			{
				used[j] = 1;
				id[j] = cnt;
			}
		}
	}
	if (cnt == n)
	{
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= cnt; i++) pa[i] = i;
	for (int i = 1; i <= n; i++) 
	{
		if (i != cur) arr[++ct] = i;
	}
	sort(arr + 1, arr + ct + 1, cmp);
	for (int i = 1; i < ct; i++)
	{
		if (cross(arr[i], arr[i + 1]) > 0) continue;
		if (Union(id[arr[i]], id[arr[i + 1]]))
		{
			ans.push_back(make_pair(arr[i], arr[i + 1]));
			swap(p[arr[i]], p[arr[i + 1]]);
		}
	}
	for (int i = 1; i < n; i++)
	{
		ans.push_back(make_pair(p[cur], cur));
		swap(p[p[cur]], p[cur]);
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	printf("\n");
	return 0;
}