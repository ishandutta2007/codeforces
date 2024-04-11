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

/*
//VERIFY: yosupo
//CF Global3 H
//ARC073 F
//point update
template<class T,class F>
struct SegTree{
	vc<T> buf;
	int s;
	const F f;
	const T g;
	SegTree(F ff,T gg):f(ff),g(gg){}
	void init(const vc<T>& d){
		int n=d.size();
		s=1;
		while(s<n)s*=2;
		buf.resize(s*2,g);
		rep(i,n)
			buf[i+s]=d[i];
		gnr(i,1,s)
			u(i);
	}
	SegTree(const vc<T>& d,F ff,T gg):f(ff),g(gg){
		init(d);
	}
	void u(int i){
		buf[i]=f(buf[i*2],buf[i*2+1]);
	}
	void set(int i,T t){
		i+=s;
		buf[i]=t;
		while(i>>=1)u(i);
	}
	void upd(int i,T t){
		i+=s;
		buf[i]=f(buf[i],t);
		while(i>>=1)u(i);
	}
	T get(int b,int e){
		T lf=g,rt=g;
		for(int l=b+s,r=e+s;l<r;l>>=1,r>>=1){
			if (l&1){
				lf=f(lf,buf[l]);
				l++;
			}
			if (r&1){
				r--;
				rt=f(buf[r],rt);
			}
		}
		return f(lf,rt);
	}
};
template<class T,class F>
SegTree<T,F> segtree(const vc<T>& d,F f,T g){
	return SegTree<T,F>(d,f,g);
}
const auto imin=[](int a,int b){return min(a,b);};
const auto imax=[](int a,int b){return max(a,b);};
const auto iplus=[](int a,int b){return a+b;};

//PakenCamp2019 Day2 Jikka
template<class t,class F>
struct Point1D{
	SegTree<t,F> seg;
	vi pos;
	const t g;
	Point1D(F ff,t gg):seg(ff,gg),g(gg){}
	void addp(int p){
		pos.pb(p);
	}
	void init(){
		mkuni(pos);
		seg.init(vc<t>(pos.size(),g));
	}
	int idx(int p){
		return lwb(pos,p);
	}
	void updv(int p,t v){
		seg.upd(idx(p),v);
	}
	t get(int b,int e){
		return seg.get(idx(b),idx(e));
	}
};
*/

const auto imin=[](int a,int b){return min(a,b);};

template<class t,class F>
struct Point1D{
	vc<t> buf;
	vi pos;
	const F f;
	const t g;
	Point1D(F ff,t gg):f(ff),g(gg){}
	void addp(int p){
		pos.pb(p);
	}
	void init(){
		mkuni(pos);
		//seg.init(vc<t>(pos.size(),g));
		buf.resize(si(pos),g);
	}
	int idx(int p){
		return lwb(pos,p);
	}
	void updv(int p,t v){
		//seg.upd(idx(p),v);
		for(int i=idx(p);i<si(pos);i+=(i+1)&(-i-1)){
			buf[i]=f(buf[i],v);
		}
	}
	t get(int,int e){
		//discard b
		//return seg.get(idx(b),idx(e));
		t res=g;
		for(int i=idx(e)-1;i>=0;i-=(i+1)&(-i-1)){
			res=f(res,buf[i]);
		}
		return res;
	}
};

//PakenCamp2019 Day2 Jikka
template<class t,class F>
struct Point2D{
	vc<Point1D<t,F>> buf;
	vi pos,xs,ys;
	const F f;
	const t g;
	int s;
	Point2D(F ff,t gg):f(ff),g(gg){}
	void addp(int x,int y){
		xs.pb(x);
		ys.pb(y);
	}
	int idx(int p){
		return lwb(pos,p);
	}
	void init(){
		pos=xs;
		mkuni(pos);
		s=1;
		while(s<(int)pos.size())s*=2;
		rep(i,s*2)buf.emplace_back(f,g);
		rep(i,xs.size()){
			int j=lwb(pos,xs[i])+s;
			while(j>=1){
				buf[j].addp(ys[i]);
				j>>=1;
			}
		}
		for(auto&b:buf)b.init();
	}
	void updv(int x,int y,t v){
		int j=idx(x)+s;
		while(j>=1){
			buf[j].updv(y,v);
			j>>=1;
		}
	}
	//[x1,x2)*[y1,y2)
	t get(int x1,int x2,int y1,int y2){
		int b=idx(x1),e=idx(x2);
		t lf=g,rt=g;
		for(int l=b+s,r=e+s;l<r;l>>=1,r>>=1){
			if (l&1){
				lf=f(lf,buf[l].get(y1,y2));
				l++;
			}
			if (r&1){
				r--;
				rt=f(buf[r].get(y1,y2),rt);
			}
		}
		return f(lf,rt);
	}
};

void slv(){
	int n;cin>>n;
	int m;cin>>m;
	vc<pi> lr(m);
	vvc<int> ls(n+1);
	Point2D<int,decltype(imin)> p2d(imin,inf);
	rep(i,m){
		int l,r;cin>>l>>r;
		l--;
		lr[i]=pi(l,r);
		ls[r-l].pb(i);
		p2d.addp(l,r);
	}
	p2d.init();
	vi ans;
	gnr(len,1,n+1){
		for(auto j:ls[len]){
			auto [l,r]=lr[j];
			p2d.updv(l,r,j);
		}
		int sum=0;
		auto dfs=[&](auto self,int l,int r)->void{
			int k=p2d.get(l,inf,-inf,r+1);
			if(k>=m)return;
			sum+=lr[k].b-lr[k].a;
			self(self,l,lr[k].a);
			self(self,lr[k].b,r);
		};
		dfs(dfs,0,n);
		ans.pb(sum);
	}
	reverse(all(ans));
	print(ans);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}