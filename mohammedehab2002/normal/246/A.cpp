#include <iostream>
using namespace std;
int main()
{
	int n,i;
	cin >> n;
	if (n<3)
	cout << -1;
	else
	{
		for (i=n;i>0;i--)
		cout << i << " ";
	}
}