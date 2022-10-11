#include <iostream>
using namespace std;
int main()
{
	int a,b,c,i;
	cin >> a >> b >> c;
	for (i=1;i*a<=c;i++)
	{
		if ((c-i*a)%b==0)
		{
			cout << "Yes";
			return 0;
		}
	}
	for (i=1;i*b<=c;i++)
	{
		if ((c-i*b)%a==0)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}