#include<bits/stdc++.h>
using namespace std;

// FUCK :|

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int T = 230;

vector<int> adj[maxn];

int h , t , is[maxn];

void ok(int v , int u)
{
	vector<int> A , B , C;

	for(int i = 0; i < (int)adj[v].size() && i < T; i++)
		is[adj[v][i]]++;

	for(int i = 0; i < (int)adj[u].size() && i < T; i++)
		is[adj[u][i]]++;

	for(int i = 0; i < (int)adj[v].size() && i < T; i++)
	{
		int x = adj[v][i];
		if(x == u)
			continue;

		if(is[x] == 1)
			A.pb(x);
		else
			C.pb(x);
	}

	for(int i = 0; i < (int)adj[u].size() && i < T; i++)
	{
		int x = adj[u][i];
		if(is[x] == 1 && x != v)
			B.pb(x);
	}

	while((int)A.size() > h)
		A.pop_back();
	while((int)B.size() > t)
		B.pop_back();

	if(h - (int)A.size() + t - (int)B.size() <= (int)C.size())
	{
		cout << "YES" << endl;
		cout << v + 1 << " " << u + 1 << endl;

		for(auto x : A)
			cout << x + 1 << " ";
		while(h - (int)A.size())
			cout << C.back() + 1 << " " , C.pop_back() , h--;
		cout << endl;

		for(auto x : B)
			cout << x + 1 << " ";
		while(t - (int)B.size())
			cout << C.back() + 1 << " " , C.pop_back() , t--;
		exit(0);
	}

	for(int i = 0; i < (int)adj[v].size() && i < T; i++)
		is[adj[v][i]]--;

	for(int i = 0; i < (int)adj[u].size() && i < T; i++)
		is[adj[u][i]]--;	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m >> h >> t;

	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	for(int i = 0; i < n; i++)
		sort(adj[i].begin() , adj[i].end());

	for(int v = 0; v < n; v++)
		if(h + 1 <= (int)adj[v].size())
			for(auto u : adj[v])
				if(t + 1 <= (int)adj[u].size())
					ok(v , u);
	cout << "NO" << endl;
}