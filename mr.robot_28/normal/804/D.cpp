#include<bits/stdc++.h>
 
using namespace std;
#define double long double
vector <vector <int> > g, mass;
vector <int> col;
vector <int> hmax;
vector <int> up;
void dfs(int v, int c, int p = -1)
{
	col[v] = c;
	mass[c].push_back(v);
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs(to, c, v);
			hmax[v] = max(hmax[v], hmax[to] + 1);
		}
	}
}
void dfsup(int v, int p = -1)
{
	vector <int> pref(g[v].size(), 0);
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			if(i != 0)
			{
				pref[i] = pref[i - 1];
			}
			pref[i] = max(pref[i], hmax[to] + 2);
		}
		else if(i != 0)
		{
			pref[i] = pref[i - 1];
		}
	}
	int ans = up[v] + 1;
	for(int i = g[v].size() - 1; i >= 0; i--)
	{
		int to = g[v][i];
		if(to != p)
		{
			int val = ans;
			if(i != 0)
			{
				val = max(val, pref[i - 1]);
			}
			up[to] = val;
			dfsup(to, v);
			ans = max(ans, hmax[to] + 2);
		}
	}
}
bool cmp(int a , int b)
{
	return max(up[a], hmax[a]) < max(up[b], hmax[b]);
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	g.resize(n);
	col.resize(n, -1);
	mass.resize(n);
	hmax.resize(n);
	up.resize(n);
	for(int i = 0;  i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int t = sqrt(n);
	vector <int> vec;
	vector <vector <int> > post(n);
	for(int i = 0; i < n; i++)
	{
		if(col[i] == -1)
		{
			dfs(i, i);
			dfsup(i);
			sort(mass[i].begin(), mass[i].end(), cmp);
			if(mass[i].size() > t)
			{
				vec.push_back(i);
			}
			post[i].resize(mass[i].size());
			for(int j = mass[i].size() - 1; j >= 0; j--)
			{
				if(j != mass[i].size() - 1)
				{
					post[i][j] = post[i][j + 1];
				}
				post[i][j] += max(up[mass[i][j]], hmax[mass[i][j]]);
			}
		}
	}
	vector <vector <double> > dp(vec.size(), vector <double> (vec.size()));
	for(int i = 0; i < vec.size(); i++)
	{
		for(int j = i + 1; j < vec.size(); j++)
		{
			int ind1 = mass[vec[i]].back();
			int ind2 = mass[vec[j]].back();
			int h1 = max(max(up[ind1], hmax[ind1]), max(up[ind2], hmax[ind2]));
			for(int p = 0; p < mass[vec[i]].size(); p++)
			{
				int ind2 = mass[vec[i]][p];
				int H1 = max(up[ind2], hmax[ind2]);
				int l = -1, r = mass[vec[j]].size();
				while(r - l > 1)
				{
					int midd = (r + l) / 2;
					int H2 = max(up[mass[vec[j]][midd]], hmax[mass[vec[j]][midd]]);
					if(H1 + H2 + 1 >= h1)
					{
						r = midd;
					}
					else
					{
						l = midd;
					}
				}
				dp[i][j] += 1LL * r * h1 + 1LL * (mass[vec[j]].size() - r) * (H1 + 1) + post[vec[j]][r];
			}
			dp[i][j] /= 1LL * (mass[vec[i]].size()) * (mass[vec[j]].size());
			dp[j][i] = dp[i][j];
		}
	}
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		a = col[a];
		b = col[b];
		if(a == b)
		{
			cout << -1 << "\n";
			continue;
		}
		if(mass[a].size() > t && mass[b].size() > t)
		{
			int ind1 = 0, ind2 = 0;
			for(int i = 0; i< vec.size(); i++)
			{
				if(vec[i] == a)
				{
					ind1 = i;
				}
				if(vec[i] == b)
				{
					ind2 = i;
				}
			}
			cout << fixed << setprecision(10) << dp[ind1][ind2] << "\n";
			continue;
		}
		if(mass[a].size() > mass[b].size())
		{
			swap(a, b);
		}
		double ans = 0;
		int h1 = max(max(up[mass[a].back()], hmax[mass[a].back()]), max(up[mass[b].back()], hmax[mass[b].back()]));
		for(int i = 0; i < mass[a].size(); i++)
		{
			int ind2 = mass[a][i];
			int H1 = max(up[ind2], hmax[ind2]);
			int l = -1, r = mass[b].size();
			while(r - l > 1)
			{
				int midd = (r + l) / 2;
				int H2 = max(up[mass[b][midd]], hmax[mass[b][midd]]);
				if(H1 + H2 + 1 >= h1)
				{
					r = midd;
				}
				else
				{
					l = midd;
				}
			}
			ans += 1LL * r * h1 + 1LL * (mass[b].size() - r) * (H1 + 1) + post[b][r];
		}
		ans /= 1LL * (mass[a].size()) * (mass[b].size());
		cout << fixed << setprecision(10) << ans << "\n";
	}
	return 0;
}