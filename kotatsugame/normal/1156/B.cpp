#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T;
int cnt[26];
main()
{
	cin>>T;
	for(;T--;)
	{
		string s;cin>>s;
		for(int i=0;i<26;i++)cnt[i]=0;
		for(int i=0;i<s.size();i++)cnt[s[i]-'a']++;
		vector<pair<char,int> >a;
		for(int i=0;i<26;i++)
		{
			if(cnt[i]==0)continue;
			a.push_back(make_pair((char)(i+'a'),cnt[i]));
		}
		string ans="";
		if(a.size()==3&&a[0].first+1==a[1].first)
		{
			reverse(a.begin(),a.end());
		}
		for(int i=1;i<a.size();i+=2)
		{
			for(int j=0;j<a[i].second;j++)ans+=a[i].first;
		}
		for(int i=0;i<a.size();i+=2)
		{
			for(int j=0;j<a[i].second;j++)ans+=a[i].first;
		}
		bool flag=1;
		for(int i=1;i<ans.size();i++)
		{
			if(abs((int)ans[i]-(int)ans[i-1])==1)
			{
				flag=0;
				break;
			}
		}
		cout<<(flag?ans:"No answer")<<endl;
	}
}