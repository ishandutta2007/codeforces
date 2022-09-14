#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;
		cin>>N;
		long long ans=0;
		ans+=N/1;
		ans+=N/2;
		ans+=N/3;
		ans+=N/2;
		ans+=N/3;
		cout<<ans<<"\n";
	}
}