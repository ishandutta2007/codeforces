#include<iostream>
using namespace std;
int T,N,P[5000];
int cnt[5001];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>P[i];
		for(int i=1;i<=N;i++)cnt[i]=0;
		long long ans=0;
		for(int c=N;c--;)
		{
			long long now=0;
			for(int a=c;a--;)
			{
				if(P[a]<P[c])ans+=now;
				now+=cnt[P[a]];
			}
			for(int k=P[c]+1;k<=N;k++)cnt[k]++;
		}
		cout<<ans<<"\n";
	}
}