#ifndef LOCAL
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

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

template<class T>
void print_offset(const vector<T>&v,ll off,int suc=1){
	rep(i,v.size())
		print(v[i]+off,i==int(v.size())-1?suc:2);
}

template<class T,size_t N>
void print(const array<T,N>&v,int suc=1){
	rep(i,N)
		print(v[i],i==int(N)-1?suc:2);
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

//mint107  verify 
//#define DYNAMIC_MOD

struct modinfo{uint mod,root;
#ifdef DYNAMIC_MOD
constexpr modinfo(uint m,uint r):mod(m),root(r),im(0){set_mod(m);}
ull im;
constexpr void set_mod(uint m){
	mod=m;
	im=ull(-1)/m+1;
}
uint product(uint a,uint b)const{
	ull z=ull(a)*b;
	uint x=((unsigned __int128)z*im)>>64;
	uint v=uint(z)-x*mod;
	return v<mod?v:v+mod;
}
#endif
};
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
		#ifndef DYNAMIC_MOD
		v=ull(v)*rhs.v%mod;
		#else
		v=ref.product(v,rhs.v);
		#endif
		return *this;
	}
	modular&operator/=(const modular&rhs){return *this*=rhs.inv();}
	modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}
	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
	modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}
	modular pow(ll n)const{
		if(n<0)return inv().pow(-n);
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

#ifndef DYNAMIC_MOD
//extern constexpr modinfo base{998244353,3};
extern constexpr modinfo base{1000000007,0};
//modinfo base{1,0};
#ifdef USE_GOOD_MOD
static_assert(base.mod==998244353);
#endif
#else
modinfo base(1,0);
extern constexpr modinfo base107(1000000007,0);
using mint107=modular<base107>;
#endif
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

/*
const int vmax=110;
mint binbuf[vmax][vmax];
mint choose(int n,int k){
	return binbuf[n-k][k];
}
mint binom(int a,int b){
	return binbuf[a][b];
}
void initfact(){
	binbuf[0][0]=1;
	rep(i,vmax)rep(j,vmax){
		if(i)binbuf[i][j]+=binbuf[i-1][j];
		if(j)binbuf[i][j]+=binbuf[i][j-1];
	}
}
*/



void slv(){
	int n;cin>>n;
	/*{
		vc<string> ss(n);
		rep(i,n)ss[i]=to_string(i+1);
		sort(all(ss));
		int cnt=0;
		rep(i,n)if(i+1<stol(ss[i]))cnt++;
		dmp(cnt);
	}*/
	string s=to_string(n);
	int nlen=si(s);
	int hlen=nlen/2;
	vvc<int> ls[2];
	ls[0].resize(hlen);
	ls[1].resize(hlen+1);
	vvc<int> ls2[2];
	ls2[0].resize(hlen);
	ls2[1].resize(hlen+1);
	{
		int x=0,z=0;
		auto dfs=[&](auto self,int d,int y)->void{
			if(d<hlen){
				ls[0][d].pb(z);
				ls2[0][d].pb(z-y);
				z++;
			}
			ls[1][d].pb(x);
			ls2[1][d].pb(x-y);
			x++;
			if(d<hlen){
				rep(v,10){
					self(self,d+1,y*10+v);
				}
			}
		};
		dfs(dfs,0,0);
	}
	const int P=998244353;
	{
		int ans=0;
		int cur=0;
		auto dfs=[&](auto self,int d,int pre,int tp)->void{
			if(hlen==nlen-d&&tp){
				dmp2(d,pre,ans,cur,tp);
				int tot=0;
				int k=tp<0?1:0;
				rep(l,nlen-d+k){
					//cur+x mod P < pre+y mod P
					int a=lwb(ls[k][l],P-cur);
					int b=min(P-pre,si(ls[k][l]));
					auto sub=[&](int lf,int rt,int tar){
						auto itr=lower_bound(ls2[k][l].bg+lf,ls2[k][l].bg+rt,tar);
						return itr-ls2[k][l].bg-lf;
					};
					{
						//cur+x < pre+y
						int lf=0,rt=min(a,b);
						//x-y < pre-cur
						ans+=sub(lf,rt,pre-cur);
					}
					if(a<b){
						//cur+x-P < pre+y
						int lf=a,rt=b;
						//x-y < pre-cur+P
						ans+=sub(lf,rt,pre-cur+P);
					}
					if(b<a){
						//cur+x < pre+y-P
						int lf=b,rt=a;
						//x-y < pre-cur-P
						ans+=sub(lf,rt,pre-cur-P);
					}
					{
						//cur+x < pre+y
						int lf=max(a,b),rt=si(ls[k][l]);
						//x-y < pre-cur
						ans+=sub(lf,rt,pre-cur);
					}
					pre=pre*10%P;
					tot+=si(ls[k][l]);
				}
				cur=(cur+tot)%P;
				dmp(ans);
				return;
			}
			{
				dmp2(d,pre,ans);
				if(cur<pre)ans++;
				cur=(cur+1)%P;
				if(d<nlen){
					int mx=9;
					if(d==nlen-1){
						if(tp==0)mx=s[d]-'0';
						else if(tp==1)mx=-1;
					}
					rng(v,d==0?1:0,mx+1){
						int nx=tp;
						if(tp==0){
							if(v<s[d]-'0')nx=-1;
							else if(v>s[d]-'0')nx=1;
						}
						self(self,d+1,(pre*10+v)%P,nx);
					}
				}
			}
		};
		dfs(dfs,0,0,0);
		dmp(ans);
		print(mint(ans)*998244353);
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}