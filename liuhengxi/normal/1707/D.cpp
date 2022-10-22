#include<cstdio>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define mod(x) (int)((x)%p)
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
int n,p,f[N][N],t[N],z[N],ans[N],C[N][N];
inline void reduce(int &x){(x>=p)&&(x-=p);}
long long pow(long long a,int b)
{
	long long c=1;
	for(;b;b>>=1,(a*=a)%=p)if(b&1)(c*=a)%=p;
	return c;
}
vector<int> adj[N];
void dfs(int u,int fa)
{
	if(u)
	{
		for(int v:adj[u])if(v!=fa)dfs(v,u);
		F(i,0,n)t[i]=1,z[i]=0;
		for(int v:adj[u])if(v!=fa)
		{
			int s=0;
			F(i,0,n)
			{
				reduce(s+=f[v][i]);
				if(s)t[i]=mod(t[i]*(long long)s);
				else ++z[i];
			}
		}
		F(i,0,n)f[u][i]=t[i]*!z[i];
		for(int v:adj[u])if(v!=fa)
		{
			int s=0;
			long long sum=0;
			F(i,0,n)
			{
				f[u][i]=mod(f[u][i]+sum*f[v][i]);
				reduce(s+=f[v][i]);
				sum=(sum+(s?t[i]*pow(s,p-2)*!z[i]:t[i]*!(z[i]-1)))%p;
			}
		}
	}
	else
	{
		for(int v:adj[u])dfs(v,u);
		F(i,0,n)t[i]=1;
		for(int v:adj[u])
		{
			F(i,0,n)
			{
				reduce(f[v][i+1]+=f[v][i]);
				t[i]=mod(t[i]*(long long)f[v][i]);
			}
		}
		F(i,0,n)f[u][i+1]=t[i];
	}
}
int main()
{
	read(n,p);
	F(i,0,n-1)
	{
		int u,v;read(u,v);--u,--v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(0,0);
	F(i,0,n+1)C[i][0]=1;
	F(i,1,n+1)F(j,1,i+1)reduce(C[i][j]=C[i-1][j]+C[i-1][j-1]);
	F(i,1,n)F(j,1,i+1)ans[i]=mod(ans[i]+((i^j)&1?p-1ll:1ll)*C[i][j]%p*f[0][j]);
	F(i,1,n)printf("%d ",ans[i]);
	puts("");
	return 0;
}