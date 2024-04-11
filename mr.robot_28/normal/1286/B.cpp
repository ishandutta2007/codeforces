#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int N = 2000;
int c[N];
vector <int> g[N];
int p_ans[N];
vector <pair <int, int> > dfs(int v)
{
	if(sz(g[v]) == 0)
	{
		if(c[v] > 0)
		{
			cout << "NO";
			exit(0);
		}
		vector <pair <int, int> > res;
		res.push_back(make_pair(1, v));
		return res;
	}
	vector <pair <int, int> > res;
	int last = 0;
	for(auto to : g[v])
	{
		vector <pair <int, int> > res1 = dfs(to);
		for(auto p : res1)
		{
			res.push_back({p.X + last, p.Y});
		}
		//cout << sz(res1) << "\n";
		last = res.back().X;
	}
	if(c[v] > sz(res))
	{
		cout << "NO";
		exit(0);
	}
	for(int i = c[v]; i < sz(res); i++)
	{
		res[i].X++;
	}
	if(c[v] == sz(res))
	{
		res.push_back({res.back().X + 1, v});
	}
	else
	{
		res.push_back({res[c[v]].X - 1, v});
	}
	sort(res.begin(), res.end());
	return res;
}
signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int n;
	cin >> n;
	int u = -1;
	for(int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		cin >> c[i];
		p--;
		if(p == -1)
		{
			u = i;
		}
		else
		{
			g[p].push_back(i);
		}
	}
	vector <pair <int, int> > t = dfs(u);
	for(auto p : t)
	{
	//	cout << p.X << " " << p.Y << "\n";
		p_ans[p.Y] = p.X;
	}
	cout << "YES\n";
	for(int i = 0; i < n; i++)
	{
		cout << p_ans[i] << " ";
	}
	return 0;
}