#include <iostream>
using namespace std;
int main()
{
	int n,d,h;
	scanf("%d%d%d",&n,&d,&h);
	if (d>2*h || n<=d || (h==1 && d==1 && n!=2))
	{
		printf("-1");
		return 0;
	}
	for (int i=0;i<d;i++)
	{
		if (i==h)
		printf("1 %d\n",i+2);
		else
		printf("%d %d\n",i+1,i+2);
	}
	for (int i=d+1;i<n;i++)
	printf("%d %d\n",h,i+1);
}