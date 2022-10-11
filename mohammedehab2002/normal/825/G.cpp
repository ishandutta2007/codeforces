#include <iostream>
#include <vector>
using namespace std;
vector<int> v[1000005];
int mn[1000005],ans=(1<<30);
void dfs(int node,int p)
{
	mn[node]=min(mn[p],node);
	for (int u:v[node])
	{
		if (u!=p)
		dfs(u,node);
	}
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	mn[0]=(1<<30);
	int last=0,f=1;
	while (q--)
	{
		int t,x;
		scanf("%d%d",&t,&x);
		x=(x+last)%n+1;
		if (f)
		{
			dfs(x,0);
			f=0;
		}
		if (t==1)
		ans=min(ans,mn[x]);
		else
		{
			last=min(ans,mn[x]);
			printf("%d\n",last);
		}
	}
}