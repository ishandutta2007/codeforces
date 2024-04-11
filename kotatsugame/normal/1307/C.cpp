#include<iostream>
#include<algorithm>
using namespace std;
string s;
int cnt[26];
main()
{
	cin>>s;
	long long ans=0;
	for(int i=0;i<s.size();i++)cnt[s[i]-'a']++;
	for(int i=0;i<26;i++)ans=max(ans,(long long)cnt[i]);
	for(char a='a';a<='z';a++)for(char b='a';b<='z';b++)
	{
		long long now=0,cnta=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==b)now+=cnta;
			if(s[i]==a)cnta++;
		}
		ans=max(ans,now);
	}
	cout<<ans<<endl;
}