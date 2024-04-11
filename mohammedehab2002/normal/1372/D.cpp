#include <bits/stdc++.h>
using namespace std;
int a[200005];
long long pre[200005],suf[200005],ans;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=2;i<=n+1;i++)
	{
		scanf("%d",&a[i]);
		pre[i]=pre[i-2]+a[i];
	}
	for (int i=n+1;i>1;i--)
	{
		suf[i]=suf[i+2]+a[i];
		ans=max(ans,pre[i-1]+suf[i]);
	}
	printf("%I64d",ans);
}