#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int n,a,i;
	float res,ans=0;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> a;
		ans+=a;
	}
	res=ans/(n*100)*100;
	printf ("%9.7f",res);
}