#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=n-n%2-1;i>=1;i-=2)
	printf("%d ",n-i);
	for (int i=1;i<n;i+=2)
	printf("%d ",n-i);
	for (int i=2-n%2;i<n;i+=2)
	printf("%d ",i);
	printf("%d ",n);
	for (int i=n-2;i>=1;i-=2)
	printf("%d ",i);
	printf("%d",n);
}