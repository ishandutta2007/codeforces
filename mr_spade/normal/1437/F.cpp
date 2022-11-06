#include<cstdio>
#include<algorithm>
using std::sort;
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
const int N=5005;
int n,ans;
int fact[N],ifact[N],inv[N];
int a[N],c[N];
int dp[N],s[N],cdp[N];
inline void init()
{
	register int i;
	fact[0]=1;
	for(i=1;i<=n;i++)
		fact[i]=mul(fact[i-1],i);
	ifact[n]=qpow(fact[n],mod-2);
	for(i=n-1;i>=0;i--)
		ifact[i]=mul(ifact[i+1],i+1);
	for(i=1;i<=n;i++)
		inv[i]=mul(ifact[i],fact[i-1]);
	return;
}
signed main()
{
	int pt;
	register int i,j,k;
	scanf("%d",&n);init();
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			if(a[j]*2<=a[i])
				c[i]=j;
	if(c[n]!=n-1)
		return puts("0"),0;
	dp[n]=1;s[n]=1;cdp[n]=1;
	for(i=n-1;i>=1;i--)
	{
		for(pt=i+1;a[pt]<a[i]*2;pt++);
		dp[i]=mul(s[pt],inv[n-c[i]-1]);s[i]=add(s[i+1],dp[i]);
		cdp[i]=mul(dp[i],fact[n-c[i]-1]);
	}
	for(i=1;i<=n;i++)
		ans=add(ans,dp[i]);
	printf("%d\n",mul(ans,fact[n-1]));
	return 0;
}