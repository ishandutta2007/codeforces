#ifndef LOCAL
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

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

template<class t>
struct BIT{
	vc<t> buf;
	int s;
	BIT(int n=0){init(n);}
	void init(int n){buf.clear();buf.resize(s=n,0);}
	void init(const vc<t>&a){
		s=si(a);
		buf.resize(s);
		rep(i,s)buf[i]=a[i];
		rep(i,s){
			int j=i+((i+1)&(-i-1));
			if(j<s)buf[j]+=buf[i];
		}
	}
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

const int B=800;
const int C=2000;

int wei[C][B];

struct Query{
	int t,a,b;
	void readquery(){
		cin>>t>>a>>b;
		if(t==1){
			a--;
		}else if(t==2){
			a--;
		}else if(t==3){
			a--;b--;
		}else assert(0);
	}
};

int ITR=0;
bool dbg=false;

void slv(){
	int n;cin>>n;if(n==200000)dbg=true;
	vi a=readvi(n);
	vi p=readvi(n,-1);
	int qnum;cin>>qnum;
	vc<Query> qs(qnum);
	rep(i,qnum)qs[i].readquery();
	vc<bool> mark(n);
	vi idx(n);
	vc<pi> lrs;lrs.reserve(n);
	vi jp;jp.reserve(n);
	vi gr(n),add;add.reserve(n);
	vi sum(n+1);
	vi cmp(n+1);
	vi large;
	vc<bool> islarge;
	for(int lw=0;lw<qnum;lw+=B){
		int tail=min(lw+B,qnum);
		
		sum[0]=0;
		rep(i,n)sum[i+1]=sum[i]+a[i];
		
		vi ps{0,n};
		rng(i,lw,tail){
			if(qs[i].t==1){
				int l=qs[i].a,r=qs[i].b;
				ps.pb(l);
				ps.pb(r);
			}
		}
		mkuni(ps);
		rep(i,si(ps)-1)rng(j,ps[i],ps[i+1])cmp[j]=i;
		cmp[n]=si(ps)-1;
		vi cval(si(ps)-1);
		
		rep(i,n)mark[i]=0;
		
		rng(i,lw,tail){
			if(qs[i].t==2){
				mark[qs[i].a]=true;
			}else if(qs[i].t==3){
				mark[qs[i].a]=true;
				mark[qs[i].b]=true;
			}
		}
		
		rep(i,n)gr[i]=-1;
		lrs.clear();
		jp.clear();
		int head=0;
		rep(i,n)if(mark[i]){
			int cur=p[i];
			assert(gr[cur]==-1);
			int l=head;
			int g=si(lrs);
			while(1){
				idx[head++]=cur;
				gr[cur]=g;
				if(mark[cur])break;
				cur=p[cur];
			}
			int r=head;
			lrs.eb(l,r);
			sort(idx.bg+l,idx.bg+r);
			jp.pb(cur);
		}
		int mid=si(lrs);
		rep(i,n)if(gr[i]==-1){
			int l=head;
			int g=si(lrs);
			int cur=i;
			do{
				idx[head++]=cur;
				gr[cur]=g;
				cur=p[cur];
			}while(cur!=i);
			int r=head;
			lrs.eb(l,r);
			sort(idx.bg+l,idx.bg+r);
		}
		
		add.clear();
		add.resize(si(lrs));
		large.clear();
		islarge.resize(si(lrs));
		rep(i,si(lrs))islarge[i]=0;
		rep(i,mid)large.pb(i);
		int asknum=0;
		vi addcnt(si(lrs));
		rng(i,lw,tail)if(qs[i].t==1)asknum++;
		else if(qs[i].t==2){
			int g=gr[qs[i].a];
			addcnt[g]++;
		}
		rng(i,mid,si(lrs)){
			if(asknum*10<addcnt[i]*(lrs[i].b-lrs[i].a)){
				large.pb(i);
			}
		}
		if(si(large)>C)large.resize(C);
		for(auto i:large)islarge[i]=true;
		vi buf(si(ps));
		rep(i,si(large)){
			rep(j,si(ps))buf[j]=0;
			auto [b,e]=lrs[large[i]];
			rng(pos,b,e)buf[cmp[idx[pos]]+1]++;
			rep(j,si(ps)-1)buf[j+1]+=buf[j];
			rng(j,lw,tail)if(qs[j].t==1){
				int l=qs[j].a,r=qs[j].b;
				l=cmp[l];
				r=cmp[r];
				wei[i][j-lw]=buf[r]-buf[l];
			}
		}
		
		rng(i,lw,tail){
			if(qs[i].t==1){
				int l=qs[i].a,r=qs[i].b;
				int ans=sum[r]-sum[l];
				rep(j,si(large)){
					ans+=wei[j][i-lw]*add[large[j]];
				}
				{
					int lf=lwb(ps,l);
					int rt=lwb(ps,r);
					rng(j,lf,rt)ans+=cval[j];
				}
				print(ans);
			}else if(qs[i].t==2){
				int v=qs[i].a;
				do{
					int g=gr[v];
					add[g]+=qs[i].b;
					if(g<si(jp)){
						v=p[v];
						v=jp[gr[v]];
					}else{
						if(!islarge[g]){
							auto [b,e]=lrs[g];
							rng(pos,b,e){
								int j=idx[pos];
								cval[cmp[j]]+=qs[i].b;
							}
						}
						break;
					}
				}while(v!=qs[i].a);
			}else if(qs[i].t==3){
				swap(p[qs[i].a],p[qs[i].b]);
			}else assert(0);
		}
		
		rep(i,n)a[i]+=add[gr[i]];
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}