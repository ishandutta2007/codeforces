#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const ll INF=10000000000000000LL;

template<class type=int> class flow_graph
{
	private:
		//const type INF=typeid(int)==typeid(type)?1000000000:1000000000000000000LL;
		const static type INF=10000000000000000LL;
	public:
		int n,S,T;
	private:
		struct node
		{
			int from,way;
			type cap,cost;
			node *next,*rev;
		};
		node **v;
		type max_flow,ans;
		type *dis;
		node **pre;
		int *used;
		bool SPFA()
		{
			for (int i=1;i<=n;++i)
			{
				dis[i]=INF;
				used[i]=0;
			}
			dis[S]=0;
			queue<int> Q;
			Q.push(S);
			used[S]=1;
			while (!Q.empty())
			{
				int x=Q.front();
				Q.pop();
				used[x]=0;
				for (node *it=v[x];it;it=it->next)
					if (it->cap>0&&dis[it->way]>dis[x]+it->cost)
					{
						dis[it->way]=dis[x]+it->cost;
						pre[it->way]=it;
						if (!used[it->way])
						{
							used[it->way]=1;
							Q.push(it->way);
						}
					}
			}
			if (dis[T]==INF) return 0;
			type flow=INF;
			for (int i=T;i!=S;i=pre[i]->from)
				flow=min(flow,pre[i]->cap);
			max_flow+=flow;
			ans+=flow*dis[T];
			for (int i=T;i!=S;i=pre[i]->from)
			{
				pre[i]->cap-=flow;
				pre[i]->rev->cap+=flow;
			}
			return 1;
		}
	public:
		flow_graph (int _n,int _S,int _T)
		{
			n=_n;
			S=_S;
			T=_T;
			v=new node*[n+1]();
			dis=new type[n+1]();
			used=new int[n+1]();
			pre=new node*[n+1]();
			for (int i=1;i<=n;++i)
				v[i]=pre[i]=0;
		}
		void addedge(int x,int y,type c,type w)
		{
			node *p=new node;
			node *q=new node;
			*p=(node){x,y,c,w,v[x],q};
			*q=(node){y,x,0,-w,v[y],p};
			v[x]=p;
			v[y]=q;
		}
		pair<type,type> solve()
		{
			max_flow=ans=0;
			while (SPFA());
			return pair<type,type>(max_flow,ans);
		}
};

const int MAXN = 2222;

int n, k;
int a[MAXN], b[MAXN];

int main()
{
	
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &b[i]);
	int SS = n+1, T = n+2, S = n+3;
	flow_graph<ll> G(n+3, SS, T);
	G.addedge(SS, S, k, 0);
	for (int i = 1; i < n; ++ i)
		G.addedge(i, i+1, INF, 0);
	for (int i = 1; i <= n; ++ i)
	{
		G.addedge(S, i, 1, a[i]);
		G.addedge(i, T, 1, b[i]);
	}
	cout << G.solve().Y << endl;
	return 0;
}