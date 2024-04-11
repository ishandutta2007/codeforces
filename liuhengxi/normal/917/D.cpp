#include<cstdio>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define mod(x) (int)((x)%MOD)
using namespace std;
const int N=105,MOD=1000000007;
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
int pow(int aa,int b)
{
	long long a=aa,c=1;
	for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
	return (int)c;
}
inline void reduce(int &x){(x>=MOD)&&(x-=MOD);}
int n,f[N][N][2],siz[N],C[N][N],g[N],t[N][2],ivn;
vector<int> adj[N];
void dfs(int u,int fa)
{
	f[u][1][0]=1;
	f[u][1][1]=1;
	siz[u]=1;
	for(int v:adj[u])if(v!=fa)
	{
		dfs(v,u);
		F(i,1,siz[u]+siz[v]+1)t[i][0]=t[i][1]=0;
		F(i,1,siz[u]+1)
		{
			long long x0=f[u][i][0],x1=f[u][i][1];
			long long z0=x0*ivn%MOD,z1=x1*ivn%MOD;
			long long y0,y1;
			F(j,1,siz[v]+1)
			{
				y0=f[v][j][0],y1=f[v][j][1];
				t[i+j][0]=mod(t[i+j][0]+x0*y1);
				t[i+j][1]=mod(t[i+j][1]+x1*y1);
				t[i+j-1][0]=mod(t[i+j-1][0]+z0*y0);
				t[i+j-1][1]=mod(t[i+j-1][1]+z1*y0);
				t[i+j-1][1]=mod(t[i+j-1][1]+z0*y1);
			}
		}
		F(i,1,siz[u]+siz[v]+1)f[u][i][0]=t[i][0],f[u][i][1]=t[i][1];
		siz[u]+=siz[v];
	}
}
int main()
{
	read(n);
	ivn=pow(n,MOD-2);
	F(i,0,n+1)C[i][0]=1;
	F(i,1,n+1)F(j,1,i+1)reduce(C[i][j]=C[i-1][j]+C[i-1][j-1]);
	F(i,0,n-1)
	{
		int u,v;read(u,v);--u,--v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(0,0);
	F(i,0,n)
	{
		long long ans=0;
		F(j,i,n)ans+=((i^j)&1?-1ll:1ll)*C[j][i]*f[0][n-j][1]%MOD;
		ans%=MOD;ans+=MOD;ans%=MOD;
		ans*=pow(n,n-2);ans%=MOD;
		printf("%lld ",ans);
	}
	puts("");
	return 0;
}