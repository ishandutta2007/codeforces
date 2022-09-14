#include<iostream>
using namespace std;
int T,N;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		int Z;
		cin>>N>>Z;
		int ans=0;
		for(int i=0;i<N;i++)
		{
			int A;cin>>A;
			ans=max(ans,A|Z);
		}
		cout<<ans<<"\n";
	}
}