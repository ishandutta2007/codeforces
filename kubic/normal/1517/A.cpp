#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T,ans;ll n;
void slv()
{
	scanf("%lld",&n);ans=0;
	if(n%2050) {puts("-1");return;}
	n/=2050;for(;n;n/=10) ans+=n%10;
	printf("%d\n",ans);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}