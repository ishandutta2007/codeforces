#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , a[100002] , f[100002] , h[100002];

int main ()
{
	int i , j , t , ma , p , mm=1;
	scanf("%d",&n);
	for (i = 2 ; i <= n+1 ; i++)
	{
		t = sqrt(i);
		ma = 0;
		p = 0;
		for (j = 2 ; j <= t ; j++)
		{
			if (i%j == 0)
			    p = 1;
		    if (i%j == 0 && f[j] == -1)
		        ma = max(ma,h[j]);
		}
		ma++;
		mm = max(ma,mm);
		a[i] = ma;
		if (p == 0)
		{
			f[i] = -1;
			h[i] = ma;
		}
	}
	cout << mm << "\n";
	for (i = 2 ; i <= n ; i++)
	    printf("%d ",a[i]);
	cout << a[n+1] << "\n";    
    //system("PAUSE");
	return 0;
}