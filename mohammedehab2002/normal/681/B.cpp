#include <iostream>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	for (int a=0;a<=n/1234567;a++)
	{
		for (int b=0;b<=(n-a*1234567)/123456;b++)
		{
			if ((n-(a*1234567+b*123456))%1234==0)
			{
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}