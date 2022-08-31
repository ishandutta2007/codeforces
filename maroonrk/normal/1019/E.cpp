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
int mask(int i){
	return (int(1)<<i)-1;
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
    static random_device rd;
    static mt19937_64 gen(rd());
    #endif
    return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

//max hull

//Author: Simon Lindholm
//https://github.com/kth-competitive-programming/kactl/blob/master/content/data-structures/LineContainer.h
struct Line {
	mutable ll k, m, p;
	int idx;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m, int idx=-1) {
		auto z = insert({k, m, 0, idx}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	pi query(ll x) {
		assert(!empty());
		//if(empty())return -inf;
		auto l = *lower_bound(x);
		return pi(l.k * x + l.m,l.idx);
	}
};

struct Lines{
	int s;
	vvc<pi> ls;
	vvc<tuple<int,int,int*>> buf;
	void init(int n){
		s=n;
		ls.resize(s+1);
		buf.resize(s+1);
	}
	void addq(int i,int t,int off,int*dst){
		buf[i].eb(t,off,dst);
	}
	void addl(int i,int a,int b){
		ls[i].eb(a,b);
	}
	void calc(){
		rep(_,2){
			LineContainer lc;
			lc.add(0,0);
			rep(i,s+1){
				for(auto q:buf[i]){
					int t,off,*dst;
					tie(t,off,dst)=q;
					chmax(*dst,lc.query(t).a+off);
				}
				for(auto q:ls[i])
					lc.add(q.a,q.b);
			}
			reverse(ls.bg,ls.bg+s);
			reverse(buf.bg,buf.bg+s);
		}
	}
};

//Nikkei2019 Final G
//XX Opencup GP of Warsaw I
template<class E>
struct cdecomp{
	const vvc<E>&g;
	int n,h;
	vi lv,rem;
	vvc<vc<E>> fr;
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
	void mk(int v,int p,vvc<E>&t){
		for(auto e:g[v])if(e!=p&&!rem[e]){
			t[v].pb(e);
			mk(e,v,t);
		}
	}
	void con(int r,int d){
		assert(d<h);
		r=-fc(r,-1,ts(r,-1));
		lv[r]=d;
		mk(r,-1,fr[d]);
		rem[r]=1;
		for(auto e:fr[d][r])
			con(e,d+1);
	}
	cdecomp(const vvc<E>&gg):g(gg),n(g.size()),h(__lg(n)+1),
		lv(n),rem(n),fr(h,vvc<E>(n)),/*nd(h,vc<N>(n))*/nd(n){
		con(0,0);
		//init();
	}
	//
	struct N{
		int a,b,i,j;
	};
	//nd 
	//
	//vvc<N> nd;
	vc<N> nd;
	vc<Lines> lss;
	void dfs(int v,int a,int b,int i,int j,const vvc<E>&t,vc<N>&x){
		x[v]=N{a,b,i,j};
		lss[i].addl(j,a,b);
		for(auto e:t[v])
			dfs(e.to,a+e.a,b+e.b,i,j,t,x);
	}
	//
	void initsub(int r,const vvc<E>&t,vc<N>&x){
		int i=lss.size();
		lss.eb();
		lss[i].init(si(t[r]));
		x[r]=N{0,0,i,si(t[r])};
		rep(j,si(t[r]))
			dfs(t[r][j].to,t[r][j].a,t[r][j].b,i,j,t,x);
	}
	/*void init(){
		rep(i,n)initsub(i,fr[lv[i]],nd[lv[i]]);
	}
	void addquery(int v,int t,int*dst){
		rep(i,lv[v]+1){
			auto x=nd[i][v];
			lss[x.i].addq(x.j,t,x.a*t+x.b,dst);
		}
	}
	void calc(){
		for(auto&z:lss)
			z.calc();
	}*/
	void calc(const vi&idx,vi&ans){
		rep(z,h){
			lss.clear();
			rep(i,n)if(lv[i]==z){
				initsub(i,fr[lv[i]],nd);
			}
			rep(i,idx.size()){
				int v=idx[i];
				if(z<=lv[v]){
					auto x=nd[v];
					lss[x.i].addq(x.j,i,x.a*i+x.b,&ans[i]);
				}
			}
			for(auto&w:lss)
				w.calc();
		}
	}
};

const int nmax=100010;

struct E{
	int to,a,b;
	operator int()const{return to;}
};

vvc<E> t;
void dfs(int v,int r,int a,int b,LineContainer&lc){
	lc.add(a,b,v);
	for(auto e:t[v])if(e.to!=r){
		dfs(e.to,v,a+e.a,b+e.b,lc);
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	int m=read();
	t.resize(n);
	rep(i,n-1){
		int u,v,a,b;cin>>u>>v>>a>>b;
		u--;v--;
		t[u].pb({v,a,b});
		t[v].pb({u,a,b});
	}
	
	LineContainer lc;
	dfs(0,-1,0,0,lc);
	
	vi idx(m);
	vi ans(m);
	rep(i,m)
		idx[i]=lc.query(i).b;
	
	dmp(idx);
	cdecomp<E> cd(t);
	//rep(i,m)
	//	cd.addquery(idx[i],i,&ans[i]);
	
	//cd.calc();
	cd.calc(idx,ans);
	
	print(ans);
}