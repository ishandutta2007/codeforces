#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e3+5,INF=0x3f3f3f3f;
const long long LLINF=0x3f3f3f3f3f3f3f3fll;
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
inline void update(int &a,long long &b,int c,long long d){if(a<c||(a==c&&b<d))a=c,b=d;}
struct line{int next,to;}e[2*N];
int tt,n,m,a[N],hd[N],cnt,siz[N],f[N][N];long long g[N][N];
inline void adline(int u,int v){e[cnt].to=v;e[cnt].next=hd[u];hd[u]=cnt++;}
void dfs(int u,int fa)
{
	siz[u]=1;
	f[u][1]=0;g[u][1]=a[u];
	for(int k=hd[u];~k;k=e[k].next)
	{
		int v=e[k].to;if(v==fa)continue;
		dfs(v,u);siz[u]+=siz[v];
		for(int i=min(m,siz[u]);i;--i)
		{
			int x=f[u][i]+f[v][1];
			long long y=g[u][i]+g[v][1];
			f[u][i]=-INF,g[u][i]=-LLINF;
			update(f[u][i],g[u][i],x,y);
			update(f[u][i],g[u][i],f[u][i-1]+f[v][1]+(g[v][1]>0),g[u][i-1]);
			F(j,max(2,i+siz[v]-siz[u]),min(i,siz[v])+1)
			{
				update(f[u][i],g[u][i],f[u][i-j]+f[v][j]+(g[v][j]>0),g[u][i-j]);
				update(f[u][i],g[u][i],f[u][i-j+1]+f[v][j],g[u][i-j+1]+g[v][j]);
			}
		}
	}
}
int main()
{
	read(tt);
	while(tt--)
	{
		read(n,m);
		F(i,0,n)read(a[i]);
		F(i,0,n){int x;a[i]=read(x)-a[i];}
		F(i,cnt=0,n)hd[i]=-1;
		F(i,0,n-1)
		{
			int u,v;--read(u),--read(v);
			adline(u,v);adline(v,u);
		}
		memset(f,-0x3f,sizeof(int)*N*n);
		memset(g,-0x3f,sizeof(long long)*N*n);
		dfs(0,0);
		printf("%d\n",f[0][m]+(g[0][m]>0));
	}
	return 0;
}