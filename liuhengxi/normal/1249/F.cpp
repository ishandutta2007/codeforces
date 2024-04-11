#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=200;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k,a[N],f[N][N+1],g[N+1];
bool c[N][N];
void dfs(int u,int fa)
{
	f[u][k]=a[u];
	F(v,0,n)if(v!=fa&&c[u][v])
	{
		dfs(v,u);
		F(i,0,k+1)g[i]=0;
		F(i,0,k+1)F(j,0,k+1)if(i+j<=k)
		{
			int ii=i>j-1?i:j-1;
			g[ii]=g[ii]>f[u][i]+f[v][j]?g[ii]:f[u][i]+f[v][j];
		}
		F(i,0,k+1)f[u][i]=g[i];
		F(i,0,k)if(f[u][i+1]<f[u][i])f[u][i+1]=f[u][i];
	}
}
int main()
{
	read(n);read(k);
	F(i,0,n)read(a[i]);
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);
		--u,--v;
		c[u][v]=c[v][u]=true;
	}
	dfs(0,0);
	printf("%d\n",f[0][k]);
	return 0;
}