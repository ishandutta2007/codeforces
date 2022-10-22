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
int n,hd[N],cnt,ch[N];
int ans=true,f[N][2];// 0 - not chain; 1 - not 'Y'
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs1(int u,int fsb)
{
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fsb)continue;
		dfs1(v,u);
		++ch[u];
	}
	f[u][0]=ch[u]>1;
	f[u][1]=ch[u]>2;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fsb)continue;
		f[u][0]+=f[v][0];
		f[u][1]+=f[v][1]+f[v][0];
	}
}
void moveroot(int u,int v)
{
	f[u][0]-=f[v][0];
	f[u][1]-=f[v][0]+f[v][1];
	f[u][0]-=ch[u]>1;f[u][1]-=ch[u]>2;
	f[v][0]-=ch[v]>1;f[v][1]-=ch[v]>2;
	--ch[u];++ch[v];
	f[u][0]+=ch[u]>1;f[u][1]+=ch[u]>2;
	f[v][0]+=ch[v]>1;f[v][1]+=ch[v]>2;
	f[v][0]+=f[u][0];
	f[v][1]+=f[u][0]+f[u][1];
}
void dfs(int u,int fsb)
{
	int cnt=0;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		cnt+=!!f[v][1];
	}
	if(cnt>=3)ans=false;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fsb)continue;
		moveroot(u,v);
		dfs(v,u);
		moveroot(v,u);
	}
}
int main()
{
	read(n);
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);--u,--v;
		adline(u,v);adline(v,u);
	}
	dfs1(0,0);
	dfs(0,0);
	puts(ans?"Yes":"No");
	return 0;
}