#include<iostream>
using namespace std;
int T,N;
int cnt[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=1;i<=N;i++)cnt[i]=0;
		int ans=-1;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;
			if(++cnt[a]>=3)ans=a;
		}
		cout<<ans<<"\n";
	}
}