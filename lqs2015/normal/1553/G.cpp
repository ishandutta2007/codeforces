#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn = 1e6;
int test, n, prime[1111111], cnt, q, a[222222], x, id[1111111], pa[555555], y, ans[555555];
vector<int> v[222222], p;
bool f[1111111], flg;
set<pair<int, int> > s;
void Init()
{
	for (int i = 2; i <= maxn; i++)
	{
		if (!f[i])
		{
			prime[++cnt] = i;
			id[i] = cnt;
		}
		for (int j = 1; j <= cnt && i * prime[j] <= maxn; j++)
		{
			f[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}
int root(int x)
{
	if (pa[x] != x) pa[x] = root(pa[x]);
	return pa[x];
}
void Union(int x, int y)
{
	int rx = root(x), ry = root(y);
	if (rx == ry) return;
	pa[rx] = ry;
}
int main()
{
	Init();
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n + cnt; i++) pa[i] = i;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		x = a[i];
		for (int j = 1; prime[j] <= 1000 && x > 1; j++)
		{
			if (x % prime[j] == 0)
			{
				while(x % prime[j] == 0) x /= prime[j];
				v[i].push_back(j);
			}
		}
		if (x > 1) v[i].push_back(id[x]);
		for (int j = 0; j < v[i].size(); j++) Union(i, n + v[i][j]);
	}
	for (int i = 1; i <= n; i++)
	{
		p = v[i];
		x = a[i] + 1;
		for (int j = 1; prime[j] <= 1000 && x > 1; j++)
		{
			if (x % prime[j] == 0)
			{
				while(x % prime[j] == 0) x /= prime[j];
				p.push_back(j);
			}
		}
		if (x > 1) p.push_back(id[x]);
		sort(p.begin(), p.end());
		p.resize(unique(p.begin(), p.end()) - p.begin());
		for (int j = 0; j < p.size(); j++)
		{
			for (int k = j + 1; k < p.size(); k++)
			{
				s.insert(make_pair(root(p[j] + n), root(p[k] + n)));
				s.insert(make_pair(root(p[k] + n), root(p[j] + n)));
			}
		}
	}
	for (int i = 1; i <= q; i++) 
	{
		scanf("%d%d", &x, &y);
		if (root(x) == root(y)) ans[i] = 0;
		else if (s.find(make_pair(root(x), root(y))) != s.end()) ans[i] = 1;
		else ans[i] = 2;
	}
	for (int i = 1; i <= q; i++)
	{
		printf("%d\n", ans[i]);
	}
	return Accepted;
}