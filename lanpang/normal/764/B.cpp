#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , a[200001] , i;

int main ()
{
	scanf("%d",&n);
	for (i = 1 ; i <= n ; i++)
	    scanf("%d",&a[i]);
	for (i = 1 ; i <= n/2 ; i++)
	    if (i % 2 == 1)
		    swap(a[i],a[n-i+1]);  
	for (i = 1 ; i < n ; i++)		  
	    printf("%d ",a[i]);
	printf("%d\n",a[n]);	    
    //system("PAUSE");
	return 0;
}