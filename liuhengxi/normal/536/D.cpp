#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=2005;
constexpr long long LLINF=0x3fffffffffffffff;
int n,m;
long long g[N][N];
void dij(int s,long long *dis)
{
	static bool vis[N];
	F(i,0,n)dis[i]=LLINF,vis[i]=false;
	dis[s]=0;
	F(_,0,n)
	{
		int u=-1;
		F(v,0,n)if(!vis[v]&&(!~u||dis[v]<dis[u]))u=v;
		vis[u]=true;
		F(v,0,n)dis[v]=min(dis[v],dis[u]+g[u][v]);
	}
}
int p[N];
bool d[2*N][2*N][2];
long long dis[2][N],f[2*N][2*N][2],val[2*N];
int main()
{
	int s,t;
	read(n,m);
	read(s,t);--s,--t;
	F(i,0,n)read(p[i]);
	F(i,0,n)F(j,0,n)g[i][j]=LLINF;
	F(i,0,n)g[i][i]=0;
	F(i,0,m)
	{
		int u,v,w;read(u,v,w);--u,--v;
		g[u][v]=g[v][u]=min(g[u][v],(long long)w);
	}
	dij(s,dis[0]);
	dij(t,dis[1]);
	F(i,0,n)val[i]=dis[0][i],val[i+n]=dis[1][i];
	sort(val,val+2*n);
	F(i,0,n)dis[0][i]=(int)(lower_bound(val,val+2*n,dis[0][i])-val)+1,dis[1][i]=(int)(lower_bound(val,val+2*n,dis[1][i])-val)+1;
	F(i,0,2*n+1)F(j,0,n)
	{
		if(dis[0][j]>i)f[i][dis[1][j]-1][1]-=p[j],d[i][dis[1][j]-1][1]=true;
		if(dis[1][j]>i)f[dis[0][j]-1][i][0]+=p[j],d[dis[0][j]-1][i][0]=true;
	}
	for(int i=2*n;~i;--i)for(int j=2*n;~j;--j)
	{
		f[i][j][0]+=max(f[i+1][j][0],d[i][j][0]?f[i+1][j][1]:-LLINF);
		f[i][j][1]+=min(d[i][j][1]?f[i][j+1][0]:LLINF,f[i][j+1][1]);
	}
	puts(f[0][0][0]?(f[0][0][0]>0?"Break a heart":"Cry"):"Flowers");
	return 0;
}