#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define int long long
#define N 50100
#define INF (1LL << 60)
#define ll long long
#define lc(x) ch[x][0]
#define rc(x) ch[x][1]
#define wch(x) (rc(fa[x])==x)
using namespace std;
	int ch[N][2],fa[N],siz[N],ct[N],rt,ed;ll v[N];
struct fck{int to;int cap;int rev;};
vector <fck> Eee[N];
int tot,n,m,s,t,dis[N],cur[N];
	inline int upd(int x){if (x) siz[x]=siz[lc(x)]+ct[x]+siz[rc(x)];}
	inline void rot(int x)
	{
		int f=fa[x],z=fa[f],k=wch(x);
		ch[f][k]=ch[x][k^1],fa[ch[f][k]]=f,fa[f]=x,ch[x][k^1]=f,fa[x]=z;
		if(z) ch[z][f==ch[z][1]]=x;upd(f);upd(x);
	}
int DFS(int s,int t,int wolf)
{
	if(s==t) return wolf;
	int len=Eee[s].size();
	for(int i=cur[s];i<len;i++)
	{
		cur[s]=i;
		fck &temp=Eee[s][i];
		if(temp.cap>0&&dis[temp.to]==dis[s]+1)
		{
			int found_wolf=DFS(temp.to,t,min(temp.cap,wolf));
			if(found_wolf>0)
			{
				temp.cap-=found_wolf;
				Eee[temp.to][temp.rev].cap+=found_wolf;
				return found_wolf;
			}
		}
	}
	return 0;
}
	
	inline ll krf(ll x)
	{
		int tmp=0,t=rt;
		while (1)
		{
			if (ch[t][0] && x<=siz[ch[t][0]]) t=ch[t][0];
			else
			{
				tmp=siz[ch[t][0]]+ct[t];
				if (x<=tmp) return t;
				x-=tmp,t=ch[t][1];
			}
		}
	}
int BFS(int s,int t)
{
	queue<int> q;
	q.push(s);
	for(int i=0;i<=N;i++) dis[i]=INF;
	dis[s]=0;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		int len=Eee[now].size();
		for(int i=0;i<len;i++)
		{
			fck &temp=Eee[now][i];
			if(temp.cap>0&&dis[temp.to]==INF)
			{
				q.push(temp.to);
				dis[temp.to]=dis[now]+1;
			}
		}
	}
	return dis[t]!=INF;
}
	inline void spl(int x){
		for (int y;y=fa[x];rot(x)) if (fa[y]) rot(((wch(x)==wch(y)))?y:x);rt=x;
	}
	inline void fd(ll x){
		int t=rt;while (v[t]!=x && ch[t][x>v[t]]) t=ch[t][x>v[t]];spl(t);
	}
	inline void ins(ll x)
	{
		if (!rt) {rt=ed=1;v[1]=x;ct[1]=siz[1]=1;return;}int t=rt;
		while (v[t]!=x && ch[t][x>v[t]]) siz[t]++,t=ch[t][x>v[t]];
		siz[t]++;if (v[t]==x) {ct[t]++;upd(t);spl(t);return;}ed++;
		ch[t][x>v[t]]=ed;siz[ed]=ct[ed]=1;v[ed]=x;fa[ed]=t;spl(ed);
	}
inline void add(int u,int v,int z)
{
	Eee[u].push_back((fck){v,z,Eee[v].size()});
	Eee[v].push_back((fck){u,0,Eee[u].size()-1});
}
long long din(int s,int t)
{
	long long ans=0;
	while(BFS(s,t))
	{
		int wolf;
		for(int i=0;i<=N;i++) cur[i]=0;
		while(1) 
		{
			wolf=DFS(s,t,INF);
			if(wolf<=0) break;
			ans+=wolf;
		}
	}
	return ans;
}
int init()
{
	int u,v,x,y,z,ss = 0;cin>>n>>m;
	tot = n;s = 0,t = 2501;
	for(int i=1;i<=n;i++){cin>>x;add(i,t,x);}
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		add(s,n+i,z);
		add(n+i,y,INF);
		add(n+i,x,INF);
		ss += z;
	}
	return ss;
}
signed main()
{
	printf("%I64d",init() - din(s,t));return 0;
}
inline int qry(ll x,int k)
	{
		fd(x);int t=rt;if ((v[t]>x && k) || (v[t]<x && !k)) return t;
		t=ch[t][k];while (ch[t][k^1]) t=ch[t][k^1];spl(t);return t;
	}
	inline void del(ll x)
	{
		fd(x);int r=rt;if (ct[r]>1) {ct[r]--;return;}qry(x,0);fa[rc(r)]=rt;ch[rt][1]=rc(r);spl(rc(r));
	}
	inline ll frk(ll x){fd(x);return siz[lc(rt)];}