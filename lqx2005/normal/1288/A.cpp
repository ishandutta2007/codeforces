#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1000000000000000;
int t,n,d;
signed main()
{
	scanf("%lld",&t);
	for(int tot=1;tot<=t;tot++)
	{
		scanf("%lld%lld",&n,&d);
		int X=sqrt(d),det=inf;
		X--;
		for(int i=X;i<=X+10;i++) det=min(det,i+(int)ceil((double)d/(i+1)));
		if(det<=n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}