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

const int T=11;
const int nmax=3010;

mint dp[2][nmax];
mint wt[nmax][nmax];
mint work[1<<T];
bool pc[1<<T];

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,c;cin>>n>>c;
	vi a=readvi(n,-1);
	
	vc<mint> p2(n+1);
	p2[0]=1;
	rep(i,n)p2[i+1]=p2[i]*2;
	vc<mint> p2m1=p2;
	for(auto&v:p2m1)v-=1;
	vc<mint> p2m1inv=p2m1;
	for(auto&v:p2m1inv)v=v.inv();
	
	int cur=0;
	vc<mint> goout(n);
	{
		vi cnt(c);
		mint w=1;
		int zeros=c;
		auto init=[&](){
			fill(all(cnt),0);
			w=1;
			zeros=c;
		};
		auto add=[&](int x){
			if(cnt[x]==0){
				zeros--;
			}else{
				w*=p2m1inv[cnt[x]];
			}
			w*=p2m1[++cnt[x]];
		};
		auto get=[&](int x){
			if(cnt[x]==0){
				if(zeros>1)return mint(0);
				else return w;
			}else{
				if(zeros)return mint(0);
				else return w*p2m1inv[cnt[x]];
			}
		};
		init();
		rep(i,n){
			dp[cur][i]=get(a[i]);
			add(a[i]);
		}
		rep(i,n){
			init();
			rng(j,i+1,n){
				wt[i][j]=get(a[j]);
				add(a[j]);
			}
			{
				mint z=1;
				rep(j,c)z*=p2[cnt[j]];
				goout[i]+=z;
			}
			{
				mint z=1;
				rep(j,c)z*=p2m1[cnt[j]];
				goout[i]-=z;
			}
		}
	}
	
	vc<mint> ans(n+1);
	ans[0]=p2m1[n];
	
	if(c<=T)
		rep(bit,1<<c)
			pc[bit]=popcount(bit)%2;
	rng(step,1,n+1){
		rep(i,n)ans[step]+=dp[cur][i]*goout[i];
		if((step+1)*c>n)break;
		int nx=cur^1;
		zero(dp[nx]);
		if(c<=T){
			zero(work);
			rep(i,n){
				rep(bit,1<<c)if(bit&1<<a[i]){
					if(pc[bit])
						dp[nx][i]+=work[bit];
					else
						dp[nx][i]-=work[bit];
				}else{
					work[bit]+=work[bit];
				}
				rep(bit,1<<c)
					work[bit]+=dp[cur][i];
			}
		}else{
			rep(i,n)rng(j,i+1,n)
				dp[nx][j]+=dp[cur][i]*wt[i][j];
		}
		cur=nx;
	}
	
	rng(i,1,n+1)ans[0]-=ans[i];
	print(ans);
}