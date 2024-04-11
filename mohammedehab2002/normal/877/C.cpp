#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",2*(n/2)+(n+1)/2);
	for (int i=2;i<=n;i+=2)
	printf("%d ",i);
	for (int i=1;i<=n;i+=2)
	printf("%d ",i);
	for (int i=2;i<=n;i+=2)
	printf("%d ",i);
}