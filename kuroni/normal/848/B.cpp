#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct TDance
{
	int g, p, t, i;
} a[100005];
vector <TDance> u, l;
int n, w, h, i, cur, x[100005], y[100005];

inline bool operator < (const TDance &a, const TDance &b)
{
	return (a.p - a.t < b.p - b.t) || (a.p - a.t == b.p - b.t && (a.g < b.g || (a.g == b.g && a.p < b.p)));
}

void solve()
{
	for (int i = 0; i < u.size(); i++)
		if (u.size() - i <= l.size())
		{
			x[u[i].i] = w;
			y[u[i].i] = l[u.size() - i - 1].p;
		}
		else
		{
			x[u[i].i] = u[i + l.size()].p;
			y[u[i].i] = h;
		}
	for (int i = 0; i < l.size(); i++)
		if (l.size() - i <= u.size())
		{
			x[l[i].i] = u[l.size() - i - 1].p;
			y[l[i].i] = h;
		}
		else
		{
			x[l[i].i] = w;
			y[l[i].i] = l[i + u.size()].p;
		}
	u.clear(); l.clear();
}

int main()
{
	scanf("%d%d%d", &n, &w, &h);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &a[i].g, &a[i].p, &a[i].t);
		a[i].i = i;
	}
	sort(a + 1, a + n + 1);
	i = 1;
	while (i <= n)
	{
		cur = a[i].p - a[i].t;
		while (a[i].g == 1 && a[i].p - a[i].t == cur)
			u.push_back(a[i++]);
		while (a[i].g == 2 && a[i].p - a[i].t == cur)
			l.push_back(a[i++]);
		solve();
	}
	for (i = 1; i <= n; i++)
		printf("%d %d\n", x[i], y[i]);
}