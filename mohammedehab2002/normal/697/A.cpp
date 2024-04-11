#include <iostream>
using namespace std;
int main()
{
	long long t,s,x;
	cin >> t >> s >> x;
	x-=t;
	if (!x)
	{
		cout << "YES";
		return 0;
	}
	x-=s;
	if (x<0)
	{
		cout << "NO";
		return 0;
	}
	if (x%s==0 || (x-1)%s==0)
	cout << "YES";
	else
	cout << "NO";
}