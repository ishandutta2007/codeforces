#include <bits/stdc++.h>
#define ll long long 
#define ull unsigned long long 
#define pii pair<int,int>
#define mp make_pair
#define all(x) x.begin(),x.end()
#define mt make_tuple
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
using namespace std;
const int inf=103714778;
const int mod=998244353;
template <typename T> inline void chmax(T &x,const T &b) {x=max(x,b);}
template <typename T> inline void chmin(T &x,const T &b) {x=min(x,b);}
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

template <typename T1,typename T2>
ostream & operator << (ostream &cout,const pair<T1,T2> &o)
{
	cout<<'('<<o.first<<','<<o.second<<')';
	return cout;
}

template <typename T>
ostream & operator << (ostream &cout,const vector<T> &v)
{
	cout<<'{';
	int fst=1;
	for(auto x:v)
	{
		if(!fst) cout<<',';
		else fst=0;
		cout<<x;
	}
	cout<<'}';
	return cout;
}

namespace FastIO
{
	int cursor=(1<<20);
	char buf[(1<<20)+5];
	char getchar()
	{
		if(cursor==(1<<20))
		{
			cursor=0;
			fread(buf,1,(1<<20),stdin);
		}
		return buf[cursor++];
	}
	int getnum()
	{
		char ch=0;
		int res=0;
		while(!isdigit(ch)) ch=getchar();
		while(isdigit(ch))
		{
			res=res*10+ch-'0';
			ch=getchar();
		}
		return res;
	}
}
using FastIO::getnum;

set<pii> edges1[300005];
int n,m;
map<pii,pii> M;//colors, rk
int dfn[300005],stk[300005],top,low[300005],T;
int flag,colors;

set<int> edges2[300005];
int deg[300005];
int has[300005];
int que[300005],l,r;
pii edge[300005];
int tote;
set<pii> ban;
vector<int> edges3[300005];
int rk[300005];
vector<tuple<int,int,int> > vec[300005];
void solve(vector<int> v)
{
	// cout<<flag<<' '<<v<<endl;
	if(v.size()==2)
	{
		int a=v[0],b=v[1];
		vec[a].emplace_back(b,colors,0);
		vec[b].emplace_back(a,colors,0);
		return;
	}
	if(!flag) return;
	ban.clear();
	int t=v.back(),mn=inf;
	for(auto x:v)
	{
		deg[x]=0;
		edges2[x].clear();
		edges3[x].clear();
		has[x]=1;
		chmin(mn,x);
	}
	tote=0;
	for(auto x:v)
	{
		if(x==t) continue;
		for(auto &e:edges1[x])
		{
			int u=e.first;
			if(has[u])
			{
				edges2[x].insert(u);
				edges2[u].insert(x);
				if(u==t || u<x) edge[tote++]=mp(u,x);
			}
		}
	}
	// cout<<endl;
	// for(auto x:v) cout<<x+1<<' '<<edges2[x].size()<<endl;
	// cout<<v.size()<<endl;
	// cout<<tote<<endl;
	// for(int i=0;i<tote;i++) cout<<edge[i]<<endl;
	for(auto x:v) has[x]=0;

	l=r=0;
	for(auto x:v)
	{
		deg[x]=edges2[x].size();
		assert(deg[x]!=1);
		if(deg[x]==2) que[r++]=x;
	}

	int cc=tote;
	while(cc>3)
	{
		if(l==r)
		{
			flag=0;
			return;
		}
		int x=que[l++];
		// cout<<x+1<<endl;
		int a=*edges2[x].begin(),b=*edges2[x].rbegin();
		if(edges2[a].count(b))
		{
			assert(edges2[b].count(a));
			ban.insert(mp(a,b));
			ban.insert(mp(b,a));
			edges2[x].clear();
			edges2[a].erase(x);edges2[b].erase(x);deg[a]--;deg[b]--;
			if(deg[a]==2) que[r++]=a;
			if(deg[b]==2) que[r++]=b;
			cc--;cc--;
		}
		else
		{
			edges2[x].clear();
			edges2[a].erase(x);edges2[a].insert(b);
			edges2[b].erase(x);edges2[b].insert(a);
			cc--;
		}
	}

	for(int i=0;i<tote;i++)
	{
		int x=edge[i].first,y=edge[i].second;
		if(ban.count(mp(x,y))) continue;
		edges3[x].emplace_back(y);
		edges3[y].emplace_back(x);
	}
	for(auto x:v) if(edges3[x].size()!=2)
	{
		flag=0;
		return;
	}
	int now=t,par=edges3[t][0];
	int n=v.size();
	for(int i=0;i<n;i++)
	{
		// cout<<i<<' '<<now<<endl;
		rk[now]=i;
		par=(edges3[now][0]==par)?edges3[now][1]:edges3[now][0];
		swap(par,now);
	}
	if(now!=t)
	{
		flag=0;
		return;
	}
	int a=edges3[mn][0],b=edges3[mn][1];
	if((a<b) ^ ((rk[a]-rk[mn]+n)%n==1))
	{
		for(auto x:v) rk[x]=n-1-rk[x];
	}
	// for(auto x:v) cout<<x<<','<<rk[x]<<' ';
	// cout<<endl;
	// cout<<mn<<' '<<a<<' '<<b<<' '<<rk[mn]<<' '<<rk[a]<<endl;
	// for(auto x:v) cout<<x+1<<' '<<rk[x]<<endl;

	for(auto &o:ban)
	{
		edges3[o.first].emplace_back(o.second);
	}
	// for(auto x:v) cout<<edges3[x]<<endl;
	for(auto &x:v)
	{
		int pos=rk[x];
		sort(all(edges3[x]),[&pos](int x,int y){
			if(rk[x]>pos && rk[y]<pos) return true;
			if(rk[x]<pos && rk[y]>pos) return false;
			return rk[x]<rk[y];
		});
		for(int i=0;i<(int)edges3[x].size();i++)
		{
			int u=edges3[x][i];
			vec[x].emplace_back(mt(u,colors,i));
		}
	}
}

void tarjan(int x,int pid)
{
	dfn[x]=low[x]=T++;stk[top++]=x;
	// cout<<low[u]<<' '<<dfn[x]<<endl;
	for(auto &e:edges1[x])
	{
		if(e.second==pid) continue;
		int u=e.first;
		// cout<<dfn[u]<<' '<<low[u]<<endl;
		if(dfn[u]==-1)
		{
			tarjan(u,e.second);
			chmin(low[x],low[u]);
			if(low[u]>=dfn[x])
			{
				vector<int> v;
				do
				{
					top--;
					v.emplace_back(stk[top]);
				}while(stk[top]!=u);
				v.emplace_back(x);
				solve(v);
				colors++;
			}
		}
		else chmin(low[x],dfn[u]);
	}
}

vector<int> ans[300005];
namespace AA
{
	vector<int> que[300005];
	int len[300005];
	vector<int> v;
	set<pii> squ;
	void reorder(int x)
	{
		v.clear();
		for(auto &o:vec[x])
		{
			int u,colors,rk;
			tie(u,colors,rk)=o;
			v.emplace_back(colors);
			que[colors].emplace_back(u);
		}
		sort(all(v));v.erase(unique(all(v)),v.end());
		for(auto x:v)
		{
			squ.insert(mp(que[x].front(),x));
			len[x]=0;
			// cout<<que[x]<<' '<<len[x]<<endl;
		}
		// cout<<endl;
		while(squ.size())
		{
			ans[x].emplace_back(squ.begin()->first);
			int col=squ.begin()->second;
			squ.erase(squ.begin());
			len[col]++;
			if(len[col]!=(int)que[col].size())
			{
				squ.insert(mp(que[col][len[col]],col));
			}
		}
		for(auto x:v) len[x]=0,que[x].clear();
	}
}
using AA::reorder;

set<pii> S;
void solve(bool dbg)
{
	scanf("%d%d",&n,&m);
	if(dbg) cerr<<n<<' '<<m<<endl;
	for(int i=0;i<n;i++) edges1[i].clear(),vec[i].clear(),ans[i].clear();
	colors=0;
	S.clear();
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		// if(dbg) cerr<<x<<' '<<y<<endl;
		// x--;y--;
		// assert(!S.count(mp(x,y)));
		// assert(!S.count(mp(y,x)));
		// S.insert(mp(x,y));
		edges1[x].insert(mp(y,i));
		edges1[y].insert(mp(x,i));
	}
	T=0;
	flag=1;
	for(int i=0;i<n;i++) dfn[i]=-1;
	for(int i=0;i<n;i++)
	{
		// cout<<dfn[i]<<endl;
		if(dfn[i]==-1) tarjan(i,-1);
	}
	if(!flag) return (void)puts("NO");
	for(int i=0;i<n;i++) reorder(i);
	puts("YES");
	for(int i=0;i<n;i++)
	{
		for(auto x:ans[i]) printf("%d ",x);
		puts("");
	}
}

int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("granddesign.in","r",stdin);
	// freopen("granddesign.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		// cout<<"Case: "<<i<<endl;
		solve(0);
	}
	return 0;
}