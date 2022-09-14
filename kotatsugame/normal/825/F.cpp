#include<iostream>
using namespace std;
//Longest Common Prefix(s,s.substr(i)) O(|s|)
#include<vector>
#include<string>
vector<int>Zalgo(const string&s)
{
	vector<int>ret(s.size());
	if(s.empty())return ret;
	ret[0]=s.size();
	int i=1,j=0;
	while(i<s.size())
	{
		while(i+j<s.size()&&s[j]==s[i+j])j++;
		ret[i]=j;
		if(j==0)
		{
			i++;
			continue;
		}
		int k=1;
		while(i+k<s.size()&&k+ret[k]<j)ret[i+k]=ret[k],k++;
		i+=k;j-=k;
	}
	return ret;
}
string S;
int dp[8080];
int p[8080];
bool vis[8080];
main()
{
	cin>>S;
	for(int i=1;i<=S.size();i++)
	{
		dp[i]=1e9;
		int t=i;
		while(t)t/=10,p[i]++;
	}
	for(int i=0;i<S.size();i++)
	{
		vector<int>now=Zalgo(S.substr(i));
		for(int j=i+1;j<=S.size();j++)vis[j]=false;
		for(int j=i+1;j<=S.size();j++)if(!vis[j])
		{
			int c=1;
			int l=j-i;
			int pos=j;
			while(true)
			{
				dp[pos]=min(dp[pos],dp[i]+p[c]+l);
				vis[pos]=true;
				c++;
				if(pos<S.size()&&now[pos-i]>=l)pos+=l;
				else break;
			}
		}
	}
	cout<<dp[S.size()]<<endl;
}