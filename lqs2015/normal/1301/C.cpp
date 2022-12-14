#include<bits/stdc++.h>
using namespace std;
int test,n,m,k,a,b,t,h,p;
long long ans;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		a=n-m;b=m+1;
		t=a/b;
		h=a-b*t;
		p=b-h;
		ans=1ll*n*(n+1)/2-1ll*h*(t+2)*(t+1)/2-1ll*p*(t+1)*t/2;
		printf("%lld\n",ans);
	}
	return 0;
}