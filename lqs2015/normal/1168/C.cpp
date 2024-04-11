#include<bits/stdc++.h>
using namespace std;
int n,q,a[333333],x,y,nxt[333333][172],id[22][22],cnt,dist[22],mn,mnp;
bool used[22],ans;
vector<int> v;
int get(int x,int y)
{
	if (x>y) swap(x,y);
	return id[x][y];
}
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=0;i<=18;i++)
	{
		for (int j=i+1;j<=18;j++)
		{
			id[i][j]=++cnt;
		}
	}
	for (int i=0;i<=18;i++)
	{
		for (int j=i+1;j<=18;j++)
		{
			nxt[n+1][get(i,j)]=n+1;
		}
	}
	for (int i=n;i>=1;i--)
	{
		for (int j=1;j<=cnt;j++)
		{
			nxt[i][j]=nxt[i+1][j];
		}
		for (int j=0;j<=18;j++)
		{
			for (int k=j+1;k<=18;k++)
			{
				if ((a[i]&(1<<j)) && (a[i]&(1<<k))) nxt[i][get(j,k)]=i;
			}
		}
	}
	while(q--)
	{
		scanf("%d%d",&x,&y);
		for (int i=0;i<=18;i++) dist[i]=1e9;
		memset(used,0,sizeof(used));
		for (int i=0;i<=18;i++)
		{
			if (a[x]&(1<<i)) dist[i]=x;
		}
		for (int i=0;i<=18;i++)
		{
			mn=1e9;
			for (int j=0;j<=18;j++)
			{
				if (!used[j] && dist[j]<mn)
				{
					mn=dist[j];
					mnp=j;
				}
			}
			if (mn>=n+1) break;
			used[mnp]=1;
			for (int j=0;j<=18;j++)
			{
				if (!used[j])
				{
					int cur=nxt[dist[mnp]][get(mnp,j)];
					if (cur<dist[j])
					{
						dist[j]=cur;
					}
				}
			}
		}
		ans=0;
		for (int i=0;i<=18;i++)
		{
			if (a[y]&(1<<i))
			{
				if (dist[i]<=y) ans=1; 
			}
		}
		if (ans) printf("Shi\n");
		else printf("Fou\n");
	}
	return 0;
}