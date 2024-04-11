#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <int> h(n * m + 1), v(m * n + 1);
	vector <vector <int> > A(n, vector <int> (m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> A[i][j];
		}
	}
	for(int i = 0; i < n; i++)
	{
		int a = 0;
		for(int j = 0; j < m; j++)
		{
			a = max(a, A[i][j]);
		}
		h[a] = 1;
	}
	for(int j = 0; j < m; j++)
	{
		int a = 0;
		for(int i = 0; i < n; i++)
		{
			a = max(a, A[i][j]);
		}
		v[a] = 1;
	}
	vector <vector <int> > ans(n, vector <int> (m));
	int x = -1, y = -1;
	queue <pair <int, int> > q;
	for(int i = n * m; i >= 1; i--)
	{
		x += h[i];
		y += v[i];
		if(h[i] || v[i])
		{
			ans[x][y] = i;
		}
		else
		{
			pair <int, int> v = q.front();
			q.pop();
			ans[v.first][v.second] = i;
		}
		if(h[i])
		{
			for(int j = y - 1; j >= 0; j--)
			{
				q.push({x, j});
			}
		}
		if(v[i])
		{
			for(int j = x - 1; j >= 0; j--)
			{
				q.push({j, y});
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
  	return 0;
}