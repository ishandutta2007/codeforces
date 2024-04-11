#include <iostream>
using namespace std;
int main()
{
	int n,f;
	scanf("%d%d",&n,&f);
	if (n==1)
	{
		printf("%d",f);
		return 0;
	}
	long long ans=abs(f);
	int mn=abs(f);
	bool s=1;
	for (int i=1;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		ans+=abs(a);
		mn=min(mn,abs(a));
		s&=(a>0)==(f>0);
	}
	if (s)
	ans-=2*mn;
	printf("%I64d",ans);
}