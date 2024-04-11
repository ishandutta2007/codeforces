#include<iostream>
using namespace std;
int T,N;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int mn=1e9,mx=0;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;
			mn=min(mn,a);
			mx=max(mx,a);
		}
		cout<<mx-mn<<"\n";
	}
}