#ifndef LOCAL
#pragma GCC optimize ("-Ofast")
#pragma GCC optimize ("-unroll-loops")
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

const int nmax=20010;

struct E{
	int to;
	char c;
};

vc<E> t[nmax];
int to_nv[nmax];

int par[nmax],sub[nmax];
E pe[nmax];
int dep[nmax];
int v_org[nmax];
int vs;

int dfs(int v,int p,int np,int d){
	int nv=vs++;
	v_org[nv]=v;
	to_nv[v]=nv;
	par[nv]=np;
	sub[nv]=1;
	dep[nv]=d;
	for(auto e:t[v])if(e.to!=p){
		sub[nv]+=dfs(e.to,v,nv,d+1);
	}else{
		e.to=np;
		pe[nv]=e;
	}
	return sub[nv];
}

int n;

int es;
E buf[nmax*2];
int el[nmax],er[nmax];

void init_es(){
	rep(v,n){
		el[v]=er[v]=es;
		for(auto e:t[v_org[v]]){
			e.to=to_nv[e.to];
			buf[er[v]++]=e;
		}
		es=er[v];
	}
}

vc<pi> qbuf[nmax];
int ans[nmax];
char str[nmax];
int pos[nmax];
int ls[nmax];

void slv(int rt,int tar,int dst){
	int len=0;
	while(tar!=rt){
		str[len++]=pe[tar].c;
		tar=pe[tar].to;
	}
	int b=0,en=0;
	ls[en++]=rt;
	pos[rt]=0;
	while(b<en){
		int v=ls[b++];
		ans[dst]++;
		char w=str[len-1-pos[v]];
		rng(j,el[v],er[v]){
			auto e=buf[j];
			if(e.to!=pe[v].to){
				if(e.c>w)break;
				else if(e.c<w){
					ans[dst]+=sub[e.to];
				}else if(pos[v]<len-1){
					ls[en++]=e.to;
					pos[e.to]=pos[v]+1;
				}else break;
			}
		}
	}
	ans[dst]--;
}

void dfs_slv(int v,int p){
	for(auto w:qbuf[v])slv(v,w.a,w.b);
	rng(j,el[v],er[v]){
		auto e=buf[j];
		if(e.to!=p){
			int s=sub[e.to];
			sub[v]=n-s;
			pe[v]=e;
			
			sub[e.to]=n;
			E tmp{-1,-1};
			swap(pe[e.to],tmp);
			
			dfs_slv(e.to,v);
			
			sub[e.to]=s;
			swap(pe[e.to],tmp);
		}
	}
	sub[v]=n;
	pe[v]={-1,-1};
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int q;cin>>n>>q;
	bool dbg=n<0;
	if(dbg){
		n=-n;
	}
	
	rep(_,n-1){
		int a,b;
		char c;
		if(!dbg){
			cin>>a>>b;
			a--;b--;
			c=readString()[0];
		}else{
			//a=_+1,b=rand_int(0,_);
			a=_,b=_+1;
			//a=0,b=_+1;
			//c=rand_int('a','z');
			c='a';
		}
		t[a].pb({b,c});
		t[b].pb({a,c});
	}
	
	rep(i,n){
		sort(all(t[i]),[&](auto a,auto b){return a.c<b.c;});
	}
	
	pe[0]={-1,-1};
	dfs(0,-1,-1,0);
	
	init_es();
	
	rep(i,q){
		int a,b;
		if(!dbg){
			cin>>a>>b;
			a--;b--;
		}else{
			/*do{
				a=rand_int(0,n-1);
				b=rand_int(0,n-1);
			}while(a==b);*/
			a=0;
			//b=rand_int(1,n-1);
			b=n-1;
		}
		a=to_nv[a];
		b=to_nv[b];
		qbuf[a].eb(b,i);
	}
	
	dfs_slv(0,-1);
	
	rep(i,q)print(ans[i]);
}