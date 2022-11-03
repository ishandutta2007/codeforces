#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
vector<int> out[maxn] , topol , keys[maxn];
vector<pair<int , int> > clause;
int pos[maxn];
bool visited[maxn] , r[maxn] , is[maxn];
void dfs(int v)
{
	visited[v] = 1;
	for(auto u : out[v])
		if(!visited[u])
			dfs(u);
	pos[v] = topol.size();
	topol.pb(v);
}
int main()
{
	int n , m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> r[i];
	for(int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		for(int j = 0; j < x; j++)
		{
			int a;
			cin >> a;
			a--;
			keys[a].pb(i);
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(r[i])
		{
			int a = keys[i][0] , b = keys[i][1];
			clause.pb({2 * a , 2 * b + 1});
			clause.pb({2 * a + 1 , 2 * b});
		}
		else
		{
			int a = keys[i][0] , b = keys[i][1];
			clause.pb({2 * a , 2 * b});
			clause.pb({2 * a + 1 , 2 * b + 1});
		}
	}
	for(auto e : clause)
	{
		out[e.first ^ 1].pb(e.second);
		out[e.second ^ 1].pb(e.first);
	}
	for(int i = 0; i < 2 * m; i++)
		if(!visited[i])
			dfs(i);
	for(int i = 0; i < m; i++)
	{
		if(pos[2 * i] > pos[2 * i + 1])
			is[i] = 1;
	}
	bool f = 0;
	for(auto e : clause)
	{
		bool a = is[e.first / 2] , b = is[e.second / 2];
		if(e.first & 1)
			a = !a;
		if(e.second & 1)
			b = !b;
		if(a | b)
			continue;
		f = 1;
		break;
	}
	cout << (f? "NO" : "YES") << endl;
}