#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int CONST = 1e9 + 7;
signed main () {
	int n , m, p;
	cin >> n >> m >> p;
	vector <int> s(p);
	for(int i = 0; i < p; i++)
	{
		cin >> s[i];
	}
	vector <vector <int> > used(n, vector <int> (m));
	vector <queue <pair <int, int> > > pos(p);
	vector <vector <int> > d(n, vector <int> (m, 1e9));
	vector <int> ans(p);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			char t;
			cin >> t;
			if(t >= '0' && t <= '9')
			{
				d[i][j] = 0;
				ans[t - '0' - 1]++;
				pos[t - '0' - 1].push({i, j});
				used[i][j] = t - '0';
			}
			else if(t == '#')
			{
				used[i][j] = -2;
			}
			else
			{
				used[i][j] = 0;
			}
		}
	}
	while(true)
	{
		bool flag = false;
		for(int i = 0; i < p; i++)
		{
			queue <pair <int, int> > E;
			while(!pos[i].empty())
			{
				pair <int, int> t = pos[i].front();
				pos[i].pop();
				if(d[t.first][t.second] == s[i])
				{
					d[t.first][t.second] = 0;
					E.push(t);
					continue;
				}
				if(t.first > 0 && used[t.first - 1][t.second] == 0)
				{
					flag = true;
					d[t.first - 1][t.second] = d[t.first][t.second] + 1;
					used[t.first - 1][t.second] = i + 1;
					ans[i]++;
					pos[i].push({t.first - 1, t.second});
				}
				if(t.second > 0 && used[t.first][t.second - 1] == 0)
				{
					flag = true;
					d[t.first][t.second - 1] = d[t.first][t.second] + 1;
					used[t.first][t.second - 1] = i + 1;
					pos[i].push({t.first, t.second - 1});
					ans[i]++;
				}
				if(t.first + 1 < n && used[t.first + 1][t.second] == 0)
				{
					flag = true;
					d[t.first + 1][t.second] = d[t.first][t.second] + 1;
					used[t.first + 1][t.second] = i + 1;
					pos[i].push({t.first + 1, t.second});
					ans[i]++;
				}
				if(t.second + 1 < m && used[t.first][t.second + 1] == 0)
				{
					flag = true;
					d[t.first][t.second + 1] = d[t.first][t.second] + 1;
					used[t.first][t.second + 1] = i + 1;
					pos[i].push({t.first, t.second + 1});
					ans[i]++;
				}
			}
			pos[i] = E;
		}
		if(!flag)
		{
			break;
		}
	}
	for(int i = 0; i < p; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}