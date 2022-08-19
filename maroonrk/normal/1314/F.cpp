#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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

template<class t>
bool inc(t a,t b,t c){
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

//x*y=g mod m
//returns (g,y)
pi modinv(int x,int m){
	int a,b;
	int g=extgcd(x,m,a,b);
	if(a<0)a+=m/g;
	return pi(g,a);
}

//https://codeforces.com/blog/entry/62393
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template<class t,class u>
using hash_table=gp_hash_table<t,u,custom_hash>;

//count 
//find 

namespace Nimber64{
	ull multiply_powers_of_2(ull,ull);

	ull multiply(ull a,ull b) {
	   ull ans = 0;
	   rep(p1,64)if((a>>p1)&1)
		   rep(p2,64)if((b>>p2)&1)
			  ans=ans^multiply_powers_of_2(ull(1)<<p1,ull(1)<<p2);
	   return ans;
	}
	ull multiply_powers_of_2(ull a, ull b) {
		if (a == 1 or b == 1) return a * b;
		int n=__lg(__lg(max(a,b)));
		ull power = ull(1)<<(1<<n);
		if (a >= power and b >= power) {
			return multiply(power * 3 / 2, multiply_powers_of_2(a / power, b / power));
		} else if (a >= power) {
			return multiply_powers_of_2(a / power, b) * power;
		} else {
			return multiply_powers_of_2(a, b / power) * power;
		}
	}
	
	struct precalc{
		ull tmp[64][64];
		unsigned char x[256][256];
		ull y[8][8][256];
		template<int len>
		ull multfast(ull a,ull b){
			ull c=0;
			rep(i,len)if((a>>i)&1)rep(j,len)if((b>>j)&1)c^=tmp[i][j];
			return c;
		}
		precalc():tmp(),x(),y(){
			rep(i,64)rep(j,64)tmp[i][j]=multiply_powers_of_2(1ULL<<i,1ULL<<j);
			rep(i,256)rep(j,256)x[i][j]=multfast<8>(i,j);
			rep(i,8)rep(j,i+1)rep(k,256)y[i][j][k]=multfast<64>(tmp[i*8][j*8],k);
		}
		ull multfast2(ull a,ull b)const{
			ull res=0;
			rep(i,8){
				rep(j,i){
					res^=y[i][j][
					x[(a>>(i*8))&255][(b>>(j*8))&255]^
					x[(a>>(j*8))&255][(b>>(i*8))&255]];
				}
				res^=y[i][i][x[(a>>(i*8))&255][(b>>(i*8))&255]];
			}
			return res;
		}
	};
	const precalc buf;
	
	struct nim{
		ull v;
		nim(ull vv=0):v(vv){}
		nim& operator+=(const nim&rhs){v^=rhs.v;return *this;}
		nim& operator*=(const nim&rhs){v=buf.multfast2(v,rhs.v);return *this;}
		nim operator+(const nim&rhs)const{return nim(*this)+=rhs;}
		nim operator*(const nim&rhs)const{return nim(*this)*=rhs;}
		nim pow(ull n)const{
			nim res=1,x=*this;
			while(n){
				if(n&1)res*=x;
				x*=x;
				n>>=1;
			}
			return res;
		}
	};
	istream& operator>>(istream&is,nim&x){
		return is>>x.v;
	}
	ostream& operator<<(ostream&os,const nim&x){
		return os<<x.v;
	}
	
	pair<ull,ull> garnerull(vc<pi> z){
		ull ans=0,w=1;
		rep(i,si(z)){
			int x=z[i].a;
			ans=(ans+w*x);
			rng(j,i+1,si(z))
				z[j].a=(z[j].a+z[j].b-x%z[j].b)*modinv(z[i].b,z[j].b).b%z[j].b;
			w=(w*z[i].b);
		}
		return {ans,w};
	}
	
	//returns minimum x s.t. a^x=b
	//and its period
	//returns (0,0) if infeasible
	pair<ull,ull> discrete_log(const nim a,const nim b){
		static const vi fs{3,5,17,257,641,65537,6700417};
		static const ull s=-1;
		
		vc<pi> z;
		for(auto f:fs){
			nim x=a.pow(s/f);
			nim y=b.pow(s/f);
			if(x.v==1){
				if(y.v==1){
					continue;
				}else{
					return {0,0};
				}
			}
			
			const int L=ceil(sqrt(f-1));
			//map<ull,int> v;
			hash_table<ull,int> v;
			{
				nim cur=1;
				rep(i,L){
					auto itr=v.find(cur.v);
					if(itr==v.ed)v[cur.v]=i;
					cur*=x;
				}
			}
			int ans=-1;
			{
				nim cur=1;
				nim w=x.pow((f-1)*L);
				for(int i=0;i<f;i+=L){
					nim tar=y*cur;
					auto itr=v.find(tar.v);
					if(itr!=v.ed){
						ans=i+itr->b;
						break;
					}
					cur*=w;
				}
			}
			if(ans==-1)return {0,0};
			z.eb(ans,f);
		}
		
		return garnerull(z);
	}
}
using namespace Nimber64;

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int t;cin>>t;
	rep(_,t){
		nim a,b;cin>>a>>b;
		auto ans=discrete_log(a,b);
		if(ans.b==0)print(-1);
		else cout<<ans.a<<"\n";
	}
}