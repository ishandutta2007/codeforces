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
		vector<pair<int,int> >G;
		G.reserve(2*N);
		for(int i=0;i<N;i++)
		{
			int l,r;scanf("%d%d",&l,&r);
			G.push_back(make_pair(l,-i-1));
			G.push_back(make_pair(r,i+1));
		}
		vector<int>ans(N);
		int cnt=0,del=0;
		sort(G.begin(),G.end());
		for(pair<int,int>p:G)
		{
			if(p.second<0)
			{
				ans[-p.second-1]-=del;
				cnt++;
			}
			else
			{
				ans[p.second-1]+=cnt;
				del++;
			}
		}
		int mx=0;
		for(int i=0;i<N;i++)mx=max(mx,ans[i]);
		printf("%d\n",N-mx);
	}
}