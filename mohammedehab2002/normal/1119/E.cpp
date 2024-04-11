#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	long long pen=0,ans=0;
	while (n--)
	{
		int a;
		scanf("%d",&a);
		int tmp=min(a/2LL,pen);
		a-=2*tmp;
		ans+=tmp+a/3;
		pen+=a%3-tmp;
	}
	printf("%I64d",ans);
}