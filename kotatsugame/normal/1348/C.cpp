#include<iostream>
#include<vector>
using namespace std;
int T,N,K;
string s;
int cnt[26];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K>>s;
		for(int i=0;i<26;i++)cnt[i]=0;
		for(int i=0;i<N;i++)cnt[s[i]-'a']++;
		int L=-1,R=-1;
		int id=0;
		for(int i=0;i<K;i++)
		{
			while(cnt[id]==0)id++;
			cnt[id]--;
			if(L==-1)
			{
				L=R=id;
			}
			else
			{
				R=id;
			}
		}
		if(L!=R)
		{
			cout<<(char)(R+'a')<<endl;
		}
		else
		{
			vector<int>ids;
			for(int i=0;i<26;i++)if(cnt[i]>0)ids.push_back(i);
			if(ids.size()>=2)
			{
				string ans="";
				ans+=L+'a';
				for(int i=0;i<26;i++)for(int j=0;j<cnt[i];j++)ans+=i+'a';
				cout<<ans<<endl;
			}
			else if(ids.size()==1)
			{
				int T=cnt[ids[0]];
				int l=(T+K-1)/K;
				string ans="";
				ans+=L+'a';
				for(int i=0;i<l;i++)ans+=ids[0]+'a';
				cout<<ans<<endl;
			}
			else
			{
				cout<<(char)(L+'a')<<endl;
			}
		}
	}
}