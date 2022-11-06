#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
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
const int N=1e5+5;
int n,m,ans;
int dp[N][4];
signed main()
{
	register int i,j;
	scanf("%d%d",&n,&m);
	if(n==1&&m==1)
		return puts("2"),0;
	if(m>n)
		swap(n,m);
	for(i=0;i<4;i++)
		dp[2][i]=1;
	for(i=2;i<n;i++)
		for(j=0;j<4;j++)
		{
			if(j!=0)
				dp[i+1][(j&1)<<1]=add(dp[i+1][(j&1)<<1],dp[i][j]);
			if(j!=3)
				dp[i+1][(j&1)<<1|1]=add(dp[i+1][(j&1)<<1|1],dp[i][j]);
		}
	if(m==1)
		return printf("%d\n",mul(2,add(dp[n][0],dp[n][1]))),0;
	int cur=sub(mul(2,add(dp[n][0],dp[n][1])),2);
	printf("%d\n",add(cur,mul(2,add(dp[m][0],dp[m][1]))));
	return 0;
}