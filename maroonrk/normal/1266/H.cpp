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

using int128=__int128_t;
using uint128=unsigned __int128_t;

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

extern constexpr modinfo base{9000000000000000041LL,0};
using mint=modular<base>;

//VERIFY: yosupo
mint det(vvc<mint> a){
	const int n=a.size();
	mint ans(1);
	rep(i,n){
		rng(j,i+1,n)if(a[j][i].v){
			ans=-ans;
			swap(a[j],a[i]);
			break;
		}
		if(!a[i][i].v)return 0;
		ans*=a[i][i];
		rng(j,i+1,n){
			mint w=-a[j][i]/a[i][i];
			rng(k,i,n)
				a[j][k]+=a[i][k]*w;
		}
	}
	return ans;
}

//csweep
//arank
//
vi sweep(vvc<mint>&a,int c=-1){
	if(a.empty())return {};
	if(c==-1)c=a[0].size();
	int h=a.size(),w=a[0].size(),r=0;
	vi res;
	rep(i,c){
		if(r==h)break;
		rng(j,r,h)if(a[j][i].v){
			swap(a[r],a[j]);
			break;
		}
		if(a[r][i].v==0)continue;
		rep(j,h)if(j!=r){
			mint z=-a[j][i]/a[r][i];
			rng(k,i,w)
				a[j][k]+=a[r][k]*z;
		}
		res.pb(i);
		r++;
	}
	return res;
}

//
//kernel
//aaw
// {} 
vc<mint> lineareq(vvc<mint> a,int w,vc<mint> b){
	int h=a.size();
	rep(i,h)a[i].pb(b[i]);
	vi idx=sweep(a,w);
	rng(i,idx.size(),h)
		if(a[i][w].v)return {};
	vc<mint> res(w);
	rep(i,idx.size())
		res[idx[i]]=a[i][w]/a[i][idx[i]];
	return res;
}

//yosupo system of linear equations
//ker(a)
//aaw
vvc<mint> kernel(const vvc<mint>&a,int w){
	int h=a.size();
	vvc<mint> b(w,vc<mint>(h+w));
	rep(i,h)rep(j,w)b[j][i]=a[i][j];
	rep(i,w)b[i][h+i]=1;
	int r=sweep(b,h).size();
	vvc<mint> res;
	rng(i,r,w)res.eb(b[i].bg+h,b[i].ed);
	return res;
}

vc<mint> multmv(const vvc<mint>&a,const vc<mint>&x){
	int n=si(a),m=si(x);
	vc<mint> y(n);
	rep(i,n)rep(j,m)y[i]+=a[i][j]*x[j];
	return y;
}

vvc<mint> inverse(vvc<mint> a){
	int n=si(a);
	rep(i,n){
		assert(si(a[i])==n);
		a[i].resize(2*n);
		a[i][n+i]=1;
	}
	auto tmp=sweep(a,n);
	assert(si(tmp)==n);
	vvc<mint> b(n,vc<mint>(n));
	rep(i,n){
		mint w=a[i][i].inv();
		rep(j,n)b[i][j]=a[i][n+j]*w;
	}
	return b;
}

//Petrozavodsk 2020w Day9 K
void hessenberg_form(vvc<mint>&a){
	int n=si(a);
	rng(i,1,n){
		rng(j,i+1,n)if(a[j][i-1]){
			rep(k,n)swap(a[k][i],a[k][j]);
			rep(k,n)swap(a[i][k],a[j][k]);
			break;
		}
		if(a[i][i-1]==0)continue;
		rng(j,i+1,n){
			mint w=a[j][i-1]/a[i][i-1];
			rep(k,n)a[k][i]+=a[k][j]*w;
			rep(k,n)a[j][k]-=a[i][k]*w;
		}
	}
}

//Petrozavodsk 2020w Day9 K
vc<mint> characteristic_polynomial(vvc<mint> a){
	int n=si(a);
	hessenberg_form(a);
	vvc<mint> f(n+1);
	f[0]={1};
	rep(i,n){
		f[i+1].resize(i+2);
		rep(j,i+1)f[i+1][j+1]=-f[i][j];
		mint w=1;
		per(j,i+1){
			mint z=w*a[j][i];
			rep(k,j+1)f[i+1][k]+=f[j][k]*z;
			if(j)w*=-a[j][j-1];
		}
	}
	return f[n];
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;n--;
	vi a(n),b(n);
	rep(i,n){
		b[i]=read()-1;
		a[i]=read()-1;
	}
	vvc<mint> m(n,vc<mint>(n));
	rep(i,n){
		m[i][i]=2;
		if(a[i]<n)m[a[i]][i]-=1;
		if(b[i]<n)m[b[i]][i]-=1;
	}
	vvc<mint> z=inverse(m);
	int q;cin>>q;
	rep(_,q){
		int v=read()-1;
		string s;cin>>s;
		bool ok=true;
		vc<mint> y(n);
		y[0]=1;
		rep(i,n){
			if(s[i]=='R')y[i]+=1;
			if(i==v)y[i]-=1;
			if(b[i]<n&&s[i]=='R')y[b[i]]-=1;
		}
		dmp(y);
		auto xraw=multmv(z,y);
		vc<ull> x(n);
		rep(i,n)x[i]=xraw[i].v;
		rep(i,n)if(x[i]>=(1ULL<<n))ok=false;
		rep(i,n)if(x[i]==0&&s[i]=='R')ok=false;
		dmp(ok);
		rep(r,n)if(x[r]){
			vi vis(n);
			int cur=r;
			while(cur!=v&&cur<n){
				if(vis[cur])break;
				vis[cur]=1;
				if(s[cur]=='R')cur=a[cur];
				else cur=b[cur];
			}
			if(cur!=v){
				ok=false;
				break;
			}
		}
		if(ok){
			dmp(x);
			ull sum=0;
			rep(i,n){
				sum+=x[i];
				sum+=x[i];
				if(s[i]=='R')sum--;
			}
			print(sum);
		}
		if(!ok)print(-1);
	}
}