#include<bits/stdc++.h>
using namespace std;
long long l,r;int t;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%lld%lld",&l,&r);
		if(l*2<=r) printf("%lld %lld\n",l,l*2);
		else printf("-1 -1\n");
	}
	return 0;
}