#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,K;
vector<int>L,R;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		L.clear();
		R.clear();
		for(int i=0;i<N;i++)
		{
			int x;scanf("%d",&x);
			(x>=0?R:L).push_back(x);
		}
		sort(L.begin(),L.end());
		sort(R.begin(),R.end());
		long long ans=0;
		long long mx=0;
		for(int i=R.size();i>0;i-=K)
		{
			ans+=R[i-1]*2;
			if(mx<R[i-1])mx=R[i-1];
		}
		for(int i=0;i<L.size();i+=K)
		{
			ans-=L[i]*2;
			if(mx<-L[i])mx=-L[i];
		}
		printf("%lld\n",ans-mx);
	}
}