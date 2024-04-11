#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d",max(abs(a-c),abs(b-d)));
}