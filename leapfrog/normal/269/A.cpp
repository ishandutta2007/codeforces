#include<bits/stdc++.h>
#define int long long
using namespace std;
struct squ{int a,k;}a[100005];
int n,ans,ret;
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].k,&a[i].a);
	for(int i=1,t;i<=n;i++) t=ceil(log(a[i].a)/log(4)),ans=max(ans,a[i].k+max(t,1ll));
	return printf("%lld\n",ans),0;
}