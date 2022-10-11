#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
#define MX 300000
int dist[MX+5],lp[MX+5],u[MX+5],c[MX+5],cnt[MX+5];
vector<int> v[MX+5];
bool check(int a,int b)
{
	long long tmp=0;
	for (int d:v[a])
	{
		if (b>MX/d)
		continue;
		tmp+=u[d]*cnt[b*d];
	}
	return (tmp>0);
}
int main()
{
	int n;
	scanf("%d",&n);
	queue<int> q;
	memset(dist,-1,sizeof(dist));
	while (n--)
	{
		int a;
		scanf("%d",&a);
		c[a]++;
		if (dist[a]==-1)
		q.push(a);
		dist[a]=1;
	}
	u[1]=1;
	for (int i=1;i<=MX;i++)
	{
		for (int j=i;j<=MX;j+=i)
		{
			if (i!=1 && !lp[j])
			lp[j]=i;
			v[j].push_back(i);
			cnt[i]+=c[j];
		}
		if (i==1)
		u[i]=1;
		else if (lp[i]==lp[i/lp[i]])
		u[i]=0;
		else
		u[i]=-u[i/lp[i]];
	}
	while (!q.empty())
	{
		int i=q.front();
		q.pop();
		for (int j:v[i])
		{
			if (dist[j]==-1 && check(i,j))
			{
				q.push(j);
				dist[j]=dist[i]+1;
			}
		}
	}
	printf("%d",dist[1]);
}