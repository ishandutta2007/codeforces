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

int getans(int n){
	assert(n>=3);
	return 1<<(topbit(n-1)+1);
}

void mult2(int a,int b,vc<pi>&x){
	if(a<b)swap(a,b);
	x.eb(a,b);
	x.eb(a+b,a-b);
}

vc<pi> modify(vc<pi> x){
	for(auto&[a,b]:x){
		a*=2;
		b*=2;
	}
	return x;
}

vc<pi> slv(int);

vc<pi> work(int n,int tar,bool hasz){
	if(n==0)return {};
	vc<pi> res;
	int cur;
	if(n==1){
		assert(hasz);
		cur=1;
	}else if(n==2){
		assert(hasz);
		mult2(0,1,res);
		cur=2;
	}else{
		res=slv(n);
		cur=getans(n);
		if(hasz)res.eb(0,cur);
	}
	while(cur<tar){
		rep(_,(n+hasz)-1)mult2(0,cur,res);
		cur*=2;
	}
	return res;
}

void append(vc<pi>&x,const vc<pi>&y){
	x.insert(x.ed,all(y));
}

//ans(n)*(n-1)+0 
vc<pi> slv(int n){
	assert(n>=3);
	if(ispow2(n))return slv(n-1);
	if(n==3){
		return vc<pi>{{1,3},{2,2}};
	}else if(n==5){
		vc<pi> res{{3,5},{2,2},{4,4}};
		mult2(0,1,res);
		mult2(0,2,res);
		mult2(0,4,res);
		res.eb(0,8);
		return res;
	}else if(n==6){
		vc<pi> res{{3,5},{2,6},{4,4}};
		mult2(0,1,res);
		mult2(0,2,res);
		mult2(0,4,res);
		mult2(0,2,res);
		mult2(0,4,res);
		return res;
	}
	int tar=getans(n);
	int p=n-tar/2;
	int q=tar/2-1-p;
	dmp2(tar,p,q);
	vc<pi> res;
	rep(i,p)res.eb(tar/2-1-i,tar/2+1+i);
	if(p>=q){
		assert(p>=3);
		append(res,modify(work(p,tar/2,false)));
		append(res,work(q,tar,true));
	}else{
		assert(q>=3);
		append(res,work(q,tar,false));
		append(res,modify(work(p,tar/2,true)));
	}
	mult2(0,tar/2,res);
	return res;
}

void test(int n){
	auto ans=slv(n);
	ans.eb(0,getans(n));
	
	{
		multiset<int> s;
		rep(i,n)s.insert(i+1);
		for(auto [a,b]:ans){
			dmp2(a,b);
			{
				auto itr=s.find(a);
				assert(itr!=s.ed);
				s.erase(itr);
			}
			{
				auto itr=s.find(b);
				assert(itr!=s.ed);
				s.erase(itr);
			}
			s.insert(a+b);
			s.insert(abs(a-b));
		}
		dmp(vi(all(s)));
		assert(vi(all(s))==vi(n,getans(n)));
	}
	
	assert(si(ans)<=20*n);
}

void slv(){
	int n;cin>>n;
	if(n==2)return print(-1);
	auto ans=slv(n);
	ans.eb(0,getans(n));
	
	#ifdef LOCAL
	{
		multiset<int> s;
		rep(i,n)s.insert(i+1);
		for(auto [a,b]:ans){
			dmp2(a,b);
			{
				auto itr=s.find(a);
				assert(itr!=s.ed);
				s.erase(itr);
			}
			{
				auto itr=s.find(b);
				assert(itr!=s.ed);
				s.erase(itr);
			}
			s.insert(a+b);
			s.insert(abs(a-b));
		}
		dmp(vi(all(s)));
		assert(vi(all(s))==vi(n,getans(n)));
	}
	#endif
	
	assert(si(ans)<=20*n);
	print(si(ans));
	for(auto [a,b]:ans){
		print(a,2);
		print(b);
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	/*rng(n,3,1025){
		test(n);
	}
	rng(n,49995,50001){
		test(n);
	}
	return 0;*/
	
	int t;cin>>t;rep(_,t)
	slv();
}