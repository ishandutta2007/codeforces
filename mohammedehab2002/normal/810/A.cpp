#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main()
{
	int n,k;
	cin >> n >> k;
	int sum=0,c=n;
	for (int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		sum+=a;
	}
	while (1)
	{
		int m=sum/c;
		if (2*(sum%c)>=c)
		m++;
		if (m==k)
		{
			cout << c-n;
			return 0;
		}
		else
		{
			c++;
			sum+=k;
		}
	}
}