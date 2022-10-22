#include <bits/stdc++.h>
using namespace std;
#define N 105
#define M 200005
#define MOD 1000000007
const int lim=1e5;
int n,m,L=lim,R=lim,a[N],b[N],ans[M],dp[N*N],s[N*N];
int f(int x,int y) {return x>0?x/y:-(-x-1)/y-1;}
int slv(int x)
{
	int res=0;for(int i=0;i<=a[n];++i) dp[i]=0;dp[0]=1;
	for(int i=1,t;i<=n;++i)
	{
		for(int j=0;j<=a[n];++j)
			s[j]=(dp[j]+(j?s[j-1]:0))%MOD,dp[j]=0;
		for(int j=max(b[i]+x*i,0);j<=a[n];++j)
			t=a[i]-a[i-1],dp[j]=(s[j]-(j>t?s[j-t-1]:0))%MOD;
	}for(int i=0;i<=a[n];++i) res=(res+dp[i])%MOD;
	return (res+MOD)%MOD;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),a[i]+=a[i-1];
	for(int i=2;i<=n;++i) scanf("%d",&b[i]),b[i]+=b[i-1];
	scanf("%d",&m);for(int i=2;i<=n;++i) b[i]+=b[i-1];
	for(int i=1;i<=n;++i)
		L=min(L,f(-b[i],i)),R=min(R,f(a[i]-b[i],i));
	L=max(L,-lim);for(int i=L;i<=R;++i) ans[lim+i]=slv(i);
	for(int i=1,x;i<=m;++i)
		scanf("%d",&x),printf("%d\n",ans[lim+max(x,L)]);return 0;
}