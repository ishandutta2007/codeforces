#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;ll a,b,ans[3];
int main()
{
	scanf("%lld %lld",&b,&a);if(a<b) {puts("-1");return 0;}a-=b;
	if(a&1) {puts("-1");return 0;}
	for(int i=0;i<63;++i)
	{
		if((a>>i)&1) ans[0]|=(1ll<<i-1),ans[1]|=(1ll<<i-1);
		if((b>>i)&1) ans[2]|=(1ll<<i);
	}
	for(int i=0,t;i<63;++i)
	{
		t=((ans[0]>>i)&1)+((ans[1]>>i)&1)+((ans[2]>>i)&1);
		for(int j=0;j<3;++j) if((ans[j]>>i)&1) ans[j]^=1ll<<i;
		for(int j=0;j<t;++j) ans[j]|=1ll<<i;
	}for(int i=0;i<3;++i) if(ans[i]) ++n;printf("%d\n",n);
	for(int i=0;i<3;++i) if(ans[i]) printf("%lld ",ans[i]); 
	return 0;
}