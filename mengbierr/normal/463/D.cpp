#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
queue<int> q;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
struct node
{
	int from;
	int to;
	int next;
}edge[1000005];
int n,k,a[1005][7],s[1005][7],tot,head[1005],du[1005],dis[1005];
void add(int u,int v)
{
	edge[tot].from=u;
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
void topsort()
{
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i!=-1;i=edge[i].next)
		{
			dis[edge[i].to]=max(dis[edge[i].to],dis[x]+1);
			du[edge[i].to]--;
			if(!du[edge[i].to])
			q.push(edge[i].to);
		}
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	n=read();k=read();
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[j][i]=read();
			s[a[j][i]][i]=j;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j==i) continue;
			bool ac=1;
			for(int l=1;l<=k;l++)
			{
				if(s[i][l]>s[j][l])
				{
					ac=0;
					break;
				}
			}
			if(ac)
			{
				add(i,j);
				du[j]++;
				//cout<<i<<" "<<j<<endl;
			}
		}
	}
	memset(dis,0,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		if(!du[i])
		{
			q.push(i);
			dis[i]=1;
		}
	}
	topsort();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dis[i]);
	}
	cout<<ans;
}