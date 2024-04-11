#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int mod=998244353;
int n,p[222222],ans2,pos[222222],ps[222222],cnt,k;
long long ans1;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++) pos[p[i]]=i;
	for (int i=n;i>=n-k+1;i--)
	{
		ps[++cnt]=pos[i];
		ans1+=i;
	}
	sort(ps+1,ps+cnt+1);ans2=1;
	for (int i=1;i<cnt;i++) ans2=1ll*ans2*(ps[i+1]-ps[i])%mod;
	printf("%lld %d\n",ans1,ans2);
	return Accepted;
}