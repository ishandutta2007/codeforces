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

ll fdiv(ll a, ll b) { // floored division
	return a / b - ((a ^ b) < 0 && a % b); }

ll cdiv(ll a, ll b) { // ceiled division
	return a / b + ((a ^ b) > 0 && a % b); }

/*
//count
//0<=x<=a,0<=y<=b,x+y=s
int sum_equation(int a,int b,int s){
	assert(0<=s);
	if(a+b<s)return 0;
	if(a>b)swap(a,b);
	if(s<=a)return s+1;
	else if(s<=b)return a+1;
	else return a+b-s+1;
}
*/

const int vmax=5;
int bin[vmax][vmax];
void initbin(){
	bin[0][0]=1;
	rep(i,vmax)rep(j,vmax){
		if(i)bin[i][j]+=bin[i-1][j];
		if(j)bin[i][j]+=bin[i][j-1];
	}
}

const int nmax=105;
int dp[2][2][nmax];
int subset_sum_pow2(vi a,int s,int tarcnt){
	int L=topbit(s)+1;
	for(auto v:a)chmax(L,topbit(v)+1);
	vi cnt(L);
	for(auto v:a)cnt[topbit(v)]++;
	int cur=0,mx=0;
	zero(dp);
	dp[cur][0][0]=1;
	rep(i,L){
		int nx=cur^1,nxmx=-1;
		rep(j,2){
			int tar=((s>>i)&1)^j;
			rep(k,mx+1){
				for(int u=tar;u<=cnt[i];u+=2){
					dp[nx][(j+u)>>1][k+u]+=dp[cur][j][k]*bin[cnt[i]-u][u];
					chmax(nxmx,k+u);
				}
				dp[cur][j][k]=0;
			}
		}
		cur=nx;
		mx=nxmx;
	}
	int ans=dp[cur][0][tarcnt];
	/*{
		int n=si(a);
		int tmp=0;
		rep(bit,1<<n){
			int sum=0;
			rep(i,n)if(bit&1<<i)sum+=a[i];
			if(sum==s&&popcount(bit)==tarcnt)tmp++;
		}
		if(tmp!=ans){
			dmp2(a,s,tarcnt,tmp,ans);
			assert(false);
		}
	}*/
	return ans;
}

//a:2-1
int subset_sum_pow2_minus1(vi a,int s){
	int n=si(a);
	int ans=0;
	rep(u,n+1){
		vi b=a;for(auto&v:b)v++;
		ans+=subset_sum_pow2(b,s+u,u);
	}
	/*{
		int tmp=0;
		rep(bit,1<<n){
			int sum=0;
			rep(i,n)if(bit&1<<i)sum+=a[i];
			if(sum==s)tmp++;
		}
		if(tmp!=ans){
			dmp2(a,s,tmp,ans);
			assert(false);
		}
	}*/
	return ans;
}

void slv(){
	int tar;cin>>tar;
	int ans=0;
	rep(l,60)rep(r,60){
		int w=mask(l+1)+mask(r+1)-1;
		int s=tar-mask(r);
		if(w<=s){
			vi ls;
			rng(i,1,l)ls.pb(mask(i));
			rng(i,1,r)ls.pb(mask(i));
			
			int mn=max(cdiv(s-accumulate(all(ls),int(0)),w),1LL);
			int mx=fdiv(s,w);
			
			rng(v,mn,mx+1){
				int u=s-v*w;
				//int val=sum_equation(x,y,u);
				int val=subset_sum_pow2_minus1(ls,u);
				ans+=val;
				dmp2(l,r,v,val);
			}
		}
	}
	print(ans);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	initbin();
	//int t;cin>>t;rep(_,t)
	slv();
}