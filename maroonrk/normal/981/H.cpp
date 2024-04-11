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

using uint=unsigned;
using ull=unsigned long long;

//initfact();
const uint mod=998244353;
//const uint mod=1000000007;
//uint mod=1;
struct mint{
	uint v;
	mint(ll vv=0){s(vv%mod+mod);}
	mint& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	mint operator-()const{return mint()-*this;}
	mint& operator+=(const mint&rhs){return s(v+rhs.v);}
	mint&operator-=(const mint&rhs){return s(v+mod-rhs.v);}
	mint&operator*=(const mint&rhs){
		v=ull(v)*rhs.v%mod;
		return *this;
	}
	mint&operator/=(const mint&rhs){return *this*=rhs.inv();}
	mint operator+(const mint&rhs)const{return mint(*this)+=rhs;}
	mint operator-(const mint&rhs)const{return mint(*this)-=rhs;}
	mint operator*(const mint&rhs)const{return mint(*this)*=rhs;}
	mint operator/(const mint&rhs)const{return mint(*this)/=rhs;}
	mint pow(int n)const{
		mint res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	mint inv()const{return pow(mod-2);}
	/*mint inv()const{
		int x,y;
		int g=extgcd(v,mod,x,y);
		assert(g==1);
		if(x<0)x+=mod;
		return mint(x);
	}*/
	friend mint operator+(int x,const mint&y){
		return mint(x)+y;
	}
	friend mint operator-(int x,const mint&y){
		return mint(x)-y;
	}
	friend mint operator*(int x,const mint&y){
		return mint(x)*y;
	}
	friend mint operator/(int x,const mint&y){
		return mint(x)/y;
	}
	friend ostream& operator<<(ostream&os,const mint&m){
		return os<<m.v;
	}
	friend istream& operator>>(istream&is,mint&m){
		ll x;is>>x;
		m=mint(x);
		return is;
	}
	bool operator<(const mint&r)const{return v<r.v;}
	bool operator==(const mint&r)const{return v==r.v;}
	bool operator!=(const mint&r)const{return v!=r.v;}
	explicit operator bool()const{
		return v;
	}
};

const int vmax=(1<<21)+10;
mint fact[vmax],finv[vmax],invs[vmax];
void initfact(){
	fact[0]=1;
	rng(i,1,vmax){
		fact[i]=fact[i-1]*i;
	}
	finv[vmax-1]=fact[vmax-1].inv();
	for(int i=vmax-2;i>=0;i--){
		finv[i]=finv[i+1]*(i+1);
	}
	for(int i=vmax-1;i>=1;i--){
		invs[i]=finv[i]*fact[i-1];
	}
}
mint choose(int n,int k){
	return fact[n]*finv[n-k]*finv[k];
}
mint binom(int a,int b){
	return fact[a+b]*finv[a]*finv[b];
}
mint catalan(int n){
	return binom(n,n)-(n-1>=0?binom(n-1,n+1):0);
}

#define USE_FMT
//998244353
const mint prim_root=3;

/*
//in-place fft
//size of input must be a power of 2
void inplace_fmt(vector<mint>&f,const bool inv){
	const int n=f.size();
	const mint root=inv?prim_root.inv():prim_root;
	vc<mint> g(n);
	for(int b=n/2;b>=1;b/=2){
		mint w=root.pow((mint::base-1)/(n/b)),p=1;
		for(int i=0;i<n;i+=b*2){
			rep(j,b){
				f[i+j+b]*=p;
				g[i/2+j]=f[i+j]+f[i+b+j];
				g[n/2+i/2+j]=f[i+j]-f[i+b+j];
			}
			p*=w;
		}
		swap(f,g);
	}
	if(inv)rep(i,n)
		f[i]*=inv[n];
}*/

static const int LG=21;
mint roots[1<<(LG+1)],iroots[1<<(LG+1)];
struct PrepareRoots{
	PrepareRoots(){
		rep(w,LG+1){
			const int s=(1<<w)-1;
			const mint g=prim_root.pow((mod-1)/(1<<w)),ig=g.inv();
			mint p=1,ip=1;
			rep(i,1<<w){
				roots[s+i]=p;p*=g;
				iroots[s+i]=ip;ip*=ig;
			}
		}
	}
} PrepareRootsDummy;

void broken_fmt(vc<mint>&f){
	const int n=f.size();
	for(int b=n/2;b>=1;b/=2){
		for(int i=0;i<n;i+=b*2){
			rep(j,b){
				mint tmp=f[i+j]-f[i+j+b];
				f[i+j]+=f[i+j+b];
				f[i+j+b]=tmp*roots[b*2-1+j];
			}
		}
	}
}

void broken_ifmt(vc<mint>&f){
	const int n=f.size();
	for(int b=1;b<=n/2;b*=2){
		for(int i=0;i<n;i+=b*2){
			rep(j,b){
				f[i+j+b]*=iroots[b*2-1+j];
				mint tmp=f[i+j]-f[i+j+b];
				f[i+j]+=f[i+j+b];
				f[i+j+b]=tmp;
			}
		}
	}
	rep(i,n)
		f[i]*=invs[n];
}

void inplace_fmt(vector<mint>&f,const bool i){
	if(!i)broken_fmt(f);
	else broken_ifmt(f);
}

vc<mint> multiply(vc<mint> x,vc<mint> y,bool same=false){
	int n=x.size()+y.size()-1;
	int s=1;
	while(s<n)s*=2;
	x.resize(s);inplace_fmt(x,false);
	if(!same){
		y.resize(s);inplace_fmt(y,false);
	}else
		y=x;
	rep(i,s)
		x[i]*=y[i];
	inplace_fmt(x,true);x.resize(n);
	return x;
}

template<class D>
struct Poly:public vc<D>{
	template<class...Args>
	Poly(Args...args):vc<D>(args...){}
	Poly(initializer_list<D>init):vc<D>(all(init)){}
	int size()const{
		return vc<D>::size();
	}
	void ups(int s){
		if(size()<s)this->resize(s,0);
	}
	Poly low(int s)const{
		return Poly(this->bg,this->bg+min(max(s,int(1)),size()));
	}
	Poly rev()const{
		auto r=*this;
		reverse(all(r));
		return r;
	}
	Poly operator-()const{
		Poly res=*this;
		for(auto&v:res)v=-v;
		return res;
	}
	Poly& operator+=(const Poly&r){
		ups(r.size());
		rep(i,r.size())
			(*this)[i]+=r[i];
		return *this;
	}
	template<class T>
	Poly& operator+=(T t){
		(*this)[0]+=t;
		return *this;
	}
	Poly& operator-=(const Poly&r){
		ups(r.size());
		rep(i,r.size())
			(*this)[i]-=r[i];
		return *this;
	}
	template<class T>
	Poly& operator-=(T t){
		(*this)[0]-=t;
		return *this;
	}
	template<class T>
	Poly& operator*=(T t){
		for(auto&v:*this)
			v*=t;
		return *this;
	}
	Poly& operator*=(const Poly&r){
		return *this=multiply(*this,r);
	}
	Poly square()const{
		return multiply(*this,*this,true);
	}
	#ifndef USE_FMT
	Poly inv(int s)const{
		Poly r{D(1)/(*this)[0]};
		for(int n=1;n<s;n*=2)
			r=r*2-(r.square()*low(2*n)).low(2*n);
		return r.low(s);
	}
	#else
	Poly inv(int s)const{
		Poly r{D(1)/(*this)[0]};
		for(int n=1;n<s;n*=2){
			r.resize(n*4);
			inplace_fmt(r,false);
			vc<D> f=low(2*n);
			f.resize(n*4);
			inplace_fmt(f,false);
			rep(i,n*4)
				r[i]=r[i]*2-r[i]*r[i]*f[i];
			inplace_fmt(r,true);
			r.resize(2*n);
		}
		return r.low(s);
	}
	#endif
	template<class T>
	Poly& operator/=(T t){
		return *this*=D(1)/D(t);
	}
	Poly quotient(const Poly&r,const Poly&rri)const{
		int m=r.size();
		assert(r[m-1].v);
		int n=size();
		int s=n-m+1;
		if(s<=0) return {0};
		return (rev().low(s)*rri.low(s)).low(s).rev();
	}
	Poly& operator/=(const Poly&r){
		return *this=quotient(r,r.rev().inv(max(size()-r.size(),int(0))+1));
	}
	Poly& operator%=(const Poly&r){
		*this-=*this/r*r;
		return *this=low(r.size()-1);
	}
	Poly operator+(const Poly&r)const{return Poly(*this)+=r;}
	template<class T>
	Poly operator+(T t)const{return Poly(*this)+=t;}
	Poly operator-(const Poly&r)const{return Poly(*this)-=r;}
	template<class T>
	Poly operator-(T t)const{return Poly(*this)-=t;}
	template<class T>
	Poly operator*(T t)const{return Poly(*this)*=t;}
	Poly operator*(const Poly&r)const{return Poly(*this)*=r;}
	template<class T>
	Poly operator/(T t)const{return Poly(*this)/=t;}
	Poly operator/(const Poly&r)const{return Poly(*this)/=r;}
	Poly operator%(const Poly&r)const{return Poly(*this)%=r;}
	Poly dif()const{
		Poly r(max(int(0),size()-1));
		rep(i,r.size())
			r[i]=(*this)[i+1]*(i+1);
		return r;
	}
	Poly inte()const{
		Poly r(size()+1,0);
		rep(i,size())
			r[i+1]=(*this)[i]*invs[i+1];
		return r;
	}
	//VERIFY: yosupo
	//opencupXvcIII GP of Peterhof H
	Poly log(int s)const{
		return (low(s).dif()*inv(s-1)).low(s-1).inte();
	}
	//Petrozavodsk 2019w Day1 G
	//yosupo judge
	Poly exp(int s)const{
		return exp2(s).a;
	}
	//2
	pair<Poly,Poly> exp2(int s)const{
		assert((*this)[0]==mint(0));
		Poly f{1},g{1};
		for(int n=1;;n*=2){
			if(n>=s)break;
			g=g*2-(g.square()*f).low(n);
			//if(n>=s)break;
			Poly q=low(n).dif();
			q=q+g*(f.dif()-f*q).low(2*n-1);
			f=f+(f*(low(2*n)-q.inte())).low(2*n);
		}
		return make_pair(f.low(s),g.low(s));
	}
	//CF250 E
	Poly sqrt(int s)const{
		assert((*this)[0]==1);
		Poly r{1};
		for(int n=1;n<s;n*=2)
			r=(r+(r.inv(n*2)*low(n*2)).low(n*2))*invs[2];
		return r.low(s);
	}
	pair<Poly,Poly> divide(const Poly&r,const Poly&rri)const{
		Poly a=quotient(r,rri);
		Poly b=*this-a*r;
		return make_pair(a,b.low(r.size()-1));
	}
	//Yukicoder No.215
	Poly pow_mod(int n,const Poly&r)const{
		Poly rri=r.rev().inv(r.size());
		Poly cur{1},x=*this%r;
		while(n){
			if(n%2)
				cur=(cur*x).divide(r,rri).b;
			x=(x*x).divide(r,rri).b;
			n/=2;
		}
		return cur;
	}
	D eval(D x)const{
		D r=0,w=1;
		for(auto v:*this){
			r+=w*v;
			w*=x;
		}
		return r;
	}
};

const int nmax=100010;

int n,k;

vi t[nmax];

mint ans;

pair<mint,int> dfs(int v,int p){
	mint z=0;
	int s=1;
	vc<pair<mint,int>> w;
	for(auto c:t[v])if(c!=p){
		auto res=dfs(c,v);
		ans+=z*res.a;
		z+=res.a;
		s+=res.b;
		w.pb(res);
	}
	if(si(w)){
		auto rec=[&](auto self,int l,int r)->pair<Poly<mint>,Poly<mint>>{
			if(l+1==r){
				return {{w[l].a},{1,w[l].b}};
			}
			int m=(l+r)/2;
			auto a=self(self,l,m);
			auto b=self(self,m,r);
			return {a.a*b.b+a.b*b.a,a.b*b.b};
		};
		Poly<mint> a,b;
		tie(a,b)=rec(rec,0,si(w));
		dmp(w);
		dmp(a);
		dmp(b);
		mint rem=n-s;
		a.resize(si(a)+1);
		gnr(i,1,si(a))
			a[i]+=a[i-1]*rem;
		rep(i,min(si(a),k+1))if(i!=1||k!=1)
			ans+=a[i]*fact[k]*finv[k-i];
		rep(i,min(si(b),k+1))if(i!=1||k!=1)
			z+=b[i]*fact[k]*finv[k-i];
	}else{
		z=1;
	}
	return {z,s};
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	initfact();
	
	cin>>n>>k;
	rep(_,n-1){
		int a=read()-1;
		int b=read()-1;
		t[a].pb(b);
		t[b].pb(a);
	}
	
	dfs(0,-1);
	
	cout<<ans<<endl;
}