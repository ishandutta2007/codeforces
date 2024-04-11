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
#define dmp2(...) dmpr(cerr,"Line:",__LINE__,##__VA_ARGS__)
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

void print(ll x,int suc=1){
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
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
	#endif
	if(ex)exit(0);
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<endl;
	#else
	cout<<"Possible"<<endl;
	#endif
	if(ex)exit(0);
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<endl;
	#else
	cout<<"Impossible"<<endl;
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

const int nmax=500010;

vi t[nmax];

int len[nmax],dia;

using E=tuple<int,int,int>;
vc<E> es;

int par[nmax];

void dfs1(int v,int p){
	par[v]=p;
	for(auto c:t[v])if(c!=p){
		dfs1(c,v);
		chmax(len[v],len[c]);
	}
	len[v]++;
	if(p!=-1)
		es.eb(len[v],v,p);
}

void dfs2(int v,int p,int d){
	if(p!=-1)
		es.eb(d,p,v);
	vi z{d};
	for(auto c:t[v])if(c!=p){
		z.pb(len[c]);
	}
	sort(all(z),greater<int>());
	chmax(dia,z[0]);
	for(auto c:t[v])if(c!=p){
		int w=z[0];
		if(w==len[c])
			w=z[1];
		dfs2(c,v,w+1);
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	rep(_,n-1){
		int a,b;cin>>a>>b;
		a--;b--;
		t[a].pb(b);
		t[b].pb(a);
	}
	
	dfs1(0,-1);
	dfs2(0,-1,0);
	
	sort(all(es),greater<E>());
	
	vi e(n+2,-1),oe(n+2,-1),eo(n+2,-1);
	
	vi cnt(n),pre(n,-1),nei(n,0);
	
	for(auto www:es){
		dmp(www);
		int k,u,v;
		tie(k,u,v)=www;
		
		//e
		{
			if(cnt[v]>=1){
				chmax(e[k*2],cnt[v]+1);
			}
		}
		//oe
		{
			if(cnt[v]>=2&&pre[v]>k){
				chmax(oe[k*2+2],cnt[v]+1);
			}
		}
		//eo
		{
			int z=nei[v];
			if(par[v]!=-1)
				chmax(z,cnt[par[v]]);
			if(z>=2){
				z--;
				chmax(eo[k*2+1],z+cnt[v]);
			}
		}
		
		cnt[v]++;
		pre[v]=k;
		if(par[v]!=-1)
			chmax(nei[par[v]],cnt[v]);
	}
	
	dmp(e);
	dmp(oe);
	dmp(eo);
	
	per(i,n+1)chmax(e[i],e[i+1]);
	per(i,n+1)chmax(oe[i],oe[i+1]);
	per(i,n+1)chmax(eo[i],eo[i+1]);
	
	vi ans;
	rng(i,2,n+2){
		int w=1;
		if(i-1<=dia)
			w=2;
		if(i%2==0){
			chmax(w,e[i]);
			chmax(w,oe[i]);
		}else{
			chmax(w,eo[i]);
			chmax(w,e[i-1]);
		}
		ans.pb(w);
	}
	rep(i,n)
		chmax(ans[0],(int)t[i].size()+1);
	print(ans);
}