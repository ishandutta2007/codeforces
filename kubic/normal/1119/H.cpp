#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 1<<17
#define C 3
#define C1 1<<3
#define MOD 998244353
#define ctz __builtin_ctz
int n,m,c,a[C],b[C],z1[C1],z2[M],z[C1][M],pw[C1][N];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1)
		res=1ll*res*x%MOD;return res;
}
void FWT(bool fl,int n,int a[])
{
	for(int i=1,t1,t2;i<1<<n;i*=2)
		for(int j=0;j<1<<n;j+=i*2) for(int k=0;k<i;++k)
		{
			t1=a[j+k];t2=a[i+j+k];
			a[j+k]=add(t1,t2);a[i+j+k]=add(t1,MOD-t2);
		}
	if(fl)
	{
		int t=qPow(2,MOD-n-1);
		for(int i=0;i<1<<n;++i) a[i]=1ll*a[i]*t%MOD;
	}
}
int main()
{
	scanf("%d %d",&n,&m);c=3;
	for(int i=0;i<c;++i) scanf("%d",&b[i]),W(z1[0],b[i]);
	for(int i=0,t;i<1<<c;++i)
	{
		if(i) t=MOD-b[ctz(i)],z1[i]=add(z1[i&i-1],add(t,t));
		pw[i][0]=1;
		for(int j=1;j<=n;++j) pw[i][j]=1ll*pw[i][j-1]*z1[i]%MOD;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<c;++j) scanf("%d",&a[j]);z1[0]=0;
		for(int j=0;j<1<<c;++j)
		{if(j) z1[j]=z1[j&j-1]^a[ctz(j)];++z[j][z1[j]];}
	}for(int i=0;i<1<<c;++i) FWT(0,m,z[i]);
	for(int i=0;i<1<<m;++i)
	{
		for(int j=0;j<1<<c;++j) z1[j]=z[j][i];FWT(1,c,z1);z2[i]=1;
		for(int j=0;j<1<<c;++j) z2[i]=1ll*z2[i]*pw[j][z1[j]]%MOD;
	}FWT(1,m,z2);for(int i=0;i<1<<m;++i) printf("%d ",z2[i]);
	putchar('\n');return 0;
}