#include <bits/stdc++.h>
using namespace std;

signed main()
{
	int n, m;
	cin >> n >> m;
	vector <vector <char> > A(n, vector <char> (m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> A[i][j];
		}
	}
	set <pair <int, pair <int, int> > > w;
	vector <vector <int> > d(n, vector <int> (m, 1e9));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(A[i][j] == '.')
			{
				w.insert({-1, {i, j}});
				d[i][j] = -1;
			}
			else if(i == 0 || j == 0 || i == n - 1 || j == m - 1)
			{
				w.insert({0, {i, j}});
				d[i][j] = 0;
			}
		}
	}
	while(w.size() > 0)
	{
		pair <int, int> v = w.begin() -> second;
		w.erase(w.begin());
		int x = v.first;
		int y = v.second;
		if(x > 0 && d[x - 1][y] > d[x][y] + 1)
		{
			w.erase({d[x - 1][y], {x - 1, y}});
			d[x - 1][y] = d[x][y] + 1;
			w.insert({d[x][y], {x, y}});
		}
		if(y > 0 && d[x][y - 1] > d[x][y] + 1)
		{
			w.erase({d[x][y - 1], {x, y - 1}});
			d[x][y - 1] = d[x][y] + 1;
			w.insert({d[x][y], {x, y - 1}});
		}
		if(x < n - 1 && d[x + 1][y] > d[x][y] + 1)
		{
			w.erase({d[x + 1][y], {x + 1, y}});
			d[x + 1][y] = d[x][y] + 1;
			w.insert({d[x + 1][y], {x + 1, y}});
		}
		if(y < m - 1 && d[x][y + 1] > d[x][y] + 1)
		{
			w.erase({d[x][y + 1], {x, y + 1}});
			d[x][y + 1] = d[x][y] + 1;
			w.insert({d[x][y + 1], {x, y + 1}});
		}
		if(x > 0 && y > 0 && d[x - 1][y - 1] > d[x][y] + 1)
		{
			w.erase({d[x - 1][y - 1], {x - 1, y - 1}});
			d[x - 1][y - 1] = d[x][y] + 1;
			w.insert({d[x - 1][y - 1], {x - 1, y - 1}});
		}
		if(x > 0 && y < m - 1 && d[x - 1][y + 1] > d[x][y] + 1)
		{
			w.erase({d[x - 1][y + 1], {x - 1, y + 1}});
			d[x - 1][y + 1] = d[x][y] + 1;
			w.insert({d[x - 1][y + 1], {x - 1, y + 1}});
		}
		if(x < n - 1 && y > 0 && d[x + 1][y - 1] > d[x][y] + 1)
		{
			w.erase({d[x + 1][y - 1], {x + 1, y - 1}});
			d[x + 1][y - 1] = d[x][y] + 1;
			w.insert({d[x + 1][y - 1], {x + 1, y - 1}});
		}
		if(x < n - 1 && y < m - 1 && d[x + 1][y + 1] > d[x][y] + 1)
		{
			w.erase({d[x + 1][y + 1], {x + 1, y + 1}});
			d[x + 1][y + 1] = d[x][y] + 1;
			w.insert({d[x + 1][y + 1], {x + 1, y + 1}});
		}
	}
	int maxh = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			maxh = max(maxh, d[i][j]);
		}
	}
	int l = 0, r = maxh + 1;
	vector <vector <bool> > used(n, vector <bool> (m, false));
	vector <vector <int> > d1(n, vector <int> (m, 0));
	while(r - l > 1)
	{
		int midd = (r + l) / 2;
		queue <pair<int, int> > Q;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				used[i][j] = false;
				d1[i][j] = 1e9;
				if(d[i][j] >= midd)
				{
					d1[i][j] = 0;
					Q.push({i, j});
					used[i][j] = true;
				}
			}
		}
		while(!Q.empty())
		{
			pair <int, int> v = Q.front();
			Q.pop();
			if(v.first > 0 && !used[v.first - 1][v.second] && A[v.first - 1][v.second] == 'X')
			{
				Q.push({v.first - 1, v.second});
				d1[v.first - 1][v.second] = d1[v.first][v.second] +1;
				used[v.first - 1][v.second] = true; 
			}
			if(v.second > 0 && !used[v.first][v.second - 1] && A[v.first][v.second - 1] == 'X')
			{
				Q.push({v.first, v.second - 1});
				d1[v.first][v.second - 1] = d1[v.first][v.second] + 1;
				used[v.first][v.second - 1] = true;
			}
			if(v.first < n - 1 && !used[v.first + 1][v.second] && A[v.first + 1][v.second] == 'X')
			{
				Q.push({v.first + 1, v.second});
				d1[v.first + 1][v.second] = d1[v.first][v.second] + 1;
				used[v.first + 1][v.second] = true;
			}
			if(v.second < m - 1 && !used[v.first][v.second + 1] && A[v.first][v.second + 1] == 'X')
			{
				Q.push({v.first, v.second + 1});
				d1[v.first][v.second + 1] = d1[v.first][v.second] + 1;
				used[v.first][v.second + 1] = true;
			}
			if(v.first > 0 && v.second > 0 && !used[v.first - 1][v.second - 1] && A[v.first - 1][v.second - 1] == 'X')
			{
				Q.push({v.first - 1, v.second - 1});
				used[v.first - 1][v.second - 1] = true;
				d1[v.first - 1][v.second - 1] = d1[v.first][v.second] + 1;
			}
			if(v.first > 0 && v.second < m - 1 && !used[v.first - 1][v.second + 1] && A[v.first - 1][v.second + 1] == 'X')
			{
				Q.push({v.first - 1, v.second + 1});
				used[v.first - 1][v.second + 1] = true;
				d1[v.first - 1][v.second + 1] = d1[v.first][v.second] + 1;
			}
			if(v.first < n - 1 && v.second > 0 && !used[v.first + 1][v.second - 1] && A[v.first + 1][v.second - 1] == 'X')
			{
				used[v.first + 1][v.second - 1] = true;
				d1[v.first + 1][v.second - 1] = d1[v.first][v.second] + 1;
				Q.push({v.first + 1, v.second - 1});
			}
			if(v.first < n - 1 && v.second < m - 1 && !used[v.first + 1][v.second + 1] && A[v.first + 1][v.second + 1] == 'X')
			{
				used[v.first + 1][v.second + 1] = true;
				d1[v.first + 1][v.second + 1] = d1[v.first][v.second + 1];
				Q.push({v.first + 1, v.second + 1});
			}
			
		}
		bool lag = true;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if((!used[i][j] || d1[i][j] > midd) && A[i][j] == 'X')
				{
					lag = false;
				}
			}
		}
		if(!lag)
		{
			r = midd;
		}
		else
		{
			l = midd;
		}
	}
	cout << l << "\n";
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(d[i][j] >= l)
			{
				cout << "X";
			}
			else
			{
				cout << ".";
			}
		}
		cout << "\n";
	}
	return 0;
}