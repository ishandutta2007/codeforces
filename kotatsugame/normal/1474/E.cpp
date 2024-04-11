#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		long long ans=0;
		vector<int>P(N);
		for(int i=0;i<N;i++)P[i]=i;
		vector<pair<int,int> >T;
		vector<int>L,R;
		for(int i=1;i<N/2;i++)
		{
			L.push_back(N-i-1);
			R.push_back(i);
		}
		if(N%2==1)R.push_back(N/2);
		T.push_back(make_pair(0,N-1));
		swap(P[0],P[N-1]);
		ans+=(long long)(N-1)*(N-1);
		for(int l:L)
		{
			T.push_back(make_pair(l,0));
			swap(P[0],P[l]);
			ans+=(long long)l*l;
		}
		for(int r:R)
		{
			T.push_back(make_pair(r,N-1));
			swap(P[r],P[N-1]);
			long long t=N-1-r;
			ans+=t*t;
		}
		reverse(T.begin(),T.end());
		printf("%lld\n",ans);
		for(int i=0;i<N;i++)printf("%d%c",P[i]+1,i+1==N?10:32);
		printf("%d\n",(int)T.size());
		for(pair<int,int>p:T)printf("%d %d\n",p.first+1,p.second+1);
	}
}