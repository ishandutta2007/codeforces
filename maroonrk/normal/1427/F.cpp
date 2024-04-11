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

bool dbg=false;

void work(vi&x,vi&y,vi&z){
	vi tmp;
	while(si(y)&&si(x)){
		tmp.pb(y.back());y.pop_back();
		tmp.pb(x.back());x.pop_back();
	}
	reverse(all(tmp));
	z.insert(z.bg,all(tmp));
}

void slv(){
	int n;cin>>n;
	if(n<0){
		n=-n;
		dbg=true;
	}
	vi t(6*n,1);
	if(dbg){
		vi ls(6*n);iota(all(ls),0);
		rep(step,2*n){
			int s=si(ls);
			int i=rand_int(0,s-3);
			rep(k,3){
				t[ls[i]]=step%2;
				ls.erase(ls.bg+i);
			}	
		}
	}else{
		rep(i,3*n){
			int a;cin>>a;
			a--;
			t[a]=0;
		}
	}
	dmp(t);
	vi idx(6*n);iota(all(idx),0);
	vvc<int> buf;
	vc<tuple<int,int,int>> alive;
	vvc<int> g(2*n);
	vi kind(2*n);
	rep(step,2*n){
		int s=si(idx);
		bool done=false;
		rep(i,s-2){
			if(t[idx[i]]==t[idx[i+1]]&&t[idx[i]]==t[idx[i+2]]){
				int cur=si(buf);
				int a=idx[i];
				int b=idx[i+1];
				int c=idx[i+2];
				buf.pb(vi{a,b,c});
				
				kind[cur]=t[a];
				vc<tuple<int,int,int>> tmp;
				for(auto [l,r,ch]:alive){
					if(a<=l&&r<=c){
						g[cur].pb(ch);
					}else{
						tmp.eb(l,r,ch);
					}
				}
				alive.swap(tmp);
				alive.eb(a,c,cur);
				
				idx.erase(idx.bg+i,idx.bg+i+3);
				done=true;
				break;
			}
		}
		assert(done);
	}
	
	auto rec=[&](auto self,int v)->tuple<vi,vi,vi>{
		vi x,y,z;
		for(auto ch:g[v]){
			auto [a,b,c]=self(self,ch);
			x.insert(x.ed,all(a));
			y.insert(y.ed,all(b));
			z.insert(z.ed,all(c));
		}
		work(x,y,z);
		z.pb(v);
		if(si(y)){
			z.insert(z.bg,y.back());
			y.pop_back();
		}else{
			x.pb(z[0]);
			z.erase(z.bg);
		}
		return mt(y,x,z);
	};
	
	vc<bool> rs(2*n,true);
	rep(i,2*n)for(auto j:g[i])rs[j]=false;
	
	vi x,y,z;
	rep(i,2*n)if(rs[i]&&kind[i]==1){
		auto [a,b,c]=rec(rec,i);
		x.insert(x.ed,all(a));
		y.insert(y.ed,all(b));
		z.insert(z.ed,all(c));
	}
	work(x,y,z);
	rep(i,2*n)if(rs[i]&&kind[i]==0){
		auto [a,b,c]=rec(rec,i);
		if(si(z)){
			x.insert(x.ed,all(b));
			y.insert(y.ed,all(a));
			z.insert(z.ed-1,all(c));
		}else if(si(c)){
			assert(si(y));
			int w=y.back();y.pop_back();
			z=c;
			z.pb(w);
			x.insert(x.ed,all(b));
			y.insert(y.ed,all(a));
			y.pb(z[0]);
			z.erase(z.bg);
		}else{
			x.insert(x.ed,all(b));
			y.insert(y.ed,all(a));
		}
		work(x,y,z);
	}
	assert(x.empty());
	assert(y.empty());
	rep(step,2*n){
		int i=z[step];
		assert(kind[i]==step%2);
		for(auto&v:buf[i])v++;
		print(buf[i]);
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}