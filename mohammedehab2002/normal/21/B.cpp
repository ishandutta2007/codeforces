#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a1,b1,c1,a2,b2,c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    if (a1==0 && b1==0)
    {
    	if (c1==0)
    	{
    		if (a2==0 && b2==0 && c2)
    		cout << 0;
    		else
    		cout << -1;
		}
		else
		cout << 0;
	}
	else if (a2==0 && b2==0)
    {
    	if (c2==0)
    	cout << -1;
		else
		cout << 0;
	}
	else if (a1*b2==a2*b1)
	{
		if (a1==0 && a2==0 && b1==0 && b2==0)
		{
			if (b2*c1==b1*c2)
			cout << -1;
			else
			cout << 0;
		}
		else if (b1==0 && b2==0)
		{
			if (a2*c1==a1*c2)
			cout << -1;
			else
			cout << 0;
		}
		else if (b2*c1==b1*c2)
		cout << -1;
		else
		cout << 0;
	}
	else
	cout << 1;
}