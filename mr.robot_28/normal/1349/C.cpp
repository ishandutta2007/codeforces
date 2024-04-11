#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int n, m, t;
	cin >> n >> m >> t;
	vector <vector <char> > A(n, vector <char> (m));
	queue <pair <int, int> > q;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> A[i][j];
		}
	}
	vector <vector <bool> > used(n, vector <bool> (m));
	vector <vector <pair <int, int> > > p(n, vector <pair <int, int> > (m));
	vector <vector <int> > dist(n, vector <int> (m, 1e18 + 1));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(i > 0 && A[i - 1][j] == A[i][j] || j > 0 && A[i][j - 1] == A[i][j] || 
			i < n - 1 && A[i + 1][j] == A[i][j] || j < m - 1 && A[i][j + 1] == A[i][j])
			{
				used[i][j] = 1;
				dist[i][j] = 0;
				p[i][j] = {i, j};
				q.push({i, j});
			}
		}
	}
	while(q.size() != 0)
	{
		pair <int, int>  v= q.front();
		q.pop();
		int x = v.first;
		int y = v.second;
		if(x > 0 && !used[x - 1][y])
		{
			used[x - 1][y] = true;
			q.push({x - 1, y});
			dist[x - 1][y] = dist[x][y] + 1;
			p[x - 1][y] = p[x][y];
		}
		if(y > 0 && !used[x][y - 1])
		{
			used[x][y - 1] = true;
			q.push({x, y - 1});
			dist[x][y - 1] = dist[x][y] + 1;
			p[x][y - 1] = p[x][y];
		}
		if(x < n - 1 && !used[x + 1][y])
		{
			used[x + 1][y] = true;
			q.push({x + 1, y});
			dist[x + 1][y] = dist[x][y] + 1;
			p[x + 1][y] = p[x][y];
		}
		if(y < m - 1 && !used[x][y + 1])
		{
			used[x][y + 1] = true;
			q.push({x, y + 1});
			dist[x][y + 1] = dist[x][y] + 1;
			p[x][y + 1] = p[x][y];
		}
	}
	while(t--)
	{
		int i, j, ptime;
		cin >> i >> j >> ptime;
		i--;
		j--;
		if(dist[i][j] > ptime)
		{
			cout << A[i][j] << "\n";
		}
		else
		{
			int x = p[i][j].first;
			int y = p[i][j].second;
			int w = A[x][y] - '0';
			w = w ^ (ptime % 2);
			cout << w << "\n";
			
		}
	}
    return 0;
}