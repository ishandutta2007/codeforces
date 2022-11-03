#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int maxs = 27;

int adj[maxn][maxs] , id = 1;

vector<pair<int , int> > num[maxn];

int node[maxn] , h[maxn];

string s[maxn];

void add(int i)
{
	int pos = 0;

	for(auto ch : s[i])
	{
		if(!adj[pos][ch - 'a'])
			adj[pos][ch - 'a'] = id++;

		int u = adj[pos][ch - 'a'];
		h[u] = h[pos] + 1;
		pos = u;
	}

	node[pos] = i;
}

void dfs(int v)
{
	if(node[v])
		num[v].pb({h[v] , node[v]});

	for(int i = 0; i < maxs; i++)
		if(adj[v][i])
		{
			int u = adj[v][i];
			dfs(u);

			for(auto x : num[u])
				num[v].pb(x);
		}

	sort(num[v].begin() , num[v].end());

	if(!node[v] && v)
	{
		int ind = num[v].back().second;

		num[v].pop_back();
		num[v].pb({h[v] , ind});
	}

	sort(num[v].begin() , num[v].end());
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		add(i);
	}

	dfs(0);

	int res = 0;
	for(auto x : num[0])
		res += x.first;

	cout << res << endl;
}