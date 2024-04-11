#ifndef LOCAL
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

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

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

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

pi readpi(int off=0){
	int a,b;cin>>a>>b;
	return pi(a+off,b+off);
}

template<class t,class u>
void print(const pair<t,u>&p,int suc=1){
	print(p.a,2);
	print(p.b,suc);
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

template<class T>
void print_offset(const vector<T>&v,ll off,int suc=1){
	rep(i,v.size())
		print(v[i]+off,i==int(v.size())-1?suc:2);
}

template<class T,size_t N>
void print(const array<T,N>&v,int suc=1){
	rep(i,N)
		print(v[i],i==int(N)-1?suc:2);
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
	#ifdef LOCAL
	cout.flush();
	#endif
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
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

vvc<int> readGraph(int n,int m){
	vvc<int> g(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		//sc.read(a,b);
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return g;
}

vvc<int> readTree(int n){
	return readGraph(n,n-1);
}

//CF Hello2020
template<class LM,class RM>
struct MatroidIntersection{
	int n,m,s;
	LM& lm;
	RM& rm;
	struct Edge{
		int to,cost,id;
		friend ostream& operator<<(ostream&os,const Edge&e){
			return os<<"{T:"<<e.to<<", C:"<<e.cost<<", I:"<<e.id<<"}";
		}
	};
	vc<tuple<int,int,int>> es;
	vvc<Edge> g;
	MatroidIntersection(LM& llm,RM& rrm):lm(llm),rm(rrm){
		n=lm.size();
		m=rm.size();
		s=n+m;
	}
	void AddEdge(int a,int b,int c){
		assert(0<=a&&a<n);
		assert(0<=b&&b<m);
		assert(0<=c);
		es.eb(a,b,c);
	}
	vi h;
	vc<pi> dist,prev;
	void FindShortest(const vi&src){
		dist.assign(s,pi(inf,-1));
		prev.assign(s,pi(-1,-1));
		
		using Node=tuple<int,int,int>;
		priority_queue<Node,vc<Node>,greater<Node>> pq;
		const auto Reach=[&](int v,int d,int step,int j,int k){
			if(pi(d,step)<dist[v]){
				dist[v]=pi(d,step);
				prev[v]=pi(j,k);
				pq.push(make_tuple(d,step,v));
			}
		};

		for(auto i:src)
			Reach(i,0,0,-1,-1);
		
		while(!pq.empty()){
			int d,step,v;
			tie(d,step,v)=pq.top();
			pq.pop();
			if(dist[v]!=pi(d,step))
				continue;
			for(auto e:g[v]){
				assert(e.cost+h[v]-h[e.to]>=0);
				Reach(e.to,d+e.cost+h[v]-h[e.to],step+1,v,e.id);
			}
		}
	}
	int Augment(vc<bool>&use){
		g.assign(s,vc<Edge>());
		vi m1,m2;
		rep(i,es.size()){
			int a,b,c;
			tie(a,b,c)=es[i];
			if(use[i]){
				g[n+b].pb(Edge{a,-c,i});
				m1.pb(a);
				m2.pb(b);
			}else{
				g[a].pb(Edge{n+b,c,i});
			}
		}
		vi src,dst;
		{
			auto w=lm.Get(m1);
			src=w.first;
			if(src.empty())return -1;
			for(auto e:w.second)
				g[e.first].pb(Edge{e.second,0,-1});
		}
		{
			auto w=rm.Get(m2);
			dst=w.first;
			if(dst.empty())return -1;
			for(auto e:w.second)
				g[n+e.second].pb(Edge{n+e.first,0,-1});
		}
		
		FindShortest(src);
		
		pair<pi,int> w(pi(inf/2,-1),-1);
		for(auto i:dst)
			chmin(w,mp(dist[n+i],n+i));
		if(w.second==-1)
			return -1;
		int x=w.second;
		while(prev[x].first!=-1){
			int i=prev[x].second;
			if(i!=-1)
				use[i]=!use[i];
			x=prev[x].first;
		}
		int mn=w.first.first;
		rep(i,s){
			h[i]+=min(dist[i].first,mn);
			chmin(h[i],inf);
		}
		return h[w.second];
	}
	pair<int,vi> Solve(){
		h.assign(s,0);
		vc<bool> use(es.size());
		int c=0,f;
		while((f=Augment(use))>=0)
			c+=f;
		vi sol;
		rep(i,es.size())
			if(use[i])
				sol.pb(i);
		return mp(c,sol);
	}
};
//Matroid
//size(): returns the size of the universe
//Get(vi cur): 
//given is a set of indices of currently used elements.
//returns pair of
//1. indices of src(vertices that it is free to add)
//2. all (x,y) s.t. del x & add y is possible (y is not a src)
//practically it runs with low constants (why?)

//VERIFY: yosupo
//KUPC2017J
//AOJDSL1A
//without rank
struct unionfind{
	vi p,s;
	int c;
	unionfind(int n=0):p(n,-1),s(n,1),c(n){}
	void init(int n){
		p.clear();p.resize(n,-1);
		s.clear();s.resize(n,1);
		c=n;
	}
	int find(int a){
		return p[a]==-1?a:(p[a]=find(p[a]));
	}
	//set b to a child of a
	bool unite(int a,int b){
		a=find(a);
		b=find(b);
		if(a==b)return false;
		p[b]=a;
		s[a]+=s[b];
		c--;
		return true;
	}
	bool same(int a,int b){
		return find(a)==find(b);
	}
	int sz(int a){
		return s[find(a)];
	}
};

struct MST{
	int n;
	vc<pi> base,es;
	MST(int nn,vc<pi> bb,vc<pi> ee){
		n=nn;
		base=bb;
		es=ee;
	}
	int size(){
		return es.size();
	}
	unionfind uf;
	void ufinit(){
		uf.init(n);
		for(auto [a,b]:base){
			uf.unite(a,b);
		}
	}
	pair<vi,vc<pi>> Get(const vi&cur){
		ufinit();
		vi t(size(),0);
		for(auto i:cur){
			uf.unite(es[i].first,es[i].second);
			t[i]=1;
		}
		vi src;
		rep(i,size())if(!t[i]){
			if(!uf.same(es[i].first,es[i].second)){
				src.pb(i);
				t[i]=2;
			}
		}
		vc<pi> res;
		rep(i,size())if(t[i]==1){
			ufinit();
			rep(j,size())if(t[j]==1&&j!=i)
				uf.unite(es[j].first,es[j].second);
			rep(j,size())if(!t[j])
				if(!uf.same(es[j].first,es[j].second))
					res.eb(i,j);
		}
		return mp(src,res);
	}
};

struct FreeMatroid{
	int n;
	vc<pi> base,es;
	vi lim,deg;
	FreeMatroid(int nn,vc<pi> bb,vc<pi> ee,vi unko){
		n=nn;
		base=bb;
		es=ee;
		lim=unko;
	}
	int size(){
		return es.size();
	}
	void deginit(){
		deg.clear();deg.resize(si(lim));
		for(auto [a,b]:base){
			deg[a]++;
			deg[b]++;
		}
	}
	void add(int i){
		if(es[i].a<si(deg))deg[es[i].a]++;
		if(es[i].b<si(deg))deg[es[i].b]++;
	}
	bool canadd(int i){
		if(es[i].a<si(deg))if(deg[es[i].a]>=lim[es[i].a])return false;
		if(es[i].b<si(deg))if(deg[es[i].b]>=lim[es[i].b])return false;
		return true;
	}
	pair<vi,vc<pi>> Get(const vi&cur){
		deginit();
		vi t(size());
		for(auto i:cur){
			add(i);
			t[i]=1;
		}
		vi src;
		rep(i,size())if(!t[i]){
			if(canadd(i)){
				src.pb(i);
				t[i]=2;
			}
		}
		vc<pi> res;
		rep(i,size())if(t[i]==1){
			deginit();
			rep(j,size())if(t[j]==1&&j!=i)
				add(j);
			rep(j,size())if(!t[j])
				if(canadd(j))
					res.eb(i,j);
		}
		return mp(src,res);
	}
};

void slv(){
	int n,k;cin>>n>>k;
	vi d=readvi(k);
	
	vi x,y;
	vc<pi> es,fs;
	
	rep(i,n)rng(j,i+1,n){
		if(j<k){
			x.pb(read());
			es.eb(i,j);
		}else{
			y.pb(read());
			fs.eb(i,j);
		}
	}
	
	int ans=inf;
	
	rep(bit,1<<si(es)){
		unionfind uf(n);
		int off=0;
		bool ok=true;
		vi deg(k);
		vc<pi> tmp;
		rep(i,si(es))if(bit&1<<i){
			ok&=uf.unite(es[i].a,es[i].b);
			off+=x[i];
			deg[es[i].a]++;
			deg[es[i].b]++;
			tmp.pb(es[i]);
		}
		rep(i,k)ok&=deg[i]<=d[i];
		if(ok){
			dmp(bit);
			MST lf(n,tmp,fs);
			FreeMatroid rt(n,tmp,fs,d);
			
			MatroidIntersection<MST,FreeMatroid> mi(lf,rt);
			rep(i,si(fs))mi.AddEdge(i,i,y[i]);
			
			auto [cost,used]=mi.Solve();
			if(popcount(bit)+si(used)==n-1){
				chmin(ans,off+cost);
			}
		}
	}
	
	if(ans==inf)ans=-1;
	print(ans);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}