/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int n,m,q,scc;
int a[100005],dfn[100005],low[100005],cnt;
vector<int>g[100005],tr[200005];
stack<int>stk;
int val[200005];
void dfs(int x,int par){
	low[x]=dfn[x]=++cnt;stk.push(x);
	for(auto to:g[x])if(to!=par){
//		cerr<<x<<" "<<to<<endl;
		if(!dfn[to]){
			dfs(to,x);
			low[x]=min(low[x],low[to]);
			if(low[to]>=dfn[x]){
//				cerr<<x<<" "<<to<<endl;
				scc++;
				while(1){
					int y=stk.top();stk.pop();
//					cerr<<x<<" "<<y<<" "<<scc<<endl;
					tr[scc].push_back(y);
					tr[y].push_back(scc);
					if(y==to)break;
				}
				tr[scc].push_back(x);
				tr[x].push_back(scc);
			}
		}else low[x]=min(low[x],dfn[to]);
	}
}
int l[200005],r[200005],clk,top[200005],sz[200005],wson[200005],p[200005],dep[200005];
multiset<int>s[200005];
#define SIZE 262144
struct SGT{
	int f[SIZE<<1];
	SGT(){memset(f,inf,sizeof f);}
	void update(int x,int v){
		x+=SIZE;f[x]=v;
		while(x!=1){
			x>>=1;
			f[x]=min(f[x<<1],f[x<<1|1]);
		}
	}
	int query(int l,int r,int k,int ql,int qr){
		if(qr<l||r<ql)return inf;
		if(ql<=l&&r<=qr)return f[k];
		return min(query(l,(l+r)/2,k<<1,ql,qr),query((l+r)/2+1,r,k<<1|1,ql,qr));
	}
}T;
void dfs_tr(int x,int par){
	if(x>n)val[x]=inf;
	else val[x]=a[x];
	sz[x]=1;
	for(auto to:tr[x])if(to!=par){
		dfs_tr(to,x);sz[x]+=sz[to];
		if(wson[x]==0||sz[to]>sz[wson[x]])wson[x]=to;
		if(x>n){
			val[x]=min(val[x],a[to]);
			s[x].insert(a[to]);
		}
	}
}
void go(int x,int par,int tp){
	p[x]=par;dep[x]=dep[par]+1;
	top[x]=tp;l[x]=++clk;
	if(wson[x])go(wson[x],x,tp);
	for(auto to:tr[x])if(to!=par&&to!=wson[x]){
		go(to,x,to);
	}
	r[x]=clk;
}
int query(int x,int y){
	int ret=inf;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
//		cerr<<l[top[x]]<<" "<<l[x]<<" "<<x<<" "<<y<<endl;
		ret=min(ret,T.query(0,SIZE-1,1,l[top[x]],l[x]));
		x=p[top[x]];
	}
	ret=min(ret,T.query(0,SIZE-1,1,min(l[x],l[y]),max(l[x],l[y])));
//	cerr<<min(l[x],l[y])<<" "<<max(l[x],l[y])<<" "<<x<<" "<<y<<" "<<top[x]<<" "<<top[y]<<endl;
	int cur=(dep[x]>dep[y]?y:x);
	if(cur>n){
//		cerr<<l[p[cur]]<<" "<<l[p[cur]]<<endl;
		ret=min(ret,T.query(0,SIZE-1,1,l[p[cur]],l[p[cur]]));
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	scc=n;dfs(1,0);
	for(int i=1;i<=scc;i++)for(auto to:tr[i])if(i<to)cerr<<"tree edge: "<<i<<" "<<to<<endl;
	dfs_tr(1,0);
	go(1,0,1);
	for(int i=1;i<=scc;i++)cerr<<"dfs order: "<<l[i]<<" "<<r[i]<<endl;
	for(int i=1;i<=scc;i++)T.update(l[i],val[i]);
	while(q--){
		string ss;cin>>ss;
		if(ss[0]=='C'){
			int x,y;cin>>x>>y;
			T.update(l[x],y);
			if(p[x]){
				s[p[x]].erase(s[p[x]].find(val[x]));
				s[p[x]].insert(y);
				T.update(l[p[x]],*s[p[x]].begin());
			}
			val[x]=y;
		}else{
			int x,y;cin>>x>>y;
			cout<<query(x,y)<<endl;
		}
	}
	return 0;
}