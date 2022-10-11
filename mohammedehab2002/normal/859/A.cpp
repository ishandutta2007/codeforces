#include <iostream>
using namespace std;
int main()
{
	int n,x=0;
	scanf("%d",&n);
	while (n--)
	{
		int a;
		scanf("%d",&a);
		x=max(x,a);
	}
	printf("%d",max(x-25,0));
}