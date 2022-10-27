#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
int n, m;
vector <vector <pair <int, int> > > g;
vector <int> cnt1, cnt2;
vector <pair <int, pair <int, int> > > scan;
vector <int> used;
set <double> st;
const double eps = 1e-9;
void dfs(int v)
{
	used[v] = 1;
	if(cnt1[v] < 0)
	{
		scan.push_back({-1e9, {-1, -1e9 - 1}});
		scan.push_back({-1e9, {0, cnt2[v]}});
		scan.push_back({cnt2[v], {1, -1e9 - 1}});
		scan.push_back({cnt2[v], {0, -cnt2[v]}});
	}
	else
	{
		scan.push_back({-1e9, {-1, -1e9 - 1}});
		scan.push_back({-1e9, {0, -cnt2[v]}});
		scan.push_back({-cnt2[v], {1, -1e9 - 1}});
		scan.push_back({-cnt2[v], {0, cnt2[v]}});
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		int type = g[v][i].second;
		if(!used[to])
		{
			cnt1[to] = -cnt1[v];
			cnt2[to] = type - cnt2[v];
			dfs(to);
		}
		else if(cnt1[v] + cnt1[to] == 0 && cnt2[v] + cnt2[to] != type)
		{
			cout << "NO";
			exit(0);
		}
		else if(cnt1[v] + cnt1[to] != 0)
		{
			double newval = (type -(cnt2[v] + cnt2[to])) * 1.0 / (cnt1[v] + cnt1[to]);
			if(st.size() == 1 && fabs(*st.begin() - newval) <= eps)
			{
				continue;
			}
			st.insert(newval);
		}
	}
}
vector <double> ans;
void dfs1(int v, double a)
{
	used[v] = 2;
	ans[v] = cnt1[v] * a + cnt2[v];
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(used[to] != 2)
		{
			dfs1(to, a);
		}
	}
}
signed main() {
	cin >> n >> m;
	cnt1.resize(n);
	cnt2.resize(n);
	used.resize(n);
	g.resize(n);
	ans.resize(n);
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	for(int i = 0; i < n; i++)
	{
		if(!used[i]){
			cnt1[i] = 1;
			cnt2[i] = 0;
			dfs(i);
			if(st.size() > 1)
			{
				cout << "NO";
				return 0;
			}
			if(st.size() != 0)
			{
				dfs1(i, *st.begin());
				st.clear();
				scan.clear();
				continue;
			}
			sort(scan.begin(), scan.end());
			int sum1 = 0, sum2 = 0;
			double minsum = 1e18;
			double mina;
			for(int j = 0; j < scan.size(); j++)
			{
				if(scan[j].first == -1e9)
				{
					if(scan[j].second.second == -1e9 - 1)
					{
						sum1 += scan[j].second.first;
					}
					else
					{
						sum2 += scan[j].second.second;
					}
				}
				else
				{
					if(scan[j].second.second == -1e9 - 1)
					{
						sum1 += 2 * scan[j].second.first;
					}
					else
					{
						sum2 += 2 * scan[j].second.second;
					}
				}
				if(j == scan.size() - 1 || scan[j + 1].first != scan[j].first)
				{
					if(sum1 == 0)
					{
						if(sum2 <= minsum)
						{
							minsum = sum2;
							mina = 0;
						}
					}
					else
					{
						double t = -sum2 * 1.0 / sum1;
						if(t >= scan[j].first && (j == scan.size() - 1 || t <= scan[j + 1].first))
						{
							minsum = 0;
							mina = t;
						}
						if(scan[j].first != -1e9 && sum1 * scan[j].first + sum2 <= minsum)
						{
							minsum = sum1 * scan[j].first + sum2;
							mina = scan[j].first;
						}
					}
				}
			}
			dfs1(i, mina);
			scan.clear();
		}
	}
	cout << "YES\n";
	for(int i = 0; i < n; i++)
	{
		cout << fixed << setprecision(10) << ans[i] << " ";
	}
  	return 0;
}