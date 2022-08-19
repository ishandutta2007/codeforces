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
int mask(int i){
	return (int(1)<<i)-1;
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
    static random_device rd;
    static mt19937_64 gen(rd());
    #endif
    return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

//AGC034E
//XX Opencup GP of Korea
//int(E)->to
template<class N,class E>
struct treedp{
	const vvc<E>& g;
	vc<N> a,b,res;
	void dfs1(int v,int p){
		a[v].init(v);
		E up;
		for(auto e:g[v])
			if(e!=p){
				dfs1(e,v);
				b[e]=a[v];
				a[v]=a[v]+a[e];
			}else
				up=e;
		if(p!=-1)a[v]=a[v].up(up);
	}
	void dfs2(int v,int p,N cur){
		per(i,g[v].size()){
			auto e=g[v][i];
			if(e==p)continue;
			dfs2(e,v,(cur+b[e]).up(e));
			cur=cur+a[e];
		}
		res[v]=cur;
	}
	treedp(const vvc<E>&gg):g(gg),a(g.size()),b(g.size()),res(g.size()){
		dfs1(0,-1);
		N tmp;tmp.init(0);
		dfs2(0,-1,tmp);
	}
};

struct E{
	int to,cost;
	operator int()const{
		return to;
	}
};

vi wt;
struct N{
	int top,c,s;
	void init(int v){
		top=c=wt[v];
		s=0;
	}
	N up(E e)const{
		return N{wt[e.to],c+wt[e.to],s+c*e.cost};
	}
	N operator+(const N&r)const{
		assert(top==r.top);
		return N{top,c+r.c-top,s+r.s};
	}
};

const int vmax=5010;
//const int vmax=20;

bool pri[vmax];
void initprime(){
	rng(i,2,vmax)
		pri[i]=1;
	rng(i,2,vmax)if(pri[i])
		for(int j=i*2;j<vmax;j+=i)
			pri[j]=0;
}
vi factors[vmax];
void initfactor(){
	rng(i,2,vmax)if(pri[i])
		for(int j=i;j<vmax;j+=i){
			int x=j;
			while(x%i==0){
				factors[j].pb(i);
				x/=i;
			}
		}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	initprime();
	initfactor();
	
	vi cnt(vmax);
	
	{
		int n;cin>>n;
		if(n<0){
			n=-n;
			rep(i,n)cnt[max(i,int(1))]++;
			//rep(_,n){
			//	cnt[rand_int(1,1000)]++;
			//}
		}else{
			rep(_,n){
				cnt[max(int(1),read())]++;
			}
		}
	}
	
	vi ps;
	rep(i,vmax)if(pri[i])ps.pb(i);
	int s=ps.size();
	
	auto getidx=[&](int p){
		return s-1-lwb(ps,p);
	};
	
	dmp(s);
	
	auto lca=[&](const vi&a,const vi&b){
		rep(i,s)if(a[i]!=b[i]){
			vi res(s);
			rep(j,i)res[j]=a[j];
			res[i]=min(a[i],b[i]);
			return res;
		}
		return a;
	};
	auto dist=[&](const vi&a,const vi&b){
		//assume a is a proper ancestor of b
		int res=0;
		rep(i,s)res+=b[i]-a[i];
		return res;
	};
	auto asds=[&](const vi&a,const vi&b){
		//assume a != b
		rep(i,s)if(a[i]!=b[i]){
			if(a[i]>b[i])return false;
			rng(j,i+1,s)if(a[j])return false;
			return true;
		}
		//return true;
		dmp2(a,b);
		assert(false);
	};
	
	int n=0;
	vc<tuple<int,int,int>> es;
	
	vc<pair<vi,int>> st;
	auto ae=[&](int i){
		es.eb(st[i].b,st[i+1].b,dist(st[i].a,st[i+1].a));
	};
	vi cur(s);
	rep(i,vmax){
		for(auto f:factors[i])
			cur[getidx(f)]++;
		if(cnt[i]){
			dmp(cur);
			dmp(st);
			if(st.size()){
				auto z=lca(st.back().a,cur);
				dmp(z);
				auto itr=lower_bound(all(st),pair<vi,int>(z,-1));
				if(itr==st.ed||itr->a!=z){
					st.insert(itr,mp(z,n++));
					wt.pb(0);
				}
				while(!asds(st.back().a,cur)){
					ae(si(st)-2);
					st.pop_back();
				}
			}
			st.eb(cur,n++);
			wt.pb(cnt[i]);
		}
	}
	rep(i,si(st)-1)ae(i);
	
	{
		vvc<E> tr(n);
		for(auto e:es){
			int a,b,c;tie(a,b,c)=e;
			tr[a].pb({b,c});
			tr[b].pb({a,c});
		}
		auto dp=treedp<N,E>(tr).res;
		int ans=inf;
		rep(i,n)chmin(ans,dp[i].s);
		cout<<ans<<endl;
	}
}