#include <bits/stdc++.h>
using namespace std;

using ll=long long;
//#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp2(...) dmpr(cerr,__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif

using uint=unsigned;
using ull=unsigned long long;

template<class t,size_t n>
ostream& operator<<(ostream&os,const array<t,n>&a){
	return os<<vc<t>(all(a));
}

template<int i,class T>
void print_tuple(ostream&,const T&){
}

template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
	if(i)os<<",";
	os<<get<i>(t);
	print_tuple<i+1,T,Args...>(os,t);
}

template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
	os<<"{";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<"}";
}

template<class t>
void print(t x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<"\n";
	if(suc==2)
		cout<<" ";
}

ll read(){
	ll i;
	cin>>i;
	return i;
}

vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=read()+off;
	return v;
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

string readString(){
	string s;
	cin>>s;
	return s;
}

template<class T>
T sq(const T& t){
	return t*t;
}

//#define CAPITAL
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<"\n";
	#else
	cout<<"Yes"<<"\n";
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
}

constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}
ll mask(int i){
	return (ll(1)<<i)-1;
}

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
	#ifdef LOCAL
	static mt19937_64 gen;
	#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
void myshuffle(vc<t>&a){
	rep(i,si(a))swap(a[i],a[rand_int(0,i)]);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

//Lyft Level 5 Challenge 2018 - Final F
template<class E>
struct doubling{
	const vvc<E>&g;
	const int n,h;
	int cnt;
	vvc<int> par;
	vi dep,in,out;
	void dfs(int v,int p,int d){
		par[0][v]=p;
		dep[v]=d;
		in[v]=cnt++;
		for(auto e:g[v])if(e!=p)
			dfs(e,v,d+1);
		out[v]=cnt;
	}
	doubling(const vvc<E>&gg,int r):g(gg),n(g.size()),h(__lg(n)+1),
		cnt(0),par(h,vi(n,-1)),dep(n),in(n),out(n){
		dfs(r,-1,0);
		rng(i,1,h){
			rep(j,n)
				if(par[i-1][j]!=-1)
					par[i][j]=par[i-1][par[i-1][j]];
		}
	}
	int lca(int a,int b){
		assert(0<=a&&a<(int)g.size());
		assert(0<=b&&b<(int)g.size());
		if(dep[a]>dep[b])swap(a,b);
		int w=dep[b]-dep[a];
		rep(i,h)if(w&1<<i)
			b=par[i][b];
		if(a==b)return a;
		per(i,h){
			int x=par[i][a],y=par[i][b];
			if(x!=y)tie(a,b)=pi(x,y);
		}
		return par[0][a];
	}
	int len(int a,int b){
		assert(0<=a&&a<(int)g.size());
		assert(0<=b&&b<(int)g.size());
		return dep[a]+dep[b]-dep[lca(a,b)]*2;
	}
	int jump(int a,int b,int d){
		assert(0<=a&&a<(int)g.size());
		assert(0<=b&&b<(int)g.size());
		int c=lca(a,b);
		int w=dep[a]+dep[b]-dep[c]*2;
		assert(0<=d&&d<=w);
		if(d<=dep[a]-dep[c]){
			rep(i,h)if(d&1<<i)
				a=par[i][a];
			return a;
		}else{
			d=w-d;
			rep(i,h)if(d&1<<i)
				b=par[i][b];
			return b;
		}
	}
	int getpar(int v,int len)const{
		rep(i,h)if(len&1<<i)v=par[i][v];
		return v;
	}
};

template<class t>
struct BIT{
	vc<t> buf;
	int s;
	BIT(int n=0){init(n);}
	void init(int n){buf.assign(s=n,0);}
	void add(int i,t v){
		for(;i<s;i+=(i+1)&(-i-1))
			buf[i]+=v;
	}
	t get(int i){
		t res=0;
		for(;i>=0;i-=(i+1)&(-i-1))
			res+=buf[i];
		return res;
	}
	t sum(int b,int e){
		return get(e-1)-get(b-1);
	}
	int kth(int k){
		int res=0;
		for(int i=topbit(s);i>=0;i--){
			int w=res+(1<<i);
			if(w<=s&&buf[w-1]<=k){
				k-=buf[w-1];
				res=w;
			}
		}
		return res;
	}
	//yukicoder No.1024
	int kth_helper(int k,int i){
		return kth(k+get(i-1));
	}
};

//offline
//ROI2018 day2 D
struct point2d{
	struct query{
		int x,i,l,r;
		bool operator<(const query&rhs)const{
			return pi(x,-i)<pi(rhs.x,-rhs.i);
		}
	};
	vi ys,ans;
	vc<query> qs;
	point2d(const vc<pi>&ps){
		for(auto p:ps)
			ys.pb(p.b);
		mkuni(ys);
		for(auto p:ps)
			qs.pb({p.a,-1,lwb(ys,p.b),-1});
	}
	void aq(int x1,int x2,int y1,int y2){
		int i=si(ans);
		ans.pb(0);
		y1=lwb(ys,y1);
		y2=lwb(ys,y2);
		qs.pb({x1,i*2,y1,y2});
		qs.pb({x2,i*2+1,y1,y2});
	}
	vi calc(){
		sort(all(qs));
		BIT<int> bit(si(ys));
		for(auto q:qs){
			if(q.i==-1){
				bit.add(q.l,1);
			}else{
				int w=bit.sum(q.l,q.r);
				if(q.i%2==0)ans[q.i/2]-=w;
				else ans[q.i/2]+=w;
			}
		}
		return ans;
	}
};

// in,out 
//VERIFY: yosupo
//CF530F
//CodeChef Persistent Oak
//AOJ GRL5C
template<class E>
struct HLD{
	vvc<E> g;
	int n,rt,cnt;
	vi sub,in,out,par,head,dep;
	int dfs1(int v,int p,int d){
		par[v]=p;
		dep[v]=d;
		g[v].erase(remove(all(g[v]),p),g[v].ed);
		for(auto&e:g[v]){
			sub[v]+=dfs1(e,v,d+1);
			if(sub[g[v][0]]<sub[e])
				swap(g[v][0],e);
		}
		return sub[v];
	}
	void dfs2(int v,int h){
		in[v]=cnt++;
		head[v]=h;
		for(int to:g[v])
			dfs2(to,to==g[v][0]?h:to);
		out[v]=cnt;
	}
	HLD(){}
	HLD(const vvc<E>&gg,int rr):g(gg),n(g.size()),rt(rr),cnt(0),
		sub(n,1),in(n),out(n),par(n,-1),head(n),dep(n){
		dfs1(rt,-1,0);
		dfs2(rt,rt);
	}
	int lca(int a,int b){
		while(head[a]!=head[b]){
			if(dep[head[a]]>dep[head[b]])
				swap(a,b);
			b=par[head[b]];
		}
		if(dep[a]>dep[b])
			swap(a,b);
		return a;
	}
	int len(int a,int b){
		return dep[a]+dep[b]-dep[lca(a,b)]*2;
	}
	bool asde(int a,int b){
		return in[a]<=in[b]&&out[b]<=out[a];
	}
	int k;
	vvc<pi> pt;
	struct Query{
		int i,x1,x2,y1,y2,w;
		bool has(int x,int y){
			return x1<=x&&x<x2&&y1<=y&&y<y2;
		}
	};
	vc<Query> qs;
	map<int,int> dfs(int v,const doubling<int>&d){
		map<int,int> res;
		int l=0,r=0;
		if(si(g[v])){
			res=dfs(g[v][0],d);
			l=in[g[v][0]];
			r=out[g[v][0]];
		}
		auto add=[&](int i,int to){
			auto itr=res.find(i);
			if(itr==res.ed)res[i]=to;
			else res.erase(itr);
		};
		bool curvert=false;
		auto waf=[&](int i,int to){
			if(!asde(v,to)){
				int c=lca(v,to);
				int uplen=dep[v]-dep[c];
				int downlen=dep[to]-dep[c];
				if(uplen+downlen>=k){
					if(uplen>=k){
						int z=d.getpar(v,k-1);
						if(l<r){
							qs.pb({i,0,in[z],l,r,2});
							qs.pb({i,l,r,out[z],n,2});
						}
						if(curvert){
							qs.pb({i,0,in[z],in[v],in[v]+1,1});
							qs.pb({i,in[v],in[v]+1,out[z],n,1});
						}
						if(in[to]>in[v]&&downlen){
							int w=d.getpar(to,downlen-1);
							if(l<r)qs.pb({i,l,r,in[w],out[w],-2});
							if(curvert)qs.pb({i,in[v],in[v]+1,in[w],out[w],-1});
						}
					}else{
						if(in[to]<in[v]){
							int z=d.getpar(to,(uplen+downlen-k));
							if(l<r)qs.pb({i,in[z],out[z],l,r,2});
							if(curvert)qs.pb({i,in[z],out[z],in[v],in[v]+1,1});
						}
					}
				}
			}
			add(i,to);
		};
		rng(tmpi,1,si(g[v])){
			map<int,int> z=dfs(g[v][tmpi],d);
			for(auto kv:z){
				waf(kv.a,kv.b);
			}
			r=out[g[v][tmpi]];
		}
		curvert=1;
		for(auto kv:pt[v]){
			waf(kv.a,kv.b);
		}
		return move(res);
	}
	void slv(int kk,int m){
		k=kk;
		pt.resize(n);
		vc<pi> xy;
		ll res=0;
		rep(i,m){
			int a,b;cin>>a>>b;
			a--;b--;
			pt[a].eb(i,b);
			pt[b].eb(i,a);
			xy.pb(minmax(in[a],in[b]));
			if(len(a,b)<k)res++;
		}
		doubling<int> d(g,0);
		dfs(0,d);
		
		vi ans(m);
		
		point2d ysp(xy);
		for(auto z:qs)ysp.aq(z.x1,z.x2,z.y1,z.y2);
		auto mrt=ysp.calc();
		rep(i,si(qs)){
			res+=qs[i].w*mrt[i];
		}
		
		dmp(ans);
		res-=m;
		print(res/2);
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,m;cin>>n>>m;
	int k;cin>>k;
	
	vvc<int> t(n);
	rep(_,n-1){
		int a,b;cin>>a>>b;
		a--;b--;
		t[a].pb(b);
		t[b].pb(a);
	}
	
	HLD<int> h(t,0);
	h.slv(k,m);
}