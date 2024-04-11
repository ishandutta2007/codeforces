#include<iostream>
using namespace std;
int N,P;
string S[40];
main()
{
	cin>>N>>P;
	for(int i=0;i<N;i++)cin>>S[i];
	long long ans=0,now=0;
	for(int i=N;i--;)
	{
		now*=2;
		if(S[i]=="halfplus")now++;
		ans+=now*P/2;
	}
	cout<<ans<<endl;
}