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
const int N=2e5+5,M=3005;
int n,m,ans,ans2,sa,sb;
int a[N],p[N];
int dp[M][M];
int c[M][M];
int dpowa[M],dpowb[M],dpowc[M];
signed main()
{
	int x,y;
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]),(a[i]?sa=add(sa,p[i]):sb=add(sb,p[i]));
	for(i=0;i<=m;i++)
	{
		c[i][0]=c[i][i]=1;
		for(j=1;j<i;j++)
			c[i][j]=add(c[i-1][j-1],c[i-1][j]);
	}
	dp[0][0]=1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<=i;j++)
			if(dp[i][j])
			{
				x=qpow(sa+j+sb-(i-j),mod-2);
				if(sa+j)
					dp[i+1][j+1]=add(dp[i+1][j+1],mul(mul(sa+j,x),dp[i][j]));
				if(sb-(i-j))
					dp[i+1][j]=add(dp[i+1][j],mul(mul(sb-(i-j),x),dp[i][j]));
			}
	}
	dpowa[0]=1;
	for(i=1;i<=m;i++)
		dpowa[i]=mul(dpowa[i-1],i);
	dpowb[0]=1;
	for(i=1;i<=m;i++)
		dpowb[i]=mul(dpowb[i-1],add(sub(sa,2),i));
	dpowc[0]=1;
	for(i=1;i<=m;i++)
		dpowc[i]=mul(dpowc[i-1],add(sub(sa,1),i));
	for(i=0;i<=m;i++)
		if(dp[m][i])
		{
			y=qpow(dpowc[i],mod-2);
			for(j=0;j<=i;j++)
			{
				x=mul(mul(c[i][j],mul(dpowa[j],dpowb[i-j])),y);
				ans=add(ans,mul(mul(dp[m][i],x),j));
			}
		}
	dpowa[0]=1;
	for(i=1;i<=m;i++)
		dpowa[i]=mul(dpowa[i-1],sub(2,i));
	dpowb[0]=1;
	for(i=1;i<=m;i++)
		dpowb[i]=mul(dpowb[i-1],sub(sb,i));
	dpowc[0]=1;
	for(i=1;i<=m;i++)
		dpowc[i]=mul(dpowc[i-1],sub(add(sb,1),i));
	for(i=0;i<=m;i++)
		if(dp[m][m-i])
		{
			y=qpow(dpowc[i],mod-2);
			for(j=0;j<=i;j++)
			{
				x=mul(mul(c[i][j],mul(dpowa[j],dpowb[i-j])),y);
				ans2=add(ans2,mul(mul(dp[m][m-i],x),j));
			}
		}
	for(i=1;i<=n;i++)
		if(a[i]==1)
			printf("%d\n",mul(add(1,ans),p[i]));
		else
			printf("%d\n",mul(sub(1,ans2),p[i]));
	return 0;
}