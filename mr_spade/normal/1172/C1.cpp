#include<cstdio>
#include<cstring>
const int mod=998244353;
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
const int N=55;
int n,m,sp,sa,sb;
int a[N];
int p[N];
int dp[N][N][N];
inline int solve(int x)
{
	int res=0,sum,isum;
	register int i,j,k;
	if(a[x]>0)
		sa=sub(sa,p[x]);
	else
		sb=sub(sb,p[x]);
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(i=0;i<m;i++)
		for(j=0;j<=i;j++)
			for(k=0;j+k<=i;k++)
				if(dp[i][j][k])
				{
					sum=sp+j-k+a[x]*(i-j-k);
					isum=qpow(sum,mod-2);
					if(sa+j)
						dp[i+1][j+1][k]=add(dp[i+1][j+1][k],mul(dp[i][j][k],mul(sa+j,isum)));
					if(sb-k)
						dp[i+1][j][k+1]=add(dp[i+1][j][k+1],mul(dp[i][j][k],mul(sb-k,isum)));
					if(p[x]+a[x]*(i-j-k))
						dp[i+1][j][k]=add(dp[i+1][j][k],mul(dp[i][j][k],mul(p[x]+a[x]*(i-j-k),isum)));
				}
	for(j=0;j<=m;j++)
		for(k=0;j+k<=m;k++)
			if(dp[m][j][k])
				res=add(res,mul(dp[m][j][k],p[x]+a[x]*(m-j-k)));
	if(a[x]>0)
		sa=add(sa,p[x]);
	else
		sb=add(sb,p[x]);
	return res;
}
signed main()
{
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]?0:(a[i]=-1);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		sp=add(sp,p[i]);
		if(a[i]>0)
			sa=add(sa,p[i]);
		else
			sb=add(sb,p[i]);
	}
	for(i=1;i<=n;i++)
		printf("%d\n",solve(i));
	return 0;
}