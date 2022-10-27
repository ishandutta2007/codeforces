#include<bits/stdc++.h>
using namespace std;
 
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <vector <char> > a(n, vector <char> (m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	vector <vector <int> > dist1(n, vector <int> (m, 1e8)),
	dist2(n, vector <int> (m, 1e8)), dist3(n, vector <int> (m, 1e8));
	queue <pair <int, int> > q1, q2 ,q3;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(a[i][j] == '1')
			{
				q1.push({i, j});
				dist1[i][j] = 0;
			}
			else if(a[i][j] == '2')
			{
				q2.push({i, j});
				dist2[i][j] = 0;
			}
			else if(a[i][j] == '3')
			{
				q3.push({i, j});
				dist3[i][j] = 0;
			}
		}
	}
	int ans = 1e8;
	int min12 = 1e8, min23 = 1e8, min13 = 1e8;
	while(q1.size() != 0)
	{
		pair <int, int> v = q1.front();
		q1.pop();
		if(v.first > 0 && dist1[v.first - 1][v.second] == 1e8 && a[v.first - 1][v.second] != '#')
		{
			if(a[v.first - 1][v.second] == '.')
			{
			q1.push({v.first - 1, v.second});
				dist1[v.first - 1][v.second] = dist1[v.first][v.second] + 1;
			}
			else
			{
				dist1[v.first - 1][v.second] = dist1[v.first][v.second];
			}
		}
		if(v.first <n - 1 && dist1[v.first + 1][v.second] == 1e8 && a[v.first + 1][v.second] != '#')
		{
			if(a[v.first + 1][v.second] == '.')
			{
			q1.push({v.first + 1, v.second});
				dist1[v.first + 1][v.second] = dist1[v.first][v.second] + 1;
			}
			else
			{
				dist1[v.first + 1][v.second] = dist1[v.first][v.second];
			}
		}
		if(v.second > 0 && dist1[v.first][v.second - 1] == 1e8 && a[v.first][v.second - 1] != '#')
		{
			if(a[v.first][v.second - 1] == '.')
			{
			q1.push({v.first, v.second - 1});
				dist1[v.first][v.second - 1] = dist1[v.first][v.second] + 1;
			}
			else
			{
				dist1[v.first][v.second - 1] = dist1[v.first][v.second];
			}
		}
		if(v.second < m - 1 && dist1[v.first][v.second + 1] == 1e8 && a[v.first][v.second + 1] != '#')
		{
			if(a[v.first][v.second + 1] == '.')
			{
			q1.push({v.first, v.second + 1});
				dist1[v.first][v.second + 1] = dist1[v.first][v.second] + 1;
			}
			else
			{
				dist1[v.first][v.second + 1] = dist1[v.first][v.second];
			}
		}
	}
	while(q2.size() != 0)
	{
		pair <int, int> v = q2.front();
		q2.pop();
		if(v.first > 0 && dist2[v.first - 1][v.second] == 1e8 && a[v.first - 1][v.second] != '#')
		{
			if(a[v.first - 1][v.second] == '.')
			{
			q2.push({v.first - 1, v.second});
				dist2[v.first - 1][v.second] = dist2[v.first][v.second] + 1;
			}
			else
			{
				dist2[v.first - 1][v.second] = dist2[v.first][v.second];
			}
		}
		if(v.first <n - 1 && dist2[v.first + 1][v.second] == 1e8 && a[v.first + 1][v.second] != '#')
		{
			if(a[v.first + 1][v.second] == '.')
			{
			q2.push({v.first + 1, v.second});
				dist2[v.first + 1][v.second] = dist2[v.first][v.second] + 1;
			}
			else
			{
				dist2[v.first + 1][v.second] = dist2[v.first][v.second];
			}
		}
		if(v.second > 0 && dist2[v.first][v.second - 1] == 1e8 && a[v.first][v.second - 1] != '#')
		{
			if(a[v.first][v.second - 1] == '.')
			{
			q2.push({v.first, v.second - 1});
				dist2[v.first][v.second - 1] = dist2[v.first][v.second] + 1;
			}
			else
			{
				dist2[v.first][v.second - 1] = dist2[v.first][v.second];
			}
		}
		if(v.second < m - 1 && dist2[v.first][v.second + 1] == 1e8 && a[v.first][v.second + 1] != '#')
		{
			if(a[v.first][v.second + 1] == '.')
			{
			q2.push({v.first, v.second + 1});
				dist2[v.first][v.second + 1] = dist2[v.first][v.second] + 1;
			}
			else
			{
				dist2[v.first][v.second + 1] = dist2[v.first][v.second];
			}
		}
	}
	while(q3.size() != 0)
	{
		pair <int, int> v = q3.front();
		q3.pop();
		if(v.first > 0 && dist3[v.first - 1][v.second] == 1e8 && a[v.first - 1][v.second] != '#')
		{
			if(a[v.first - 1][v.second] == '.')
			{
			q3.push({v.first - 1, v.second});
				dist3[v.first - 1][v.second] = dist3[v.first][v.second] + 1;
			}
			else
			{
				dist3[v.first - 1][v.second] = dist3[v.first][v.second];
			}
		}
		if(v.first <n - 1 && dist3[v.first + 1][v.second] == 1e8 && a[v.first + 1][v.second] != '#')
		{
			if(a[v.first + 1][v.second] == '.')
			{
			q3.push({v.first + 1, v.second});
				dist3[v.first + 1][v.second] = dist3[v.first][v.second] + 1;
			}
			else
			{
				dist3[v.first + 1][v.second] = dist3[v.first][v.second];
			}
		}
		if(v.second > 0 && dist3[v.first][v.second - 1] == 1e8 && a[v.first][v.second - 1] != '#')
		{
			if(a[v.first][v.second - 1] == '.')
			{
			q3.push({v.first, v.second - 1});
				dist3[v.first][v.second - 1] = dist3[v.first][v.second] + 1;
			}
			else
			{
				dist3[v.first][v.second - 1] = dist3[v.first][v.second];
			}
		}
		if(v.second < m - 1 && dist3[v.first][v.second + 1] == 1e8 && a[v.first][v.second + 1] != '#')
		{
			if(a[v.first][v.second + 1] == '.')
			{
			q3.push({v.first, v.second + 1});
				dist3[v.first][v.second + 1] = dist3[v.first][v.second] + 1;
			}
			else
			{
				dist3[v.first][v.second + 1] = dist3[v.first][v.second];
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(a[i][j] == '1')
			{
				min12 = min(min12, dist2[i][j]);
			}
			else if(a[i][j] == '2')
			{
				min23 = min(min23, dist3[i][j]);
			}
			else if(a[i][j] == '3')
			{
				min13 = min(min13, dist1[i][j]);
			}
			int k = dist1[i][j] + dist2[i][j] + dist3[i][j];
			if(a[i][j] == '.')
			{
				k -= 2;
			}
			ans = min(ans, k);
		}
	}
	ans = min(ans, min12 + min23);
	ans = min(ans, min23 + min13);
	ans = min(ans, min12 + min13);
	if(ans > 1e7)
	{
		cout << -1;
		return 0;
	}
	cout << ans;
	return 0;
}