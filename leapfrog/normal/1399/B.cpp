#include<bits/stdc++.h>
using namespace std;
int T,n;long long a[105],b[105];
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);long long ma=1000000005,mb=1000000005,r=0;
		for(int i=1;i<=n;i++) scanf("%lld",a+i),ma=min(ma,a[i]);
		for(int i=1;i<=n;i++) scanf("%lld",b+i),mb=min(mb,b[i]);
		for(int i=1;i<=n;i++) r+=max(a[i]-ma,b[i]-mb);
		printf("%lld\n",r);
	}
	return 0;
}