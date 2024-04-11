#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e3+5,INF=0x3fffffff;
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
	int next,to,dis;
}e[2*N];
int n,f[N][N],d[N],l[N],hd[N],cnt;
bool v[N],ans=true;
void adline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int fa,int s,long long now)
{
	if(f[s][u]!=now)ans=false;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u,s,now+e[i].dis);
	}
}
int main()
{
	read(n);
	F(i,0,n)hd[i]=-1;
	F(i,0,n)F(j,0,n)read(f[i][j]),ans=ans&&((int)(i==j)!=(int)(bool)f[i][j]);
	v[0]=true;
	F(i,1,n)d[i]=INF;
	F(j,1,n)if(f[0][j]<d[j])d[j]=f[0][j],l[j]=0;
	F(i,1,n)
	{
		int u=0;
		F(j,0,n)if(!v[j]&&(!u||d[j]<d[u]))u=j;
		v[u]=true;
		adline(u,l[u],d[u]);adline(l[u],u,d[u]);
		F(j,0,n)if(f[u][j]<d[j])d[j]=f[u][j],l[j]=u;
	}
	F(i,0,n)dfs(i,i,i,0);
	puts(ans?"YES":"NO");
	return 0;
}