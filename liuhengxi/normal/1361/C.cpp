#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5,M=(1<<20)+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int next,to;
}e[2*N];
int n,u[2*N],v[2*N],ans,deg[M],fa[M],p[2*N],hd[M],cnt,uu[N],vv[N],nex[2*N],pre[2*N];
int head,tail;
bool vis[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
bool check(int k)
{
	int kk=1<<k;
	if(k==21)return false;
	F(i,0,kk)deg[i]=0,fa[i]=i;
	--kk;
	F(i,0,n)
	{
		++deg[uu[i]=u[i]&kk];
		++deg[vv[i]=v[i]&kk];
	}
	F(i,0,1<<k)if(deg[i]&1)return false;
	F(i,0,n)fa[find(uu[i])]=find(vv[i]);
	F(i,1,n)if(find(uu[0])!=find(uu[i]))return false;
	return true;
}
void insert(int u,int v)// insert u after v
{
	pre[nex[u]=nex[v]]=u;
	pre[nex[v]=u]=v;
}
#ifdef ZKYAKIOI
void printlist()
{
	for(int i=nex[head];i!=tail;i=nex[i])printf("%d ",i);
	puts("");
}
#endif
void dfs(int u,int pos)
{
	for(int &i=hd[u];~i;)
	{
		int v=e[i].to,ii=i<n?i:i-n;
		if(vis[ii]){i=e[i].next;continue;}
		vis[ii]=true;
		insert(ii=i,pos);
		i=e[i].next;
		dfs(v,ii);
	}
}
void construct(int k)
{
	int kk=1<<k;
	head=2*n,tail=2*n+1;
	F(i,0,kk)hd[i]=-1;
	--kk;
	F(i,0,n)
	{
		u[i+n]=v[i]=v[i]&kk;
		v[i+n]=u[i]=u[i]&kk;
	}
	F(i,0,2*n)adline(u[i],v[i]);
	nex[pre[tail]=head]=tail;
	dfs(u[0],head);
	for(int i=nex[head],j=0;i!=tail;i=nex[i])
	{
		int u,v;
		if(i<n)u=2*i,v=2*i+1;
		else u=2*(i-n)+1,v=2*(i-n);
		p[j++]=u;p[j++]=v;
	}
#ifdef ZKYAKIOI
	for(int i=nex[head];i!=tail;i=nex[i])printf("%d %d ",u[i],v[i]);
	puts("");
#endif
}
int main()
{
	read(n);
	F(i,0,n)read(u[i]),read(v[i]);
	while(check(ans+1))++ans;
	printf("%d\n",ans);
	construct(ans);
	F(i,0,2*n)printf("%d ",++p[i]);
	puts("");
	return 0;
}