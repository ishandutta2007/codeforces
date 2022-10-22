#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100000;
int t,n,s,a[maxn+5];
signed main()
{
	scanf("%lld",&t);
	for(int tot=1;tot<=t;tot++)
	{
		scanf("%lld%lld",&n,&s);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]+=a[i-1];
		if(a[n]<=s)
		{
			printf("0\n");
			continue;
		}
		int ans,mx=-1;
		for(int i=1;i<=n;i++)
		{
			int sum=s-a[i-1];
			if(sum<0) break;
			int pos=upper_bound(a+i,a+n+1,sum+a[i])-a;
			pos--;
			if(mx<pos-1)
			{
				mx=pos-1;
				ans=i;
			} 
		}
		printf("%lld\n",ans);
	}
	return 0;
}