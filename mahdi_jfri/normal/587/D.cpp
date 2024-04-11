#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 5e5 + 20;
vector<int> adj[maxn] , out[maxn] , in[maxn] , topol;
int tah , c[maxn] , t[maxn] , color[maxn], n , m , now;

bool visited[maxn] , sat[maxn];

bool cmp(int a , int b)
{
	return c[a] < c[b];
}

void add(int a , int b)
{
	out[a].pb(b);
	in[b].pb(a);
}

pair<int , int> d(int v , int s , int e) // {hame be in , in be hame}
{
	if(e - s < 2)
	{
		int new_vertex = tah++;
		add(new_vertex , 2 * adj[v][s] + 1);
		new_vertex = tah++;
		add(2 * adj[v][s] , new_vertex);
		return {new_vertex , new_vertex - 1};
	}
	int m = (s + e) / 2;
	pair<int , int> a = d(v , s , m);
	pair<int , int> b = d(v , m , e);
	add(a.first , b.second);
	add(b.first , a.second);
	int to_all = tah++;
	add(to_all , a.second);
	add(to_all , b.second);
	int all_to = tah++;
	add(a.first , all_to);
	add(b.first , all_to);
	return {all_to , to_all};
}

void dfs(int v)
{
	visited[v] = 1;
	for(auto u : out[v])
		if(!visited[u])
			dfs(u);
	topol.pb(v);
}

void sfd(int v)
{
	color[v] = now;
	for(auto u : in[v])
		if(!color[u])
			sfd(u);
}

bool check(ll x)
{
	for(int i = 0; i < tah; i++)
		out[i].clear() , in[i].clear();
	tah = 2 * m;
	for(int i = 1; i <= n; i++)
	{
		if(adj[i].empty())
			continue;
		for(int j = 0; j < (int)adj[i].size(); j++)
		{
			int k = j;
			while(j + 1 < (int)adj[i].size() && c[adj[i][j]] == c[adj[i][j + 1]])
				j++;
			if(j - k + 1 < 2)
				continue;
			int a = adj[i][k] , b = adj[i][k + 1];
			add(2 * a + 1 , 2 * b);
			add(2 * b + 1 , 2 * a);
		}
		d(i , 0 , (int)adj[i].size());
		for(auto e : adj[i])
			if(t[e] > x)
				add(2 * e , 2 * e + 1);
	}
	memset(visited , 0 , sizeof visited);
	memset(color , 0 , sizeof color);
	now = 0;
	for(int i = 0; i < tah; i++)
		if(!visited[i])
			dfs(i);
	reverse(topol.begin() , topol.end());
	for(auto v : topol)
		if(!color[v])
		{
			now++;
			sfd(v);
		}
	for(int i = 0; i < m; i++)
	{
		if(color[2 * i] == color[2 * i + 1])
			return 0;
		sat[i] = (color[2 * i] > color[2 * i + 1]);
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	tah = 2 * m;
	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b >> c[i] >> t[i];
		adj[a].pb(i);
		adj[b].pb(i);
	}
	for(int i = 1; i <= n; i++)
	{
		sort(adj[i].begin() , adj[i].end() , cmp);
		for(int j = 0; j < (int)adj[i].size(); j++)
		{
			int k = j;
			while(j + 1 < (int)adj[i].size() && c[adj[i][j]] == c[adj[i][j + 1]])
				j++;
			if(j - k + 1 > 2)
			{
				cout << "No" << endl;
				return 0;
			}
		}
	}
	ll l = -1 , r = 1e10;
	if(!check(r))
	{
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	while(r - l > 1)
	{
		ll m = (r + l) / 2;
		if(check(m))
			r = m;
		else
			l = m;
	}
	check(r);
	vector<int> ans;
	for(int i = 0; i < m; i++)
		if(sat[i])
			ans.pb(i);
	cout << r << " " << ans.size() << endl;
	for(auto e : ans)
		cout << e + 1 << " ";
}