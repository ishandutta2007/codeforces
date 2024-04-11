#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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

#define CAPITAL
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

template<class t>
bool inc(t a,t b,t c){
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
    static random_device rd;
    static mt19937_64 gen(rd());
    #endif
    return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

//https://codeforces.com/blog/entry/62393
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template<class t,class u>
using hash_table=gp_hash_table<t,u,custom_hash>;

//VERIFY: yosupo
//KUPC2017J
//AOJDSL1A
//without rank
struct unionfind{
	vi p,s;
	int c;
	unionfind(int n):p(n,-1),s(n,1),c(n){}
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
};

//Nikkei2019 Final G
//XX Opencup GP of Warsaw I
template<class E>
struct cdecomp{
	const vvc<E>&g;
	int n;
	vi lv,rem;
	int ts(int v,int p){
		int res=1;
		for(auto e:g[v])if(e!=p&&!rem[e])
			res+=ts(e,v);
		return res;
	}
	int fc(int v,int p,int s){
		int ret=1,mx=0;
		for(auto e:g[v])if(e!=p&&!rem[e]){
			int f=fc(e,v,s);
			if(f<=0)
				return f;
			else{
				ret+=f;
				mx=max(mx,f);
			}
		}
		mx=max(mx,s-ret);
		if(mx*2<=s)
			return -v;
		else
			return ret;
	}
	void con(int r,int d){
		r=-fc(r,-1,ts(r,-1));
		lv[r]=d;
		
		initsub(r,d);
		
		rem[r]=1;
		for(auto e:g[r])if(!rem[e])
			con(e,d+1);
	}
	cdecomp(const vvc<E>&gg):g(gg),n(g.size()),
		lv(n),rem(n),nd(n){
	}
	vi z;
	//vc<hash_table<int,int>> waf;
	vc<unordered_map<int,int>> waf;
	//
	struct N{
		int d,p;
	};
	//nd 
	//
	vc<array<N,20>> nd;
	void dfs(int v,int p,int h,int d,int rt){
		nd[v][h]={d,rt};
		if(z[v]!=-1){
			if(waf[rt].count(z[v])>0){
				chmin(waf[rt][z[v]],d);
			}else{
				waf[rt][z[v]]=d;
			}
		}
		for(auto e:g[v])if(e!=p&&!rem[e])
			dfs(e,v,h,d+1,rt);
	}
	void initsub(int r,int h){
		dfs(r,-1,h,0,r);
	}
	void init(){
		assert(si(z));
		waf.resize(n);
		con(0,0);
	}
	bool query(int v,int r,int c){
		rep(i,lv[v]+1){
			N x=nd[v][i];
			if(r>=x.d){
				int w=r-x.d;
				if(waf[x.p].count(c)&&waf[x.p][c]<=w)return true;
			}
		}
		return false;
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	int k;cin>>k;
	int r;cin>>r;
	
	vvc<int> t(n);
	rep(_,n-1){
		int a,b;cin>>a>>b;
		a--;b--;
		t[a].pb(b);
		t[b].pb(a);
	}
		vi u(n);
		rep(i,r)u[read()-1]=1;
		
	
	unionfind uf(n);
	
	vc<pi> dist(n,pi(-1,-1));
	
	{
		queue<int> q;
		auto reach=[&](int v,int d,int f){
			if(d>k)return;
			if(dist[v].a==-1){
				dist[v]=pi(d,f);
				q.push(v);
			}else{
				if(dist[v].a+d<=k){
					uf.unite(dist[v].b,f);
				}
			}
		};
		
		rep(i,n)if(u[i]){
			reach(i,0,i);
		}
		while(si(q)){
			int v=q.front();q.pop();
			for(auto to:t[v])
				reach(to,dist[v].a+1,dist[v].b);
		}
	}
	
	doubling<int> d(t,0);
	cdecomp<int> cd(t);
	cd.z.resize(n,-1);
	rep(i,n)if(u[i])cd.z[i]=uf.find(i);
	cd.init();
	
	int q;cin>>q;
	rep(_,q){
		int a,b;cin>>a>>b;
		a--;b--;
		int len=d.len(a,b);
		if(len<=k){
			yes(0);
		}else{
			int m=len/2;
			int c=d.jump(a,b,m);
			int tp=dist[c].b;
			if(tp==-1)no(0);
			else{
				tp=uf.find(tp);
				if(cd.query(a,k,tp)&&cd.query(b,k,tp))
					yes(0);
				else
					no(0);
			}
		}
	}
}