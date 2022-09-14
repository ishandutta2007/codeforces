#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
long long S;
vector<vector<pair<int,pair<int,int> > > >G;
vector<long long>A[2];
long long sum;
int dfs(int u,int p)
{
	int ch=0;
	for(pair<int,pair<int,int> >e:G[u])
	{
		int v=e.first;
		if(v!=p)
		{
			int cnt=dfs(v,u);
			long long w=e.second.first;
			int c=e.second.second-1;
			sum+=w*cnt;
			while(w>0)
			{
				A[c].push_back((w-w/2)*cnt);
				w/=2;
			}
			ch+=cnt;
		}
	}
	return ch+!ch;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%lld",&N,&S);
		G.clear();
		G.assign(N,vector<pair<int,pair<int,int> > >());
		for(int i=1;i<N;i++)
		{
			int u,v,w,c;scanf("%d%d%d%d",&u,&v,&w,&c);
			u--,v--;
			G[u].push_back(make_pair(v,make_pair(w,c)));
			G[v].push_back(make_pair(u,make_pair(w,c)));
		}
		A[0].clear();
		A[1].clear();
		sum=0;
		dfs(0,-1);
		sort(A[0].begin(),A[0].end());
		sort(A[1].begin(),A[1].end());
		reverse(A[1].begin(),A[1].end());
		for(long long a:A[0])sum-=a;
		int now=A[0].size();
		int r=0;
		while(sum>S)
		{
			sum-=A[1][r++];
			now+=2;
		}
		int ans=now;
		for(int i=0;i<A[0].size();i++)
		{
			sum+=A[0][i];
			now--;
			while(r<A[1].size()&&sum>S)
			{
				sum-=A[1][r++];
				now+=2;
			}
			if(sum<=S)ans=min(ans,now);
		}
		printf("%d\n",ans);
	}
}