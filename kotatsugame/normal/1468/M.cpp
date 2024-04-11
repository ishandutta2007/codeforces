#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int T;
int N;
int vis[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<vector<int> >A(N);
		int sumK=0;
		for(int i=0;i<N;i++)
		{
			int K;scanf("%d",&K);
			A[i].assign(K,0);
			for(int j=0;j<K;j++)scanf("%d",&A[i][j]);
			sumK+=K;
		}
		vector<int>vs;vs.reserve(sumK);
		for(int i=0;i<N;i++)for(int a:A[i])vs.push_back(a);
		sort(vs.begin(),vs.end());vs.erase(unique(vs.begin(),vs.end()),vs.end());
		vector<vector<int> >id(vs.size());
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<A[i].size();j++)
			{
				int jd=lower_bound(vs.begin(),vs.end(),A[i][j])-vs.begin();
				A[i][j]=jd;
				id[jd].push_back(i);
			}
		}
		vector<int>st(vs.size(),0);
		int ax=-1,ay=-1;
		for(int i=0;i<N;i++)vis[i]=-1;
		for(int i=0;i<N;i++)
		{
			int fn=-1;
			int mx=A[i][0];
			for(int a:A[i])
			{
				st[a]++;
				if(id[mx].size()-st[mx]<id[a].size()-st[a])mx=a;
			}
			vector<int>now;
			for(int a:A[i])if(a!=mx)
			{
				for(int j=st[a];j<id[a].size();j++)
				{
					if(vis[id[a][j]]==i)
					{
						fn=id[a][j];
						break;
					}
					vis[id[a][j]]=i;
					now.push_back(id[a][j]);
				}
				if(fn>=0)break;
			}
			if(fn>=0)
			{
				ax=i;
				ay=fn;
				break;
			}
			for(int jd:now)
			{
				auto it=lower_bound(id[mx].begin(),id[mx].end(),jd);
				if(it!=id[mx].end()&&*it==jd)
				{
					ax=i;
					ay=jd;
					break;
				}
			}
			if(ax>=0)break;
		}
		if(ax>=0)printf("%d %d\n",ax+1,ay+1);
		else puts("-1");
	}
}