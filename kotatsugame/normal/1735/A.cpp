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
		cout<<(N-6)/3<<"\n";
	}
}