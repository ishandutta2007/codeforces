#include<iostream>
using namespace std;
int T,P;
string S;
int cnt[26];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>S>>P;
		for(int i=0;i<26;i++)cnt[i]=0;
		for(char c:S)
		{
			cnt[c-'a']++;
			P-=(c-'a')+1;
		}
		for(int i=25;i>=0;i--)while(cnt[i]>0&&P<0)
		{
			cnt[i]--;
			P+=i+1;
		}
		for(char c:S)
		{
			int t=c-'a';
			if(cnt[t]>0)cnt[t]--,cout<<c;
		}
		cout<<"\n";
	}
}