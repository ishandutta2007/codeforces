#include <bits/stdc++.h>
using namespace std;
#define N 305
#define M 1005
#define LIM 1000005
#define MOD 1000000007
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
const int lim=1e3,INF=1e9;char *P1,*P2,buf[LIM];
int n,m,b[N],d[N],s[N],a[N][N],z[N][N],z1[N][N],pw[N][M],invPw[N][M];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
int rd()
{
	int res=0;char c=0;bool fl=0;while(!isdigit(c)) fl|=c=='-',c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return fl?-res:res;
}
void print(int x) {if(x<10) {putchar(x+48);return;}print(x/10);putchar(x%10+48);}
struct BitArray 
{
	int vl[N];void clear() {for(int i=0;i<=n;++i) vl[i]=0;}
	void build()
	{
		for(int i=1;i<=n;++i) s[i]=add(s[i-1],vl[i-1]);
		for(int i=1;i<=n;++i) vl[i]=add(s[i],MOD-s[i&i-1]);
	}
	void upd(int x,int w) {x=min(x+1,n);for(;x<=n;x+=x&-x) W(vl[x],w);}
	int qry(int x) {x=min(x+1,n);int res=0;for(;x;x-=x&-x) W(res,vl[x]);return res;}
}BIT[N];
int qPow(int x,int y)
{int res=1;for(;y;y/=2,x=1ll*x*x%MOD) if(y&1) res=1ll*res*x%MOD;return res;}
void init()
{
	for(int i=1,t;i<=n;++i)
	{
		pw[i][0]=invPw[i][0]=1;t=qPow(i,MOD-2);
		for(int j=1;j<=lim;++j)
			pw[i][j]=1ll*pw[i][j-1]*i%MOD,invPw[i][j]=1ll*invPw[i][j-1]*t%MOD;
	}
}
void calc(int x)
{
	for(int i=x-1,t;i;--i)
	{
		t=0;for(int j=i+1;j<=x;++j) W(t,1ll*a[i][j]*z[x][j]%MOD);
		z[x][i]=1ll*t*qPow(x-i,MOD-2)%MOD; 
	}
}
void calc1()
{
	for(int i=1;i<=n;++i) for(int j=1;j<i;++j) for(int k=1;k<=j;++k)
		W(z1[i][k],MOD-1ll*z[i][j]*z1[j][k]%MOD);
}
void build()
{
	for(int i=n;i;--i)
	{d[i]=b[i]>0?0:INF;for(int j=i+1;j<=n;++j) if(a[i][j]) d[i]=min(d[i],d[j]+1);}
	for(int i=1;i<=n;++i)
	{
		BIT[i].clear();
		for(int j=i;j<=n;++j) if(d[j]<INF)
			W(BIT[i].vl[d[j]],1ll*z1[j][i]*add(b[j],MOD)%MOD*invPw[i][d[j]]%MOD);
		BIT[i].build(); 
	}
}
void upd(int x,int w)
{
	if(d[x]<INF) for(int i=1;i<=x;++i)
		BIT[i].upd(d[x],1ll*z1[x][i]*w%MOD*invPw[i][d[x]]%MOD);b[x]+=w;
}
int qry(int x,int l,int r)
{
	int res=0;for(int i=l;i<=r;++i) if(d[i]>x) W(res,add(b[i],MOD));
	for(int i=1;i<=n;++i)
		W(res,1ll*BIT[i].qry(x)*pw[i][x]%MOD*add(z[i][r],MOD-z[i][l-1])%MOD);
	return res;
}
int main()
{
	n=rd();for(int i=1;i<=n;++i) a[i][i]=i,z[i][i]=z1[i][i]=1,b[i]=rd();
	for(int i=1,x,y;i<=n;++i) {x=rd();for(int j=1;j<=x;++j) y=rd(),a[i][y]=y;}
	m=rd();init();for(int i=1;i<=n;++i) calc(i);calc1();
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) W(z[i][j],z[i][j-1]);build();
	for(int i=1,F[4];i<=m;++i)
	{
		F[0]=rd();F[1]=rd();F[2]=rd();
		if(F[0]==1) F[3]=rd(),print(qry(F[1],F[2],F[3])),puts("");
		if(F[0]==2)
		{
			if(b[F[1]]<=0 && b[F[1]]+F[2]>0) b[F[1]]+=F[2],build();
			else upd(F[1],F[2]);
		}
	}return 0;
}