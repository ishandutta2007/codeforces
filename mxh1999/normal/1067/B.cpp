#include<bits/stdc++.h>
using namespace std;

const int maxn=100010;
struct Edge
{
	int v,next;
}	e[maxn<<1];
int g[maxn],tot;
int n,k;
int du[maxn],zha[maxn];
int que[2][maxn];
int vis[maxn];
int cnt1;
void addedge(int x,int y)
{
	du[x]++;
	tot++;
	e[tot].v=y;
	e[tot].next=g[x];
	g[x]=tot;
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	for (int i=1;i<=n;i++)
		if (du[i]==1)
		{
			que[0][++cnt1]=i;
			vis[i]=1;
		}
	for (int _=0;_<=k;_++)
	{
		int cnt2=0;
		if (_==k && cnt1==1)
		{
			printf("Yes\n");
			return 0;
		}
		if (cnt1==0)
		{
			printf("No\n");
			return 0;
		}
		for (int i=1;i<=cnt1;i++)
			vis[que[_&1][i]]=2;
		for (int i=1;i<=cnt1;i++)
		{
			int u=que[_&1][i];
			bool boom=false;
			for (int j=g[u];j;j=e[j].next)
			{
				if (vis[e[j].v]==1)
				{
					zha[e[j].v]++;
					boom=true;
					break;
				}
				if (vis[e[j].v]==0)
				{
					zha[e[j].v]++;
					que[_&1^1][++cnt2]=e[j].v;
					vis[e[j].v]=1;
					boom=true;
					break;
				}
			}
			if (!boom)
			{
				printf("No\n");
				return 0;
			}
		}
		for (int i=1;i<=cnt2;i++)
		{
			int u=que[_&1^1][i];
			du[u]-=zha[u];
			if (zha[u]<3)
			{
				printf("No\n");
				return 0;
			}
			if (du[u]>1)
			{
				printf("No\n");
				return 0;
			}
		}
		swap(cnt1,cnt2);
	}
	printf("No\n");
	return 0;
}