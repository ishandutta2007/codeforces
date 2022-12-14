#include<iostream>
#include<string>
#include<set>
using namespace std;
string s;
int n;
int dp[11111][4];
set<string> ans;
int main()
{
	cin>>s;
	n=s.size();
	dp[n][2]=dp[n][3]=1;
	for (int i=n-2;i>=5;i--)
	{
		if (dp[i+2][3] || (dp[i+2][2] && s.substr(i,2)!=s.substr(i+2,2)))
		{
			dp[i][2]=1;
			ans.insert(s.substr(i,2));
		}
		if (i==n-2) continue;
		if (dp[i+3][2] || (dp[i+3][3] && s.substr(i,3)!=s.substr(i+3,3)))
		{
			dp[i][3]=1;
			ans.insert(s.substr(i,3));
		}
	}
	cout<<ans.size()<<endl;
	for (set<string>::iterator it=ans.begin();it!=ans.end();it++)
	{
		cout<<(*it)<<endl;
	}
	return 0;
}