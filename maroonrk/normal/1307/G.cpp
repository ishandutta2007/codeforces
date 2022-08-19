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

template<class t>
bool inc(t a,t b,t c){
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
    static random_device rd;
    static mt19937_64 gen(rd());
    #endif
    return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

//AGC031E
//AGC034D
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
		pi res(a,g[a].size());
		g[a].pb({b,(int)g[b].size(),cap,cost});
		g[b].pb({a,(int)g[a].size()-1,0,-cost});
		return res;
	}
	P go(int s,int t,int f){
		priority_queue<P,vc<P>,greater<P>> q;
		fill(all(d),inf);
		d[s]=0;
		q.push(P(0,s));
		while(q.size()){
			D a;
			int v;
			tie(a,v)=q.top();q.pop();
			if(d[v]<a)continue;
			rep(i,(int)g[v].size()){
				E e=g[v][i];
				if(e.cap>0){
					D w=d[v]+e.cost+h[v]-h[e.to];
					if(w<d[e.to]){
						d[e.to]=w;
						q.push(P(w,e.to));
						pv[e.to]=v;
						pe[e.to]=i;
					}
				}
			}
		}
		if(d[t]==inf)return P(0,0);
		rep(i,n)
			h[i]=min(h[i]+d[i],inf);
		int a=f;
		for(int v=t;v!=s;v=pv[v])
			chmin(a,g[pv[v]][pe[v]].cap);
		for(int v=t;v!=s;v=pv[v]){
			E& e=g[pv[v]][pe[v]];
			e.cap-=a;
			g[e.to][e.rev].cap+=a;
		}
		return P(a*h[t],a);
	}
	D calc(int s,int t,int f){
		D res=0;
		while(f>0){
			P w=go(s,t,f);
			if(w.b==0)
				return inf;
			f-=w.b;
			res+=w.a;
		}
		return res;
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,m;cin>>n>>m;
	mincf<int> mcf(n);
	
	rep(i,m){
		int a,b;cin>>a>>b;
		a--;b--;
		int c;cin>>c;
		mcf.ae(a,b,1,c);
	}
	
	vi x{0},y{0};
	while(1){
		int a,b;tie(a,b)=mcf.go(0,n-1,inf);
		if(b==0)break;
		x.pb(x.back()+b);
		y.pb(y.back()+a);
	}
	
	using ld=long double;
	
	int q;cin>>q;
	rep(_,q){
		int p;cin>>p;
		int lw=1,up=si(x)-1;
		ld ans=inf;
		auto waf=[&](int i){
			ld w=ld(y[i]+p)/x[i];
			chmin(ans,w);
			return w;
		};
		while(up-lw>3){
			int m1=(lw+lw+up)/3;
			int m2=(lw+up+up)/3;
			if(waf(m1)<waf(m2))up=m2;
			else lw=m1;
		}
		rng(i,lw,up+1)waf(i);
		cout<<ans<<endl;
	}
}