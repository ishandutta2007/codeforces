#include <bits/stdc++.h>
using namespace std;

using ll=long long;
//#define int ll

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

template<class E,class D=ll>
pair<vc<D>,vi> dijkstra(const vvc<E>& g,int s){
	const int n=g.size();
	using P=pair<D,int>;
	priority_queue<P,vc<P>,greater<P>> pq;
	vc<D> dist(n,infLL);
	vi from(n,-1);
	const auto ar=[&](int v,D d,int f){
		if(dist[v]>d){
			dist[v]=d;
			pq.emplace(d,v);
			from[v]=f;
		}
	};
	ar(s,0,-1);
	while(pq.size()){
		D d;
		int v;
		tie(d,v)=pq.top();pq.pop();
		if(dist[v]!=d)continue;
		for(auto e:g[v])
			ar(e.to,d+e.cost,v);
	}
	return mp(dist,from);
}

struct E{
	int to,cost;
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,q,src;cin>>n>>q>>src;
	src--;
	
	int s=1;while(s<n)s*=2;
	
	int vs=n;
	
	vi x(2*s,-1);
	rng(i,1,s)x[i]=vs++;
	rep(i,n)x[s+i]=i;
	
	vi y(2*s,-1);
	rng(i,1,s)y[i]=vs++;
	rep(i,n)y[s+i]=i;
	
	
	vvc<E> g(vs);
	
	auto ae=[&](int a,int b,int c){
		if(a==-1||b==-1)return;
		g[a].pb({b,c});
	};
	
	rng(i,1,s){
		ae(x[2*i],x[i],0);
		ae(x[2*i+1],x[i],0);
	}
	rng(i,1,s){
		ae(y[i],y[2*i],0);
		ae(y[i],y[2*i+1],0);
	}
	
	rep(_,q){
		int t;cin>>t;
		if(t==1){
			int u,v,w;cin>>u>>v>>w;
			u--;v--;
			ae(u,v,w);
		}else if(t==2){
			int v,l,r,w;cin>>v>>l>>r>>w;
			v--;l--;
			for(l+=s,r+=s;l<r;l>>=1,r>>=1){
				if (l&1){
					ae(v,y[l],w);
					l++;
				}
				if (r&1){
					r--;
					ae(v,y[r],w);
				}
			}
		}else if(t==3){
			int v,l,r,w;cin>>v>>l>>r>>w;
			v--;l--;
			for(l+=s,r+=s;l<r;l>>=1,r>>=1){
				if (l&1){
					ae(x[l],v,w);
					l++;
				}
				if (r&1){
					r--;
					ae(x[r],v,w);
				}
			}
		}
	}
	
	vc<ll> ans=dijkstra(g,src).a;
	ans.resize(n);
	rep(i,n)if(ans[i]==infLL)ans[i]=-1;
	print(ans);
}