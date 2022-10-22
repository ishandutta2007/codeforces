#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=2e5+5;
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
}e[2*M];
int n,m,k,hd[N],cnt,cyc[N],nex[N],len,stk[N],tp,col[N];
bool vis[N],in[N],found;
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int fa)
{
	if(in[u])
	{
		found=true;
		while(stk[--tp]!=u)cyc[len++]=stk[tp];
		cyc[len++]=u;
		return;
	}
	if(vis[u])return;
	vis[u]=true;in[stk[tp++]=u]=true;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);
		if(found)return;
	}
	in[stk[--tp]]=false;
}
void color(int u,int fa)
{
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		col[v]=col[u]^1;
		color(v,u);
	}
}
int mincyc()//not min
{
	dfs(0,0);
	if(!found)
	{
		int one=0;
		color(0,0);
		F(i,0,n)if(col[i])++one;
		if(2*one<n)F(i,0,n)col[i]^=1;
		one=(k+1)/2;
		F(i,0,n)if(col[i])
		{
			if(one)--one;
			else col[i]=0;
		}
		return n+1;
	}
	F(i,0,n)in[i]=vis[i]=false;
	F(i,0,len)in[cyc[i]]=true;
	F(i,0,len)nex[cyc[i]]=cyc[(i+1)%len];
	for(int u=cyc[0];!vis[u];u=nex[u])
	{
		if(vis[u])break;
		vis[u]=true;
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			if(!in[v])continue;
			if(nex[u]==v||nex[v]==u)continue;
			while(nex[u]!=v)in[nex[u]]=false,nex[u]=nex[nex[u]];
		}
	}
	len=0;
	F(i,0,n)if(in[i])
	{
		cyc[len++]=i;
		for(int u=nex[i];u!=i;u=nex[u])cyc[len++]=u;
		break;
	}
	return len;
}
int main()
{
	read(n);read(m);read(k);
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);adline(v,u);
	}
	if(mincyc()<=k)
	{
		puts("2");
		printf("%d\n",len);
		F(i,0,len)printf("%d ",cyc[i]+1);
		puts("");
	}
	else
	{
		if(found)
		{
			puts("1");
			F(i,0,(k+1)/2)printf("%d ",cyc[2*i]+1);
			puts("");
		}
		else
		{
			puts("1");
			F(i,0,n)if(col[i])printf("%d ",i+1);
			puts("");
		}
	}
	return 0;
}