#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,ans,cur;
int a[N],h[N],ht[N];
signed main()
{
	register int i,j;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)
	{
		h[i]=a[i];
		for(j=i-1;j>=1;j--)
			h[j]=min(h[j+1],a[j]);
		for(j=i+1;j<=n;j++)
			h[j]=min(h[j-1],a[j]);
		cur=0;
		for(j=1;j<=n;j++)
			cur+=h[j];
		if(cur>ans)
			ans=cur,memcpy(ht+1,h+1,sizeof(int)*n);
	}
	for(i=1;i<=n;i++)
		printf("%lld ",ht[i]);
	putchar('\n');
	return 0;
}