#include<iostream>
#include<algorithm>
using namespace std;
int T;
int dp[444];
main()
{
	cin>>T;
	for(;T--;)
	{
		string s,t;cin>>s>>t;
		bool ok=false;
		for(int k=0;k<=t.size();k++)
		{
			string t1=t.substr(0,k),t2=t.substr(k);
			for(int i=0;i<=t1.size();i++)dp[i]=-1;
			dp[0]=0;
			for(int si=0;si<s.size();si++)
			{
				for(int i=min(si,(int)t1.size());i>=0;i--)
				{
					if(dp[i]<0)continue;
					int j=dp[i];
					if(i<t1.size()&&s[si]==t1[i])dp[i+1]=max(dp[i+1],dp[i]);
					if(j<t2.size()&&s[si]==t2[j])dp[i]++;
				}
			}
			if(dp[t1.size()]==t2.size())
			{
				ok=true;
				break;
			}
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
}