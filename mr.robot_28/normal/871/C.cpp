#include<bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 1e9 + 7;
vector <vector <int> > g;
vector <int> used;
bool flag = false;
set <int> X, Y;
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 0)
	{
		int t = power(a, b / 2);
		return t * t % const1;
	}
	else
	{
		int t = power(a, b / 2);
		t = t * t % const1;
		return t* a % const1;
	}
}
vector <pair <int, int> > mass;
void dfs(int v, int p = -1)
{
	X.insert(mass[v].first);
	Y.insert(mass[v].second);
	used[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to == p)
		{
			continue;
		}
		if(used[to] == 1)
		{
			flag = true;
		}
		else if(used[to] == 0)
		{
			dfs(to, v);
		}
	}
	used[v] = 2;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	g.resize(n);
	used.resize(n, 0);
	mass.resize(n);
	vector <pair <pair <int, int>, int> > x(n);
	vector <pair <pair <int, int> , int> > y;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i].first.first >> x[i].first.second;
		x[i].second = i;
		mass[i] = x[i].first;
		y.push_back({{x[i].first.second, x[i].first.first}, i});
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	for(int i = 0; i < n - 1; i++)
	{
		if(x[i].first.first == x[i + 1].first.first)
		{
			g[x[i].second].push_back(x[i + 1].second);
			g[x[i + 1].second].push_back(x[i].second);
		}
		if(y[i].first.first == y[i + 1].first.first)
		{
			g[y[i].second].push_back(y[i + 1].second);
			g[y[i + 1].second].push_back(y[i].second);
		}
	}
	int ans = 1;
	for(int i = 0; i < n; i++)
	{
		if(used[i] == 0)
		{
			dfs(i);
			int c = 1;
			if(flag)
			{
				c = power(2, X.size() + Y.size());
			}
			else
			{
				c = power(2, X.size() + Y.size()) - 1;
			}
			if(c < 0)
			{
				c += const1;
			}
			ans = ans * c % const1;
			flag = false;
			X.clear();
			Y.clear();
		}
	}
	cout << ans;
	return 0;
}