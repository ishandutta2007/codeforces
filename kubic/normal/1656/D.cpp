#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T;ll n,t;
void slv()
{
	scanf("%lld",&n);if(n&1) {puts("2");return;}
	t=n;while(!(t&1)) t/=2;
	if(t>1)
	{
		if((t+1)/2<=n/t) printf("%lld\n",t);
		else printf("%lld\n",n/t*2);return;
	}puts("-1");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}