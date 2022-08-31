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
		int g=extgcd<ll>(v,mod,x,y);
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

template<class num>
struct Vector{
	vector<num> v;
	Vector(int s=0){
		v.resize(s,num(0));
	}
	int size()const{
		return v.size();
	}
	num& operator[](int i){
		return v[i];
	}
	num const& operator[](int i)const{
		return v[i];
	}
	Vector& operator+=(const Vector&rhs){
		assert(size()==rhs.size());
		rep(i,size())
			v[i]+=rhs[i];
		return *this;
	}
	Vector& operator-=(const Vector&rhs){
		assert(size()==rhs.size());
		rep(i,size())
			v[i]-=rhs[i];
		return *this;
	}
	Vector& operator*=(const num&x){
		rep(i,size())
			v[i]*=x;
		return *this;
	}
	Vector& operator/=(const num&x){
		num y=num(1)/x;
		rep(i,size())
			v[i]*=y;
		return *this;
	}
	Vector operator+(const Vector&rhs)const{
		return Vector(*this)+=rhs;
	}
	Vector operator-(const Vector&rhs)const{
		return Vector(*this)-=rhs;
	}
	Vector operator*(const num&x)const{
		return Vector(*this)*=x;
	}
	Vector operator/(const num&x)const{
		return Vector(*this)/=x;
	}
	bool operator==(const Vector&rhs)const{
		return v==rhs.v;
	}
};

template<class num>
num dot(const Vector<num>&a,const Vector<num>&b){
	assert(a.size()==b.size());
	const int s=a.size();
	num ans(0);
	rep(i,s)
		ans+=a[i]*b[i];
	return ans;
}

template<class num>
ostream&operator<<(ostream&os,const Vector<num>&v){
	return os<<v.v;
}

template<class num>
struct Matrix{
	using V=Vector<num>;
	vector<V> m;
	Matrix(int s=0,num z=num(0)){
		m.resize(s,V(s));
		rep(i,size())
			m[i][i]=z;
	}
	int size()const{
		return m.size();
	}
	Matrix operator*(const Matrix&rhs)const{
		assert(size()==rhs.size());
		Matrix res(size());
		rep(i,size())rep(j,size())rep(k,size())
			res[i][j]+=m[i][k]*rhs[k][j];
		return res;
	}
	Matrix& operator*=(const Matrix&rhs){
		return *this=(*this)*rhs;
	}
	Matrix& operator+=(const Matrix&rhs){
		rep(i,si(m))rep(j,si(m[i]))
			m[i][j]+=rhs[i][j];
		return *this;
	}
	V operator*(const V&rhs)const{
		assert(size()==rhs.size());
		V res(size());
		rep(i,size())
			res[i]=dot(m[i],rhs);
		return res;
	}
	V& operator[](int i){
		return m[i];
	}
	V const& operator[](int i) const{
		return m[i];
	}
	Matrix& operator/=(const num&r){
		rep(i,m.size())m[i]/=r;
		return *this;
	}
	Matrix operator/(const num&r)const{
		return Matrix(*this)/=r;
	}
	bool operator==(const Matrix&rhs)const{
		return m==rhs.m;
	}
};

template<class num>
ostream&operator<<(ostream&os,const Matrix<num>&x){
	const int s=x.size();
	os<<"----------"<<endl;
	rep(i,s){
		rep(j,s){
			os<<x[i][j];
			if(j==s-1){
				os<<endl;
			}else{
				os<<" ";
			}
		}
	}
	return os<<"----------";
}

template<class num>
num det(Matrix<num> a){
	const int s=a.size();
	num ans(1);
	rep(i,s){
		rng(j,i+1,s)if(a[j][i]){
			ans=-ans;
			swap(a[j],a[i]);
			break;
		}
		if(!a[i][i])return 0;
		ans*=a[i][i];
		rng(j,i+1,s){
			mint w=-a[j][i]/a[i][i];
			rng(k,i,s)
				a[j][k]+=a[i][k]*w;
		}
	}
	return ans;
}

using V=Vector<mint>;
using M=Matrix<mint>;

M matpow(M a,int n){
	M res(si(a),1);
	while(n){
		if(n&1)res*=a;
		a*=a;
		n>>=1;
	}
	return res;
}

V matpow_V(M a,int n,V res){
	while(n){
		if(n&1)res=a*res;
		a*=a;
		n>>=1;
	}
	return res;
}

vc<mint> mod_f(vc<mint> x,const vc<mint>&f){
	int k=si(f);
	gnr(i,k-1,si(x)){
		mint w=x[i]/f[k-1];
		rep(p,k-1)x[i-(k-1)+p]-=w*f[p];
	}
	x.resize(k-1);
	return x;
}

vc<mint> mult_mod_f(const vc<mint>&x,const vc<mint>&y,const vc<mint>&f){
	int n=si(x),m=si(y);
	vc<mint> res(n+m-1);
	rep(i,n)rep(j,m)res[i+j]+=x[i]*y[j];
	return mod_f(res,f);
}

vc<mint> pow_mod_f(vc<mint> x,int n,const vc<mint>&f){
	vc<mint> res{1};
	while(n){
		if(n&1)res=mult_mod_f(res,x,f);
		x=mult_mod_f(x,x,f);
		n>>=1;
	}
	return res;
}

//VERIFY:yosupo

// for all valid i, sum_j a_{i+j}*res_j = 0
// res[last]=1
// x^n % res  n 
// 
vc<mint> berlekamp_massey(const vc<mint>& a){
	vc<mint> b{1},c{0};
	mint d=1;
	rep(i,a.size()){
		int n=b.size();
		mint w=0;
		rep(j,n)
			w+=a[i-(n-1)+j]*b[j];
		c.pb(0);
		if(!w.v)continue;
		int m=c.size();
		mint e=-w/d;
		if(m>n){
			auto tmp=b;
			b.insert(b.bg,m-n,0);
			rep(j,m)
				b[j]+=e*c[j];
			c=tmp;
			d=w;
		}else{
			rep(j,m)
				b[n-m+j]+=e*c[j];
		}
	}
	return b;
}

mint get_kth(const vc<mint>&a,int k){
	auto p=berlekamp_massey(a);
	cerr<<si(p)<<endl;
	if(si(p)==1)return 0;
	auto q=pow_mod_f({0,1},k,p);
	mint res=0;
	rep(i,si(q))res+=a[i]*q[i];
	return res;
}

const int L=60;

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int f;cin>>f;
	bool dbg=false;
	if(f<0){
		dbg=true;
		f=-f;
	}
	int b,n;
	vi p,c;
	if(!dbg){
		cin>>b>>n;
		p=readvi(f);
		c=readvi(b);
	}else{
		b=100;
		n=ten(18);
		p.resize(f);
		rep(i,f)p[i]=rand_int(1,ten(9));
		c.resize(b);
		rep(i,b)c[i]=rand_int(1,250);
	}
	sort(all(c),greater<int>());
	const int S=250;
	vc<mint> d(S+1);
	d[S]=1;
	for(auto v:c)d[S-v]-=1;
	vc<vc<mint>> buf(30,vc<mint>(S));
	buf[0][1]=1;
	rng(lv,1,30){
		buf[lv]=mult_mod_f(buf[lv-1],buf[lv-1],d);
	}
	M z(S);
	for(auto v:p){
		vc<mint> cur(S);
		bool fst=true;
		per(i,S){
			int ep=v-i+S-1;
			if(fst){
				cur[0]=1;
				fst=false;
				rep(lv,30)if(ep&1<<lv)
					cur=mult_mod_f(cur,buf[lv],d);
			}else{
				cur.insert(cur.bg,0);
				cur=mod_f(cur,d);
			}
			rep(j,S){
				z[j][i]+=cur[S-1-j];
			}
		}
	}
	V tmp(S);tmp[0]=1;
	vc<mint> ans(2*S);
	rep(i,2*S){
		ans[i]=tmp[0];
		tmp=z*tmp;
	}
	cout<<get_kth(ans,n)<<endl;
}