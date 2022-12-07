#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
LL qpow(LL x,LL n,LL MOD)
{
	LL con=1,p=x;
	while(n)
	{
		if(n&1) con=(con*p)%MOD;
		p=(p*p)%MOD;
		n>>=1;
	}
	return con;
}
int n,m,N;
pair<int,int> P[2010];
LL fac[300010],inv[300010],f[2010];
LL C(int n,int k)
{
	return ((fac[n]*inv[k])%MOD*inv[n-k])%MOD;
}
int main()
{
	scanf("%d%d%d",&n,&m,&N);
	for(int i=1;i<=N;i++) scanf("%d%d",&P[i].first,&P[i].second);
	++N,P[N].first=n,P[N].second=m;
	sort(P+1,P+N+1);
	fac[0]=1;
	for(int i=1;i<=n+m;i++) fac[i]=(fac[i-1]*i)%MOD;
	inv[n+m]=qpow(fac[n+m],MOD-2,MOD);
	for(int i=n+m-1;i>=0;i--) inv[i]=(inv[i+1]*(i+1))%MOD;
	for(int i=1;i<=N;i++)
	{
		f[i]=C(P[i].first+P[i].second-2,P[i].first-1);
		for(int j=1;j<i;j++)
		{
			if(P[j].first>P[i].first||P[j].second>P[i].second) continue;
			f[i]=(f[i]-(f[j]*C(P[i].first-P[j].first+P[i].second-P[j].second,P[i].first-P[j].first))%MOD+MOD)%MOD;
		}
	}
	printf("%d\n",f[N]);
	return 0;
}