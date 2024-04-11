#include<bits/stdc++.h>
using namespace std;
const int maxn=310;
const int maxm=2100000;
struct que
{
	int x,y,c;
}q[maxm],t[maxm];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ha[maxn][maxn];
int fa[maxn*maxn];
int mp[maxn][maxn];
int ans[maxm];
int n,m,Q;
int find(int x)
{
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void mer(int a,int b)
{
	a=find(a),b=find(b);
	if(a==b) return;
	fa[a]=b;
	return;
}
void updata(int x,int y,int id,int op)
{
	int de=1;
	fa[ha[x][y]]=ha[x][y];
	for(int i=0;i<=3;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(mp[nx][ny]==mp[x][y])
		{
			if(find(ha[x][y])==find(ha[nx][ny])) continue;
			mer(ha[x][y],ha[nx][ny]);
			de--;
		}
	}
	ans[id]+=de*op;
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n+1;i++) mp[i][0]=mp[i][m+1]=-1;
	for(int i=0;i<=m+1;i++) mp[0][i]=mp[n+1][i]=-1;
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ha[i][j]=++tot;
		}
	}
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++) scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].c);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) fa[ha[i][j]]=1;
	for(int i=1;i<=Q;i++)
	{
		int x=q[i].x,y=q[i].y;
		t[i].x=x,t[i].y=y,t[i].c=mp[x][y];
		if(q[i].c==mp[x][y]) continue;
		mp[x][y]=q[i].c;
		updata(x,y,i,1);
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) fa[ha[i][j]]=ha[i][j];
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=m;y++)
		{
			for(int k=0;k<=3;k++)
			{
				int nx=x+dx[k],ny=y+dy[k];
				if(mp[x][y]!=mp[nx][ny]) continue;
				mer(ha[x][y],ha[nx][ny]);
			}
		}
	}
	for(int i=Q;i>=1;i--)
	{
		int x=t[i].x,y=t[i].y;
		if(t[i].c==mp[x][y]) continue;
		mp[x][y]=t[i].c;
		updata(x,y,i,-1);
	}
	ans[0]=1;
	for(int i=1;i<=Q;i++) ans[i]+=ans[i-1];
	for(int i=1;i<=Q;i++) printf("%d\n",ans[i]);
	return 0;
}