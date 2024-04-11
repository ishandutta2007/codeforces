#include <bits/stdc++.h>
using namespace std;
#define N 2000005
#define MOD 998244353
int n,ans,fc[N],invFc[N],a[N],s[N];
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1)
		res=1ll*res*x%MOD;return res;
}
void init(int n)
{
	fc[0]=invFc[0]=1;
	for(int i=1;i<=n;++i) fc[i]=1ll*fc[i-1]*i%MOD;
	invFc[n]=qPow(fc[n],MOD-2);
	for(int i=n-1;i;--i) invFc[i]=1ll*invFc[i+1]*(i+1)%MOD;
}
int C(int x,int y)
{return 1ll*fc[x]*invFc[y]%MOD*invFc[x-y]%MOD;}
int main()
{
	scanf("%d",&n);init(2e6);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) for(int j=a[i]+1;j<=a[n];j+=n) ++s[j];
	for(int i=1;i<=a[n];++i) s[i]+=s[i-1];
	for(int i=0,t=1;i<=a[n];++i) if(i>=s[i])
	{
		bool fl=0;while(t<=n && a[t]<i) {if(a[t]<t-1) fl=1;++t;}
		if(fl) break;W(ans,C(i-s[i]+n-1,n-1));
		W(ans,MOD-C(i-s[i]+t-2,n-1));
	}printf("%d\n",ans);return 0;
}