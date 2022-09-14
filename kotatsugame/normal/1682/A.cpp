#include<iostream>
using namespace std;
int T,N;
string S;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>S;
		if(N%2==0)
		{
			int ans=0;
			char c=S[N/2];
			while(N/2>ans&&S[N/2-1-ans]==c&&S[N/2+ans]==c)ans++;
			cout<<ans*2<<"\n";
		}
		else
		{
			int ans=0;
			char c=S[N/2];
			while(N/2>ans&&S[N/2-1-ans]==c&&S[N/2+1+ans]==c)ans++;
			cout<<ans*2+1<<"\n";
		}
	}
}