#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , p;
char a[2001] , f[2001]; 

int main ()
{
	int i;
	scanf("%d%s",&n,&a);
	if (n % 2 == 0)
	{
		for (i = 1 ; i < n ; i += 2)
		{
			p = (i+1)/2;
			f[n/2-p+1] = a[i-1];
			f[n/2+p] = a[i];
		}
	    for (i = 1 ; i <= n ; i++)
		    printf("%c",f[i]);
		cout << "\n";    
	}	  
	else
	{
	    for (i = 2 ; i < n ; i += 2)
		{
			p = i/2;
			f[n/2-p+1] = a[i-1];
			f[n/2+p] = a[i];
 		}
 		if (n == 1)
 		    cout << a[0];
	    for (i = 1 ; i < n ; i++)
	    {
		    printf("%c",f[i]);
		    if (i == n/2)
		        cout << a[0];
		}
		cout << "\n";  
	}
    //system("PAUSE");
	return 0;
}