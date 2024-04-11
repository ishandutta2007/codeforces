#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=605,INF=0x3fffffff;
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
int n,m,f[N][N],dis[N];
bool vis[N];
void dij(int s)
{
	F(i,0,n)dis[i]=INF,vis[i]=false;
	dis[s]=0;
	F(_,0,n)
	{
		int u=-1;
		F(i,0,n)if(!vis[i]&&(!~u||dis[i]<dis[u]))u=i;
		vis[u]=true;
		for(int v=0,vv=(n-dis[u]%n)%n;v<n;++v,vv+=(vv-=n-1)>>31&n)dis[v]=min(dis[v],dis[u]+f[u][vv]);
	}
}
int main()
{
	read(n,m);
	F(i,0,n)F(j,0,n)f[i][j]=INF;
	F(i,0,m)
	{
		int a,b,c;read(a,b,c);
		f[a][b]=min(f[a][b],c);
	}
	F(i,0,n)
	{
		F(j,0,n-1)f[i][j+1]=min(f[i][j+1],f[i][j]+1);
		f[i][0]=min(f[i][0],f[i][n-1]+1);
		F(j,0,n-1)f[i][j+1]=min(f[i][j+1],f[i][j]+1);
	}
	F(i,0,n)
	{
		dij(i);
		F(j,0,n)printf("%d ",dis[j]);
		puts("");
	}
	return 0;
}