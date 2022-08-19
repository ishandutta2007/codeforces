#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#pragma GCC optimize ("-Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

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

template<class t>
struct BIT{
	vc<t> buf;
	int s;
	BIT(int n=0){init(n);}
	void init(int n){buf.assign(s=n,0);}
	void add(int i,t v){
		for(;i<s;i+=(i+1)&(-i-1))
			buf[i]+=v;
	}
	t get(int i){
		t res=0;
		for(;i>=0;i-=(i+1)&(-i-1))
			res+=buf[i];
		return res;
	}
	t sum(int b,int e){
		return get(e-1)-get(b-1);
	}
	void add_range(int b,int e,t v){
		add(b,v);
		add(e,-v);
	}
	int kth(int k){
		int res=0;
		for(int i=topbit(s);i>=0;i--){
			int w=res+(1<<i);
			if(w<=s&&buf[w-1]<=k){
				k-=buf[w-1];
				res=w;
			}
		}
		return res;
	}
	//yukicoder No.1024
	int kth_helper(int k,int i){
		return kth(k+get(i-1));
	}
};

struct maintain_1d_point{
	vc<pi> xi;
	BIT<int> bit;
	void addp(int x,int i){
		xi.eb(x,i);
	}
	void init(){
		sort(all(xi));
		bit=BIT<int>(si(xi));
		rep(i,si(xi))bit.add(i,1);
	}
	void work(int lw,int up,vi&res){
		lw=lwb(xi,pi(lw,-inf));
		int tmp=bit.get(lw-1);
		while(1){
			int i=bit.kth(tmp);
			if(i<si(xi)&&xi[i].a<up){
				res.pb(xi[i].b);
				bit.add(i,-1);
			}else break;
		}
	}
};

//CF712D
struct maintain_2d_point{
	vi xs;
	int s;
	vc<maintain_1d_point> z;
	void init(vc<pi> xy){
		for(auto [x,y]:xy)xs.pb(x);
		
		mkuni(xs);
		s=1;
		while(s<si(xs))s*=2;
		z.resize(s*2);
		
		int idx=0;
		for(auto [x,y]:xy){
			int i=lwb(xs,x);
			i+=s;
			while(i){
				z[i].addp(y,idx);
				i>>=1;
			}
			idx++;
		}
		
		rep(i,2*s)z[i].init();
	}
	//[l,r), [lw,up)
	//maybe duplicate
	vi getrect(int l,int r,int lw,int up){
		l=lwb(xs,l);
		r=lwb(xs,r);
		vi res;
		auto sub=[&](maintain_1d_point&w){
			w.work(lw,up,res);
		};
		for(l+=s,r+=s;l<r;l>>=1,r>>=1){
			if (l&1){
				sub(z[l]);
				l++;
			}
			if (r&1){
				r--;
				sub(z[r]);
			}
		}
		return res;
	}
};

bool dbg=false;

void slv(){
	int n;cin>>n;
	if(n<0){
		dbg=true;
		n=-n;
	}
	maintain_2d_point ds;
	
	vi perm(2*n);iota(all(perm),0);
	myshuffle(perm);
	sort(all(perm)-n);
	sort(n+all(perm));
	
	vc<pi> ab;
	rep(i,n){
		int a,b;
		if(!dbg){
			cin>>a>>b;
			a--;b--;
		}else{
			a=perm[i];
			b=perm[2*n-1-i];
			if(rand_int(0,1))swap(a,b);
		}
		rep(_,2){
			ab.eb(a,b);
			swap(a,b);
		}
	}
	vi pos;
	vc<pi> abbuf;
	rep(i,2*n)if(ab[i].a>ab[i].b){
		pos.pb(i);
		abbuf.pb(ab[i]);
	}
	ds.init(abbuf);
	
	int ans=0;
	vc<pi> ls;
	vi vis(2*n,-1);
	rep(i,2*n)if(vis[i]==-1){
		vc<pi> buf;
		auto reach=[&](int v,int k){
			if(vis[v]!=-1){
				if(vis[v]!=k){
					print(-1);
					exit(0);
				}
				return;
			}
			vis[v]=k;
			buf.eb(v,k);
		};
		reach(i,0);
		rep(head,si(buf)){
			auto [v,k]=buf[head];
			auto [a,b]=ab[v];
			reach(v^1,k^1);
			if(a>b){
				{
					vi tmp=ds.getrect(a+1,2*n,b+1,a);
					for(auto to:tmp)reach(pos[to],k^1);
				}
				{
					vi tmp=ds.getrect(b+1,a,0,b);
					for(auto to:tmp)reach(pos[to],k^1);
				}
			}
		}
		int cost[2]{0,0};
		for(auto [v,k]:buf){
			if(v%2)cost[k]++;
		}
		int mn=cost[0]>cost[1];
		ans+=cost[mn];
		for(auto [v,k]:buf){
			if(k==mn){
				ls.pb(ab[v]);
			}
		}
	}
	assert(si(ls)==n);
	sort(all(ls));
	bool ok=true;
	rep(i,n-1)if(ls[i].b<=ls[i+1].b)ok=false;
	if(!ok)print(-1);
	else print(ans);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}