#include <bits/stdc++.h>
using namespace std;

using ll=long long;
//#define int ll

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
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))

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

#define CAPITAL
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

/*
const int vmax=100;
bool pri[vmax];
void initprime(){
	rng(i,2,vmax)
		pri[i]=1;
	rng(i,2,vmax)if(pri[i])
		for(int j=i*2;j<vmax;j+=i)
			pri[j]=0;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	initprime();
	
	int cur=1;
	vi ps;
	rep(i,vmax)if(pri[i]){
		if(cur*i<=ten(9)){
			cur*=i;
			ps.pb(i);
		}
	}
	
	cout<<ps.size()<<endl;
	cout<<ps<<endl;
	
}*/


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
        ll y = pow_mod<ll>(a, t, n);  // over
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = ll(y) * y % n;  // flow
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}

ll pollard_single(ll n) {
    auto f = [&](ll x) { return (ll(x) * x + 1) % n; };
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

int num(int n){
	auto fs=pollard(n);
	mkuni(fs);
	return fs.size();
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	vi a;
	if(n==-1){
		n=100000;
		a=vi(n,2);
	}else
		a=readvi(n);
	vi idx(n);
	iota(all(idx),0);
	
	mt19937 gen(2434);
	
	//const int B=1000000/n;
	const int B=30;
	rep(_,B){
		shuffle(all(idx),gen);
		vi ans(n,1);
		int cur[2]{},fs[2]{inf,inf};
		for(auto i:idx){
			int v=a[i];
			int k=fs[0]<fs[1];
			rep($,2){
				int nx=gcd(cur[k],v);
				if(cur[k]==0||nx<cur[k]){
					int w=num(nx);
					if(w<fs[k]){
						cur[k]=nx;
						fs[k]=w;
						ans[i]=k+1;
						break;
					}
				}
				k^=1;
			}
			if(fs[0]==0&&fs[1]==0){
				yes(0);
				print(ans);
				return 0;
			}
		}
	}
	no();
}