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

using uint=unsigned;
using ull=unsigned long long;

struct modinfo{uint mod,root;};
template<modinfo const&ref>
struct modular{
	static constexpr uint const &mod=ref.mod;
	static modular root(){return modular(ref.root);}
	uint v;
	//modular(initializer_list<uint>ls):v(*ls.bg){}
	modular(ll vv=0){s(vv%mod+mod);}
	modular& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	modular operator-()const{return modular()-*this;}
	modular& operator+=(const modular&rhs){return s(v+rhs.v);}
	modular&operator-=(const modular&rhs){return s(v+mod-rhs.v);}
	modular&operator*=(const modular&rhs){
		v=ull(v)*rhs.v%mod;
		return *this;
	}
	modular&operator/=(const modular&rhs){return *this*=rhs.inv();}
	modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}
	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
	modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}
	modular pow(int n)const{
		modular res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	modular inv()const{return pow(mod-2);}
	/*modular inv()const{
		int x,y;
		int g=extgcd(v,mod,x,y);
		assert(g==1);
		if(x<0)x+=mod;
		return modular(x);
	}*/
	friend modular operator+(int x,const modular&y){
		return modular(x)+y;
	}
	friend modular operator-(int x,const modular&y){
		return modular(x)-y;
	}
	friend modular operator*(int x,const modular&y){
		return modular(x)*y;
	}
	friend modular operator/(int x,const modular&y){
		return modular(x)/y;
	}
	friend ostream& operator<<(ostream&os,const modular&m){
		return os<<m.v;
	}
	friend istream& operator>>(istream&is,modular&m){
		ll x;is>>x;
		m=modular(x);
		return is;
	}
	bool operator<(const modular&r)const{return v<r.v;}
	bool operator==(const modular&r)const{return v==r.v;}
	bool operator!=(const modular&r)const{return v!=r.v;}
	explicit operator bool()const{
		return v;
	}
};

template<class mint>
ll m2l(mint a){
	return a.v<mint::mod/2?a.v:ll(a.v)-ll(mint::mod);
}

//extern constexpr modinfo base{998244353,3};
extern constexpr modinfo base{1000000007,0};
//modinfo base{1,0};
using mint=modular<base>;

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

ll norm_mod(ll a,ll p){
	a%=p;
	if(a<0)a+=p;
	return a;
}

//p: odd (not necessarily prime)
//10^18 
ll jacobi(ll a,ll p){
	a=norm_mod(a,p);
	auto neg=[](ll x){return x%2?-1:1;};
	if(a==0) return p==1;
	else if(a%2) return neg(((p-1)&(a-1))>>1)*jacobi(p%a,a);
	else return neg(((p&15)*(p&15)-1)/8)*jacobi(a/2,p);
}

//yosupo sqrt mod (work without define int ll)
//LOJ 150
//p: prime
//0<=a<p
//returns minimum solution
ll sqrt_mod(ll a,ll p){
	if(p==2)return a%2;
	if(a==0)return 0;
	if(jacobi(a,p)==-1)return -1;
	ll b,c;
	do{
		b=rand_int(0,p-1);
		c=norm_mod(b*b-a,p);
	}while(jacobi(c,p)!=-1);
	auto mul=[&](pair<ll,ll> x,pair<ll,ll> y){
		return pi(norm_mod(x.a*y.a+x.b*y.b%p*c,p),norm_mod(x.a*y.b+x.b*y.a,p));
	};
	pair<ll,ll> x(b,1),cur(1,0);
	ll n=(p+1)/2;
	while(n){
		if(n&1)cur=mul(cur,x);
		x=mul(x,x);
		n>>=1;
	}
	assert(cur.b==0);
	return min(cur.a,p-cur.a);
}

//CF453E
//ax^2+bx+c=0
template<class mint>
vc<mint> quadratic_equation(mint a,mint b,mint c){
	mint d=sq(b)-4*a*c;
	ll z=sqrt_mod(d.v,mint::mod);
	if(z==-1)return {};
	vc<mint> res;
	rep(k,2){
		res.pb((-b+z)/(2*a));
		if(z==0)break;
		z=mint::mod-z;
	}
	return res;
}

//CF586
//
vc<pair<mint,mint>> cross_circle(mint x1,mint y1,mint z1,mint x2,mint y2,mint z2){
	mint a=x2-x1,b=y2-y1;
	dmp2(a,b,z1,z2);
	bool rev=false;
	if(a==0){
		rev=true;
		swap(a,b);
	}
	if(a==0){
		assert(z1!=z2);
		return {};
	}
	//(p-a)^2+(q-b)^2=z2
	//p^2+q^2=z1
	//z1+a^2+b^2-z2=2(ap+bq)
	mint w=(z1+a*a+b*b-z2)/2;
	//(ap)^2+(aq)^2=(w-bq)^2+(aq)^2=a^2z1
	auto qs=quadratic_equation(a*a+b*b,-2*b*w,w*w-a*a*z1);
	vc<pair<mint,mint>> res;
	for(auto q:qs){
		mint p=(w-b*q)/a;
		if(rev)res.eb(q,p);
		else res.eb(p,q);
	}
	for(auto&t:res){
		t.a+=x1;
		t.b+=y1;
	}
	return res;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	vc<pi> xy;
	mint cx,cy,waf;
	rep(i,n){
		int x,y;cin>>x>>y;
		xy.eb(x,y);
		cx+=x;
		cy+=y;
		waf+=x*x+y*y;
	}
	mint in=mint(n).inv();
	cx*=in;
	cy*=in;
	waf*=in;
	
	int qs;cin>>qs;
	rep(_,qs){
		vi ds=readvi(n);
		sort(all(ds));
		mint cd;
		for(auto v:ds)cd+=v;
		cd*=in;
		cd-=waf;
		cd+=cx*cx+cy*cy;
		
		vc<pi> cand;
		
		rep(i,n){
			auto f=cross_circle(xy[i].a,xy[i].b,ds[0],cx,cy,cd);
			dmp(f);
			for(auto z:f){
				int x=m2l(z.a),y=m2l(z.b);
				if(sq(x-xy[i].a)+sq(y-xy[i].b)==ds[0])
					cand.eb(m2l(z.a),m2l(z.b));
			}
		}
		
		mkuni(cand);
		vc<pi> tmp;
		for(auto z:cand){
			vi cur(n);
			rep(i,n)cur[i]=sq(z.a-xy[i].a)+sq(z.b-xy[i].b);
			sort(all(cur));
			if(cur==ds)
				tmp.pb(z);
		}
		sort(all(tmp));
		cout<<si(tmp);
		for(auto z:tmp){
			cout<<" "<<z.a<<" "<<z.b;
		}
		cout<<"\n";
	}
}