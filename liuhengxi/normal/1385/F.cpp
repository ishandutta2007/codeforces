#include<cstdio>
#include<algorithm>
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
int tt,n,k,hd[N],cnt,f[N],siz[N],ans,more[N],is[N],ch[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs1(int u,int fa)
{
	siz[u]=1;f[u]=ch[u]=0;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs1(v,u);
		if((is[v]=(f[v]*k+1==siz[v])))++ch[u];
		f[u]+=f[v];
		siz[u]+=siz[v];
	}
	more[u]=ch[u]%k;
	f[u]+=ch[u]/k;
}
void dfs2(int u,int fa,int contrib,int ava)
{
	int tot=contrib;
	ans=max(ans,f[u]+contrib+(ava+more[u]==k));
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		tot+=f[v];
	}
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		tot+=(ch[u]-is[v]+ava)/k-f[v];
		dfs2(v,u,tot,tot*k+siz[v]+1==n);
		tot-=(ch[u]-is[v]+ava)/k-f[v];
	}
}
int main()
{
	read(tt);
	while(tt--)
	{
		read(n);read(k);
		F(i,cnt=0,n)hd[i]=-1;
		F(i,1,n)
		{
			int u,v;read(u);read(v);
			adline(--u,--v);adline(v,u);
		}
		if(k==1)printf("%d\n",n-1);
		else
		{
			dfs1(0,0);ans=0;
			dfs2(0,0,0,0);
			printf("%d\n",ans);
		}
	}
	return 0;
}