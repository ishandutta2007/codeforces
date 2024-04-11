#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int N,M;
int ans[101];
int fn[101];
int ex[101];
int day[101];
vector<pair<int,int> >G[101];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int s,d,c;scanf("%d%d%d",&s,&d,&c);
		s--,d--;
		G[s].push_back(make_pair(c,i+1));
		ex[d]=i+1;
		fn[i+1]=c;
		day[i+1]=d;
	}
	priority_queue<pair<int,int> >P;
	for(int i=0;i<N;i++)
	{
		for(pair<int,int>p:G[i])
		{
			for(int j=0;j<p.first;j++)P.push(make_pair(-day[p.second],p.second));
		}
		if(ex[i])
		{
			if(fn[ex[i]])
			{
				puts("-1");
				return 0;
			}
			ans[i]=M+1;
		}
		else
		{
			if(P.empty())ans[i]=0;
			else
			{
				int id=P.top().second;
				ans[i]=id;
				fn[id]--;
				P.pop();
			}
		}
	}
	for(int i=0;i<N;i++)printf("%d%c",ans[i],i+1==N?10:32);
}