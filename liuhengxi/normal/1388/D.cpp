#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
int n,a[N],b[N],hd[N],cnt,dfn[N],ind;
long long s[N],ans;
bool ch[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u)
{
	s[u]=a[u];
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		dfs(v);
		if(s[v]>0)
		{
			ch[v]=true;
			s[u]+=s[v];
		}
	}
	ans+=s[u];
}
void dfs2(int u,int ak)
{
	if(ak==1||ak==0)
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		if(ch[v])dfs2(v,1);
	}
	if(ak==1||ak==0)dfn[ind++]=u+1;
	if(ak==2||ak==0)
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		if(ch[v])dfs2(v,2);
		else dfs2(v,0);
	}
}
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	F(i,0,n)read(b[i]);
	F(i,0,n)hd[i]=-1;
	F(i,0,n)if(~b[i])adline(--b[i],i);
	F(i,0,n)if(!~b[i])dfs(i);
	F(i,0,n)if(!~b[i])dfs2(i,0);
	printf("%lld\n",ans);
	F(i,0,n)printf("%d ",dfn[i]);
	printf("\n");
	return 0;
}