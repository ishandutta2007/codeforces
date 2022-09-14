#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T;
int N;
int P[4001];
int cnt[4001];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=1;i<=N;i++)cnt[i]=0;
		for(int i=2;i<=N;i++)cin>>P[i];
		string S;cin>>S;
		int ans=0;
		for(int i=N;i>=1;i--)
		{
			if(S[i-1]=='B')cnt[i]++;
			else cnt[i]--;
			if(cnt[i]==0)ans++;
			if(i>1)cnt[P[i]]+=cnt[i];
		}
		cout<<ans<<"\n";
	}
}