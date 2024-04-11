#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	long long ans=0;
	for (int i=2;i<=n;i++)
	{
		for (int j=2*i;j<=n;j+=i)
		ans+=4*(j/i);
	}
	printf("%I64d",ans);
}