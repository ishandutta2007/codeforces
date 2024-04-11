//yinjianren gunchu OI!!!
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define N 200005
#define pa pair<int,int>
using namespace std;
ll read()
{
	ll x=0,fh=1;
	char ch=getchar();
	while (!isdigit(ch))
	{
		if (ch=='-') fh=-1;
		ch=getchar();
	}
	while (isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return fh*x;
}
void write(ll x)
{
	if (x<0)
	{
		putchar('-');
		write(-x);
		return;
	}
	if (x>=10) write(x/10);
	putchar('0'+x%10);
}
void writeln(ll x)
{
	write(x);
	putchar('\n');
}
void writesp(ll x)
{
	write(x);
	putchar(' ');
}
int st;
int n;
vector<int>S;
int sm;
vector<pair<int,pa>>Wt[2];
int vis[2][N];
struct CWT_Mei_Ma
{
	int num,cnt;
	vector<int>G[N];
	int Dfn;
	int ldfn[N],rdfn[N],dfn[N];
	vector<pa>tr[N<<2];
	int Ltr[N<<2],Rtr[N<<2];
	pa E[N];
	inline init()
	{
		memset(Rtr,-1,sizeof(Rtr));
	}
	inline void ad(int x,int y)
	{
		++cnt;
		E[cnt].fi=x,E[cnt].se=y;
		G[x].push_back(y);
	}
	void dfs(int k,int fa)
	{
		++Dfn;
		ldfn[k]=dfn[k]=Dfn;
		for (auto u:G[k])
		{
			dfs(u,k);
		}
		rdfn[k]=Dfn;
	}
	void update(int k,int l,int r,int x,int y,int i)
	{
		if (l==r)
		{
			tr[k].push_back({y,i});
			Rtr[k]=tr[k].size()-1;
			cnt=max(cnt,k);
			return;
		}
		tr[k].push_back({y,i});
		Rtr[k]=tr[k].size()-1;
//		sm++;
		int mid=l+(r-l)/2;
		if (x<=mid) update(k<<1,l,mid,x,y,i);
		else update(k<<1|1,mid+1,r,x,y,i);
	}
	vector<int>query(int k,int l,int r,int L,int R,int val,int fh)
	{
		if (tr[k].empty()) return vector<int>();
		if (L<=l&&r<=R)
		{
			vector<int>g;
			if (fh==0)
			{
				while (Ltr[k]<=Rtr[k])
				{
					if (tr[k][Rtr[k]].fi<val) break;
					if (!vis[num^1][tr[k][Rtr[k]].se])
					{
						vis[num^1][tr[k][Rtr[k]].se]=1;
						g.push_back(tr[k][Rtr[k]].se);
					}
					Rtr[k]--;
				}
			} else
			{
				while (Ltr[k]<=Rtr[k])
				{
					if (tr[k][Ltr[k]].fi>val) break;
					if (!vis[num^1][tr[k][Ltr[k]].se])
					{
						vis[num^1][tr[k][Ltr[k]].se]=1;
						g.push_back(tr[k][Ltr[k]].se);
					}
					Ltr[k]++;
				}
			}
			return g;
		}
		int mid=l+(r-l)/2;
		if (R<=mid) return query(k<<1,l,mid,L,R,val,fh);
		if (L>mid) return query(k<<1|1,mid+1,r,L,R,val,fh);
		auto X=query(k<<1,l,mid,L,R,val,fh);
		auto Y=query(k<<1|1,mid+1,r,L,R,val,fh);
//		if (X.size()<Y.size()) Y.swap(X);
		for (auto u:Y) X.push_back(u);
//		vector<int>().swap(Y);
		return X;
	}
}T[2];
signed main()
{
	n=read();
	for (int i=2;i<=n;i++)
	{
		int x=read();
		T[0].ad(x,i);
	}
	for (int i=2;i<=n;i++)
	{
		int x=read();
		T[1].ad(x,i);
	}
	T[0].dfs(1,0);
	T[1].dfs(1,0);
	T[0].init();
	T[1].init();
	T[0].num=0;
	T[1].num=1;
	st=read();
	S.push_back(st);
	for (int now=0;now<=1;now++)
	{
		for (int i=1;i<n;i++)
		{
			if (now==0&&i==st) continue;
			int x=T[now^1].dfn[T[now].E[i].fi],y=T[now^1].dfn[T[now].E[i].se];
			Wt[now^1].push_back({y,{x,i}});
			Wt[now^1].push_back({x,{y,i}});
		}
	}
	for (int now=0;now<=1;now++) 
		sort(Wt[now].begin(),Wt[now].end());
	for (auto u:Wt[0])
	{
		T[0].update(1,1,n,u.se.fi,u.fi,u.se.se);
	}
	for (auto u:Wt[1])
	{
		T[1].update(1,1,n,u.se.fi,u.fi,u.se.se);
	}	
	puts("Blue");
	writeln(st);
	int now=0;
	while (!S.empty())
	{
		vector<int>G;
		for (auto u:S)
		{
			vector<int>g=T[now].query(1,1,n,T[now].ldfn[T[now].E[u].se],T[now].rdfn[T[now].E[u].se],T[now].rdfn[T[now].E[u].se]+1,0);
			for (auto i:g)
			{
				G.push_back(i);
			}
			g=T[now].query(1,1,n,T[now].ldfn[T[now].E[u].se],T[now].rdfn[T[now].E[u].se],T[now].ldfn[T[now].E[u].se]-1,1);
			for (auto i:g)
			{
				G.push_back(i);
			}
		}
		S.swap(G);
		if (S.empty()) break;
		if (now==0) puts("Red");
		else puts("Blue"); 
		sort(S.begin(),S.end());
		for (auto u:S) writesp(u);
		puts("");
		now^=1;
	}
}