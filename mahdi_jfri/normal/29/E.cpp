#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 5e2 + 20;
vector<int> adj[maxn] , a , b;
int dist[maxn][maxn][2];
pair<pair<int ,int> , int> p[maxn][maxn][2];
int main()
{
	int n , m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			dist[i][j][0] = dist[i][j][1] = -1;
			p[i][j][0] = p[i][j][1] = {{-1 , -1} , -1};
		}
	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	queue<pair<pair<int , int> , int> > q;
	dist[n - 1][0][0] = 0;
	q.push({{n - 1 , 0} , 0});
	while(!q.empty())
	{
		int a = q.front().first.first , b = q.front().first.second , c = q.front().second;
		q.pop();
		if(c)
		{
			for(auto x : adj[a])
			{
				if(dist[x][b][0] != -1)
					continue;
				if(x == b)
					continue;
				p[x][b][0] = {{a , b} , c};
				q.push({{x , b} , 0});
				dist[x][b][0] = dist[a][b][c];
			}
		}
		else
		{
			for(auto x : adj[b])
			{
				if(dist[a][x][1] != -1)
					continue;
				q.push({{a , x} , 1});
				p[a][x][1] = {{a , b} , c};
				dist[a][x][1] = dist[a][b][c] + 1;
			}
		}
	}
	int x = 0 , y = n - 1 , z = 0;
	cout << dist[0][n - 1][0] << endl;
	while(z != -1 && dist[0][n - 1][0] != -1)
	{
		if(!z)
			a.pb(x);
		else
			b.pb(y);
		int a1 = p[x][y][z].first.first , b1 = p[x][y][z].first.second , c1 = p[x][y][z].second;
		x = a1;
		y = b1;
		z = c1;
	}
	if(dist[0][n - 1][0] != -1)
		b.pb(0);
	for(auto x : a)
		cout << x + 1 << " ";
	cout << endl;
	for(auto x : b)
		cout << x + 1 << " ";
	cout << endl;
}