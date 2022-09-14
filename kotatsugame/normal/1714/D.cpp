#include<iostream>
#include<vector>
using namespace std;
int dp[101];
pair<int,int>pr[101];
string S,s[10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>S;
		for(int i=0;i<=S.size();i++)dp[i]=1e9;
		dp[0]=0;
		int N;cin>>N;
		for(int i=0;i<N;i++)cin>>s[i];
		for(int i=0;i<S.size();i++)
		{
			for(int j=0;j<N;j++)if(i+s[j].size()<=S.size()&&S.substr(i,s[j].size())==s[j])
			{
				for(int k=1;k<=s[j].size();k++)
				{
					if(dp[i+k]>dp[i]+1)
					{
						dp[i+k]=dp[i]+1;
						pr[i+k]=make_pair(i,j);
					}
				}
			}
		}
		int ans=dp[S.size()];
		if(ans==(int)1e9)
		{
			cout<<"-1\n";
			continue;
		}
		vector<pair<int,int> >ret;
		int id=S.size();
		while(id>0)
		{
			ret.push_back(pr[id]);
			id=pr[id].first;
		}
		cout<<ret.size()<<"\n";
		for(pair<int,int>p:ret)cout<<p.second+1<<" "<<p.first+1<<"\n";
	}
}