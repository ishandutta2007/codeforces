#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
const int MAXN=1000010;
int n,k;
LL s[MAXN],fac[MAXN],inv[MAXN],p=1,ans;
char a[MAXN];
LL qpow(LL x,LL n)
{
	LL p=x,con=1;
	while(n)
	{
		if(n&1) con=(con*p)%MOD;
		p=(p*p)%MOD;
		n>>=1;
	}
	return con;
}
LL C(int n,int k)
{
	if(k>n) return 0;
	if(k<0) return 0;
	return (((fac[n]*inv[k])%MOD)*inv[n-k])%MOD;
}
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",a+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+(int)(a[i]-'0');
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%MOD;
	inv[n]=qpow(fac[n],MOD-2);
	for(int i=n-1;i>=0;i--) inv[i]=(inv[i+1]*(i+1))%MOD;
	for(int i=n-1;i>=1;i--)
	{
		LL x=C(i-1,k-1);
		ans=(ans+(((x*s[i])%MOD)*p)%MOD)%MOD;
		x=C(i,k);
		LL z=a[i+1]-'0';
		ans=(ans+(((z*x)%MOD)*p)%MOD)%MOD;
		p=(p*10)%MOD;
	}
	LL z=a[1]-'0';
	LL x=0;
	if(k==0) x=1;
	ans=(ans+(((z*x)%MOD)*p)%MOD)%MOD;
	cout<<ans<<endl;
	return 0;
}