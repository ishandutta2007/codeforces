#include <bits/stdc++.h>
using namespace std;
#define N 505
#define M 250005
#define ull unsigned long long
#define ulll __uint128_t
#define mod FM.reduce
int n,m,MOD,ans,s[M],s1[M],dp[M];
const int D=125000;
struct FastMod
{
	ull b,m;FastMod(ull b=2):b(b),m((ull)(((ulll)(1)<<64)/b)) {}
    ull reduce(ull a) {ull q=(ull)(((ulll)(m)*a)>>64),r=a-q*b;return r>=b?r-b:r;}
}FM;
int qry1(int l,int r)
{
	int t,t1;l=max(l,-m);r=min(r,m);
	t=mod(1ull*(l-1+MOD)*(s[D+r]-s[D+l-1]+MOD));
	t1=mod(s1[D+r]-s1[D+l-1]+MOD);return mod(t1-t+MOD);
}
int qry2(int l,int r)
{
	int t,t1;l=max(l,-m);r=min(r,m);
	t=mod(1ull*(r+1+MOD)*(s[D+r]-s[D+l-1]+MOD));
	t1=mod(s1[D+r]-s1[D+l-1]+MOD);return mod(t-t1+MOD);
}
int main()
{
	scanf("%d %d",&n,&MOD);if(MOD==1) {puts("0");return 0;}
	FM=FastMod(MOD);m=n*(n-1)/2;
	for(int i=1,t=1;i<=n;++i)
	{
		for(int j=-m;j<=m;++j)
		{
			s[D+j]=mod(s[D+j-1]+dp[D+j]);
			s1[D+j]=mod(s1[D+j-1]+1ull*dp[D+j]*(j+MOD));
		}
		for(int j=-m;j<=m;++j)
		{
			dp[D+j]=mod(qry2(j+1,j+n-i)+qry1(j-n+i,j));
			if(j<0 && j>=i-n) dp[D+j]=mod(dp[D+j]+1ull*t*(n-i+j+1));
		}t=mod(1ull*t*(n-i+1));
	}for(int i=1;i<=m;++i) ans=mod(ans+dp[D+i]);printf("%d\n",ans);return 0;
}