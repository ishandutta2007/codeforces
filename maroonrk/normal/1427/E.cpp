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

int waf(int m){
	vi x;
	rng(i,1,100000){
		int v=m*i;
		for(auto z:x)
			chmin(v,z^v);
		if(v)x.pb(v);
		if(si(x)==topbit(m*i)+1){
			return i;
		}
	}
	return -1;
}

const int S=100;
using B=bitset<S>;

//csweep
//arank
//
vi sweep(vc<B>&a,int w,int c=-1){
	if(a.empty())return {};
	if(c==-1)c=w;
	int h=si(a),r=0;
	vi res;
	rep(i,c){
		if(r==h)break;
		rng(j,r,h)if(a[j][i]){
			swap(a[r],a[j]);
			break;
		}
		if(!a[r][i])continue;
		rep(j,h)if(j!=r&&a[j][i]){
			a[j]^=a[r];
		}
		res.pb(i);
		r++;
	}
	return res;
}

pair<bool,B> lineareq(vc<B> a,int w,B b){
	int h=si(a);
	rep(i,h)
		a[i][w]=b[i];
	vi idx=sweep(a,w+1,w);
	cerr<<si(idx)<<endl;
	rng(i,si(idx),h)
		if(a[i][w])
			return mp(false,B());
	B res;
	rep(i,si(idx))
		res[idx[i]]=a[i][w];
	return mp(true,res);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	vc<tuple<int,int,int>> ans;
	unordered_set<int> waf;
	auto add_add=[&](int a,int b){
		assert(waf.find(a)!=waf.ed);
		assert(waf.find(b)!=waf.ed);
		ans.eb(0,a,b);
		waf.insert(a+b);
	};
	auto add_xor=[&](int a,int b){
		assert(waf.find(a)!=waf.ed);
		assert(waf.find(b)!=waf.ed);
		ans.eb(1,a,b);
		waf.insert(a^b);
	};
	
	int m;cin>>m;
	waf.insert(m);
	vi x{m},y{m};
	rng(i,2,ten(9)){
		int v=m*i;
		for(auto z:x)
			chmin(v,z^v);
		if(v){
			y.pb(m*i);
			x.pb(v);
		}
		if(si(x)==topbit(m*i)+1){
			break;
		}
	}
	
	const int L=30;
	rep(i,L){
		add_add(m<<i,m<<i);
	}
	for(auto v:y){
		v/=m;
		vi idx;
		rep(i,L)if(v&1<<i)idx.pb(i);
		int cur=m<<idx[0];
		rng(i,1,si(idx)){
			add_add(cur,m<<idx[i]);
			cur+=m<<idx[i];
		}
	}
	
	dmp(y);
	
	int n=si(y);
	dmp(n);
	dmp(topbit(y.back())+1);
	vc<B> z(n);
	rep(i,n)rep(j,n)z[i][j]=(y[j]>>i)&1;
	B tar{};
	tar[0]=1;
	auto ysp=lineareq(z,n,tar);
	assert(ysp.a);
	vi idx;
	rep(i,n)if(ysp.b[i])idx.pb(i);
	dmp(idx);
	assert(si(idx)>=2);
	int cur=y[idx[0]];
	rng(i,1,si(idx)){
		add_xor(cur,y[idx[i]]);
		cur^=y[idx[i]];
	}
	assert(cur==1);
	assert(waf.find(1)!=waf.ed);
	
	assert(si(ans)<=100000);
	print(si(ans));
	for(auto w:ans){
		int t,a,b;tie(t,a,b)=w;
		cout<<a<<(t==0?" + ":" ^ ")<<b<<"\n";
	}
}