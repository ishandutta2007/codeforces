#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
#define ll long long
const int N = 100100;
vector <int> g[N];
struct Shop
{
	int c;
	ll k, p;
	Shop() {}
	void scan()
	{
		scanf("%d%lld%lld", &c, &k, &p);
		--c;
	}
};
Shop s[N];
int q[N],d[N];
int n, k;
bool cmp(Shop a, Shop b)
{
	return a.p < b.p;
}

void bfs(int v)
{
	int cnt = 0;
	fill(d, d + n, N);
	q[cnt++] = v;
	d[v] = 0;
	for (int i = 0; i < cnt; ++i)
	{
		int v = q[i];
		for (int to : g[v])
		{
			if (d[to] > d[v] + 1)
			{
				d[to] = d[v] + 1;
				q[cnt++] = to;
			}
		}
	}
}

bool check(int dist, ll need, ll m)
{
	for (int i = 0; i < k && need; ++i)
		if (d[s[i].c] <= dist)
		{
			if (need > s[i].k)
			{
				need -= s[i].k;
				m -= s[i].k * s[i].p;
			}
			else
			{
				m -= need * s[i].p;
				need = 0;
			}
			if (m < 0)
				return false;
		}
	return need == 0;
}

int main() 
{
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
		s[i].scan();
	sort(s, s + k, cmp);

	int q;
	scanf("%d", &q);
	while (q--)
	{
		int g, cnt, a;
		scanf("%d%d%d", &g, &cnt, &a);
		--g;
		bfs(g);
		int l = -1, r = n;
		while (r - l != 1)
		{
			int m = (l + r) / 2;
			if (check(m, cnt, a)) r = m;
			else l = m;
		}
		if (r == n) puts("-1");
		else  printf("%d\n", r);
	}
}