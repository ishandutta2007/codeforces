#include<iostream>
using namespace std;
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		{
			int t=max(l1,l2);
			if(t<=r1&&t<=r2)
			{
				cout<<t<<"\n";
				continue;
			}
		}
		cout<<l1+l2<<"\n";
	}
}