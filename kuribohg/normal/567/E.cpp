#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
typedef long long LL;
typedef pair<LL,int> PLI;
const LL INF=1000000000000000000LL;
const int MAXN=100010;
const int MOD1=998244353;
const int MOD2=1004535809;
int n,m,S,T;
struct Graph
{
	int head[MAXN],to[MAXN],next[MAXN],cnt;
	LL w[MAXN],dis[MAXN];
	pair<LL,LL> Cnt[MAXN];
	inline void adde(int f,int t,LL ww)
	{
		cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt,w[cnt]=ww;
	}
	bool used[MAXN];
	priority_queue<PLI,vector<PLI>,greater<PLI> > q;
	void Dijkstra(int S)
	{
		for(int i=1;i<=n;i++) dis[i]=INF;
		dis[S]=0,q.push(make_pair(dis[S],S));
		Cnt[S]=make_pair(1,1);
		while(!q.empty())
		{
			PLI tmp=q.top();q.pop();
			int x=tmp.second;
			if(used[x]) continue;
			used[x]=true;
			for(int i=head[x];i;i=next[i])
			{
				if(dis[to[i]]>dis[x]+w[i])
				{
					dis[to[i]]=dis[x]+w[i];
					Cnt[to[i]]=Cnt[x];
					q.push(make_pair(dis[to[i]],to[i]));
				}
				else if(dis[to[i]]==dis[x]+w[i])
				{	
					Cnt[to[i]].first=(Cnt[to[i]].first+Cnt[x].first)%MOD1;
					Cnt[to[i]].second=(Cnt[to[i]].second+Cnt[x].second)%MOD2;
				}
			}
		}
	}
}G1,G2;
struct Edge
{
	int x,y,z;
}E[MAXN];
int main()
{
	scanf("%d%d%d%d",&n,&m,&S,&T);
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		E[i].x=x,E[i].y=y,E[i].z=z;
		G1.adde(x,y,z);
		G2.adde(y,x,z);
	}
	G1.Dijkstra(S);
	G2.Dijkstra(T);
	LL D=G1.dis[T];
	for(int i=1;i<=m;i++)
	{
		pair<LL,LL> res;
		res.first=(G1.Cnt[E[i].x].first*G2.Cnt[E[i].y].first)%MOD1;
		res.second=(G1.Cnt[E[i].x].second*G2.Cnt[E[i].y].second)%MOD2;
		if(res==G1.Cnt[T]&&D==G1.dis[E[i].x]+G2.dis[E[i].y]+E[i].z) {puts("YES");continue;}
		LL x=D-1-G1.dis[E[i].x]-G2.dis[E[i].y];
		if(x>=1) printf("CAN %I64d\n",E[i].z-x);
		else puts("NO");
	}
	return 0;
}