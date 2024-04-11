#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int> > v[300005];
vector<int> del;
bool vis[300005],b[300005];
queue<int> q;
int main()
{
	int n,k,d;
	scanf("%d%d%d",&n,&k,&d);
	for (int i=0;i<k;i++)
	{
		int a;
		scanf("%d",&a);
		q.push(a);
		vis[a]=1;
	}
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back({b,i});
		v[b].push_back({a,i});
	}
	while (!q.empty())
	{
		int node=q.front();
		q.pop();
		for (auto u:v[node])
		{
			if (!vis[u.first])
			{
				q.push(u.first);
				vis[u.first]=1;
				b[u.second]=1;
			}
		}
	}
	for (int i=1;i<n;i++)
	{
		if (!b[i])
		del.push_back(i);
	}
	printf("%d\n",del.size());
	for (int i:del)
	printf("%d ",i);
}