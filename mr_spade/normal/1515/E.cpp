#include<bits/stdc++.h>
using namespace std;
int mod;
inline int add(int a,int b)
{
	return (a+=b)>=mod?a-mod:a;
}
inline int sub(int a,int b)
{
	return (a-=b)<0?a+mod:a;
}
inline int mul(int a,int b)
{
	return (long long)a*b%mod;
}
inline int qpow(int a,int b)
{
	int res=1;
	for(;b;a=mul(a,a),b>>=1)
		if(b&1)
			res=mul(res,a);
	return res;
}
const int N=405;
int fact[N],ifact[N];
inline void init(int n)
{
	register int i;
	fact[0]=1;
	for(i=1;i<=n;i++)
		fact[i]=mul(fact[i-1],i);
	ifact[n]=qpow(fact[n],mod-2);
	for(i=n-1;i>=0;i--)
		ifact[i]=mul(ifact[i+1],i+1);
	return;
}
inline int choose(int n,int m)
{
	if(n<m)
		return 0;
	return mul(fact[n],mul(ifact[m],ifact[n-m]));
}
int n;
int dp[N][N],f[N];
signed main()
{
	register int i,j,k;
	scanf("%d%d",&n,&mod);
	init(n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			f[i]=add(f[i],choose(i-1,j-1));
	for(i=1;i<=n;i++)
		for(j=0;j<=i;j++)
		{
			if(j==i)
				dp[i][j]=f[i];
			for(k=1;k<=i-2&&k<=j;k++)
				dp[i][j]=add(dp[i][j],mul(choose(j,k),mul(f[k],dp[i-k-1][j-k])));
		}
	int ans=0;
	for(i=0;i<=n;i++)
		ans=add(ans,dp[n][i]);
	printf("%d\n",ans);
}