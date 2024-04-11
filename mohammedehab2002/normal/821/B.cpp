#include <iostream>
using namespace std;
int main()
{
	int m,b;
	long long ans,res=0;
	scanf("%d%d",&m,&b);
	for (long long i=0;i<=m*b;i++)
	{
		long long y=(-i)/m+b;
		if (i%m)
		y--;
		ans=(i+1)*y*(y+1)/2+(y+1)*i*(i+1)/2;
		res=max(res,ans);
	}
	printf("%I64d",res);
}