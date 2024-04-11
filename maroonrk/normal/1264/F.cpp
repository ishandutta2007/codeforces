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

//

using int128=__int128_t;
using uint128=unsigned __int128_t;

istream& operator>>(istream&is,int128&res){
	res=0;
	string s;is>>s;
	int head=0;
	int128 w=1;
	if(s[0]=='-'){
		w=-1;
		head++;
	}
	while(head<int(s.size())){
		res=res*10+s[head++]-'0';
	}
	res*=w;
	return is;
}
ostream& operator<<(ostream&os,int128 i){
	if(i==0)
		return os<<0;
	static char buf[100];
	if(i<0){
		os<<"-";
		i=-i;
	}
	int p=0;
	while(i){
		buf[p++]='0'+i%10;
		i/=10;
	}
	reverse(buf,buf+p);
	buf[p]=0;
	return os<<buf;
}
int128 abs128(int128 a){
	return a<0?-a:a;
}
int botbit(int128 a){
	const int128 m=(int128(1)<<64)-1;
	if(a&m)return __builtin_ctzll(ll(a));
	else return __builtin_ctzll(ll(a>>64));
}
int128 gcd(int128 a,int128 b){
	if(a<0)a=-a;
	if(b<0)b=-b;
	if(a==0)return b;
	if(b==0)return a;
	int128 s=botbit(a|b);
	a>>=botbit(a);
	do{
		b>>=botbit(b);
		if(a>b)swap(a,b);
		b-=a;
	}while(b);
	return a<<s;
}
const int128 inf128=int128(1)<<122;

struct modinfo{ull mod,root;};
template<modinfo const&ref>
struct modular{
	static constexpr ull const &mod=ref.mod;
	static modular root(){return modular(ref.root);}
	ull v;
	modular(int128 vv=0){s(vv%mod+mod);}
	modular& s(ull vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	modular operator-()const{return modular()-*this;}
	modular& operator+=(const modular&rhs){return s(v+rhs.v);}
	modular&operator-=(const modular&rhs){return s(v+mod-rhs.v);}
	modular&operator*=(const modular&rhs){
		v=uint128(v)*rhs.v%mod;
		return *this;
	}
	modular&operator/=(const modular&rhs){return *this*=rhs.inv();}
	modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}
	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
	modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}
	modular pow(int128 n)const{
		modular res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	modular inv()const{return pow(mod-2);}
	friend modular operator+(int128 x,const modular&y){
		return modular(x)+y;
	}
	friend modular operator-(int128 x,const modular&y){
		return modular(x)-y;
	}
	friend modular operator*(int128 x,const modular&y){
		return modular(x)*y;
	}
	friend modular operator/(int128 x,const modular&y){
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

extern constexpr modinfo base{ten(18),0};
using mint=modular<base>;

template<class num,int S>
struct Vector{
	array<num,S> v;
	Vector(){
		rep(i,size())v[i]=0;
	}
	int size()const{
		return S;
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

template<class num,int S>
num dot(const Vector<num,S>&a,const Vector<num,S>&b){
	assert(a.size()==b.size());
	const int s=a.size();
	num ans(0);
	rep(i,s)
		ans+=a[i]*b[i];
	return ans;
}

template<class num,int S>
ostream&operator<<(ostream&os,const Vector<num,S>&v){
	return os<<v.v;
}

template<class num,int S>
struct Matrix{
	using V=Vector<num,S>;
	array<V,S> m;
	Matrix(num z=num(0)){
		rep(i,size())rep(j,size()){
			if(i==j)m[i][j]=z;
			else m[i][j]=0;
		}
	}
	int size()const{
		return S;
	}
	Matrix operator*(const Matrix&rhs)const{
		assert(size()==rhs.size());
		Matrix res;
		rep(i,size())rep(j,size())rep(k,size())
			res[i][j]+=m[i][k]*rhs[k][j];
		return res;
	}
	Matrix& operator*=(const Matrix&rhs){
		return *this=(*this)*rhs;
	}
	V operator*(const V&rhs)const{
		assert(size()==rhs.size());
		V res;
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

template<class num,int S>
ostream&operator<<(ostream&os,const Matrix<num,S>&x){
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

template<class num,int S>
num det(Matrix<num,S> a){
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

template<class num,int S>
Matrix<num,S> matpow(Matrix<num,S> a,int n){
	Matrix<num,S> res(1);
	while(n){
		if(n&1)res*=a;
		a*=a;
		n>>=1;
	}
	return res;
}

template<class num,int S>
Vector<num,S> matpow_V(Matrix<num,S> a,int n,Vector<num,S> res){
	while(n){
		if(n&1)res=a*res;
		a*=a;
		n>>=1;
	}
	return res;
}

//0,1,2,3,4,5
//1,1,2,3,5,8
//(n-th,(n+1)-th)
pair<mint,mint> getfib(int n){
	using V=Vector<mint,2>;
	using M=Matrix<mint,2>;
	M m;
	m[0][1]=m[1][0]=m[1][1]=1;
	V v;
	v[0]=v[1]=1;
	V res=matpow_V(m,n,v);
	return mp(res[0],res[1]);
}

//using V=Vector<mint,2>;
//using M=Matrix<mint,2>;

template<class t=ll>
t extgcd(t a,t b,t&x,t&y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}else{
		t g=extgcd(b,a%b,y,x);
		y-=a/b*x;
		return g;
	}
}

//x*y=g mod m
//returns (g,y)
template<class t=ll>
pair<t,t> modinv(t x,t m){
	t a,b;
	t g=extgcd(x,m,a,b);
	if(a<0)a+=m/g;
	return {g,a};
}


signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n=12*ten(9);
	mint z=getfib(n).a;
	int v=z.v;
	cerr<<v<<endl;
	int t=v/ten(9);
	cerr<<t%8<<endl;
	t/=8;
	cerr<<t<<endl;
	
	t%=ten(6);
	auto [g,y]=modinv(t,ten(6));
	assert(g==1);
	
	int tmp,a,d;cin>>tmp>>a>>d;
	int b=a*y%ten(6);
	int e=d*y%ten(6);
	cout<<b*125*n+1<<" "<<e*125*n<<endl;
}