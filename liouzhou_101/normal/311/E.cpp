#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int INF=1000000000;
const int MaxN=1000010;

int S,T;

int vh[MaxN],h[MaxN];

int tot;
struct node
{
	int x,c;
	node *next,*rev;
}e[MaxN],*v[MaxN];

void addedge(int x,int y,int c)
{
	++tot;
	e[tot]=(node){y,c,v[x],e+tot+1};
	v[x]=e+tot;
	++tot;
	e[tot]=(node){x,0,v[y],e+tot-1};
	v[y]=e+tot;
}

int max_flow(int x,int flow)
{
	if (x==T) return flow;
	int minh=T-1,now=flow;
	for (node *it=v[x];it;it=it->next)
		if (it->c)
		{
			if (h[it->x]+1==h[x])
			{
				int tmp=max_flow(it->x,min(now,it->c));
				now-=tmp;
				it->c-=tmp;
				it->rev->c+=tmp;
				if (h[S]>=T) return flow-now;
				if (!now) break;
			}
			minh=min(minh,h[it->x]);
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
	memset(vh,0,sizeof(vh));
	memset(h,0,sizeof(h));
	int f=0;
	for (vh[0]=T;h[S]<T;f+=max_flow(S,INF));
	return f;
}

int n,m,g,sum;
int s[MaxN];

void init()
{
	cin>>n>>m>>g;
	S=n+m+1;
	T=S+1;
	for (int i=1;i<=n;++i)
		scanf("%d",&s[i]);
	for (int i=1;i<=n;++i)
	{
		int v;
		scanf("%d",&v);
		if (s[i])
			addedge(S,i,v);
		else
			addedge(i,T,v);
	}
	for (int i=1;i<=m;++i)
	{
		int ns,w,k;
		scanf("%d%d%d",&ns,&w,&k);
		sum+=w;
		while (k--)
		{
			int x;
			scanf("%d",&x);
			if (ns)
				addedge(n+i,x,INF);
			else
				addedge(x,n+i,INF);
		}
		scanf("%d",&k);
		if (ns)
			addedge(S,n+i,w+k*g);
		else
			addedge(n+i,T,w+k*g);
	}
}

void work()
{
	cout<<sum-max_flow()<<endl;
}

int main()
{
	init();
	work();
	return 0;
}