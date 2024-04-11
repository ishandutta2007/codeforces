#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
int main()
{
	int n;
	long long x, y;
	cin >> x >> y >> n;
	int d = 1e9 + 7;
	long long c = y - x;
	if(n % 3 == 0)
	{
		n--;
		if(n / 3 % 2 == 0)
		{
			while(c < 0)
			{
				c = c + d;
			}
			cout << c % d;
		}
		else
		{
			c = -c;
			while( c < 0)
			{
				c = c + d;
			}
			cout << c % d;
		}
	}
	else if(n % 3 == 1)
	{
		n--;
		if(n / 3 % 2== 0)
		{
			while(x < 0)
			{
				x = x + d;
			}
			cout << x % d;
		}
		else
		{
			x =  - x;
			while(x < 0)
			{
				x = x + d;
			}
			cout << x % d;
		}
	}
	else if(n % 3 == 2)
	{
		n--;
		if(n / 3 % 2 == 0)
		{
			while(y < 0)
			{
				y = y + d;
			}
			cout << y % d;
		}
		else
		{
			y = - y;
			while(y < 0)
			{
				y = y + d;
			}
			cout << y % d;
		}
	}
	return 0;	
}