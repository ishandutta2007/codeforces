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
int n,m,a[maxn],head[maxn],s[maxn],son[maxn],x,y,ans[maxn],Max=0,cnt,c[maxn],in[maxn],d[maxn],idx=0,j=1;
void add(int x,int y){e[++cnt].v=y;e[cnt].nex=head[x];head[x]=cnt;}
bool check(int x){while(x%2==0&&x)x=x/2;if(x>1)return 0;return 1;}
void dfs(int x,int fa)
{
	int p=0;s[x]=1;d[x]=d[fa]+1;
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
	c[d[x]]^=a[x];
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;if(v==fa)continue;
		dfs2(v,x);
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
	c[d[x]]^=a[x];
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;if(v==fa||son[x]==v)continue;
		dfs2(v,x); 
	}
	//cout<<j<<" "<<q[j].x<<" "<<x<<endl;
	while(j<=m&&q[j].x==x)
	{
		//cout<<j<<" "<<x<<" "<<q[j].id<<" "<<c[q[j].y]<<endl;
		ans[q[j].id]=check(c[q[j].y]),j++;
	}
	if(num==0)dfs2(x,fa);
}
bool cmp(query a,query b){return in[a.x]<in[b.x];}
signed main()
{
	n=read();m=read();
	for(int i=2;i<=n;i++)x=read(),add(x,i),add(i,x);
	scanf("%s",b+1);
	for(int i=1;i<=n;i++)a[i]=(1<<(b[i]-'a'));
	for(int i=1;i<=m;i++)q[i].x=read(),q[i].y=read(),q[i].id=i;
	dfs(1,0);dfs3(1,0);sort(q+1,q+m+1,cmp);
	//for(int i=1;i<=n;i++)cout<<in[i]<<" "<<endl;
	dfs1(1,0,1);
	for(int i=1;i<=m;i++)ans[i]==1?puts("Yes"):puts("No");
	
	return 0;
}