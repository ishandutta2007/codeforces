#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int a , b , c , f; 

int main ()
{
	scanf("%d%d%d",&a,&b,&c);
	f = min(min(a,b/2),c/4);
	f *= 7;
	printf("%d\n",f);     
    //system("PAUSE");
	return 0;
}