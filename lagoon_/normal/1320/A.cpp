#include<bits/stdc++.h>
#define re register
int b[200100];
long long qwq[600100];
int main()
{
	re int n;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		qwq[i-b[i]+400010]+=b[i];
	}
	re long long ans=0;
	for(re int i=1;i<=600010;i++)ans=std::max(ans,qwq[i]);
	printf("%lld\n",ans);
}