#ifndef LOCAL
#pragma GCC optimize ("-Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

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

const int nmax=15010;
const int L=14;

template<class N>
struct BIT{
	int n;
	N x[nmax];
	void init(int nn){
		n=nn;
		rep(i,n)x[i]=N();
	}
	void upd(int i,N val){
		for(;i<n;i+=(i+1)&(-i-1))x[i]=N::merge(x[i],val);
	}
	N get(int i){
		N res;
		for(;i>=0;i-=(i+1)&(-i-1))res=N::merge(res,x[i]);
		return res;
	}
	template <class F,class... Args> 
	int find(F f,Args&&... args){
		N cur;
		int res=0;
		per(i,L){
			int w=res+(1<<i);
			if(w<=n){
				N nx=N::merge(cur,x[w-1]);
				if((nx.*f)(forward<Args>(args)...)){
					cur=nx;
					res=w;
				}
			}
		}
		return res;
	}
};

struct MinNode{
	int v;
	MinNode(int vv=inf):v(vv){}
	static MinNode merge(const MinNode&a,const MinNode&b){
		return MinNode(min(a.v,b.v));
	}
	bool ok(int x){return x<=v;}
};

struct MaxNode{
	int v;
	MaxNode(int vv=-inf):v(vv){}
	static MaxNode merge(const MaxNode&a,const MaxNode&b){
		return MaxNode(max(a.v,b.v));
	}
	bool ok(int x){return v<=x;}
};

const int vmax=510;

BIT<MinNode> x[vmax];
BIT<MaxNode> y[vmax];
int lf[nmax][vmax],rt[nmax][vmax];

bool dbg=false;

void slv(){
	int n;vi a;
	
	if(dbg){
		n=15000;
		a.resize(n);iota(all(a),0);
		myshuffle(a);
	}else{
		cin>>n;
		a=readvi(n,-1);
	}
	auto work=[&]()->int{
		rep(v,vmax){
			x[v].init(n);
			y[v].init(n);
		}
		int mx=0;
		per(i,n){
			rep(v,vmax){
				if(lf[i][v]<n){
					x[v].upd(n-1-a[i],lf[i][v]);
					chmax(mx,v);
				}
				if(rt[i][v]>=0){
					y[v].upd(a[i],rt[i][v]);
					chmax(mx,v);
				}
			}
			rng(v,1,mx+1){
				//lf->lf
				if(i){
					chmin(lf[i-1][v+1],x[v].get(n-1-a[i-1]).v);
				}
				//lf->rt
				if(i>=v){
					int j=n-1-x[v].find(&MinNode::ok,a[i-v]);
					chmax(rt[i-v][v+1],j);
				}
				//rt->rt
				if(i){
					chmax(rt[i-1][v+1],y[v].get(a[i-1]).v);
				}
				//rt->lf
				if(i>=v){
					int j=y[v].find(&MaxNode::ok,a[i-v]);
					chmin(lf[i-v][v+1],j);
				}
			}
		}
		return mx;
	};
	int ans=0;
	//use a_{n-1}
	{
		rep(i,n)rep(v,vmax){
			lf[i][v]=inf;
			rt[i][v]=-inf;
		}
		lf[n-1][1]=a[n-1];
		rt[n-1][1]=a[n-1];
		chmax(ans,work());
	}
	//don't
	{
		rep(i,n)rep(v,vmax){
			lf[i][v]=inf;
			rt[i][v]=-inf;
		}
		rep(i,n-1){
			lf[i][2]=a[i];
			rt[i][2]=a[i];
		}
		chmax(ans,work()-1);
	}
	print(ans);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int t;cin>>t;
	if(t<0){
		dbg=true;
		t=-t;
	}
	rep(_,t)
	slv();
}