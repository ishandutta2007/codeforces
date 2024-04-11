#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
long long u[222222],v[222222],w[222222],n,m,cost,cnt;
long long pos[222222],pa[222222],pp[222222],sub[222222];
priority_queue<pair<long long,long long> > pq;
vector<pair<long long,long long> > g[222222];
struct dsu
{
	long long pa[222222];
	dsu()
	{
		for (long long i=1;i<=200000;i++) pa[i]=i;
	}
	long long root(long long x)
	{
		if (pa[x]!=x) pa[x]=root(pa[x]);
		return pa[x];
	}
	bool Union(long long x,long long y)
	{
		long long rx=root(x),ry=root(y);
		if (rx==ry) return 0;
		pa[rx]=ry;
		return 1;
	}
}DSU;
struct chain
{
	long long head,dep,sz;
	vector<long long> pre,mem,tree;
	void build(long long l,long long r,long long node)
	{
		if (l==r) tree[node]=mem[l];
		else
		{
			long long mid=(l+r)/2;
			build(l,mid,node*2);
			build(mid+1,r,node*2+1);
			tree[node]=max(tree[node*2],tree[node*2+1]);
		}
	}
	void process()
	{
		if (!mem.size()) return;
		pre.resize(mem.size());
		tree.resize(mem.size()*4);  
		pre[0]=mem[0];
		for (long long i=1;i<mem.size();i++)
		pre[i]=max(pre[i-1],mem[i]);
		build(0,mem.size()-1,1); 
	}
	long long Q(long long beg,long long en,long long l,long long r,long long node)
	{
		if (l>en || r<beg) return 0;
		if (l>=beg && r<=en) return tree[node];
		long long mid=(l+r)/2;
		return max(Q(beg,en,l,mid,node*2),Q(beg,en,mid+1,r,node*2+1));
	}
	long long query(long long l,long long r)
	{
		if (!l) return pre[r];
		return Q(l,r,0,mem.size()-1,1);
	}
}ch[222222];
void Init(long long i,long long fa)
{
	pa[i]=fa;
	sub[i]=1;
	for (long long j=0;j<g[i].size();j++)
	{
		if (g[i][j].first!=fa) 
		{
			Init(g[i][j].first,i);
			sub[i]+=sub[g[i][j].first];
		}
	}
}
void dfs(long long i,long long w,long long dep)
{
	ch[cnt].mem.push_back(w);
	pos[i]=cnt;
	pp[i]=ch[cnt].sz;
	ch[cnt].sz++;
	long long mxi=-1,wp;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first,val=g[i][j].second;
		if (to==pa[i]) continue;
		if (mxi==-1 || sub[to]>sub[mxi]) 
		{
			wp=val;
			mxi=to;
		}
	}
	if (mxi==-1) return;
	dfs(mxi,wp,dep+1);
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first,val=g[i][j].second;
		if (to==pa[i] || to==mxi) continue;
		cnt++;
		ch[cnt].head=to;
		ch[cnt].dep=dep+1;
		ch[cnt].sz=0;
		dfs(to,val,dep+1);
	}
}
long long maxweight(long long x,long long y)
{
	long long xl=pos[x],yl=pos[y],xp=pp[x],yp=pp[y],res=0;
	while(xl!=yl)
	{
		if (ch[xl].dep>ch[yl].dep)
		{
			res=max(res,ch[xl].query(0,xp));
			xp=pp[pa[ch[xl].head]];
			xl=pos[pa[ch[xl].head]];
		}
		else
		{
			res=max(res,ch[yl].query(0,yp));
			yp=pp[pa[ch[yl].head]];
			yl=pos[pa[ch[yl].head]];
		}
	}
	if (xp>yp) swap(xp,yp);
	return max(res,ch[xl].query(xp+1,yp));
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (long long i=1;i<=m;i++)
	{
		scanf("%I64d%I64d%I64d",&u[i],&v[i],&w[i]);
		pq.push(make_pair(-w[i],i)); 
	}
	while(!pq.empty())
	{
		long long x=pq.top().second;
		pq.pop();
		if (DSU.Union(u[x],v[x])) 
		{
			g[u[x]].push_back(make_pair(v[x],w[x]));
			g[v[x]].push_back(make_pair(u[x],w[x]));  
			cost+=w[x];
		}
	}
	Init(1,0);
	cnt=1;
	dfs(1,0,1);
	for (long long i=1;i<=cnt;i++)
	{
		ch[i].process();
	}
	for (long long i=1;i<=m;i++)
	{
		printf("%I64d\n",cost-maxweight(u[i],v[i])+w[i]);
	}
	return 0;
}