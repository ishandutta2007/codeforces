#include <iostream>
using namespace std;
int main()
{
	int n,k,carry=0;
	scanf("%d%d",&n,&k);
	long long ans=0;
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		a+=carry;
		if (i==n-1)
		{
			ans+=(a+k-1)/k;
			break;
		}
		if (carry)
		{
			ans+=max(a/k,1);
			if (a<k)
			carry=0;
			else
			carry=a%k;
		}
		else
		{
			ans+=a/k;
			carry=a%k;
		}
	}
	printf("%I64d",ans);
}