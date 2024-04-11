#include <bits/stdc++.h>
using namespace std;
#define N 105
#define N1 20005 
#define M 405
#define set(a,vl) memset(a,vl,sizeof(a))
int n,m,MOD,ans,fa[N1],id[N1],z[M][M];char a[N][N];
int f(int x,int y) {return (x-1)*(m+1)+y;}
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1)
		res=1ll*res*x%MOD;return res; 
}
int findRt(int x) {return x==fa[x]?x:fa[x]=findRt(fa[x]);}
int f1(int x,int y) {return findRt(f(x,y));}
bool merge(int x,int y)
{
	x=findRt(x);y=findRt(y);if(x==y) return 0;
	fa[x]=y;return 1;
}
void addE(int u,int v)
{++z[u][u];++z[v][v];--z[u][v];--z[v][u];}
int det(int n)
{
	int res=1;
	for(int i=1,t;i<=n;++i)
	{
		if(!z[i][i])
		{
			for(int j=i+1;j<=n;++j) if(z[j][i])
			{swap(z[i],z[j]);break;}res=-res; 
		}res=1ll*res*z[i][i]%MOD;if(!z[i][i]) break;
		for(int j=i+1;j<=n;++j)
		{
			t=1ll*z[j][i]*qPow(z[i][i],MOD-2)%MOD;
			for(int k=i;k<=n;++k)
				z[j][k]=(z[j][k]-1ll*z[i][k]*t)%MOD;
		}
	}return res;
}
int main()
{
	scanf("%d %d %d",&n,&m,&MOD);
	for(int i=1;i<=n;++i) scanf("%s",a[i]+1);
	for(int i=1;i<=(n+1)*(m+1);++i) fa[i]=i;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
	{
		bool fl=1;
		if(a[i][j]=='/') fl=merge(f(i,j+1),f(i+1,j));
		if(a[i][j]=='\\') fl=merge(f(i,j),f(i+1,j+1));
		if(!fl) {puts("0");return 0;}
	}
	for(int i=1,t;i<=n+1;++i) for(int j=1;j<=m+1;++j)
	{t=f(i,j);if(i+j&1 && findRt(t)==t) id[t]=++id[0];}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
		if(a[i][j]=='*')
		{
			if(i+j&1) addE(id[f1(i,j)],id[f1(i+1,j+1)]);
			else addE(id[f1(i,j+1)],id[f1(i+1,j)]);
		}ans=det(id[0]-1);id[0]=0;set(z,0);
	for(int i=1,t;i<=n+1;++i) for(int j=1;j<=m+1;++j)
	{t=f(i,j);if(!(i+j&1) && findRt(t)==t) id[t]=++id[0];}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
		if(a[i][j]=='*')
		{
			if(i+j&1) addE(id[f1(i,j+1)],id[f1(i+1,j)]);
			else addE(id[f1(i,j)],id[f1(i+1,j+1)]);
		}ans=(ans+det(id[0]-1))%MOD;
	printf("%d\n",(ans+MOD)%MOD);return 0;
}