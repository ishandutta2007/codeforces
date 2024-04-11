#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int main()
{
	scanf("%I64d",&n);
	for (long long i=2;i<=n;i++)
	{
		for (long long j=i+i;j<=n;j+=i)
		{
			ans+=(j/i);
		}
	}
	printf("%I64d\n",ans*4ll);
	return 0;
}