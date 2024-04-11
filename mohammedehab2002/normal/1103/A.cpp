#include <iostream>
using namespace std;
int a[2];
int main()
{
	string s;
	cin >> s;
	for (char c:s)
	{
		if (c=='0')
		{
			printf("3 %d\n",a[0]+1);
			a[0]=(a[0]+1)%4;
		}
		else
		{
			printf("1 %d\n",a[1]+1);
			a[1]=(a[1]+2)%4;
		}
	}
}