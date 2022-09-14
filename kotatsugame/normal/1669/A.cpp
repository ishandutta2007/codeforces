#include<iostream>
using namespace std;
int T;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		int r;cin>>r;
		cout<<"Division "<<(r<1400?4:r<1600?3:r<1900?2:1)<<"\n";
	}
}