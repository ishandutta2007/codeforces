#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,A[4<<17],T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<pair<int,int> >ai(N);
		long long ans=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			ai[i]=make_pair(A[i],i);
			if(i>0)ans+=abs(A[i-1]-A[i]);
		}
		ans+=A[0]+A[N-1];
		sort(ai.begin(),ai.end());
		reverse(ai.begin(),ai.end());
		for(pair<int,int>p:ai)
		{
			int id=p.second;
			int L=0,R=0;
			if(id>0)L=A[id-1];
			if(id+1<N)R=A[id+1];
			int M=max(L,R);
			if(A[id]>M)
			{
				ans-=A[id]-M;
				A[id]=M;
			}
		}
		printf("%lld\n",ans);
	}
}