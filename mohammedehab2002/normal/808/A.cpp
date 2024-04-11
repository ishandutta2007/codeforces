#include <iostream>
#include <stdio.h>
using namespace std;
int pow10(int x)
{
	if (!x)
	return 1;
	return 10*pow10(x-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    int tmp=n,d=0;
    while (tmp>=10)
    tmp/=10,d++;
    printf("%d",(tmp+1)*pow10(d)-n);
}