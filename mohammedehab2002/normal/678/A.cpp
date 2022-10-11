#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	long long n,k,i;
	cin >> n >> k;
	if (k<50000)
	{
		for (i=n+1;i<=n+k;i++)
		{
			if (i%k==0)
			{
				cout << i;
				return 0;
			}
		}
	}
	else
	{
		i=0;
		while (i*k<=n)
		i++;
		cout << i*k;
	}
}