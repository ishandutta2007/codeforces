#include<iostream>
using namespace std;
int n,a,b;
main()
{
	cin>>n>>a>>b;
	int f=1,l=a+b+1;
	for(int i=0;i<99;i++)
	{
		int m=(f+l)/2;
		int c=a/m+b/m;
		if(c>=n)f=m;
		else l=m;
	}
	if(f<=a&&f<=b)cout<<f<<endl;
	else cout<<(a<b?a:b)<<endl;
}