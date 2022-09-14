#include<iostream>
using namespace std;
int T,N,K;
int cnt[31];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		for(int i=0;i<=30;i++)cnt[i]=0;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;
			for(int j=0;j<=30;j++)if(!(a>>j&1))cnt[j]++;
		}
		int ans=0;
		for(int j=30;j>=0;j--)if(cnt[j]<=K)
		{
			K-=cnt[j];
			ans|=1<<j;
		}
		cout<<ans<<"\n";
	}
}