#include <iostream>
#include <algorithm>
using namespace std;
int ghadr(int a)
{
	if(a<0)
	a*=-1;
	return a;
}
int main()
{
	long long n,res=0,min=10e10,c,d;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	for (int i = 0; i < n-1; i++)
	{
			if(ghadr(a[i]-a[i+1])<min) {c=i; d=i+1; min=ghadr(a[i]-a[i+1]);}
		if(ghadr(a[0]-a[n-1])<min ) {c=0; d=n-1; min=ghadr(a[0]-a[n-1]);}
	}
	cout<<c+1<<" "<<d+1;
}