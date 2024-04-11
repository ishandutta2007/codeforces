#include<iostream>
#include<algorithm>
using namespace std;
int T,N,K;
long long A[100];
int cnt[2<<17],ctm[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	int tm=0;
	for(;T--;)
	{
		tm++;
		cin>>N>>K;
		for(int i=0;i<N;i++)cin>>A[i];
		sort(A,A+N);
		int ans=0;
		for(int i=0;i<N-2*K;i++)ans+=A[i];
		int mxc=0;
		for(int i=N-2*K;i<N;i++)
		{
			int a=A[i];
			if(ctm[a]<tm)ctm[a]=tm,cnt[a]=0;
			cnt[a]++;
			if(mxc<cnt[a])mxc=cnt[a];
		}
		if(mxc<=K);
		else ans+=mxc-K;
		cout<<ans<<"\n";
	}
}