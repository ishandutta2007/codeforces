#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a,b;
signed main()
{
	scanf("%lld",&n);
	for(int am=1;am<=n;am++)
	{
		scanf("%lld%lld",&a,&b);
		if(a>b) swap(a,b);
		if((a+b)%3!=0) printf("NO\n");
		else if(a*2<b) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}