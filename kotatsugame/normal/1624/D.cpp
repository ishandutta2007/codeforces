#include<iostream>
using namespace std;
int T,N,K;
string S;
int cnt[26];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K>>S;
		for(int i=0;i<26;i++)cnt[i]=0;
		for(int i=0;i<N;i++)cnt[S[i]-'a']++;
		int ans=1;
		{//even
			int sum=0;
			for(int i=0;i<26;i++)sum+=cnt[i]/2;
			sum/=K;
			ans=max(ans,sum*2);
		}
		{//odd
			int rest=K;
			for(int i=0;i<26;i++)if(cnt[i]%2==1&&rest>0)rest--,cnt[i]--;
			for(int i=0;i<26;i++)
			{
				int t=min(cnt[i]/2,(rest+1)/2);
				cnt[i]-=2*t;
				rest-=2*t;
				if(rest<=0)break;
			}
			int sum=0;
			for(int i=0;i<26;i++)sum+=cnt[i]/2;
			sum/=K;
			ans=max(ans,sum*2+1);
		}
		cout<<ans<<"\n";
	}
}