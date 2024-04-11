#include<iostream>
using namespace std;
int t;
main()
{
	cin>>t;
	for(;t--;)
	{
		int h,m;cin>>h>>m;
		cout<<(23-h)*60+(60-m)<<endl;
	}
}