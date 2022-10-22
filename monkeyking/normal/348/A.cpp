#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	long long s=0,maxi=0,x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		s+=x;
		maxi=max(maxi,x);
	}
	s=s/(n-1)+!(!(s%(n-1))); 
//	s=ceil(s/(n-1));
	cout<<max(maxi,s);
	return 0;
}