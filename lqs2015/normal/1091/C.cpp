#include<bits/stdc++.h>
using namespace std;
long long n,x,ans[11111],cnt;
long long calc(long long x)
{
	return (1ll+(n-x+1ll))*(n/x)/2;
}
int main()
{
	cin>>n;
	x=sqrt(n);
	for (long long i=1;i<=x;i++)
	{
		if (n%i==0)
		{
			ans[++cnt]=calc(i);
			if (i!=n/i) ans[++cnt]=calc(n/i);
 		}
	}
	sort(ans+1,ans+cnt+1);
	for (int i=1;i<=cnt;i++) printf("%I64d ",ans[i]);
	printf("\n");
	return 0;
}