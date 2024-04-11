#include <iostream>
using namespace std;
int main()
{
	int n,i=1;
	scanf("%d",&n);
	for (;i*i<=n;i++);
	i--;
	printf("%d",2*(n/i+i)+2*(n%i!=0));
}