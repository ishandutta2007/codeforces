#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=4010;
const int MOD=1000000009;
int n,a,b,N;
LL fac[MAXN],inv[MAXN],ans;
LL qpow(LL x,LL n)
{
	LL p=x,con=1;
	while(n>0)
	{
		if(n&1) con=(con*p)%MOD;
		p=(p*p)%MOD;
		n>>=1;
	}
	return con;
}
LL C(int n,int k)
{
	return (((fac[n]*inv[k])%MOD)*inv[n-k])%MOD;
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	fac[0]=1,N=max(a,b);
	for(int i=1;i<=N;i++) fac[i]=(fac[i-1]*i)%MOD;
	inv[N]=qpow(fac[N],MOD-2);
	for(int i=N-1;i>=0;i--) inv[i]=(inv[i+1]*(i+1))%MOD;
	for(int i=2;i<n;i++)
		for(int j=i;j<n;j++)
		{
			int len=j-i+1;
			if(b<len) continue;
			if(a<n-len) continue;
			LL con=(fac[a]*fac[b])%MOD;
			con=(con*C(a-1,n-len-1))%MOD;
			con=(con*C(b-1,len-1))%MOD;
			ans=(ans+con)%MOD;
		}
	printf("%I64d\n",ans);
	return 0;
}