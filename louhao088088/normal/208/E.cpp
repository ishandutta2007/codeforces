#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
inline int read()
{
	char ch=getchar();int x=0;bool f=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
struct node 
{
	int v,nex;
}e[maxn*2];
struct query
{
	int x,y,id;
}q[maxn];
char b[maxn];
int n,m,x,a[maxn],head[maxn],s[maxn],son[maxn],y,ans[maxn],Max=0,cnt,c[maxn],in[maxn],d[maxn],idx=0,j=1,f[maxn][19];
void add(int x,int y){e[++cnt].v=y;e[cnt].nex=head[x];head[x]=cnt;}
bool check(int x){while(x%2==0&&x)x=x/2;if(x>1)return 0;return 1;}
void dfs(int x,int fa)
{
	int p=0;s[x]=1;d[x]=d[fa]+1;f[x][0]=fa;
	for(int i=1;i<=18;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;if(v==fa)continue;
		dfs(v,x);s[x]+=s[v];if(s[v]>p)p=s[v],son[x]=v;
	}
}
void dfs3(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;if(v==fa||son[x]==v)continue;
		dfs3(v,x);
	}if(son[x])dfs3(son[x],x);in[x]=++idx;
}
void dfs2(int x,int fa)
{
	c[d[x]]++;
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;if(v==fa)continue;
		dfs2(v,x);
	}
}
void del(int x,int fa)
{
	c[d[x]]--;
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;if(v==fa)continue;
		del(v,x);
	}
}
void dfs1(int x,int fa,int num)
{
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;if(v==fa||son[x]==v)continue;
		dfs1(v,x,0);
	}
	if(son[x])dfs1(son[x],x,1);
	c[d[x]]++;
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;if(v==fa||son[x]==v)continue;
		dfs2(v,x); 
	}if(x==n+1)return;
	
	while(j<=m&&q[j].x==x)
	{
		//cout<<x<<" "<<q[j].id<<" "<<j<<" "<<q[j].x<<" "<<c[q[j].x]<<endl;
		ans[q[j].id]=c[q[j].y]-1,j++;
	}
	if(num==0)del(x,fa);
}
bool cmp(query a,query b){return in[a.x]<in[b.x];}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)x=read(),x==0?x=n+1:x=x,add(x,i),add(i,x);
	d[0]=-1;dfs(n+1,0);dfs3(n+1,0);m=read();
	for(int i=1;i<=m;i++)
	{
		x=read();q[i].y=read();y=q[i].y;q[i].y=d[x];
		for(int j=18;j>=0;j--)if(y>=(1<<j))x=f[x][j],y=y-(1<<j);
		q[i].id=i;if(x==0||x==n+1)ans[i]=0;q[i].x=x;
		//cout<<"A"<<q[i].x<<" "<<q[i].y<<endl;
	}in[n+1]=in[0]=1e8;
	sort(q+1,q+m+1,cmp);dfs1(n+1,0,1);
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}