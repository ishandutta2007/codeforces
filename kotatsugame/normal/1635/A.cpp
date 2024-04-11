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
		int A=0;
		for(int i=0;i<N;i++)
		{
			int X;cin>>X;A|=X;
		}
		cout<<A<<"\n";
	}
}