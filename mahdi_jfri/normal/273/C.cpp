#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;

vector<int> adj[maxn];

int a[maxn];

bool bad(int v)
{
	int x = 0;
	for(auto u : adj[v])
		if(a[u] == a[v])
			x++;
	return (1 < x);
}

int main()
{
	int n , m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int a , b;
		scanf("%d%d", &a, &b);
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	set<int> st;
	for(int i = 0; i < n; i++)
		if(bad(i))
			st.insert(i);
	while(!st.empty())
	{
		int v = *st.begin();
		st.erase(v);
		if(!bad(v))
			continue;
		a[v] = !a[v];
		for(auto u : adj[v])
			if(bad(u))
				st.insert(u);
	}
	for(int i = 0; i < n; i++)
		printf("%d", a[i]);
	cout << endl;
}