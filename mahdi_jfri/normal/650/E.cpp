#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e5 + 20;

set<pair<int , int> > st;

vector<int> adj[maxn] , adj2[maxn];

int par[maxn] , from[maxn] , to[maxn] , from2[maxn] , to2[maxn];

vector<pair<int , int> > ans;

inline int root(int v)
{
	stack<int> st;
	while(par[v] != -1)
	{
		if(st.size() > maxn)
			cout << 1/0;

		st.push(v);
		v = par[v];
	}

	while(!st.empty())
		par[st.top()] = v , st.pop();

	return v;
}

inline void merge(int a , int b)
{
	a = root(a);

	if(b != root(b))
		cout << 1/0;

	par[b] = a;

	if(adj[a].size() < adj[b].size())
		adj[a].swap(adj[b]);

	for(auto e : adj[b])
		adj[a].pb(e);

	adj[b].clear();
}

inline int find(int v)
{
	while(1)
	{
		if(adj[v].empty())
			cout << 1/0;
		int e = adj[v].back();
		if(st.find(make_pair(from[e] , to[e])) == st.end())
			adj[v].pop_back();
		else
			return adj[v].back();
	}
}

inline void dfs(int v , int pe = -1)
{
	for(auto e : adj2[v])
		if(e != pe)
		{
			int u = from2[e] ^ to2[e] ^ v;
			dfs(u , e);

			if(st.find(make_pair(from2[e] , to2[e])) != st.end())
				merge(v , u) , st.erase(make_pair(from2[e] , to2[e]));
			else
			{
				ans.pb({from2[e] , to2[e]});
				
				int et = find(u);
				ans.pb({from[et] , to[et]});

				st.erase(make_pair(from[et] , to[et]));

				if(root(from[et]) == u)
					merge(to[et] , u);
				else
					merge(from[et] , u);
			}
		}
}

int main()
{
	memset(par , -1 , sizeof par);
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		scanf("%d%d", &a, &b);
		a-- , b--;

		if(a > b)
			swap(a , b);

		adj2[a].pb(i);
		adj2[b].pb(i);

		from2[i] = a , to2[i] = b;
	}

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		scanf("%d%d", &a, &b);
		a-- , b--;

		if(a > b)
			swap(a , b);

		st.insert(make_pair(a , b));

		adj[a].pb(i);
		adj[b].pb(i);

		from[i] = a , to[i] = b;
	}

	dfs(0);

	cout << ans.size() / 2 << endl;

	for(auto x : ans)
		cout << x.first + 1 << " " << x.second + 1 << endl;

}