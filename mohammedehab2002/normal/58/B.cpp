#include <iostream>
using namespace std;
int main()
{
	int n,i,mod;
	cin >> n;
	if (n!=1)
	cout << n << " ";
	again: for (i=2;i<=n;i++)
	{
		mod=n%i;
		if (mod==0)
		{
			n=n/i;
			break;
		}
	}
	cout << n << " ";
	if (n!=1)
	goto again;
}