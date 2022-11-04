#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , a[101] , b[101] , f[6] , fa[6] , fb[6] , c , ans;

int main ()
{
	int i;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
	    cin >> a[i];
	    f[a[i]]++;
	    fa[a[i]]++;
	}
	for (i = 1 ; i <= n ; i++)
	{
	    cin >> b[i];
	    f[b[i]]++;
	    fb[b[i]]++;
	}
	for (i = 1 ; i <= 5 ; i++)
	{
		if (f[i]%2 != 0)
		{
			c = -1;
			break;
		}
		f[i] /= 2;
	}
	if (c == -1)
	    cout << c << "\n";
	else
	{
		for (i = 1 ; i <= 5 ; i++)
			ans += fabs(fa[i]-f[i]);
		cout << ans/2 << "\n";	
	}    
    //system("PAUSE");
	return 0;
}