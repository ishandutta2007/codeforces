#include<iostream>
#include<vector>
using namespace std;
string S;
int cnt[26];
main()
{
	cin>>S;
	for(char c:S)cnt[c-'a']++;
	vector<int>id;
	for(int i=0;i<26;i++)if(cnt[i]%2)id.push_back(i);
	if(S.size()%2==0)
	{
		for(int i=0;i<id.size();i++)
		{
			if(i*2<id.size())cnt[id[i]]++;
			else cnt[id[i]]--;
		}
		for(int i=0;i<26;i++)
		{
			for(int j=0;j*2<cnt[i];j++)cout<<(char)(i+'a');
		}
		for(int i=26;i--;)
		{
			for(int j=0;j*2<cnt[i];j++)cout<<(char)(i+'a');
		}
	}
	else
	{
		int d;
		for(int i=0;i<id.size();i++)
		{
			if(i==id.size()/2)d=id[i];
			else if(i*2<id.size())cnt[id[i]]++;
			else cnt[id[i]]--;
		}
		for(int i=0;i<26;i++)
		{
			for(int j=0;j*2+1<cnt[i];j++)cout<<(char)(i+'a');
		}
		cout<<(char)(d+'a');
		for(int i=26;i--;)
		{
			for(int j=0;j*2+1<cnt[i];j++)cout<<(char)(i+'a');
		}
	}
	cout<<endl;
}