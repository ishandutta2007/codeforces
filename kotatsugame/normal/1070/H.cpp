#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int N;
map<string,int>cnt;
map<string,string>mp;
main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		string s;
		cin>>s;
		vector<string>now;
		for(int j=0;j<s.size();j++)for(int k=1;j+k<=s.size();k++)
		{
			string t=s.substr(j,k);
			now.push_back(t);
		}
		sort(now.begin(),now.end());
		now.erase(unique(now.begin(),now.end()),now.end());
		for(const string&t:now)
		{
			cnt[t]++;
			mp[t]=s;
		}
	}
	int Q;
	cin>>Q;
	for(;Q--;)
	{
		string s;
		cin>>s;
		if(cnt.find(s)==cnt.end())
		{
			cout<<"0 -\n";
		}
		else
		{
			cout<<cnt[s]<<" "<<mp[s]<<"\n";
		}
	}
}