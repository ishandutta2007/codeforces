#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , a , b , fa , fb , c , i; 
char cc;

int main ()
{
	scanf("%d%d%d",&n,&a,&b);
	cc = getchar();
	for (i = 1 ; i <= n ; i++)
	{
	    cc = getchar();
	    c = cc-'0';	    
		if (i == a)
	        fa = c;
	    if (i == b)
		    fb = c;    
	}
	fa = fa-fb;
	if (fa < 0) fa = -fa;
	printf("%d\n",fa);
    //system("PAUSE");
	return 0;
}