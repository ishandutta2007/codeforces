#ifndef LOCAL
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

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

template<class Query>
struct chronological_segtree{
	int n,s;
	vvc<Query> qs;
	chronological_segtree(int nn){
		n=nn;
		s=1;
		while(s<n)s*=2;
		qs.resize(s*2);
	}
	void add(int l,int r,Query q){
		for(l+=s,r+=s;l<r;l>>=1,r>>=1){
			if (l&1){
				qs[l].pb(q);
				l++;
			}
			if (r&1){
				r--;
				qs[r].pb(q);
			}
		}
	}
	template<class F,class G,class H,class I>
	void solve(F f,G snapshot,H rollback,I getans){
		auto rec=[&](auto self,int i,int l,int r)->void{
			auto ss=snapshot();
			for(const auto&q:qs[i])
				f(q);
			if(i<s){
				self(self,i*2,l,(l+r)/2);
				self(self,i*2+1,(l+r)/2,r);
			}else if(i-s<n){
				getans(i-s);
			}
			rollback(ss);
		};
		rec(rec,1,0,s);
	};
};

const int Buf=ten(7);
int* ptr[Buf],valbuf[Buf];
int used;

void save(int&a){
	ptr[used]=&a;
	valbuf[used]=a;
	used++;
}

ll ans=infLL;
pair<int,ll> snapshot(){
	return mp(used,ans);
}

void rollback(pair<int,ll> unko){
	while(unko.a<used){
		used--;
		*ptr[used]=valbuf[used];
	}
	ans=unko.b;
}

const int nmax=100005;

struct Top3{
	int to[3],v[3];
	Top3(){
		rep(i,3)to[i]=-1;
		rep(i,3)v[i]=inf;
	}
	void add(int z,int x){
		rep(i,3){
			if(v[i]>x){
				save(v[i]);
				swap(v[i],x);
				save(to[i]);
				swap(to[i],z);
			}
		}
	}
	ll getval(){
		if(v[2]==inf)return infLL;
		return 0LL+v[0]+v[1]+v[2];
	}
	ll getval2(int x,int y){
		rep(i,3)if(to[i]!=x&&to[i]!=y){
			if(v[i]==inf)return infLL;
			else return v[i];
		}
		assert(false);
	}
} t3[nmax];

struct Query{
	int u,v,w;
	void upd(const Query&z){
		if(u!=z.u&&u!=z.v&&v!=z.u&&v!=z.v){
			chmin(ans,ll(w)+z.w);
		}
	}
} ls[100],lstmp[100];
int num;

int last[nmax],tp[nmax];
int curtime;
int&gettp(int v){
	if(last[v]<curtime){
		last[v]=curtime;
		tp[v]=0;
	}
	
	return tp[v];
}

void add(Query z){
	save(num);
	rep(i,num){
		save(ls[i].u);
		save(ls[i].v);
		save(ls[i].w);
	}
	
	int pos=num;
	per(i,num){
		ls[i].upd(z);
		if(z.w<=ls[i].w)pos=i;
	}
	int s=0;
	rep(i,pos)lstmp[s++]=ls[i];
	lstmp[s++]=z;
	rng(i,pos,num)lstmp[s++]=ls[i];
	
	num=0;
	curtime++;
	
	int mt=0;
	rep(i,s)if(mt<3){
		const auto&e=lstmp[i];
		int&x=gettp(e.u);
		int&y=gettp(e.v);
		if(x==0&&y==0){
			x=1;
			y=1;
			ls[num++]=e;
			mt++;
		}else if(x==1||y==1){
			ls[num++]=e;
			if(x==1)x++;
			if(y==1)y++;
		}
	}
}

void slv(){
	int n,m;cin>>n>>m;
	
	map<pi,pi> es;
	
	rep(_,m){
		int u,v,w;cin>>u>>v>>w;
		u--;v--;
		es[minmax(u,v)]=pi(0,w);
	}
	
	int q;cin>>q;q++;
	
	
	chronological_segtree<Query> seg(q);
	
	rng(i,1,q){
		int t,u,v;cin>>t>>u>>v;
		u--;v--;
		if(t==0){
			auto itr=es.find(minmax(u,v));
			seg.add(itr->b.a,i,{u,v,itr->b.b});
			es.erase(itr);
		}else{
			int w;cin>>w;
			es[minmax(u,v)]=pi(i,w);
		}
	}
	for(auto [key,val]:es){
		auto [u,v]=key;
		seg.add(val.a,seg.s,{u,v,val.b});
	}
	
	auto func=[&](Query z){
		t3[z.u].add(z.v,z.w);
		t3[z.v].add(z.u,z.w);
		chmin(ans,t3[z.u].getval());
		chmin(ans,t3[z.v].getval());
		
		add(z);
	};
	
	auto output=[&](int){
		print(ans);
	};
	
	seg.solve(func,snapshot,rollback,output);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}