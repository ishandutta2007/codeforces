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

//int=ll  D=signed 
//AGC031E
//AGC034D
//CF621G
//Bellman-Ford
template<class D>
struct mincf{
	using P=pair<D,int>;
	struct E{int to,rev,cap;D cost;};
	int n;
	vvc<E> g;
	vc<D> h,d;
	vi pv,pe;
	mincf(int nn):n(nn),g(n),h(n),d(n),pv(n),pe(n){}
	pi ae(int a,int b,int cap,D cost){
		//dmp2(a,b,cap,cost);
		pi res(a,g[a].size());
		g[a].pb({b,(int)g[b].size(),cap,cost});
		g[b].pb({a,(int)g[a].size()-1,0,-cost});
		return res;
	}
	P go(int s,int t,int f){
		static vc<P> q;
		q.clear();
		fill(all(d),inf);
		d[s]=0;
		auto push=[&](D w,int v){
			q.eb(w,v);
			push_heap(all(q),greater<P>());
		};
		auto pop=[&](){
			pop_heap(all(q),greater<P>());
			auto res=q.back();
			q.pop_back();
			return res;
		};
		push(0,s);
		while(q.size()){
			D a;
			int v;
			tie(a,v)=pop();
			if(d[v]<a)continue;
			if(v==t)break;
			rep(i,(int)g[v].size()){
				E e=g[v][i];
				if(e.cap>0){
					D w=d[v]+e.cost+h[v]-h[e.to];
					if(w<d[e.to]){
						d[e.to]=w;
						push(w,e.to);
						pv[e.to]=v;
						pe[e.to]=i;
					}
				}
			}
		}
		if(d[t]==inf)return P(0,0);
		rep(i,n)
			h[i]=min<D>(h[i]+min(d[i],d[t]),inf);
		int a=f;
		for(int v=t;v!=s;v=pv[v])
			chmin(a,g[pv[v]][pe[v]].cap);
		for(int v=t;v!=s;v=pv[v]){
			E& e=g[pv[v]][pe[v]];
			e.cap-=a;
			g[e.to][e.rev].cap+=a;
		}
		return P(h[t],a);
	}
	pair<int,D> calc(int s,int t,int f){
		int a=0;
		D res=0;
		while(f>0){
			P w=go(s,t,f);
			if(w.b==0)break;
			a+=w.b;
			f-=w.b;
			res+=w.a*w.b;
		}
		return mp(a,res);
	}
	tuple<vi,vc<D>,vc<D>> get_slopes(int s,int t,int f){
		vi fs{0};
		vc<D> vs{0},sls;
		int a=0;
		D res=0;
		while(f>0){
			P w=go(s,t,f);
			if(w.b==0)break;
			sls.pb(w.a);
			if(w.b>=inf/2)break;
			a+=w.b;
			f-=w.b;
			res+=w.a*w.b;
			fs.pb(a);
			vs.pb(res);
		}
		return mt(fs,vs,sls);
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,k;cin>>n>>k;
	chmin(k,1<<(n-1));
	int s=1<<n;
	vi a=readvi(1<<n);
	
	vi lf,rt;
	
	vc<bool> used(s);
	using T=tuple<int,int,int>;
	priority_queue<T> pq;
	auto add=[&](int bit){
		int val=-1,z=-1;
		rep(i,n)if(!used[bit^1<<i]&&chmax(val,a[bit]+a[bit^1<<i])){
			z=bit^1<<i;
		}
		if(z!=-1)pq.emplace(val,bit,z);
	};
	rep(bit,s)if(popcount(bit)%2==0)add(bit);
	
	while(si(lf)<2*k&&si(pq)){
		auto [val,bit,z]=pq.top();pq.pop();
		if(!used[z]){
			lf.pb(bit);
			rt.pb(z);
			used[z]=true;
			continue;
		}
		add(bit);
	}
	
	vi x=lf,y=rt;
	for(auto v:lf)rep(i,n)y.pb(v^1<<i);
	for(auto v:rt)rep(i,n)x.pb(v^1<<i);
	mkuni(x);
	mkuni(y);
	
	mincf<int> mcf(1+si(x)+si(y)+1);
	rep(i,si(x))mcf.ae(0,1+i,1,0);
	rep(i,si(y))mcf.ae(1+si(x)+i,1+si(x)+si(y),1,0);
	
	const int V=2*ten(6);
	for(auto v:lf){
		rep(i,n){
			int z=v^1<<i;
			mcf.ae(1+lwb(x,v),1+si(x)+lwb(y,z),1,V-(a[v]+a[z]));
		}
	}
	for(auto v:rt){
		rep(i,n){
			int z=v^1<<i;
			mcf.ae(1+lwb(x,z),1+si(x)+lwb(y,v),1,V-(a[v]+a[z]));
		}
	}
	
	int cost=mcf.calc(0,1+si(x)+si(y),k).b;
	print(V*k-cost);
}