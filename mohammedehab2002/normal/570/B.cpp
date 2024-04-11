#include <iostream>
using namespace std;
int main()
{
	int a,b;
	cin >> a >> b;
	if (a==1 && b==1)
	{
		cout << 1;
		return 0;
	}
	if (b>a/2)
	cout << b-1;
	else
	cout << b+1;
}