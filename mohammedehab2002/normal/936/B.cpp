#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
vector<int> v[200005],v2[200005];
bool vis[200005][2],vis2[200005];
int par[200005][2],cnt[200005];
int go(int node,int turn)
{
	if (par[node][turn])
	go(par[node][turn],!turn);
	printf("%d ",node);
}
stack<int> s;
void go(int node)
{
	vis2[node]=1;
	for (int i=0;i<v[node].size();i++)
	{
		if (!vis2[v[node][i]])
		go(v[node][i]);
	}
	s.push(node);
}
int call;
void go2(int node)
{
	vis2[node]=1;
	cnt[call]++;
	for (int i=0;i<v2[node].size();i++)
	{
		if (!vis2[v2[node][i]])
		go2(v2[node][i]);
	}
}
bool ok(int node)
{
	if (vis2[node])
	return 0;
	vis2[node]=1;
	if (cnt[node]>1)
	return 1;
	bool ans=0;
	for (int i=0;i<v[node].size();i++)
	ans|=ok(v[node][i]);
	return ans;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		while (x--)
		{
			int a;
			scanf("%d",&a);
			v[i].push_back(a);
			v2[a].push_back(i);
		}
	}
	int st;
	scanf("%d",&st);
	queue<pair<int,int> > q;
	q.push({st,0});
	vis[st][0]=1;
	while (!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
		for (int i=0;i<v[p.first].size();i++)
		{
			if (!vis[v[p.first][i]][!p.second])
			{
				q.push({v[p.first][i],!p.second});
				par[v[p.first][i]][!p.second]=p.first;
				vis[v[p.first][i]][!p.second]=1;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (vis[i][1] && v[i].empty())
		{
			puts("Win");
			go(i,1);
			return 0;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis2[i])
		go(i);
	}
	memset(vis2,0,sizeof(vis2));
	while (!s.empty())
	{
		call=s.top();
		s.pop();
		if (!vis2[call])
		go2(call);
	}
	memset(vis2,0,sizeof(vis2));
	if (ok(st))
	puts("Draw");
	else
	puts("Lose");
}