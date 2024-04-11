#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",min(3*a+3,min(3*b,3*c-3)));
}