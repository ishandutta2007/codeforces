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

const int nmax=5010;
bool ysp[nmax][nmax];

void slv(){
	int n;cin>>n;
	vi t{0},x{0};
	rep(i,n){
		t.pb(read());
		x.pb(read());
	}
	n++;
	vc<pi> ok(n,pi(inf,-inf));
	auto upd=[&](int i,int l,int r){
		chmin(ok[i].a,l);
		chmax(ok[i].b,r);
	};
	auto unchi=[&](int i,int pos,int cur){
		int p=t[i-1]-cur,q=t[i]-t[i-1];
		for(auto z:{max(pos-p,x[i]-q),min(pos+p,x[i]+q)}){
			int aff=t[i]-t[i-1]-abs(x[i]-z);
			upd(i,min(z,x[i])-aff/2,max(z,x[i])+aff/2);
		}
	};
	upd(0,0,0);
	rep(i,n-1){
		dmp2(i,ok[i]);
		if(ok[i].a>ok[i].b)continue;
		assert(inc(ok[i].a,x[i],ok[i].b));
		rep(j,n)if(inc(ok[i].a,x[j],ok[i].b))ysp[i][j]=1;
		dmp(0);
		{//currently no clones
			int cur=t[i];
			rng(j,i+1,n){
				int nx=cur+abs(x[j]-x[j-1]);
				if(nx>t[j])break;
				//int aff=t[j]-nx;
				//upd(j,min(x[j],x[j-1])-aff/2,max(x[j],x[j-1])+aff/2);
				unchi(j,x[j-1],cur);
				cur=max(nx,t[j-1]);
			}
		}
		dmp(0);
		if(abs(x[i+1]-x[i])<=t[i+1]-t[i]){
			//carry clones
			//upd(i+1,ok[i].a,ok[i].b);
			upd(i+1,x[i+1],x[i+1]);
			rep(j,n)ysp[i+1][j]|=ysp[i][j];
		}
		dmp(0);
		if(inc(ok[i].a,x[i+1],ok[i].b)||ysp[i][i+1]){
			if(i+2<n){
				int cur=t[i]+abs(x[i]-x[i+2]);
				if(cur<=t[i+2]){
					/*{
						int p=t[i+1]-t[i],q=t[i+2]-t[i+1];
						for(auto z:{max(x[i]-p,x[i+2]-q),min(x[i]+p,x[i+2]+q)}){
							int aff=t[i+2]-t[i+1]-abs(x[i+2]-z);
							upd(i+2,min(z,x[i+2])-aff/2,max(z,x[i+2])+aff/2);
						}
					}*/
					unchi(i+2,x[i],t[i]);
					chmax(cur,t[i+1]);
					rng(j,i+3,n){
						int nx=cur+abs(x[j]-x[j-1]);
						if(nx>t[j])break;
						//int aff=t[j]-nx;
						//upd(j,min(x[j],x[j-1])-aff/2,max(x[j],x[j-1])+aff/2);
						unchi(j,x[j-1],cur);
						cur=max(nx,t[j-1]);
					}
				}
			}else{
				upd(i+1,x[i+1],x[i+1]);
			}
		}
	}
	if(ok[n-1].a<=ok[n-1].b)yes(0);
	else no(0);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}