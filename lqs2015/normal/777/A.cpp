#include<iostream>
using namespace std;
int n,k,a[3];
int main()
{
	cin>>n>>k;
	n=n%6;
	a[k]=1;
	for (int i=n;i>=1;i--)
	{
		if (i%2) swap(a[0],a[1]);
		else swap(a[1],a[2]);
	}
	for (int i=0;i<=2;i++)
	{
		if (a[i]) cout<<i<<endl;
	}
	return 0;
 }