#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

const int MaxN=200010;
const int INF=1000000000;

struct node
{
	int way,cap;
	node *next,*rev;
};

struct flow_gragh
{
	int tot;
	node edge[MaxN],*vec[MaxN];
	int S,T;
	int h[MaxN],vh[MaxN];
	void init(int x)
	{
		S=x;
		T=S+1;
	}
	void addedge(int x,int y,int c)
	{
		++tot;
		edge[tot].way=y;
		edge[tot].cap=c;
		edge[tot].next=vec[x];
		edge[tot].rev=&edge[tot+1];
		vec[x]=&edge[tot];
		++tot;
		edge[tot].way=x;
		edge[tot].cap=0;
		edge[tot].next=vec[y];
		edge[tot].rev=&edge[tot-1];
		vec[y]=&edge[tot];
	}
	int max_flow(int x,int flow)
	{
		if (x==T) return flow;
		int minh=T-1,now=flow;
		for (node *it=vec[x];it;it=it->next)
			if (it->cap>0)
			{
				if (h[it->way]+1==h[x])
				{
					int tmp=max_flow(it->way,min(now,it->cap));
					now-=tmp;
					it->cap-=tmp;
					it->rev->cap+=tmp;
					if (h[S]>=T) return flow-now;
					if (!now) break;
				}
				minh=min(minh,h[it->way]);
			}
		if (flow==now)
		{
			if (!--vh[h[x]]) h[S]=T;
			++vh[h[x]=minh+1];
		}
		return flow-now;
	}
	int max_flow()
	{
		long long ans=0;
		for (vh[0]=T;h[S]<T;ans+=max_flow(S,INF));
		return ans;
	}
}G1,G2;

int n;
vector<int> v[MaxN];
int f[MaxN];

long long ans;

int main()
{
	cin>>n;
	G1.init(n+n+1);
	for (int i=1;i<=n;++i)
	{
		G1.addedge(G1.S,i,1);
		G1.addedge(n+i,G1.T,1);
		int m;
		cin>>m;
		while (m--)
		{
			int x;
			cin>>x;
			v[i].push_back(x);
			G1.addedge(i,n+x,1);
		}
	}
	G1.max_flow();
	G2.init(n+1);
	for (int i=1;i<=n;++i)
	{
		int x;
		cin>>x;
		x=-x;
		if (x>0)
		{
			ans+=x;
			G2.addedge(G2.S,i,x);
		}
		else
			G2.addedge(i,G2.T,-x);
	}
	for (int i=1;i<=n;++i)
		for (node *it=G1.vec[n+i];it;it=it->next)
			if (it->way<=n&&it->cap) f[i]=it->way;
	for (int i=1;i<=n;++i)
		for (vector<int>::iterator it=v[i].begin();it!=v[i].end();++it)
			if (f[*it]!=i) G2.addedge(i,f[*it],INF);
	cout<<G2.max_flow()-ans<<endl;
	return 0;
}