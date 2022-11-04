#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int main ()
{
	int n , a[101] , ma , sum=0 , i;
	scanf("%d",&n);
	for (i = 1 ; i <= n ; i++)
	{
	    scanf("%d",&a[i]);
	    if (i == 1)
	        ma = a[i];
	    else
		    if (a[i] > ma) ma = a[i];    
	}
	for (i = 1 ; i <= n ; i++)
	    sum += ma-a[i];
	printf("%d\n",sum);
    //system("PAUSE");
	return 0;
}