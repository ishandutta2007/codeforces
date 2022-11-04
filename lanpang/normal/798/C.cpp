#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , a , ans , ggg , s;

int gcd(int x , int y)
{
	if (x != 0)
	    return gcd(y%x,x);
	else
	    return y;   
}

int main ()
{
	int i;
	cin >> n;
	s = 0;
	ggg = 0;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a);
		ggg = gcd(ggg,a);
		if (a%2 == 0)
		{
			if (s%2 == 0)
			    ans += s/2;
			else
			    ans += (s+3)/2;    
			s = 0;
		}
		else
		{
			s++;
		}
	}
	if (s%2 == 0)
		ans += s/2;
	else
	    ans += (s+3)/2;    
	if (ggg > 1)
	    ans = 0;
	cout << "YES\n" << ans << "\n";
	//system("PAUSE");
	return 0;
}