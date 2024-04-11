#include<bits/stdc++.h>
using namespace std;
int t;long long n;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%lld",&n);int ans=0;
		for(long long i=1;i*(i+1)/2<=n;i=i<<1|1) ans++,n-=i*(i+1)/2;
		printf("%d\n",ans);
	}
	return 0;
}