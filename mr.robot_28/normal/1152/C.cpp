#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<queue>
#include<set>
using namespace std;
#define int long long
int nod(int a, int b)
{
	if(a * b == 0)
	{
		return a + b;
	}
	else if(a > b)
	{
		return nod(a % b, b);
	}
	else
	{
		return nod(a, b % a);
	}
}
main()
{
    int a, b;
    cin >> a >> b;
    if(a > b)
    {
    	swap(a, b);
	}
	int max = 1e18, imax = 0;
	for(int i = 1; i <= sqrt(b - a); i++)
    {
    	if((b - a) % i == 0)
    	{
    		int r = (b - a) / i;
    		int r1 = (1e9 * r - a);
    		r1 = r1 % r;
    		int i1 = (1e9 * i - a);
    		i1 = i1 % i;
    		int nok1 = (a + r1) * (b + r1) / nod(a + r1, b + r1);
    		int nok2 = (a + i1) * (b + i1) / nod(a + i1, b + i1);
    		if(nok1 < max)
    		{
    			max = nok1;
    			imax = r1;
			}
			if(nok2 < max)
			{
				max = nok2;
				imax = i1;
			}
		}
	}
	cout << imax;
    return 0;
}