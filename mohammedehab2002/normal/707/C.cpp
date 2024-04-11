#include <iostream>
using namespace std;
int main()
{
	long long a,b,c;
	cin >> a;
	if (a<3)
	{
		cout << -1;
		return 0;
	}
	if (a%2)
	{
		b=(a*a+1)/2;
		c=(a*a-1)/2;
	}
	else
	{
		b=a*a/4+1;
		c=a*a/4-1;
	}
	cout << b << ' ' << c;
}