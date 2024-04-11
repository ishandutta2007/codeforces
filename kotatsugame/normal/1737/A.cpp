#include<iostream>
using namespace std;
int cnt[26];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N,K;string S;
		cin>>N>>K>>S;
		for(int i=0;i<26;i++)cnt[i]=0;
		for(int i=0;i<N;i++)cnt[S[i]-'a']++;
		string ans;
		for(int i=0;i<K;i++)
		{
			int t=N/K;
			int id=0;
			while(cnt[id]>0)id++;
			if(id>=t)
			{
				ans+='a'+t;
				id=t;
			}
			else ans+='a'+id;
			for(int j=0;j<id;j++)cnt[j]--;
		}
		cout<<ans<<"\n";
	}
}