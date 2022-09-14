#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,K;
int A[2<<17];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	sort(A,A+N);
	vector<pair<int,int> >X;
	long long Lsum=0,Rsum=0;
	for(int i=0;i<N;i++)
	{
		if(!X.empty()&&X.back().first==A[i])
		{
			X.back().second++;
		}
		else
		{
			X.push_back(make_pair(A[i],1));
		}
		Rsum+=A[i];
	}
	long long ans=1e18;
	long long Lcnt=0,Rcnt=N;
	for(pair<int,int>p:X)
	{
		long long now=0,a=p.first;
		Rcnt-=p.second;
		Rsum-=a*p.second;
		if(p.second>=K)
		{
			ans=0;
		}
		else
		{
			long long rest=K-p.second;
			if(Lcnt>=rest)
			{
				ans=min(ans,(a-1)*Lcnt+rest-Lsum);
			}
			if(Rcnt>=rest)
			{
				ans=min(ans,Rsum-(a+1)*Rcnt+rest);
			}
			if(rest>=2)
			{
				ans=min(ans,Rsum-(a+1)*Rcnt+(a-1)*Lcnt-Lsum+rest);
			}
		}
		Lcnt+=p.second;
		Lsum+=a*p.second;
	}
	printf("%lld\n",ans);
}