#include <iostream>
using namespace std;
int go(int x)
{
	int pow=2;
	for (int k=1;k<15;k++)
	{
		if ((pow-1)*pow/2==x)
		return 1;
		pow*=2;
	}
	return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	int ans=0;
	for (int x=1;x*x<=n;x++)
	{
		if (n%x==0)
		{
			if (go(x))
			ans=max(ans,x);
			if (go(n/x))
			ans=max(ans,n/x);
		}
	}
	printf("%d",ans);
}