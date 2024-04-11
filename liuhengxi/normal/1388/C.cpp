#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
int t,n,m,p[N],h[N],hd[N],cnt,hp[N];
bool ans;
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int f)
{
	for(int i=hd[u],v;~i;i=e[i].next)if((v=e[i].to)!=f)
	{
		dfs(v,u);
		p[u]+=p[v];
	}
}
void dfs2(int u,int f)
{
	int sum=0;
	int t=p[u]-h[u];
	if(t<0)ans=false;
	if(t>2*p[u])ans=false;
	if(t&1)ans=false;
	hp[u]=p[u]-t/2;
	for(int i=hd[u],v;~i;i=e[i].next)if((v=e[i].to)!=f)
	{
		dfs2(v,u);
		sum+=hp[v];
	}
	if(sum>hp[u])ans=false;
}
int main()
{
	read(t);
	while(t--)
	{
		ans=true;
		read(n);read(m);
		F(i,0,n)read(p[i]);
		F(i,0,n)read(h[i]);
		F(i,0,n)hd[i]=-1;
		cnt=0;
		F(i,0,n-1)
		{
			int u,v;read(u);read(v);
			adline(--u,--v);adline(v,u);
		}
		dfs(0,0);
		dfs2(0,0);
		puts(ans?"YES":"NO");
	}
	return 0;
}