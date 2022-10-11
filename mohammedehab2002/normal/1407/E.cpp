#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v[500005];
int dist[500005];
bool ex[2][500005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int a,b,t;
		scanf("%d%d%d",&a,&b,&t);
		v[b].push_back({a,t});
	}
	memset(dist,-1,sizeof(dist));
	queue<int> q;
	q.push(n);
	dist[n]=0;
	ex[0][n]=1;
	ex[1][n]=1;
	string ans(n,'0');
	while (!q.empty())
	{
		int node=q.front();
		q.pop();
		for (auto u:v[node])
		{
			if (!ex[u.second][u.first])
			{
				ex[u.second][u.first]=1;
				if (ex[!u.second][u.first])
				{
					q.push(u.first);
					dist[u.first]=dist[node]+1;
					ans[u.first-1]=u.second+'0';
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (dist[i]==-1 && ex[0][i])
		ans[i-1]='1';
	}
	printf("%d\n%s",dist[1],ans.c_str());
}