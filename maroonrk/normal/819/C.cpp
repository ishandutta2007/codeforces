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

pi readpi(int off=0){
	int a,b;cin>>a>>b;
	return pi(a+off,b+off);
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

int gcd(int a,int b){return b?gcd(b,a%b):a;}

template<class t>
t pow_mod(t x,t n,t m){
	t r=1;
	while(n){
		if(n&1)r=(r*x)%m;
		x=(x*x)%m;
		n>>=1;
	}
    return r;
}

bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    ll d = n - 1;
    while (d % 2 == 0) d /= 2;
    for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n <= a) break;
        ll t = d;
        ll y = pow_mod<__int128_t>(a, t, n);  // over
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = __int128_t(y) * y % n;  // flow
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}

ll pollard_single(ll n) {
    auto f = [&](ll x) { return (__int128_t(x) * x + 1) % n; };
    if (is_prime(n)) return n;
    if (n % 2 == 0) return 2;
    ll st = 0;
    while (true) {
        st++;
        ll x = st, y = f(x);
        while (true) {
            ll p = gcd((y - x + n), n);
            if (p == 0 || p == n) break;
            if (p != 1) return p;
            x = f(x);
            y = f(f(y));
        }
    }
}

vc<ll> pollard(ll n) {
    if (n == 1) return {};
    ll x = pollard_single(n);
    if (x == n) return {x};
    vc<ll> le = pollard(x);
    vc<ll> ri = pollard(n / x);
    le.insert(le.end(), ri.begin(), ri.end());
    return le;
}

ll primitive_root(ll p) {
    auto v = pollard(p - 1);
    //while (true) {
    //    ll g = rand_int(1, p - 1);  //[1, p-1]
    rng(g,4,p){
        bool ok = true;
        for (auto d : v) {
            ll f = (p - 1) / d;
            if (pow_mod<__int128_t>(g, f, p) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}

vc<pi> to_freq(vi a){
	sort(all(a));
	vc<pi> res;
	for(auto v:a){
		if(res.empty()||res.back().a!=v)res.eb(v,0);
		res.back().b++;
	}
	return res;
}


vi enum_divs(int n){
	auto f=to_freq(pollard(n));
	dmp(f);
	
	vi res;
	auto rec=[&](auto self,int i,int d)->void{
		if(i==si(f))res.pb(d);
		else{
			rep(_,f[i].b+1){
				self(self,i+1,d);
				d*=f[i].a;
			}
		}
	};
	rec(rec,0,1);
	
	return res;
}

bool dbg=false;

int waf(){
	int a,b,c;cin>>a>>b>>c;
	return a*b*c;
}

//n m 
//n 
int count_divs_lim(int n,int m,vc<pi> f){
	int n2=sqrtl(n);
	if(m>n2){
		int ans=1;
		for(auto kv:f)ans*=kv.b+1;
		return ans-count_divs_lim(n,(n-1)/m,f);
	}
	if(m==0)return 0;
	
	int res=0;
	
	auto rec=[&](auto self,int i,int d)->void{
		if(i==si(f))res++;
		else{
			rep(_,f[i].b+1){
				self(self,i+1,d);
				d*=f[i].a;
				if(d>m)break;
			}
		}
	};
	rec(rec,0,1);
	
	return res;
}

void slv(){
	int n,m,s;
	if(!dbg){
		n=waf(),m=waf(),s=waf()*2;
	}else{
		n=3LL*5*7*11*13*17*19*23*29*31*37*41*43*47;
		m=ten(18);
		s=1;
	}
	
	auto g=to_freq(pollard(s));
	
	int ans=0;
	{
		auto f=to_freq(pollard(n));
		int k=si(f);
		vi vals(k,1);
		{
			map<int,int> cnt;
			for(auto kv:g)cnt[kv.a]=kv.b;
			rep(i,k){
				rep(_,cnt[f[i].a]+1)
					vals[i]*=min(inf/vals[i],f[i].a);
			}
			vi tmp;
			for(auto v:vals)if(n%v==0)tmp.pb(v);
			vals=tmp;
			k=si(vals);
		}
		auto rec=[&](auto self,int i,int v,int w)->void{
			if(v>m)return;
			if(i==k){
				ans+=m/v*w;
			}else{
				self(self,i+1,v,w);
				self(self,i+1,v*min(inf/v,vals[i]),-w);
			}
		};
		rec(rec,0,1,1);
	}
	ans+=count_divs_lim(s,n,g);
	
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
	rep(_,t)slv();
}