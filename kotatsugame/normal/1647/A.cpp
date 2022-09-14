#include<iostream>
using namespace std;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		if(N%3==0)
		{
			for(int i=0;i<N/3;i++)cout<<"21";
		}
		else if(N%3==1)
		{
			for(int i=0;i<N/3;i++)cout<<"12";
			cout<<"1";
		}
		else if(N%3==2)
		{
			for(int i=0;i<N/3;i++)cout<<"21";
			cout<<"2";
		}
		cout<<"\n";
	}
}