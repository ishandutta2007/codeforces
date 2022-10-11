#include <iostream>
#include <math.h>
using namespace std;
int abs(int a,int b)
{
	if (a>b)
	return a-b;
	return b-a;
}
int main()
{
	int n,i,p1,pn;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	{
		cin >> arr[i];
		if (arr[i]==1)
		p1=i;
		if (arr[i]==n)
		pn=i;
	}
	cout << max(abs(0,p1),max(abs(0,pn),max(abs(n-1,p1),abs(n-1,pn))));
}