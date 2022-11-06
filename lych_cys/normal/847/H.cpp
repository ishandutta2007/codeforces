#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[100005];
ll s[100005],p[100005],f[100005],g[100005];
int main()
{
	scanf("%d",&n);
	if (n==1){ puts("0"); return 0; }
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1,now=0;i<=n;i++)
	if (a[i]>now)s[i]=s[i-1],f[i]=now=a[i];
	else s[i]=s[i-1]+now+1-a[i],f[i]=now=now+1;
	
	for (int i=n,now=0;i>=1;i--)
	if (a[i]>now)p[i]=p[i+1],g[i]=now=a[i];
	else p[i]=p[i+1]+now+1-a[i],g[i]=now=now+1;
	
	ll ans=1e15;
	for (int i=1;i<n;i++)
	{
		ans=min(ans,s[i]+p[i+1]+(f[i]==g[i+1]));
	}
	printf("%lld\n",ans);
}