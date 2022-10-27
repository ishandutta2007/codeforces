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
	int a, k;
	cin >> a >> k;
	while(k > 0)
	{
		if(a % 10 > k)
		{
			a=  a - k;
			k = 0;
		}
		else
		{
			if(a % 10 == 0)
			{
				k--;
				a = a / 10;
			}
			else
			{
			k = k - a % 10;
			a = a - a % 10;
		}
		}
	}
	cout << a;
	return 0;	
}