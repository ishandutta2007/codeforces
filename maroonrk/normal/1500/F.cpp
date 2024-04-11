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

#define CAPITAL
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

vc<ll> presum(const vi&a){
	vc<ll> s(si(a)+1);
	rep(i,si(a))s[i+1]=s[i]+a[i];
	return s;
}

//CF707 F
//N.l,N.r 
template<class N>
struct reverse_deque{
	int org;
	bool fw;
	deque<N> d;
	reverse_deque():org(0),fw(true){}
	size_t size()const{return si(d);}
	void r2i(N&x)const{
		if(fw){
			x.l+=org;
			x.r+=org;
		}else{
			swap(x.l,x.r);
			x.l=org-x.l;
			x.r=org-x.r;
		}
	}
	void i2r(N&x)const{
		if(fw){
			x.l-=org;
			x.r-=org;
		}else{
			swap(x.l,x.r);
			x.l=org-x.l;
			x.r=org-x.r;
		}
	}
	void push_back(N x){
		r2i(x);
		if(fw)d.push_back(x);
		else d.push_front(x);
	}
	void pop_back(){
		assert(!empty());
		if(fw)d.pop_back();
		else d.pop_front();
	}
	const N back()const{
		N x=fw?d.back():d.front();
		i2r(x);
		return x;
	}
	bool empty()const{return d.empty();}
	//x -> x+v
	void shift(int v){
		if(fw) org-=v;
		else org+=v;
	}
	//x -> v-x
	void rev(int v){
		shift(-v);
		fw^=true;
	}
	void clear(){
		d.clear();
	}
};

struct N{
	int l,r,i;
};

void slv(){
	int n,C;cin>>n>>C;
	vi w=readvi(n-2);w.pb(C);
	reverse_deque<N> d;
	vi g(n-1),pre(n-1,-1);
	d.pb(N{0,C,-1});
	rep(i,n-1){
		dmp(i);
		int v=w[i];
		while(si(d)){
			N x=d.back();
			if(x.r<=v)break;
			d.pop_back();
			if(x.l<=v){
				x.r=v;
				d.pb(x);
			}
		}
		if(d.empty())no();
		//set val for g,pre
		g[i]=d.back().r;
		pre[i]=d.back().i;
		//reverse
		d.rev(v);
		//new val
		if(g[i]==v){
			d.clear();
			d.pb(N{0,v,i});
		}else{
			d.pb(N{v,v,i});
		}
	}
	dmp(g);
	dmp(pre);
	vi dif(n-1),mx(n-2);
	for(int pos=n-2;pos>=0;pos=pre[pos]){
		int nx=pre[pos];
		if(nx>=0)mx[nx]=1;
		dif[pos]=g[pos];
		for(int i=pos-1;i>nx;i--){
			dif[i]=w[i]-dif[i+1];
		}
	}
	dmp(dif);
	dmp(mx);
	rep(i,n-2){
		if(mx[i]==0){
			assert(dif[i]+dif[i+1]==w[i]);
		}else{
			assert(max(dif[i],dif[i+1])==w[i]);
		}
	}
	vi h(n);
	h[1]=dif[0];
	rep(i,n-2){
		bool a=h[i]<h[i+1];
		a^=mx[i];
		if(a){
			h[i+2]=h[i+1]+dif[i+1];
		}else{
			h[i+2]=h[i+1]-dif[i+1];
		}
		assert(max({h[i],h[i+1],h[i+2]})-min({h[i],h[i+1],h[i+2]})==w[i]);
	}
	yes(0);
	print_offset(h,-*min_element(all(h)));
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}