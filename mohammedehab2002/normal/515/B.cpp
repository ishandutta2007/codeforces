#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int n,m,b,g,i,a,arr[105];
	memset(arr,0,sizeof(arr));
	cin >> n >> m >> b;
	int gcd=__gcd(n,m);
	for (i=0;i<b;i++)
	{
		cin >> a;
		arr[a%gcd]=1;
	}
	cin >> g;
	for (i=0;i<g;i++)
	{
		cin >> a;
		arr[a%gcd]=1;
	}
	for (i=0;i<gcd;i++)
	{
		if (arr[i]==0)
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}