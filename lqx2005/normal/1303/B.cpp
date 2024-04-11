#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100;
int T,n,a,b;
signed main()
{
	scanf("%lld",&T);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%lld%lld%lld",&n,&a,&b);
		int to=(n+1)/2;
		int step=to/a;
		int ans=0;
		if(step*a==to) ans=step*(a+b)-b;
		else ans=step*(a+b)+to%a;
		if(ans<n) ans=n;
		printf("%lld\n",ans);
	}
	return 0;
}