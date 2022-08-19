#include <bits/stdc++.h>
using namespace std;

using uint=unsigned;
using ll=long long;
using ull=unsigned long long;
//#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) FOR(i,0,b)
#define ROF(i,a,b) for(int i=int(b)-1;i>=a;i--)
#define per(i,b) ROF(i,0,b)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
auto& errStream=cerr;
#ifdef LOCAL
#define cerr (cerr<<"-- line "<<__LINE__<<" -- ")
#else
class CerrDummy{}cerrDummy;
template<class T>
CerrDummy& operator<<(CerrDummy&cd,const T&){
	return cd;
}
using charTDummy=char;
using traitsDummy=char_traits<charTDummy>;
CerrDummy& operator<<(CerrDummy&cd,basic_ostream<charTDummy,traitsDummy>&(basic_ostream<charTDummy,traitsDummy>&)){
	return cd;
}
#define cerr cerrDummy
#endif
#define reach cerr<<"reached"<<endl
void dmpr(decltype(cerr)&os){os<<endl;}
template<class T,class... Args>
void dmpr(decltype(cerr)&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp(...) dmpr(cerr,##__VA_ARGS__)
#define zero(x) memset(x,0,sizeof(x))
#define one(x) memset(x,-1,sizeof(x))
#define fs first
#define sc second
#define bg begin()
#define ed end()

template<class T> using V=vector<T>;
template<class T> using VV=V<V<T>>;

using pi=pair<int,int>;
using vi=vector<int>;
using ld=long double;

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	rep(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
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
	os<<"(";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<")";
}

ll read(){
	ll i;
	scanf("%lld",&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(ll x,int suc=1){
	printf("%lld",x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
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
	static char buf[3341000];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341000];
	static int bufUsed=0;
	char* ret=buf+bufUsed;
	scanf("%s",ret);
	bufUsed+=strlen(ret)+1;
	return ret;
}

template<class T,class U>
void chmax(T& a,U b){
	if(a<b)
		a=b;
}

template<class T,class U>
void chmin(T& a,U b){
	if(b<a)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

//#define CAPITAL
void Yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void No(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
	#endif
	if(ex)exit(0);
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

constexpr ll TEN(int n){
	return n==0?1:TEN(n-1)*10;
}

template<class T>
vector<T> uni(const vector<T>&vv){
	auto v(vv);
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	return v;
}
template<class T>
void mkuni(vector<T>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.end());
}

//ayasii
int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
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

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

#define SMOD

#ifdef SMOD
template<uint mod>
#else
uint mod;
#endif
struct ModInt{
	#ifdef SMOD
	static constexpr uint base=mod;
	#else
	static constexpr uint& base=mod;
	#endif
	uint v;
	ModInt():v(0){}
	ModInt(ll vv){
		s(vv%mod+mod);
	}
	ModInt& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	explicit operator bool()const{
		return v;
	}
	explicit operator int()const{
		return v;
	}
	bool operator==(const ModInt&rhs)const{
		return v==rhs.v;
	}
	bool operator!=(const ModInt&rhs)const{
		return v!=rhs.v;
	}
	ModInt operator-()const{
		return ModInt()-*this;
	}
	ModInt& operator+=(const ModInt&rhs){
		return s(v+rhs.v);
	}
	ModInt&operator-=(const ModInt&rhs){
		return s(v+mod-rhs.v);
	}
	ModInt&operator*=(const ModInt&rhs){
		v=ull(v)*rhs.v%mod;
		return *this;
	}
	ModInt&operator/=(const ModInt&rhs){
		return *this*=rhs.inv();
	}
	ModInt operator+(const ModInt&rhs)const{
		return ModInt(*this)+=rhs;
	}
	ModInt operator-(const ModInt&rhs)const{
		return ModInt(*this)-=rhs;
	}
	ModInt operator*(const ModInt&rhs)const{
		return ModInt(*this)*=rhs;
	}
	ModInt operator/(const ModInt&rhs)const{
		return ModInt(*this)/=rhs;
	}
	friend ModInt operator+(int x,const ModInt&y){
		return ModInt(x)+y;
	}
	friend ModInt operator-(int x,const ModInt&y){
		return ModInt(x)-y;
	}
	friend ModInt operator*(int x,const ModInt&y){
		return ModInt(x)*y;
	}
	friend ModInt operator/(int x,const ModInt&y){
		return ModInt(x)/y;
	}
	ModInt pow(int n)const{
		ModInt res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	ModInt inv()const{
		return pow(mod-2);
	}
};

#ifdef SMOD
template<uint mod>
ostream& operator<<(ostream&os,const ModInt<mod>&m){
	return os<<m.v;
}
template<uint mod>
void print(const ModInt<mod>&m,int suc=1){
	print(m.v,suc);
}
#else
ostream& operator<<(ostream&os,const ModInt&m){
	return os<<m.v;
}
void print(const ModInt&m,int suc=1){
	print(m.v,suc);
}
#endif

#ifdef SMOD
//using mint=ModInt<1000000007>;
using mint=ModInt<998244353>;
#else
using mint=ModInt;
#endif

const int Vmax=2000010;
mint fact[Vmax],factInv[Vmax],invs[Vmax];
void InitFact(){
	fact[0]=1;
	FOR(i,1,Vmax){
		fact[i]=fact[i-1]*i;
	}
	factInv[Vmax-1]=fact[Vmax-1].inv();
	for(int i=Vmax-2;i>=0;i--){
		factInv[i]=factInv[i+1]*(i+1);
	}
	for(int i=Vmax-1;i>=1;i--){
		invs[i]=factInv[i]*fact[i-1];
	}
}
#ifdef SMOD
struct InitFactDummy{
	InitFactDummy(){
		InitFact();
	}
} initFactDummy;
#endif
mint Choose(int n,int k){
	return fact[n]*factInv[n-k]*factInv[k];
}
mint Binom(int a,int b){
	return fact[a+b]*factInv[a]*factInv[b];
}
mint Catalan(int n){
	return Binom(n,n)-(n-1>=0?Binom(n-1,n+1):0);
}

//998244353
const mint prim_root=3;

//in-place fft
//size of input must be a power of 2
void inplace_fmt(vector<mint>&f,const bool inv){
	const int n=f.size();
	const mint root=inv?prim_root.inv():prim_root;
	V<mint> g(n);
	for(int b=n/2;b>=1;b/=2){
		mint w=root.pow((mint::base-1)/(n/b));
		mint p=1;
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
	if(inv){
		mint invn=mint(1)/n;
		rep(i,n)
			f[i]*=invn;
	}
}

vector<mint> convolution(V<mint> x,V<mint> y){
	int n=x.size()+y.size()-1;
	int s=1;
	while(s<n)s*=2;
	x.resize(s);inplace_fmt(x,false);
	y.resize(s);inplace_fmt(y,false);
	rep(i,s)
		x[i]*=y[i];
	inplace_fmt(x,true);x.resize(n);
	return x;
}

V<mint> multiply(const V<mint>&x,const V<mint>&y){
	return convolution(x,y);
}

template<class D>
struct Poly:public V<D>{
	template<class...Args>
	Poly(Args...args):V<D>(args...){}
	Poly(initializer_list<D>init):V<D>(all(init)){}
	int size()const{
		return V<D>::size();
	}
	void ups(int s){
		if(size()<s)this->resize(s,0);
	}
	Poly low(int s)const{
		return Poly(this->bg,this->bg+min(s,size()));
	}
	Poly rev()const{
		auto r=*this;
		reverse(all(r));
		return r;
	}
	Poly& operator+=(const Poly&r){
		ups(r.size());
		rep(i,r.size())
			(*this)[i]+=r[i];
		return *this;
	}
	Poly& operator-=(const Poly&r){
		ups(r.size());
		rep(i,r.size())
			(*this)[i]-=r[i];
		return *this;
	}
	template<class T>
	Poly& operator*=(T t){
		for(auto&v:*this)
			v*=D(t);
		return *this;
	}
	Poly& operator*=(const Poly&r){
		return *this=multiply(*this,r);
	}
	Poly inv(int s)const{
		Poly r{1/(*this)[0]};
		for(int n=1;n<s;n*=2)
			r=r*2-(r*r*low(2*n)).low(2*n);
		return r.low(s);
	}
	template<class T>
	Poly& operator/=(T t){
		return *this*=(D(1)/D(t));
	}
	Poly& operator/=(const Poly&r){
		int m=r.size();
		assert(r[m-1]);
		int n=size();
		int s=n-m+1;
		if(s<=0) return *this={};
		return *this=(rev().low(s)*r.rev().inv(s)).low(s).rev();
	}
	Poly& operator%=(const Poly&r){
		return *this-=*this/r*r;
	}
	Poly operator+(const Poly&r)const{return Poly(*this)+=r;}
	Poly operator-(const Poly&r)const{return Poly(*this)-=r;}
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
			r[i+1]=(*this)[i]/(i+1);
		return r;
	}
	Poly exp(int s)const{
		return exp2(s).fs;
	}
	pair<Poly,Poly> exp2(int s)const{
		assert((*this)[0]==0);
		Poly f{1},g{1};
		for(int n=1;;n*=2){
			if(n>=s)break;
			g=g*2-(g*g*f).low(n);
			//if(n>=s)break;
			Poly q=low(n).dif();
			q=q+g*(f.dif()-f*q).low(2*n-1);
			f=f+(f*(low(2*n)-q.inte())).low(2*n);
		}
		return mp(f.low(s),g.low(s));
	}
	Poly sqrt(int s)const{
		assert((*this)[0]==1);
		Poly r{1};
		for(int n=1;n<s;n*=2)
			r=(r+(r.inv(n*2)*low(n*2)).low(n*2))/2;
		return r.low(s);
	}
};

signed main(){
	int n=read(),m=read();
	Poly<mint> c(m+1);
	rep(i,n){
		int x=read();
		if(x<=m)
			c[x]=1;
	}
	c*=-4;
	c[0]=1;
	c=c.sqrt(m+1);
	c[0]+=1;
	c=c.inv(m+1)*2;
	FOR(s,1,m+1)
		print(c[s]);
}