//
//  
//
//
//  
//   
//
#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);long long r=0;
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		for(int i=2;i<=n;i++) r+=max(a[i-1]-a[i],0);
		printf("%lld\n",r);
	}
	return 0;
}