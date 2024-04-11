#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

int k , a[10] , sum , ans;
char c; 

int main ()
{
	int i , t;
	cin >> k;
	sum = 0;
	c = getchar();
	c = getchar();
	while (c >= '0' && c <= '9')
	{
		a[c-'0']++;
		sum += c-'0';
		c = getchar();
	}
	if (sum >= k)
	{
		cout << "0\n";
	}
	else
	{
		ans = 0;
		for (i = 0 ; i <= 8 ; i++)
		{
			t = (k-sum)/(9-i);
			if (t >= a[i])
			{
				ans += a[i];
				sum += a[i]*(9-i);
				if (sum == ans)
			    	break;
			}
			else
			{
				if ((k-sum)%(9-i) == 0)
					ans += t;
				else	
				 	ans += t+1;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}