#include<iostream>
using namespace std;
int T,N;
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>S;
		if(N==1)cout<<"YES\n";
		else if(N==2)
		{
			cout<<(S[0]==S[1]?"NO\n":"YES\n");
		}
		else cout<<"NO\n";
	}
}