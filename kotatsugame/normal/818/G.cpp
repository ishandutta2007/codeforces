#include<iostream>
using namespace std;
//Minimum Cost Flow O(FE log V)
//Minimum Cost Flow with negative cost O(NE+FE log V)
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<limits>
#include<cassert>
template<typename T>
struct MCF{
	struct edge{
		int to,rev,cap;
		T cost;
	};
	int n;
	bool negedge,ok;
	vector<vector<edge> >G;
	vector<T>h,d;
	vector<int>pv,pe;
	MCF(int n_=0):n(n_),negedge(false),G(n_),h(n_),d(n_),pv(n_),pe(n_){}
	void add_edge(int from,int to,int cap,T cost)
	{
		if(cost<0)negedge=true;
		G[from].push_back({to,(int)G[to].size(),cap,cost});
		G[to].push_back({from,(int)G[from].size()-1,0,-cost});
	}
	T min_cost_flow(int s,int t,int f)//ans or -1
	{
		ok=false;
		if(negedge)
		{
			fill(h.begin(),h.end(),numeric_limits<T>::max());
			h[s]=0;
			for(int i=0;i<n;i++)if(h[i]<numeric_limits<T>::max())
			{
				for(const edge&e:G[i])
				{
					if(e.cap>0&&h[e.to]>h[i]+e.cost)
					{
						h[e.to]=h[i]+e.cost;
					}
				}
			}
		}
		T ret=0;
		while(f>0)
		{
			priority_queue<pair<T,int>,vector<pair<T,int> >,greater<pair<T,int> > >P;
			fill(d.begin(),d.end(),numeric_limits<T>::max());
			d[s]=0;
			P.push(make_pair(0,s));
			while(!P.empty())
			{
				pair<T,int>p=P.top();P.pop();
				if(d[p.second]<p.first)continue;
				for(int i=0;i<G[p.second].size();i++)
				{
					edge&e=G[p.second][i];
					if(e.cap>0&&d[e.to]>d[p.second]+e.cost+h[p.second]-h[e.to])
					{
						d[e.to]=d[p.second]+e.cost+h[p.second]-h[e.to];
						pv[e.to]=p.second;
						pe[e.to]=i;
						P.push(make_pair(d[e.to],e.to));
					}
				}
			}
			if(d[t]==numeric_limits<T>::max())return -1;
			for(int u=0;u<G.size();u++)h[u]+=d[u];
			int d=f;
			for(int u=t;u!=s;u=pv[u])d=min(d,G[pv[u]][pe[u]].cap);
			f-=d;
			ret+=d*h[t];
			for(int u=t;u!=s;u=pv[u])
			{
				G[pv[u]][pe[u]].cap-=d;
				G[u][G[pv[u]][pe[u]].rev].cap+=d;
			}
		}
		ok=true;
		return ret;
	}
	operator bool()const{return ok;}
};
int N;
int A[3030];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	MCF<int>P(2*N+2);
	int st=0,go=2*N+1;
	for(int i=0;i<N;i++)
	{
		P.add_edge(st,2*i+1,1,0);
		P.add_edge(2*i+2,go,1,0);
		P.add_edge(2*i+1,2*i+2,1,-1);
		for(int j=i+1;j<N;j++)if(A[i]%7==A[j]%7||abs(A[i]-A[j])==1)
		{
			P.add_edge(2*i+2,2*j+1,1,0);
		}
	}
	cout<<-P.min_cost_flow(st,go,4)<<endl;
}