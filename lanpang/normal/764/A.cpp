#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int a, b , c , i , p=0;

int main ()
{
	scanf("%d%d%d",&a,&b,&c);
	for (i = 1 ; i <= c ; i++)
	    if (i%a==0&&i%b==0)p++;
	printf("%d\n",p);    
    //system("PAUSE");
	return 0;
}