#include <bits/stdc++.h>
using namespace std;
vector <int> A;
vector <vector <pair <int, int> > > g;
vector <vector <int> > can;
vector <int> was;
vector <int> mt;
int n, m;
bool dfs(int v, int count)
{
	if(was[v] == count){
		return false;
	}
	was[v] = count;
	for(int i = 0; i < can.size(); i++){
		if(can[v][i])
		{
			if(mt[i] == -1 || dfs(mt[i], count))
			{
				mt[i] = v;
				return true;
			}
		}
	}
	return false;
}
int maxpar()
{
	int rezult = 0;
	int cnt = 0;
	for(int i = 0; i < n; i += 2)
	{
		for(int j = 0; j < g[i].size(); j++)
		{
			if(dfs(cnt + j, cnt + j + 1))
			{
				rezult++;
			}
		}
		cnt += g[i].size() + g[i + 1].size();
	}
	return rezult;
}
signed main() {
	cin >> n >> m;
	g.resize(n);
	A.resize(n);
	int cnt = 1;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		int tmp = A[i];
		for(int j = 2; j * j <= A[i]; j++)
		{
			while(tmp % j == 0)
			{
				tmp /= j;
				g[i].push_back({j, cnt});
				cnt++;
			}
		}
		if(tmp > 1)
		{
			g[i].push_back({tmp, cnt});
			cnt++;
		}
	}
	was.resize(cnt);
	mt.resize(cnt, -1);
	can.resize(cnt, vector <int> (cnt));
	while(m--)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		for(int i =0; i < g[x].size(); i++)
		{
			for(int j = 0; j < g[y].size(); j++)
			{
				if(g[x][i].first == g[y][j].first)
				{
					can[g[y][j].second - 1][g[x][i].second- 1] = 1;
					can[g[x][i].second - 1][g[y][j].second - 1] = 1;
				}
			}
		}
	}
	cout << maxpar();
	return 0;
}