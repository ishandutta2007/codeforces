#include <bits/stdc++.h>
#define int long long
using namespace std;
int l,r;
signed main()
{
	scanf("%lld%lld",&l,&r);
	printf("YES\n");
	for(int i=l;i<=r;i+=2) printf("%lld %lld\n",i,i+1);
	return 0;
}