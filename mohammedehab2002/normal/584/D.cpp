#include <iostream>
#include <string.h>
using namespace std;
bool is_prime(int x)
{
	int i;
	for (i=2;i*i<=x;i++)
	{
		if (x%i==0)
		return false;
	}
	return true;
}
int main()
{
	int n,i;
	cin >> n;
	if (is_prime(n))
	cout << 1 << endl << n;
	else
	{
		cout << 3 << endl << 3 << ' ';
		n-=3;
		for (i=3;i<n;i+=2)
		{
			if (is_prime(i) && is_prime(n-i))
			{
				cout << i << ' ' << n-i;
				break;
			}
		}
	}
}