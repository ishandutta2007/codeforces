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
typedef pair<ll,ll> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=1000010;
const int INF=1000000000;

int S,T;

int tot;
struct node
{
	int x,y,c,w;
	node *next,*rev;
}e[MaxN],*v[MaxN];

void addedge(int x,int y,int c,int w)
{
	++tot;
	e[tot]=(node){x,y,c,w,v[x],e+tot+1};
	v[x]=e+tot;
	++tot;
	e[tot]=(node){y,x,0,-w,v[y],e+tot-1};
	v[y]=e+tot;
}

int ans,main_ans,flows;
priority_queue<pii> Q;
int dis[MaxN];
node *pre[MaxN];

bool SPFA()
{
	for (int i=1;i<=T;++i)
		dis[i]=INF;
	Q.push(pii(dis[S]=0,S));
	while (!Q.empty())
	{
		int x=Q.top().Y,d=-Q.top().X;
		Q.pop();
		if (dis[x]!=d) continue;
		for (node *it=v[x];it;it=it->next)
			if (it->c>0&&dis[it->y]>d+it->w)
			{
				Q.push(pii(-(dis[it->y]=d+it->w),it->y));
				pre[it->y]=it;
			}
	}
	if (dis[T]==INF) return false;
	int flow=INF;
	for (int i=T;i!=S;i=pre[i]->x)
		flow=min(flow,pre[i]->c);
	ans+=flow*dis[T];
	for (int i=T;i!=S;i=pre[i]->x)
	{
		pre[i]->c-=flow;
		pre[i]->rev->c+=flow;
	}
	main_ans=min(main_ans,ans);
	flows+=flow;
	return true;
}

int n,m;
string p[MaxN];
int vn[MaxN],vm[MaxN];

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		cin>>p[i]>>vn[i];
	for (int i=1;i<=m;++i)
		cin>>vm[i];
	S=n+m+1;
	T=S+1;
	for (int i=1;i<=m;++i)
		addedge(S,i,1,0);
	for (int i=1;i<=n;++i)
		addedge(m+i,T,1,0);
	for (int i=1;i<=m;++i)
		for (int j=1;j<=n;++j)
		{
			if (p[j]=="ATK"&&vm[i]>=vn[j])
			{
				addedge(i,m+j,1,vn[j]-vm[i]);
			}
			if (p[j]=="DEF"&&vm[i]>vn[j])
			{
				addedge(i,m+j,1,0);
			}
		}
	while (SPFA());
	int real_ans=-main_ans;
	if (m>n)
	{
		tot=0;
		ans=0;
		flows=0;
		for (int i=1;i<=T;++i) v[i]=0;
		++T;
	for (int i=1;i<=m;++i)
		addedge(S,i,1,0);
	for (int i=1;i<=n;++i)
		addedge(m+i,T,1,0);
	for (int i=1;i<=m;++i)
		for (int j=1;j<=n;++j)
		{
			if (p[j]=="ATK"&&vm[i]>=vn[j])
			{
				addedge(i,m+j,1,vn[j]-vm[i]);
			}
			if (p[j]=="DEF"&&vm[i]>vn[j])
			{
				addedge(i,m+j,1,0);
			}
		}
		for (int i=1;i<=m;++i)
			addedge(i,T-1,1,-vm[i]);
		addedge(T-1,T,m-n,0);
		while (SPFA());
		if (flows==m) real_ans=max(real_ans,-ans);
	}
	cout<<real_ans<<endl;
	return 0;
}