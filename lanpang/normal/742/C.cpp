#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , a[101] , f[101]; 
long long ans=1 , h;

int gcd(int x , int y)
{
	if (x == 0)
	    return y;
	else
	    return gcd(y%x,x);    
}

int main ()
{
	int i , t , p;
	scanf("%d",&n);
    for (i = 1 ; i <= n ; i++)
    	scanf("%d",&a[i]);
    for (i = 1 ; i <= n ; i++)	
    {
    	t = 1;
    	p = a[i];
    	while (p != i)
    	{
    		t++;
    		p = a[p];
    		if (t > 100)
    		{
    			t = -1;
    			break;
    		}
    	}
    	if (t != -1)
    	{
            if (t%2==0)
			    f[i] = t/2;
			else	 
    	        f[i] = t;
    	}
    	else
			break;
    }
    if (t == -1)
        printf("-1\n");
    else
	{
	    for (i = 1 ; i <= n ; i++)
	    {
	    	h = gcd(ans,f[i]);
	    	if (h != 0)
			    ans /= h;
			ans *= f[i];  
	    }
	    printf("%I64d\n",ans);
	}    
    //system("PAUSE");
	return 0;
}