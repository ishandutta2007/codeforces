#include <bits/stdc++.h>
using namespace std;
int ans[55];
long long fib[55];
int main()
{
	int n;
	long long k;
	scanf("%d%I64d",&n,&k);
	fib[0]=1;
	fib[1]=1;
	for (int i=2;i<=n;i++)
	fib[i]=fib[i-1]+fib[i-2];
	for (int i=1;i<=n;i++)
	{
		if (fib[n-i]>=k)
		ans[i]=i;
		else
		{
			ans[i]=i+1;
			ans[i+1]=i;
			k-=fib[n-i];
			i++;
		}
	}
	for (int i=1;i<=n;i++)
	printf("%d ",ans[i]);
}