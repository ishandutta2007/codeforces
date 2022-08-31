#ifndef LOCAL
#pragma GCC optimize ("-Ofast")
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

//O(1) add, O(sqrt(N)) get
struct ds1{
	int n,B,m;
	vc<ll> a,b;
	ds1(int nn){
		n=nn;
		B=max(int(sqrtl(n)),int(1));
		m=n/B+1;
		a.resize(n);
		b.resize(m);
	}
	void add(int i,ll v){
		assert(inc(0,i,n-1));
		a[i]+=v;
		b[i/B]+=v;
	}
	void addrng(int c,int d,ll v){
		if(c==d)return;
		assert(c<d);
		add(c,v);
		if(d<n)add(d,-v);
	}
	ll get(int i){
		int x=i/B;
		ll res=0;
		rep(j,x)res+=b[j];
		rng(j,x*B,i+1)res+=a[j];
		return res;
	}
	/*
	not verified
	int sum(int c,int d){
		int x=c/B,y=(d+B-1)/B;
		int res=0;
		rng(i,x,y){
			int l=max(c,i*B);
			int r=min(d,(i+1)*B);
			if(l==i*B&&r==(i+1)*B) res+=b[i];
			else rng(j,l,r) res+=a[j];
		}
		return res;
	}
	*/
};

const int B=85;
const int S=500;
const int nmax=200010+S;
const int T=nmax/S+1;

template<class D>
struct N{
	D cnt[6];
};

constexpr int idxmap[3][3]{{0,1,2},{-1,3,4},{-1,-1,5}};

template<class D,class E>
N<D> mg(const N<D>&a,const N<E>&b){
	N<D> res{};
	rep(i,6)res.cnt[i]=a.cnt[i]+b.cnt[i];
	rep(i,3)rng(j,i,3)rng(k,j+1,3)
		res.cnt[idxmap[i][k]]+=a.cnt[idxmap[i][j]]*b.cnt[idxmap[j+1][k]];
	return res;
}

int rw[nmax][3];

template<class D>
N<D> advance(const N<D>&a,int i,int val){
	N<D> res=a;
	rep(j,3)if(rw[i][j]==val){
		res.cnt[idxmap[j][j]]++;
		rep(k,j)res.cnt[idxmap[k][j]]+=a.cnt[idxmap[k][j-1]];
	}
	return res;
}

struct M{
	int val;
	N<int> buf[nmax],blk[T];
	N<ll> sum[T];
	void init(int n){
		for(int i=0;i<n;i+=S)upd(i);
	}
	void upd(int i){
		int p=i/S;
		int l=p*S,r=l+S;
		rng(j,i,r-1){
			buf[j+1]=advance(buf[j],j,val);
		}
		blk[p]=advance(buf[r-1],r-1,val);
		rep(j,T-1)sum[j+1]=mg(sum[j],blk[j]);
	}
	ll getsum(int i){
		int p=i/S;
		return mg(sum[p],buf[i]).cnt[idxmap[0][2]];
	}
} large[B];

vi pos[nmax];
vc<uint> pre[nmax];
vc<N<uint>> buri[nmax];

bool dbg=false;
const int Z=100;

struct Query{
	int t,i,v;
	void readinit(){
		if(dbg){
			t=rand_int(1,2);
			if(t==1){
				i=rand_int(0,Z-1);
				v=rand_int(0,Z-1);
			}else{
				i=rand_int(1,Z);
			}
		}else{
			cin>>t;
			if(t==1){
				cin>>i>>v;
				i--;
				v--;
			}else{
				cin>>i;
			}
		}
	}
};

void slv(){
	int n,m;
	vi arw,brw,crw;
	if(dbg){
		n=Z,m=Z;
		rep(i,n)arw.pb(rand_int(0,n-1));
		rep(i,n)brw.pb(rand_int(0,n-1));
		rep(i,n)crw.pb(rand_int(0,n-1));
	}else{
		cin>>n>>m;
		arw=readvi(n,-1);
		brw=readvi(n,-1);
		crw=readvi(n,-1);
	}
	auto updrw=[&](int i,int v){
		rw[i][0]=brw[v];
		rw[i][1]=v;
		rw[i][2]=crw[v];
	};
	vc<Query> qs(m);
	rep(i,m)qs[i].readinit();
	vi idx(n,-1);
	one(rw);
	rep(i,n)updrw(i,arw[i]);
	rep(i,n)rep(j,3)pos[rw[i][j]].pb(i);
	rep(i,m){
		if(qs[i].t==1){
			updrw(qs[i].i,qs[i].v);
			rep(j,3)pos[rw[qs[i].i][j]].pb(qs[i].i);
		}
	}
	rep(i,n)mkuni(pos[i]);
	
	//todo 
	vi ls(n);iota(all(ls),0);
	{
		vc<ll> wei(n);
		/*one(rw);
		rep(i,n)updrw(i,arw[i]);
		rep(i,m){
			if(qs[i].t==1){
				vi tmp;
				rep(j,3)tmp.pb(rw[qs[i].i][j]);
				updrw(qs[i].i,qs[i].v);
				rep(j,3)tmp.pb(rw[qs[i].i][j]);
				mkuni(tmp);
				for(auto k:tmp){
					wei[k]+=si(pos[k])-lwb(pos[k],qs[i].i);
				}
			}
		}*/
		rep(i,n)wei[i]=si(pos[i]);
		sort(all(ls),[&](int i,int j){return wei[i]>wei[j];});
	}
	if(si(ls)>B)ls.resize(B);
	rep(i,si(ls))idx[ls[i]]=i;
	
	one(rw);
	rep(i,n)updrw(i,arw[i]);
	ds1 unko(n);
	auto kusogayo=[&](int k,int i){
		if(idx[k]==-1){
			assert(binary_search(all(pos[k]),i));
			ll tot=0;
			rng(j,lwb(pos[k],i),si(pos[k])-1){
				buri[k][j+1]=advance(buri[k][j],pos[k][j],k);
				ll cur=buri[k][j+1].cnt[idxmap[0][2]];
				cur-=pre[k][j];
				unko.add(pos[k][j],cur-tot);
				pre[k][j]+=cur;
				tot=cur;
			}
		}else{
			large[idx[k]].upd(i);
		}
	};
	rep(i,si(ls)){
		large[i].val=ls[i];
		large[i].init(n);
	}
	rep(i,n)if(si(pos[i])&&idx[i]==-1){
		pre[i].resize(si(pos[i]));
		pos[i].pb(n);
		buri[i].resize(si(pos[i]));
		kusogayo(i,pos[i][0]);
	}
	for(auto w:qs){
		if(w.t==1){
			vi tmp;
			rep(j,3)tmp.pb(rw[w.i][j]);
			updrw(w.i,w.v);
			rep(j,3)tmp.pb(rw[w.i][j]);
			mkuni(tmp);
			for(auto k:tmp)
				kusogayo(k,w.i);
		}else{
			ll ans=0;
			rep(i,si(ls))
				ans+=large[i].getsum(w.i);
			ans+=unko.get(w.i-1);
			print(ans);
			
			if(dbg){
				vi t;
				int sum=0;
				rep(i,w.i)rng(j,i+1,w.i)rng(k,j+1,w.i){
					if(rw[i][0]==rw[j][1]&&rw[j][1]==rw[k][2]){
						sum++;
						t.pb(rw[i][0]);
					}
				}
				if(sum!=ans){
					dmp(w.i);
					cerr<<sum<<" "<<ans<<endl;
					dmp(t);
					mkuni(t);
					for(auto i:t){
						dmp(pos[i]);
						dmp(pre[i]);
					}
					/*rep(i,n)cerr<<vi(rw[i],rw[i]+3)<<endl;
					rep(i,si(ls))
						dmp2(ls[i],large[i].getsum(w.i));*/
				}
				assert(sum==ans);
			}
		}
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}