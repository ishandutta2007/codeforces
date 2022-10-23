#include<iostream>
using namespace std;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N,M;cin>>N>>M;
		if(N==1||M==1)cout<<"1 1\n";
		else cout<<"2 2\n";
	}
}