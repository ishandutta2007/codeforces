#include <iostream>
#include <vector>
using namespace std;
bool prime(int x)
{
	for (int i=2;i*i<=x;i++)
	{
		if (x%i==0)
		return 0;
	}
	return 1;
}
int main()
{
	int a,b;
	cin >> a >> b;
	if (a!=b)
	cout << 2;
	else
	{
		for (int i=2;i*i<=a;i++)
		{
			if (a%i)
			continue;
			if (prime(i))
			{
				cout << i;
				return 0;
			}
		}
		cout << a;
	}
}