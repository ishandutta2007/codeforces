#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , a[200001] , b[200001] , c[200001] , f[200001] , k , ans;

int main ()
{
	int i;
	cin >> n >> k;
	for (i = 1 ; i <= n ; i++)
	    scanf("%d",&a[i]);
	for (i = 1 ; i <= n ; i++)
	{
	    scanf("%d",&b[i]);
	    c[i] = a[i]-b[i];
	    if (c[i] <= 0)
	    {
	    	ans += a[i];
	    	k--;
	    	f[i] = 1;
	    }
	    else
	        ans += b[i];
	}
	sort(c+1,c+n+1);
	i = 1;
	while (k > 0)
	{
		if (c[i] > 0)
		{
			ans += c[i];
			k--;
		}
		i++;
	}
	cout << ans << "\n";
    //system("PAUSE");
	return 0;
}