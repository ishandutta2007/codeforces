#include<iostream>
#include<vector>
using namespace std;
int T;
string s,t;
vector<int>is,it;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		int N;cin>>N>>s>>t;
		if(s[0]!=t[0]||s[N-1]!=t[N-1])
		{
			cout<<"-1\n";
			continue;
		}
		is.clear();
		it.clear();
		for(int i=1;i<N;i++)
		{
			if(s[i-1]!=s[i])is.push_back(i-1);
			if(t[i-1]!=t[i])it.push_back(i-1);
		}
		if(is.size()!=it.size())
		{
			cout<<"-1\n";
			continue;
		}
		long long ans=0;
		for(int i=0;i<is.size();i++)ans+=abs(is[i]-it[i]);
		cout<<ans<<"\n";
	}
}