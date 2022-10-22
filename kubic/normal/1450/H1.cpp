#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define MOD 998244353
int n,m,ans,cnt1,cnt[2],fc[N],invF[N];char a[N];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1)
		res=1ll*res*x%MOD;return res;
}
int C(int x,int y)
{return 1ll*fc[x]*invF[y]%MOD*invF[x-y]%MOD;}
int main()
{
	scanf("%d %d %s",&n,&m,a+1);fc[0]=invF[0]=1;
	for(int i=1;i<=n;++i) fc[i]=1ll*fc[i-1]*i%MOD;
	invF[n]=qPow(fc[n],MOD-2);
	for(int i=n-1;i;--i) invF[i]=1ll*invF[i+1]*(i+1)%MOD;
	for(int i=1;i<=n;++i)
	{
		if(a[i]=='w') cnt1+=(i&1?-1:1);
		if(a[i]=='?') ++cnt[i&1];
	}
	for(int i=-cnt[1],t;i<=cnt[0];++i)
	{
		t=abs(i+cnt1);if(t&1) continue;
		ans=add(ans,1ll*t*C(cnt[0]+cnt[1],i+cnt[1])%MOD);
	}ans=1ll*ans*qPow(2,MOD-cnt[0]-cnt[1]-1)%MOD;
	printf("%d\n",ans);return 0;
}