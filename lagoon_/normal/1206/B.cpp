#include<bits/stdc++.h>
using namespace std;
#define re register
int main()
{
	re int n,x,nw=0;
	re long long ans=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x<0)
		{
			ans+=-1-x;
			nw^=1;
		}else if(x==0)ans++,nw=2;
		else ans+=x-1;
	}
	if(nw==1)ans+=2;
	printf("%lld\n",ans);
}