#line 1 "a.cpp"
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#line 1 "/home/kotatsugame/library/graph/MF_Dinic.cpp"
//Dinic O(EV^2)
#line 3 "/home/kotatsugame/library/graph/MF_Dinic.cpp"
#include<utility>
#line 5 "/home/kotatsugame/library/graph/MF_Dinic.cpp"
#include<queue>
#include<limits>
template<typename T>
struct MF{
	struct edge{
		int to,rev;
		T cap;
	};
	vector<vector<edge> >G;
	vector<int>level,iter;
	MF(int n_=0):G(n_),level(n_),iter(n_){}
	void add_edge(int from,int to,T cap)
	{
		G[from].push_back({to,(int)G[to].size(),cap});
		G[to].push_back({from,(int)G[from].size()-1,0});
	}
	T dfs(int u,int t,T f)
	{
		if(u==t)return f;
		for(;iter[u]<G[u].size();iter[u]++)
		{
			edge&e=G[u][iter[u]];
			if(e.cap>0&&level[u]<level[e.to])
			{
				T d=dfs(e.to,t,min(f,e.cap));
				if(d>0)
				{
					e.cap-=d;
					G[e.to][e.rev].cap+=d;
					return d;
				}
			}
		}
		return 0;
	}
	T max_flow(int s,int t)
	{
		T ret=0;
		for(;;)
		{
			fill(level.begin(),level.end(),-1);
			queue<int>P;
			level[s]=0;
			P.push(s);
			while(!P.empty())
			{
				int u=P.front();P.pop();
				for(edge&e:G[u])
				{
					if(e.cap>0&&level[e.to]<0)
					{
						level[e.to]=level[u]+1;
						P.push(e.to);
					}
				}
			}
			if(level[t]<0)return ret;
			fill(iter.begin(),iter.end(),0);
			for(T f;(f=dfs(s,t,numeric_limits<T>::max()))>0;)ret+=f;
		}
	}
};
#line 6 "a.cpp"
main()
{
	int N,B,Q;
	scanf("%d%d%d",&N,&B,&Q);
	vector<pair<int,int> >A(Q);
	for(int i=0;i<Q;i++)scanf("%d%d",&A[i].first,&A[i].second);
	A.push_back(make_pair(B,N));
	sort(A.begin(),A.end());
	for(int i=Q;i--;)
	{
		A[i+1].second-=A[i].second;
		if(A[i+1].second<0)
		{
			puts("unfair");
			return 0;
		}
	}
	MF<int>P(2+5+Q+1);
	int st=Q+6,go=Q+7;
	int pre=0;
	for(int i=0;i<=Q;i++)
	{
		P.add_edge(st,i,A[i].second);
		int cnt[5]={};
		while(pre<A[i].first)
		{
			cnt[++pre%5]++;
		}
		for(int j=0;j<5;j++)P.add_edge(i,Q+1+j,cnt[j]);
	}
	for(int j=0;j<5;j++)P.add_edge(Q+1+j,go,N/5);
	puts(P.max_flow(st,go)==N?"fair":"unfair");
}