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

//ARC055D
int gcd(int a,int b){return b?gcd(b,a%b):a;}
/*int gcd(int a,int b){
	if(a<0)a=-a;
	if(b<0)b=-b;
	if(a==0)return b;
	if(b==0)return a;
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


void slv(){
	int n,m;cin>>n>>m;
	vvc<int> g(n);
	rep(_,m){
		int a,b;cin>>a>>b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	{
		vi cyc;
		vi a(n,0),par(n,-1);
		auto rec=[&](auto self,int v,int p)->void{
			assert(a[v]==0);
			a[v]=1;
			par[v]=p;
			for(auto to:g[v])if(to!=p){
				if(a[to]==0){
					self(self,to,v);
				}else if(a[to]==1){
					if(cyc.empty()){
						int x=v;
						while(1){
							cyc.pb(x);
							if(x==to)break;
							x=par[x];
						}
					}
				}
			}
			a[v]=2;
		};
		rep(i,n)if(!a[i])rec(rec,i,-1);
		if(si(cyc)){
			yes(0);
			vi ans(n);
			for(auto i:cyc)ans[i]=1;
			print(ans);
			return;
		}
	}
	
	vi a(n),par(n,-1);
	vi vs;
	auto rec=[&](auto self,int v,int p)->void{
		assert(a[v]==0);
		a[v]=1;
		par[v]=p;
		vs.pb(v);
		for(auto to:g[v])if(to!=p){
			assert(a[to]==0);
			if(a[to]==0){
				self(self,to,v);
			}
		}
		a[v]=2;
	};
	
	vi ans(n);
	rep(waf,n)if(!a[waf]){
		vs.clear();
		rec(rec,waf,-1);
		int cnt=0;
		for(auto i:vs)if(si(g[i])==1)cnt++;
		if(cnt>=4){
			for(auto i:vs)if(si(g[i])==1)ans[i]=1;
			else ans[i]=2;
			yes(0);
			print(ans);
			return;
		}
		if(cnt==3){
			int rt=-1;
			for(auto i:vs)if(si(g[i])==3){
				assert(rt==-1);
				rt=i;
			}
			assert(rt!=-1);
			
			auto dfs=[&](auto self,int v,int p,vi&dst)->void{
				dst.pb(v);
				int num=0;
				for(auto to:g[v])if(to!=p){
					num++;
					self(self,to,v,dst);
				}
				assert(num<=1);
			};
			
			vvc<int> ls(3);
			rep(i,3){
				dfs(dfs,g[rt][i],rt,ls[i]);
				reverse(all(ls[i]));
			}
			
			int v=1;
			rep(i,3)v=lcm(v,si(ls[i])+1);
			chmin(v,ten(6));
			
			ans[rt]=v;
			rep(i,3){
				rep(j,si(ls[i])){
					ans[ls[i][j]]=v*(j+1)/(si(ls[i])+1);
				}
			}
			
			int sum=0;
			for(auto i:vs)sum-=sq(ans[i]);
			for(auto i:vs)for(auto j:g[i])if(i<j)sum+=ans[i]*ans[j];
			if(sum>=0){
				yes(0);
				print(ans);
				return;
			}
			
			for(auto i:vs)ans[i]=0;
		}
	}
	no(0);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int t;cin>>t;
	rep(_,t)slv();
}