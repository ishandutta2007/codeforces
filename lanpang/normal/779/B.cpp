#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , a[11] , k , f0 , t , ans;
long long f;

int main ()
{
	int i;
	cin >> f >> k;
	if (f == 0)
	    cout << "0\n";
	else
	{    
	    while (f > 0)
	    {
	    	if (f%10 == 0)
	    	    f0++;
	    	n++;
	    	a[n] = f%10;
	    	f /= 10;
	    }
	    if (f0 < k)
	        cout << n-1 << "\n";
	    else
		{
			for (i = 1 ; i <= n && t < k ; i++)
			{
				if (a[i] == 0)
				    t++;
				else
				    ans++;    
			}
			cout << ans << "\n";
		}    
    }
    //system("PAUSE");
	return 0;
}