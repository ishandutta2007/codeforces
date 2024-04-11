#include<iostream>
using namespace std;
int t;
string S,T;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
main()
{
	cin>>t;
	for(;t--;)
	{
		cin>>S>>T;
		int g=gcd(S.size(),T.size());
		string ans="",bns="";
		for(int i=0;i<S.size()/g;i++)ans+=T;
		for(int i=0;i<T.size()/g;i++)bns+=S;
		if(ans==bns)cout<<ans<<"\n";
		else cout<<"-1\n";
	}
}