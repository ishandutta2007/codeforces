#include <bits/stdc++.h>
 
using namespace std;
#define double long double
#define int long long
vector <vector <int> > g;
vector <int> tin, h, tout;
int timer = 0;
void dfs(int v, int pred = -1)
{
	tin[v] = timer++;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != pred)
		{
			h[to] = h[v] + 1;
			dfs(to , v);
		}
	}
	tout[v] = timer++;
}
bool cmp(int a, int b)
{
	return tout[a] < tout[b];
}
double intersect(pair <int, int> a, pair <int, int> b)
{
	double k1 = a.first;
	double b1 = a.second;
	double k2 = b.first;
	double b2 = b.second;
	return (b2 - b1) / (k1 - k2); 
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	g.resize(n);
	tin.resize(n);
	tout.resize(n);
	h.resize(n);
	vector <int> A(n), B(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> B[i];
	}
	for(int i =0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0);
	vector <int> ind(n);
	for(int i = 0; i < n; i++)
	{
		ind[i] = i;
	}
	sort(ind.begin(), ind.end(), cmp);
	vector <int> left(n), right(n);
	int k = sqrt(n) + 1;
	vector <vector <pair <int, int> > > SQRT(k); 
	for(int i = 0; i < n; i++)
	{
		int time1 = tin[ind[i]], time2 = tout[ind[i]], hv = h[ind[i]] + 1;
		if(g[ind[i]].size() == 1 && ind[i] != 0)
		{
			left[i] = right[i] = -1;
			continue;
		}
		int l = 0, r = n;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			if(tout[ind[midd]] < time2)
			{
				l = midd;
			}
			else
			{
				r = midd;
			}
		}
		right[i] = l;
		l = -1, r = n - 1;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			if(tout[ind[midd]] < time2 && tin[ind[midd]] < time1)
			{
				l = midd;
			}
			else
			{
				r = midd;
			}
		}
		left[i] = r;
	}
	vector <int> ans(n, 1e18);
	for(int i = 0; i < n; i++)
	{
		int l = left[i], r = right[i];
		assert(l <= r);
		if(l == -1)
		{
			ans[ind[i]] = 0;
		}
		else{
			if(r - l + 1 <= k)
			{
				for(int j = l; j <= r; j++)
				{
					ans[ind[i]] = min(ans[ind[i]], ans[ind[j]] + A[ind[i]] * B[ind[j]]);
				}
			}
			else
			{
				int l1 = l;
				if(l % k != 0)
				{
					l1 += k - l % k; 
				}
				int r1 = r;
				r1 -= r % k;
				for(int j = l; j <= min(l1, r); j++)
				{
					ans[ind[i]] = min(ans[ind[i]], ans[ind[j]] + A[ind[i]] * B[ind[j]]);
				}
				for(int j = max(l, r1); j <= r; j++)
				{
					ans[ind[i]] = min(ans[ind[i]], ans[ind[j]] + A[ind[i]] * B[ind[j]]);
				}
				for(int p = l1 / k; p < r1 / k; p++)
				{
					int l1 = -1, r1 = SQRT[p].size() - 1;
					while(r1 - l1 > 1)
					{
						int midd = (r1 + l1) / 2;
						if(intersect(SQRT[p][midd], SQRT[p][midd + 1]) <= A[ind[i]])
						{
							l1 = midd;
						}
						else
						{
							r1 = midd;
						}
					}
					ans[ind[i]] = min(ans[ind[i]], SQRT[p][l1 + 1].second + SQRT[p][l1 + 1].first * A[ind[i]]);
				}
			}
		}
		if(i % k == k - 1)
		{
			vector <pair<int, int> > cht;
			for(int j = i - k + 1; j <= i; j++)
			{
				cht.push_back({B[ind[j]], ans[ind[j]]});
			}
			sort(cht.begin(), cht.end());
			reverse(cht.begin(), cht.end());
			vector <pair <int, int> > cht1;
			for(int j = 0; j < cht.size(); j++)
			{
				while(cht1.size() > 0 && cht1.back().first == cht[j].first)
				{
					cht1.pop_back();
				}
				while(cht1.size() > 1 && intersect(cht1[cht1.size() - 2], cht1.back()) >= intersect(cht1[cht1.size() - 2], cht[j]))
				{
					cht1.pop_back();
				}
				cht1.push_back({cht[j].first, cht[j].second});
			}
			for(int j = 0; j < cht1.size(); j++)
			{
				SQRT[i / k].push_back(cht1[j]);
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}