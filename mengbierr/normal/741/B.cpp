#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
queue<int> q;
vector<int> vw[1005],vb[1005];
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f;
}
struct node
{
	int from;
	int to;
	int next;
}edge[1000005];
int tot,cnt,head[1005],n,k,m,w[1005],b[1005],f[1005][1005];
int w1[1005],b1[1005];bool vis[1005];
void add(int u,int v)
{
	edge[tot].from=u;
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
void bfs()
{
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		w1[cnt]+=w[x];b1[cnt]+=b[x];
		vw[cnt].push_back(w[x]);
		vb[cnt].push_back(b[x]);
		for(int i=head[x];i!=-1;i=edge[i].next)
		{
			if(!vis[edge[i].to])
			{
				q.push(edge[i].to);
				vis[edge[i].to]=1;
			}
		}
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	n=read();k=read();m=read();
	for(int i=1;i<=n;i++) w[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	for(int i=1;i<=k;i++)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cnt++;
			q.push(i);
			vis[i]=1;
			bfs();
			vw[cnt].push_back(w1[cnt]);
			vb[cnt].push_back(b1[cnt]);
		}
	}
	//cout<<cnt;
	for(int i=1;i<=cnt;i++)
	{
		for(int l=0;l<=m;l++)
		{
			f[i][l]=f[i-1][l];
		}
		//cout<<vw[i].size()<<" ";
		for(int j=0;j<vw[i].size();j++)
		{
			//cout<<vw[i][j]<<" "<<vb[i][j]<<endl;
			for(int l=0;l<=m;l++)
			{
				if(l>=vw[i][j])
				f[i][l]=max(f[i][l],f[i-1][l-vw[i][j]]+vb[i][j]);
			}
		}
	}
	/*for(int i=1;i<=cnt;i++)
	{
		for(int j=0;j<=m;j++)
		printf("%d ",f[i][j]);
		printf("\n");
	}*/
	int ans=0;
	for(int j=0;j<=m;j++)
	{
		ans=max(ans,f[cnt][j]);
	}
	cout<<ans;
}