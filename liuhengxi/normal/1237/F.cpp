#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3605,MOD=998244353;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,m,k,n2,m2,nm,f[N][N/2],g[N][N/2],c[N][N],ans,aa,bb,fac[N];
bool a[N],b[N];
int main()
{
	read(n,m,k);n2=n/2+1,m2=m/2+1;nm=max(n,m)+1;
	F(i,0,n)a[i]=true;
	F(i,0,m)b[i]=true;
	F(i,0,k)
	{
		int x1,y1,x2,y2;
		read(x1,y1,x2,y2);
		a[--x1]=a[--x2]=b[--y1]=b[--y2]=false;
	}
	F(i,0,n)if(a[i])++aa;
	F(i,0,m)if(b[i])++bb;
	F(i,fac[0]=1,nm)fac[i]=fac[i-1]*(long long)i%MOD;
	F(i,0,nm)c[i][0]=1;
	F(i,1,nm)F(j,1,i+1)c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
	F(i,0,n+1)f[i][0]=1;
	F(i,2,n+1)F(j,1,n2)
	{
		f[i][j]=f[i-1][j];
		if(a[i-1]&&a[i-2])f[i][j]=(f[i][j]+f[i-2][j-1])%MOD;
	}
	F(i,0,m+1)g[i][0]=1;
	F(i,2,m+1)F(j,1,m2)
	{
		g[i][j]=g[i-1][j];
		if(b[i-1]&&b[i-2])g[i][j]=(g[i][j]+g[i-2][j-1])%MOD;
	}
	F(h,0,(bb>>1)+1)F(v,0,(aa>>1)+1)
		(ans+=(long long)f[n][v]*c[aa-(v<<1)][h]%MOD*g[m][h]%MOD*c[bb-(h<<1)][v]%MOD*fac[h]%MOD*fac[v]%MOD)%=MOD;
	printf("%d\n",ans);
	return 0;
}