#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, dis[110];
vector <pair<int, int> > e[110];

int main()
{
    cin >> n;
	for(int i = 1; i < n; i ++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		e[x].push_back(make_pair(c, y));
		e[y].push_back(make_pair(c, x));
	}
	for (int i = 0; i < n; i ++)
		dis[i] = -1;
	dis[0] = 0;
	queue <int> Q;
	Q.push(0);
	while (!Q.empty())
	{
		int t = Q.front();
		Q.pop();
		for(int i = 0; i < e[t].size(); i ++)
		{
			pair<int, int> now = e[t][i];
			if (dis[now.Y] == -1)
			{
				dis[now.Y] = dis[t] + now.X;
				Q.push(now.Y);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i ++)
		ans = max(ans, dis[i]);
	printf("%d\n", ans);
	return 0;
}