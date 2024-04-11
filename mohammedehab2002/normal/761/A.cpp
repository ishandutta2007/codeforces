#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int a,b;
	cin >> a >> b;
	if (b==0 && a==0)
	{
		cout << "NO";
		return 0;
	}
	if (abs(a-b)<=1)
	cout << "YES";
	else
	cout << "NO";
}