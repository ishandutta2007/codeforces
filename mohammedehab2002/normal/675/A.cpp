#include <iostream>
using namespace std;
int main()
{
	long long a,b,c;
	cin >> a >> b >> c;
	if (a==b)
	{
		cout << "YES";
		return 0;
	}
	if (c==0)
	{
		cout << "NO";
		return 0;
	}
	if (((b-a)/c)<=0)
	cout << "NO";
	else
	{
		if ((long long)(b-a)%c)
		cout << "NO";
		else
		cout << "YES";
	}
}