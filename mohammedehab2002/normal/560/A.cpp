#include <iostream>
using namespace std;
int main()
{
	int n,a,i;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> a;
		if (a==1)
		{
			cout << -1;
			return 0;
		}
	}
	cout << 1;
}