#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int maxk = 1e2 + 20;

int d[maxn][maxk] , a[maxn];
ll res[maxn];

vector<int> adj[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m , k , s;
	cin >> n >> m >> k >> s;

	for(int i = 0; i < n; i++)
		cin >> a[i] , a[i]--;

	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	memset(d , 63 , sizeof d);

	for(int i = 0; i < k; i++)
	{
		queue<int> q;

		for(int j = 0; j < n; j++)
			if(a[j] == i)
				d[j][i] = 0 , q.push(j);

		while(!q.empty())
		{
			int v = q.front();
			q.pop();

			for(auto u : adj[v])
				if(d[v][i] + 1 < d[u][i])
				{
					d[u][i] = d[v][i] + 1;
					q.push(u);
				}
		}
	}

	for(int i = 0; i < n; i++)
		sort(d[i] , d[i] + k);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < s; j++)
			res[i] += d[i][j];

	for(int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;

}