#include<bits/stdc++.h>
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
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
	vector <vector <bool> > used(n, vector <bool> (m));
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(used[i][j])
			{
				continue;
			}
			if(A[i][j] == '.')
			{
				continue;
			}
			ans++;
			queue <pair <int, int> > q;
			q.push({i, j});
			used[i][j] = true;
			while(q.size() != 0)
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				if(x > 0 && !used[x - 1][y] && A[x - 1][y] == '#')
				{
					q.push({x - 1, y});
					used[x - 1][y] = true;
				}
				if(x < n - 1 && !used[x + 1][y] && A[x + 1][y] == '#')
				{
					q.push({x + 1, y});
					used[x + 1][y] = true;
				}
				if(y > 0 && !used[x][y - 1] && A[x][y - 1] == '#')
				{
					q.push({x, y - 1});
					used[x][y - 1] = true;
				}
				if(y < m - 1 && !used[x][y+ 1] && A[x][y + 1] == '#')
				{
					q.push({x, y + 1});
					used[x][y + 1] = true;
				}
			}
		}
	}
	bool fl1 = false, fl2 = false;
	bool flag = true;
	for(int i = 0; i < n; i++)
	{
		int cnt = 0;
		for(int j = 0; j < m; j++)
		{
			if(A[i][j] == '.'){
				continue;
			}
			if(j == 0 || A[i][j - 1] == '.')
			{
				cnt++;
			}
		}
		if(cnt > 1)
		{
			flag = false;
		}
		if(cnt == 0)
		{
			fl1 = true;
		}
	}
	for(int j = 0; j < m; j++)
	{
		int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			if(A[i][j] == '.')
			{
				continue;
			}
			if(i == 0 || A[i - 1][j] == '.')
			{
				cnt++;
			}
		}
		if(cnt == 0)
		{
			fl2 = true;
		}
		if(cnt > 1)
		{
			flag = false;
		}
	}
	if(fl1 ^ fl2)
	{
		flag = false;
	}
	if(!flag)
	{
		ans = -1;
	}
	cout << ans;
	return 0;
}