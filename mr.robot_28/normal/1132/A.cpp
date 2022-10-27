#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
	int a, b, c , d;
	cin >> a >> b >> c >> d;
	if(a == d)
	{
		if(c != 0 && a > 0)
		{
			cout << 1;
		}
		else if(c == 0)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		cout << 0;
	}
    return 0;
}