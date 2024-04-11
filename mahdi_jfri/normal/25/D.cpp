#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
vector<int> adj[maxn] , cmp[maxn];
set<pair<int , int> > bck , add;
int c;
bool visited[maxn];
void dfs(int v , int p = -1)
{
	visited[v] = 1;
	cmp[c].pb(v);
	for(auto u : adj[v])
	{
		if(!visited[u])
			dfs(u , v);
		else if(u != p)
			bck.insert({min(v , u) , max(v , u)});
	}
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			dfs(i);
			c++;
		}
	}
	cout << bck.size() << endl;
	for(int i = 1; i < c; i++)
	{
		cout << (bck.begin() -> first) + 1 << " " << (bck.begin() -> second) + 1 << " " << cmp[0][0] + 1 << " " << cmp[i][0] + 1 << endl;
		bck.erase(bck.begin());
	}
}