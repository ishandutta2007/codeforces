#include <bits/stdc++.h>
using namespace std;
vector<int> v[200005];
int dist[2][200005],p[200005];
void calc(int s,int i)
{
	queue<int> q;
	q.push(s);
	dist[i][s]=0;
	while (!q.empty())
	{
		int node=q.front();
		q.pop();
		for (int u:v[node])
		{
			if (dist[i][u]==-1)
			{
				dist[i][u]=dist[i][node]+1;
				q.push(u);
			}
		}
	}
}
bool cmp(int a,int b)
{
	return dist[0][a]<dist[0][b];
}
int main()
{
	int n,m,k,ans=0,f=-1e9;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<k;i++)
	scanf("%d",&p[i]);
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(dist,-1,sizeof(dist));
	calc(1,0);
	calc(n,1);
	sort(p,p+k,cmp);
	for (int i=k-1;i>=0;i--)
	{
		ans=max(ans,min(dist[0][n],dist[0][p[i]]+f+1));
		f=max(f,dist[1][p[i]]);
	}
	printf("%d",ans);
}