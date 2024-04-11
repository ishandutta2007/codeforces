#include<iostream>
using namespace std;
int T;
string S;
int cnt[26];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>S;
		for(int i=0;i<26;i++)cnt[i]=0;
		for(char c:S)cnt[c-'a']++;
		string ret="";
		for(int i=0;i<26;i++)if(cnt[i]==2)ret+=i+'a';
		for(int i=0;i<26;i++)if(cnt[i]==1)ret+=i+'a';
		for(int i=0;i<26;i++)if(cnt[i]==2)ret+=i+'a';
		cout<<ret<<"\n";
	}
}