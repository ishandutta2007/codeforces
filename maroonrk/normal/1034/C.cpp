#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=a;i--)
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

using uint=unsigned;
using ull=unsigned long long;

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

void print(ll x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<endl;
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
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
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

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
    static random_device rd;
    static mt19937 gen(rd());
    return uniform_int_distribution<ll>(l, r)(gen);
}

//ARC055D
int gcd(int a,int b){return b?gcd(b,a%b):a;}
/*int gcd(int a,int b){
	if(a==0)return b;
	if(b==0)return a;
	if(a<0)a=-a;
	if(b<0)b=-b;
	int s=botbit(a|b);
	a>>=botbit(a);
	do{
		b>>=botbit(b);
		if(a>b)swap(a,b);
		b-=a;
	}while(b);
	return a<<s;
	
}*/
int lcm(int a,int b){return a/gcd(a,b)*b;}

int extgcd(int a,int b,int&x,int&y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}else{
		int g=extgcd(b,a%b,y,x);
		y-=a/b*x;
		return g;
	}
}

/*
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
}*/

vi pollard(int x){
	vi res;
	for(int i=2;i*i<=x;i+=(i==2?1:2)){
		while(x%i==0){
			x/=i;
			res.pb(i);
		}
	}
	if(x>1)res.pb(x);
	sort(all(res));
	return res;
}

vc<ll> divs(vc<ll> f){
	vc<ll> a;
	vi b;
	ll last=-1;
	for(auto v:f){
		if(last!=v){
			a.pb(v);
			b.pb(0);
			last=v;
		}
		b.back()++;
	}
	vi res;
	function<void(int,ll)> dfs=[&](int i,ll cur){
		if(i==int(a.size())){
			res.pb(cur);
			return;
		}
		rep(j,b[i]+1){
			dfs(i+1,cur);
			cur*=a[i];
		}
	};
	dfs(0,1);
	return res;
}

using uint=unsigned;
using ull=unsigned long long;

//const uint mod=998244353;
const uint mod=1000000007;
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
	friend ostream& operator<<(ostream&os,const mint&m){
		return os<<m.v;
	}
	bool operator<(const mint&r)const{return v<r.v;}
	bool operator==(const mint&r)const{return v==r.v;}
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


const int nmax=1000010;

vi tr[nmax];
int a[nmax];

int dfs(int v,vi&dst){
	int s=a[v];
	for(auto c:tr[v])
		s+=dfs(c,dst);
	dst.pb(s);
	return s;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	rep(i,n)cin>>a[i];
	int sum=accumulate(a,a+n,int(0));
	vi f=pollard(sum);
	vi d=divs(f);
	sort(all(d));
	mkuni(f);
	
	rng(i,1,n){
		int p;cin>>p;
		p--;
		tr[p].pb(i);
	}
	
	auto idx=[&](int v){
		return lower_bound(all(d),v)-d.bg;
	};
	
	vi vs;
	dfs(0,vs);
	
	int m=d.size();
	vi cnt(m);
	
	dmp(d);
	for(auto v:vs){
		int i=idx(gcd(sum,v));
		cnt[i]++;
	}
	
	for(auto v:f){
		per(i,m)if(d[i]%v==0){
			cnt[idx(d[i]/v)]+=cnt[i];
		}
	}
	
	int k=f.size();
	vvc<mint> dp(m,vc<mint>(k));
	dp[0][0]=1;
	rep(i,m){
		rep(j,k-1)
			dp[i][j+1]+=dp[i][j];
		if(cnt[i]==sum/d[i]){
			mint w=dp[i][k-1];
			if(i==m-1)
				cout<<w<<endl;
			rep(j,k)
				dp[i][j]+=w;
		}
		rep(j,k){
			if(sum%(d[i]*f[j])==0)
				dp[idx(d[i]*f[j])][j]+=dp[i][j];
		}
	}
}