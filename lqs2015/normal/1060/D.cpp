#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,a[111111],b[111111],ans;
int main()
{
	scanf("%I64d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&a[i],&b[i]);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++)
	{
		ans+=max(a[i],b[i]);
	}
	printf("%I64d\n",ans+n);
	return 0;
}