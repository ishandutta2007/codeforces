#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn=1<<20;
int n,a[333333],pre[333333],cnt[2222222][2];
long long ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]^a[i];
	cnt[0][0]++;
	for (int i=1;i<=n;i++)
	{
		cnt[pre[i]][i&1]++;
	}
	for (int i=0;i<maxn;i++)
	{
		for (int j=0;j<2;j++)
		{
			ans+=(1ll*cnt[i][j]*(cnt[i][j]-1)/2);
		}
	}
	printf("%lld\n",ans);
	return Accepted;
}