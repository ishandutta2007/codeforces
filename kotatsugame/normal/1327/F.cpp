#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,K,M;
const long long mod=998244353;
int dp[5<<17];
vector<pair<pair<int,int>,int> >A;
main()
{
	scanf("%d%d%d",&N,&K,&M);
	for(int i=0;i<M;i++)
	{
		int l,r,x;scanf("%d%d%d",&l,&r,&x);
		l--;
		A.push_back(make_pair(make_pair(l,r),x));
	}
	long long ans=1;
	for(int z=0;z<K;z++)
	{
		vector<pair<int,int> >y;
		vector<int>x(N+1);
		for(pair<pair<int,int>,int>p:A)
		{
			int l=p.first.first,r=p.first.second;
			if(p.second>>z&1)
			{
				x[l]++;
				x[r]--;
			}
			else
			{
				y.push_back(make_pair(r,l));
			}
		}
		sort(y.begin(),y.end());
		long long cumsum=1;
		int cnt=0;
		int iy=0,il=0;
		dp[0]=1;
		for(int i=0;i<N;i++)
		{
			cnt+=x[i];
			if(cnt>0)dp[i+1]=0;
			else
			{
				dp[i+1]=cumsum;
				cumsum*=2;
				if(cumsum>=mod)cumsum-=mod;
			}
			while(iy<y.size()&&y[iy].first==i+1)
			{
				while(il<=y[iy].second)
				{
					cumsum+=mod-dp[il++];
					if(cumsum>=mod)cumsum-=mod;
				}
				iy++;
			}
		}
		ans=ans*cumsum%mod;
	}
	printf("%lld\n",ans);
}