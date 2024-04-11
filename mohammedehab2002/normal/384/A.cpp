#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n,i,x;
	cin >> n;
	if (n%2)
	{
		cout << (n/2+1)*(n/2+1)+(n/2)*(n/2) << endl;
		for (i=0;i<n;i++)
		{
			for (x=0;x<n;x++)
			{
				if (i%2==0 && x%2==0)
				cout << 'C';
				else if (i%2 && x%2)
				cout << 'C';
				else
				cout << '.';
			}
			cout << endl;
		}
	}
	else
	{
		cout << n*n/2 << endl;
		for (i=0;i<n;i++)
		{
			for (x=0;x<n;x++)
			{
				if (i%2 && x%2==0)
				cout << 'C';
				else if (i%2==0 && x%2)
				cout << 'C';
				else
				cout << '.';
			}
			cout << endl;
		}
	}
}