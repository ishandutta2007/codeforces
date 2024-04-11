#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> dsu, rang;
int pred(int x)
{
	if(dsu[x] == x) return x;
	else return dsu[x] = pred(dsu[x]);
}
void unite(int a, int b)
{
	a = pred(a);
	b = pred(b);
	if(a != b)
	{
		if(rang[a] < rang[b])
		{
			swap(a, b);
		}
		dsu[b] = a;
		if(rang[a] == rang[b])
		{
			rang[a]++;
		}
	}
}
signed main()
{
	int n, m;
	cin >> n >> m;
	dsu.resize(n);
	rang.resize(n);
	for(int i = 0; i < n; i++)
	{
		dsu[i] = i;
		rang[i] = 1;
	}
	vector <pair <int, int> > scanline;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		if(x > y)
		{
			swap(x, y);
		}
		unite(x - 1, y - 1);
		scanline.push_back({x - 1, -1});
		scanline.push_back({y - 1, 1});
	}
	sort(scanline.begin(), scanline.end());
	int st = -1;
	int bal = 0;
	int ans = 0;
	for(int i = 0; i < 2 * m; i++)
	{
		if(bal == 0)
		{
			st = scanline[i].first;
		}
		bal -= scanline[i].second;
		if(bal == 0)
		{
			set <int> t;
			for(int j = st; j <= scanline[i].first; j++)
			{
				t.insert(pred(j));
			}
			ans += t.size() - 1;
		}
	}
	cout << ans;
    return 0;
}