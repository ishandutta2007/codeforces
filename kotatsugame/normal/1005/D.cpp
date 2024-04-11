#include<iostream>
#include<algorithm>
using namespace std;
string S;
int s[2<<17],dp[2<<17];
main()
{
	cin>>S;
	for(int i=0;i<S.size();i++)
	{
		s[i+1]=(s[i]+S[i]-'0')%3;
	}
	for(int i=0;i<S.size();i++)
	{
		bool ex[3]={};
		for(int j=i;j>=0;j--)
		{
			if(ex[s[j]])break;
			ex[s[j]]=true;
			dp[i+1]=max(dp[i+1],dp[j]+(s[i+1]==s[j]));
		}
	}
	cout<<dp[S.size()]<<endl;
}