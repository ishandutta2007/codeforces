#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		string S;cin>>S;
		int cnt[10]={};
		char mn='9';
		for(int i=S.size();i--;)
		{
			if(S[i]<=mn)
			{
				mn=S[i];
				cnt[S[i]-'0']++;
			}
			else
			{
				cnt[min(S[i]-'0'+1,9)]++;
			}
		}
		for(int i=0;i<10;i++)for(int j=0;j<cnt[i];j++)cout<<i;
		cout<<"\n";
	}
}