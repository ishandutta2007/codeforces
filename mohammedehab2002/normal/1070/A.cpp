#include <iostream>
#include <queue>
using namespace std;
bool vis[505][5005];
pair<pair<int,int>,int> par[505][5005];
void go(pair<int,int> s)
{
	if (!s.second)
	return;
	go(par[s.first][s.second].first);
	cout << par[s.first][s.second].second;
}
int main()
{
	int d,s;
	cin >> d >> s;
	queue<pair<int,int> > q;
	q.push({0,0});
	vis[0][0]=1;
	while (!q.empty())
	{
		auto cur=q.front();
		q.pop();
		for (int i=0;i<10;i++)
		{
			int nd=(cur.first*10+i)%d,ns=cur.second+i;
			if (ns<=s && !vis[nd][ns])
			{
				vis[nd][ns]=1;
				par[nd][ns]={cur,i};
				q.push({nd,ns});
			}
		}
	}
	if (!vis[0][s])
	printf("-1");
	else
	go({0,s});
}