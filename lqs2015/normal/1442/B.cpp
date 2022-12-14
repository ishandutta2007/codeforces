#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int pos[222222],test,n,k,a[222222],b[222222],ans,cnt,pp[222222],id;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=k;i++) scanf("%d",&b[i]);
		for (int i=1;i<=n;i++) pp[a[i]]=i;
		for (int i=1;i<=n;i++) pos[i]=-1;
		for (int i=1;i<=k;i++) pos[b[i]]=i;
		ans=1;
		for (int i=1;i<=k;i++)
		{
			cnt=0;id=pp[b[i]];
			if (id>1 && pos[a[id-1]]<=i) cnt++;
			if (id<n && pos[a[id+1]]<=i) cnt++;
			ans=1ll*cnt*ans%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}