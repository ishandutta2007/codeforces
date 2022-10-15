//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
//#define int ll
#define N 300005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int dep[N],st[N][25];
int dfn[N],rdfn[N],DFN;
int s[N],t[N],l[N];
vector<int>Q[N],G[N],G1[N],P[N];
ll ans;
int rt[N];
int sta[N],tp;
int siz[N];
int n,m,K;
void ad(int x,int y)
{
	G[x].push_back(y);
}
void ad1(int x,int y)
{
	// cout<<"Ad1 "<<x<<" "<<y<<endl;
	G1[x].push_back(y);
}
namespace BIT
{
	int tr[N];
	void update(int x,int y)
	{
		while (x<=n)
		{
			tr[x]+=y;
			x+=(x&-x);
		}
	}
	int query(int x)
	{
		int res=0;
		while (x)
		{
			res+=tr[x];
			x-=(x&-x);
		}
		return res;
	}
}
bool cmp1(int x,int y)
{
	return dfn[s[x]]<dfn[s[y]];
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=20;i>=0;i--)
		if (dep[st[x][i]]>=dep[y]) x=st[x][i];
	if (x==y) return x;
	for (int i=20;i>=0;i--)
		if (st[x][i]!=st[y][i])
			x=st[x][i],y=st[y][i];
	return st[x][0];
}
int gt(int x,int y)
{
	// cout<<x<<" "<<y<<" ";
	for (int i=0;i<=20;i++)
		if ((y>>i)&1) x=st[x][i];
	// cout<<x<<endl;
	return x;
}
void dfs_pre(int k,int fa)
{
	dep[k]=dep[fa]+1;
	dfn[k]=++DFN;
	st[k][0]=fa;
	for (int i=1;i<=20;i++)
		st[k][i]=st[st[k][i-1]][i-1];
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs_pre(u,k);
	}
	rdfn[k]=DFN;
}
void dfs1(int k,int fa)
{
	for (auto i:Q[k])
	{
		if (dep[s[i]]-K>=dep[k])
		{
			int x=gt(s[i],dep[s[i]]-dep[k]-K);
			ans+=BIT::query(rdfn[x])-BIT::query(dfn[x]-1);
		}
		if (dep[t[i]]-K>=dep[k])
		{
			int x=gt(t[i],dep[t[i]]-dep[k]-K);
			ans+=BIT::query(rdfn[x])-BIT::query(dfn[x]-1);
		}
	}
	for (auto i:Q[k])
	{
		BIT::update(dfn[s[i]],1);
		BIT::update(dfn[t[i]],1);
	}
	for (auto u:G[k])
	{
		if (u==fa)continue;
		dfs1(u,k);
	}
	for (auto i:Q[k])
	{
		BIT::update(dfn[s[i]],-1);
		BIT::update(dfn[t[i]],-1);
	}
}
int lson[N*200],rson[N*200],tr[N*200];
// int sta1[N*400];
int tp1,cnt;
bool cmp(int x,int y)
{
	return dfn[x]<dfn[y];
}
// bool cmp1(int x,int y)
// {
// 	
void pushup(int k)
{
	tr[k]=tr[lson[k]]+tr[rson[k]];
}
int query(int k,int l,int r,int L,int R)
{
	// assert(!tr[0]);
	if (!k) return 0;
	if (L<=l&&r<=R) return tr[k];
	int mid=l+(r-l)/2,res=0;
	if (L<=mid) res+=query(lson[k],l,mid,L,R);
	if (R>mid) res+=query(rson[k],mid+1,r,L,R);
	return res;
}
int rubbish()
{
	// if (tp1) return sta1[tp1--];
	assert(cnt+1<N*200);
	++cnt;
	tr[cnt]=lson[cnt]=rson[cnt]=0;
	return cnt;
}
void update(int &k,int l,int r,int L,int val)
{
	if (!k)
	{
		k=rubbish();
	}
	if (l==r)
	{
		tr[k]+=val;
		return;
	}
	int mid=l+(r-l)/2;
	if (L<=mid)
	{
		update(lson[k],l,mid,L,val);
	}
	else update(rson[k],mid+1,r,L,val);
	pushup(k);
}
void rub(int k)
{
	// sta1[++tp1]=k;
	// if (lson[k])
	// {
		// rub(lson[k]);
	// }
	// if (rson[k]) rub(rson[k]);
}
void dfs2(int k,int fa,int rrt)
{
	siz[k]=P[k].size();
	if (!P[k].size()) rt[k]=rubbish();
	for (auto i:P[k])
	{
		int x=0;
		if (dep[k]-dep[rrt]>=K)
		{
			x=rrt;
		} else
		{
			if ((K-(dep[k]-dep[rrt]))<=dep[t[i]]-dep[rrt])
				x=gt(t[i],dep[t[i]]-dep[rrt]-(K-(dep[k]-dep[rrt])));
		}
		if (x)
		{
			ans+=query(rt[k],1,n,dfn[x],rdfn[x]);
		}
		update(rt[k],1,n,dfn[t[i]],1);
	}
	for (auto u:G1[k])
	{
		if (u==fa)continue;
		dfs2(u,k,rrt);
		if (siz[u]>siz[k])
		{
			swap(rt[k],rt[u]);
			swap(P[u],P[k]);
		}
		for (auto i:P[u])
		{
			int x=0;
			if (dep[k]-dep[rrt]>=K)
			{
				x=rrt;
			} else
			{
				if ((K-(dep[k]-dep[rrt]))<=dep[t[i]]-dep[rrt])
					x=gt(t[i],dep[t[i]]-dep[rrt]-(K-(dep[k]-dep[rrt])));
			}
			if (x)
			{
				ans+=query(rt[k],1,n,dfn[x],rdfn[x]);
			}
		}
		for (auto i:P[u])
		{
			update(rt[k],1,n,dfn[t[i]],1);
		}
		for (auto i:P[u]) P[k].push_back(i);
		P[u].clear();
		siz[k]+=siz[u];
	}
}	
void BellaKira()
{
	n=read();m=read(),K=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		ad(u,v);
		ad(v,u);
	}
	dfs_pre(1,0);
	for (int i=1;i<=m;i++)
	{
		s[i]=read(),t[i]=read();
		if (dfn[s[i]]>dfn[t[i]]) swap(s[i],t[i]);
		l[i]=lca(s[i],t[i]);
		Q[l[i]].push_back(i);
	}
	dfs1(1,0);
	// if (n==233)
	// {
		// writeln(ans);
		// return void();
	// }
	for (int i=1;i<=n;i++)
	{
		tp=0;
		vector<int>gall,Gall;
		for (auto u:Q[i])
		{
			gall.push_back(s[u]);
			P[s[u]].push_back(u);
			// cout<<u<<" "<<s[u]<<" "<<t[u]<<endl;
		}
		gall.push_back(i);
		sort(gall.begin(),gall.end());
		gall.erase(unique(gall.begin(),gall.end()),gall.end());
		sort(gall.begin(),gall.end(),cmp);
		Gall=gall;
		for (auto u:gall)
		{
			if (tp<=1)
			{
				sta[++tp]=u;
				continue;
			}
			int x=lca(sta[tp],u);
			if (x==sta[tp])
			{
				sta[++tp]=u;
				continue;
			}
			while (tp>1&&dfn[x]<dfn[sta[tp-1]]) 
			{
				ad1(sta[tp-1],sta[tp]);
				tp--;
			}
			if (x==sta[tp-1])
			{
				ad1(sta[tp-1],sta[tp]);
				sta[tp]=u;
				Gall.push_back(u);
			} else
			{
				ad1(x,sta[tp]);
				sta[tp]=x;
				Gall.push_back(x);
				sta[++tp]=u;
				Gall.push_back(u);
			}
		}
		while (tp>1)
			ad1(sta[tp-1],sta[tp]),tp--;
		dfs2(i,0,i);
		for (auto u:Gall) G1[u].clear(),rt[u]=0,P[u].clear();
		tp1=0;cnt=0;
	}
	for (int i=1;i<=n;i++)
	{
		sort(Q[i].begin(),Q[i].end(),cmp1);
		for (auto u:Q[i])
		{
			if (dep[s[u]]-dep[i]>=K)
			{
				int x=gt(s[u],dep[s[u]]-dep[i]-K);
				ans+=BIT::query(rdfn[x])-BIT::query(dfn[x]-1);
			}
			BIT::update(dfn[t[u]],1);
		}
		for (auto u:Q[i]) BIT::update(dfn[t[u]],-1);
	}
	writeln(ans);
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/