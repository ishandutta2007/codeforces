#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=110000;
struct node
{
	int a,b;
}s[N];
int t,n,m,a[N],b[N],sum[N];
int cmp(node x,node y)
{
	if(x.a!=y.a) return x.a<y.a;
	return x.b<y.b;
}
signed main()
{
	scanf("%lld",&t);
	for(int am=1;am<=t;am++)
	{
		scanf("%lld%lld",&m,&n);
		for(int i=1;i<=n;i++) scanf("%lld%lld",&s[i].a,&s[i].b);
		sort(s+1,s+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n;i++) a[i]=s[i].a,b[i]=s[i].b;
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
		for(int i=n;i>=n-min(n,m)+1;i--) ans+=a[i];
		for(int i=n;i>=1;i--)
		{
			int pos=upper_bound(a+1,a+n+1,b[i])-(a);
			if(pos==n+1) ans=max(ans,a[i]+(m-1)*b[i]);
			else
			{
				if(n-pos+1>=m) continue;
				else 
				{
					int now=sum[n]-sum[pos-1],cnt=m-(n-pos+1);
					if(a[i]<=b[i]) ans=max(ans,now+(cnt-1)*b[i]+a[i]);
					else ans=max(ans,now+cnt*b[i]);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}