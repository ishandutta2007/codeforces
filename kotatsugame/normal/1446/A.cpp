#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
long long W;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%lld",&N,&W);
		vector<pair<int,int> >w(N);
		for(int i=0;i<N;i++)
		{
			int nw;scanf("%d",&nw);
			w[i]=make_pair(nw,i);
		}
		long long sum=0;
		sort(w.begin(),w.end());
		vector<int>ans;
		for(int i=N;i--;)
		{
			if(sum+w[i].first<=W)
			{
				sum+=w[i].first;
				ans.push_back(w[i].second);
			}
		}
		if(sum<(W+1)/2)puts("-1");
		else
		{
			printf("%d\n",(int)ans.size());
			for(int i=ans.size();i--;)printf("%d%c",ans[i]+1,i==0?'\n':' ');
		}
	}
}