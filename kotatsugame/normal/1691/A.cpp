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
		int x=0,y=0;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;
			if(a%2==0)x++;
			else y++;
		}
		cout<<N-max(x,y)<<"\n";
	}
}