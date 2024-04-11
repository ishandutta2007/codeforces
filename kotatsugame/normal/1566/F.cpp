#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,M;
long long A[2<<17];
vector<pair<int,int> >seg;
long long mR[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)scanf("%lld",&A[i]);
		A[N++]=-1e10;
		A[N++]=1e10;
		sort(A,A+N);
		seg.clear();
		for(int i=0;i<M;i++)
		{
			int l,r;scanf("%d%d",&l,&r);
			int id=lower_bound(A,A+N,(long long)l)-A;
			if(id<N&&A[id]<=r)continue;
			seg.push_back(make_pair(l,r));
		}
		sort(seg.begin(),seg.end());
		long long dp0=0,dp1=0;
		int segl=0;
		for(int i=0;i+1<N;i++)
		{
			int segr=segl;
			while(segr<seg.size()&&seg[segr].second<A[i+1])segr++;
			mR[segr]=A[i+1];
			for(int j=segr-1;j>=segl;j--)mR[j]=min(mR[j+1],(long long)seg[j].second);
			long long ndp0=1e18,ndp1=1e18;
			for(int j=segl;j<=segr;j++)
			{
				long long l=j==segl?0LL:seg[j-1].first-A[i];
				long long r=A[i+1]-mR[j];
				ndp0=min({ndp0,dp0+l+r*2,dp1+l*2+r*2});
				ndp1=min({ndp1,dp0+l+r,dp1+l*2+r});
			}
			dp0=ndp0;
			dp1=ndp1;
			segl=segr;
		}
		printf("%lld\n",min(dp0,dp1));
	}
}