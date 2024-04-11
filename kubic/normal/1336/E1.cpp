#include <bits/stdc++.h>
using namespace std;
#define N 1<<18
#define M 45
#define MOD 998244353
#define ll long long
int n,m,m1,cnt,w,dig[N],ans[M],A[N],B[19][N];ll z[M];
void ins(ll x)
{
	for(int i=m1-1;i>=0;--i) if(x>>i&1)
	{if(!z[i]) {--cnt;z[i]=x;return;}x^=z[i];}
}
int qPow(int x,int y)
{int res=1;for(;y;y/=2,x=1ll*x*x%MOD) if(y&1) res=1ll*res*x%MOD;return res;}
void FWT_xor(bool fl,int n,int a[])
{
	int t=fl?qPow(2,MOD-n-1):1,t1,t2;
	for(int i=1;i<1<<n;i*=2) for(int j=0;j<1<<n;j+=i*2) for(int k=0;k<i;++k)
		t1=a[j+k],t2=a[i+j+k],a[j+k]=(t1+t2)%MOD,a[i+j+k]=(t1-t2)%MOD;
	if(fl) for(int i=0;i<1<<n;++i) a[i]=1ll*a[i]*t%MOD;
}
int main()
{
	scanf("%d %d",&n,&m1);m=(m1+1)/2;cnt=n;
	for(int i=1;i<1<<m;++i) dig[i]=dig[i&i-1]+1;
	for(int i=1;i<=n;++i) {ll x;scanf("%lld",&x);ins(x);}w=qPow(2,cnt);
	for(int i=0;i<1<<m;++i)
	{
		ll t=0;bool fl=0;
		for(int j=0;j<m;++j) if(i>>j&1) {if(!z[j]) {fl=1;break;}t^=z[j];}
		if(fl) continue;++A[t];
	}
	for(int i=0;i<1<<m;++i)
	{
		ll t=0;bool fl=0;
		for(int j=0;j<m;++j) if(i>>j&1) {if(!z[m+j]) {fl=1;break;}t^=z[m+j];}
		if(fl) continue;++B[dig[t>>m]][t&(1<<m)-1];
	}FWT_xor(0,m,A); 
	for(int i=0;i<=m;++i)
	{
		FWT_xor(0,m,B[i]);
		for(int j=0;j<1<<m;++j) B[i][j]=1ll*A[j]*B[i][j]%MOD;
		FWT_xor(1,m,B[i]);
		for(int j=0;j<1<<m;++j) ans[i+dig[j]]=(ans[i+dig[j]]+B[i][j])%MOD; 
	}for(int i=0;i<=m1;++i) printf("%lld ",1ll*(ans[i]+MOD)*w%MOD);return 0;
}