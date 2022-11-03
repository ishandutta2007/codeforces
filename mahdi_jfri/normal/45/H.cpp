#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e3 + 20;
const int maxm = 1e5 + 20;

vector<int> adj[maxn] , out[maxn] , in[maxn] , comp[maxn] , topol , leaf;

int color[maxn] , from[maxm] , to[maxm] , h[maxn] , c = 1;

bool visited[maxn];

set<pair<int , int> > st;

void direct_dfs(int v)
{
	visited[v] = 1;
	for(auto u : adj[v])
	{
		if(!visited[u])
		{
			out[v].pb(u);
			in[u].pb(v);
			h[u] = h[v] + 1;
			direct_dfs(u);
		}
		else if(h[u] < h[v] && h[u] != h[v] - 1)
		{
			out[v].pb(u);
			in[u].pb(v);
		}
	}
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
	comp[c].pb(v);
	color[v] = c;
	for(auto u : in[v])
		if(!color[u])
			sfd(u);
}

void dfs_st(int v , int p = -1)
{
	for(auto u : adj[v])
		if(u != p)
			dfs_st(u , v);
	if(adj[v].size() == 1)
		leaf.pb(v);
}

int main()
{
	int n , m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> from[i] >> to[i];
		from[i]--;
		to[i]--;
		st.insert({from[i] , to[i]});
		st.insert({to[i] , from[i]});
		adj[from[i]].pb(to[i]);
		adj[to[i]].pb(from[i]);
	}
	direct_dfs(0);
	
	fill(visited , visited + n , 0);
	for(int i = 0; i < n; i++)
		if(!visited[i])
			dfs(i);

	reverse(topol.begin() , topol.end());

	for(auto v : topol)
		if(!color[v])
		{
			sfd(v);
			c++;
		}
	for(int i = 0; i < n; i++)
	{
		adj[i].clear();
		out[i].clear();
		in[i].clear();
		topol.clear();
	}
	fill(visited , visited + n , 0);

	int k = 0;

	for(int i = 0; i < m; i++)
	{
		int v = from[i] , u = to[i];
		if(color[v] != color[u])
			adj[color[v]].pb(color[u]) , adj[color[u]].pb(color[v]) , k++;
	}

	bool f = 0;

	for(int i = 1; i < c; i++)
		if(adj[i].size() > 1)
		{
			dfs_st(i);
			f = 1;
			break;
		}
	
	if(!f)
	{
		if(c == 2)
		{
			cout << 0 << endl;
			return 0;
		}
		for(auto v : comp[1])
			for(auto u : comp[2])
				if(st.find({v , u}) == st.end())
				{
					cout << 1 << endl << v + 1 << " " << u + 1 << endl;
					return 0;
				}
		cout << -1 << endl;
		return 0;
	}
	
	k = leaf.size();

	cout << (k + 1) / 2 << endl;

	for(int i = 0; i < (k + 1) / 2; i++)
	{
		int x = leaf[i] , y = leaf[min(i + k / 2 , k - 1)];

		bool z = 0;

		for(auto v : comp[x])
		{
			for(auto u : comp[y])
				if(st.find({v , u}) == st.end())
				{
					cout << v + 1 << " " << u + 1 << endl;
					z = 1;
					break;
				}
			if(z)
				break;
		}
	}
}