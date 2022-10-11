#include <iostream>
using namespace std;
long long ans=1;
int main()
{
	int n;
	scanf("%d",&n);
	int l=-1;
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if (a==1)
		{
			if (l!=-1)
			ans*=(i-l);
			l=i;
		}
	}
	if (l==-1)
	ans=0;
	printf("%I64d",ans);
}