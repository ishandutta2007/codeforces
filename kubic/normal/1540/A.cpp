#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int T,n,a[N];ll s,ans;
void slv()
{
	scanf("%d",&n);s=ans=0;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);ans=a[n];
	for(int i=n;i;--i) ans+=1ll*a[i]*(n-i)-s,s+=a[i];
	printf("%lld\n",ans);
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}