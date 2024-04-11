#include<bits/stdc++.h>
using namespace std;
vector <int> used1;
vector <vector <int> > g;
void dfs(int v)
{
	used1[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(used1[g[v][i]] == 1)
		{
			cout << "Draw";
			exit(0);
		}
		dfs(g[v][i]);
	}
	used1[v] = 2;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	g.resize(n);
	used1.resize(n);
	for(int i = 0; i < n; i++)
	{
		int z;
		cin >> z;
		for(int j = 0; j < z; j++)
		{
			int to;
			cin >> to;
			to--;
			g[i].push_back(to);
		}
	}
	int st;
	cin >> st;
	st--;
	vector <vector <int> > pred(n, vector <int> (2, -1));
	vector <vector <bool> > used(n, vector <bool> (2));
	queue <pair <int, int> > Q;
	Q.push({st, 0});
	while(Q.size() != 0)
	{
		pair <int, int> v = Q.front();
		Q.pop();
		int col = v.second;
		for(int i = 0; i < g[v.first].size(); i++)
		{
			int to = g[v.first][i];
			if(!used[to][1 - col])
			{
				Q.push({to, 1 - col});
				pred[to][1 - col] = v.first;
				used[to][1 - col] = true;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(g[i].size() == 0 && used[i][1])
		{
			cout << "Win\n";
			int nxt = i, col = 1;
			stack <int> s;
			while(nxt != st || col != 0)
			{
				s.push(nxt);
				nxt = pred[nxt][col];
				col = 1 - col;
			}
			s.push(nxt);
			while(s.size() > 0)
			{
				cout << s.top() + 1 << " ";
				s.pop();
			}
			return 0;	
		}
	}
	dfs(st);
	cout << "Lose";
    return 0;
}