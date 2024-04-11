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

template<class d>
struct maxflow{
	struct E{
		int to;
		d cap;
	};
	int n,m;
	E es[2*ten(6)];
	vi itr,lv,q,head;
	int nx[2*ten(6)];
	maxflow(int nn):n(nn),m(0),itr(n),lv(n),q(n),head(n,-1){one(nx);}
	int ae(int s,int t,d c){
		nx[m]=head[s];
		head[s]=m;
		es[m]={t,c};
		m++;
		
		nx[m]=head[t];
		head[t]=m;
		es[m]={s,0};
		m++;
		
		return m-2;
	}
	void bfs(int s){
		fill(all(lv),-1);
		lv[s]=0;
		int l=0,r=0;
		q[r++]=s;
		while(l<r){
			int v=q[l++];
			for(int eid=head[v];eid!=-1;eid=nx[eid]){
				auto e=es[eid];
				if(e.cap>0&&lv[e.to]==-1){
					lv[e.to]=lv[v]+1;
					q[r++]=e.to;
				}
			}
		}
	}
	d dfs(int v,int t,d f){
		if(v==t)return f;
		d res=0;
		for(int&eid=itr[v];eid!=-1;eid=nx[eid]){
			auto&e=es[eid];
			if(e.cap>0&&lv[e.to]==lv[v]+1){
				d a=dfs(e.to,t,min(f,e.cap));
				if(a>0){
					e.cap-=a;
					es[eid^1].cap+=a;
					res+=a;
					f-=a;
					if(f<=0)break;
				}
			}
		}
		return res;
	}
	d calc(int s,int t,d mx=inf){
		d f=0;
		while(f<mx){
			bfs(s);
			if(lv[t]==-1)
				return f;
			rep(i,n)itr[i]=head[i];
			f+=dfs(s,t,mx-f);
		}
		return f;
	}
};

//Lyft Level 5 Challenge 2018 - Final F
//CF635F
template<class E>
struct doubling{
	const vvc<E>&g;
	const int n,h;
	int cnt;
	int par[15][20010];
	vi dep,in,out,pe;
	void dfs(int v,int p,int z,int d){
		par[0][v]=p;
		pe[v]=z;
		dep[v]=d;
		in[v]=cnt++;
		for(auto e:g[v])if(e!=p)
			dfs(e,v,e.idx,d+1);
		out[v]=cnt;
	}
	doubling(const vvc<E>&gg,int r):g(gg),n(g.size()),h(__lg(n)+1),
		cnt(0),dep(n),in(n),out(n),pe(n){
		one(par);
		dfs(r,-1,-1,0);
		rng(i,1,h){
			rep(j,n)
				if(par[i-1][j]!=-1)
					par[i][j]=par[i-1][par[i-1][j]];
		}
	}
	int lca(int a,int b){
		assert(0<=a&&a<(int)g.size());
		assert(0<=b&&b<(int)g.size());
		if(dep[a]>dep[b])swap(a,b);
		int w=dep[b]-dep[a];
		rep(i,h)if(w&1<<i)
			b=par[i][b];
		if(a==b)return a;
		per(i,h){
			int x=par[i][a],y=par[i][b];
			if(x!=y)tie(a,b)=pi(x,y);
		}
		return par[0][a];
	}
	int len(int a,int b){
		assert(0<=a&&a<(int)g.size());
		assert(0<=b&&b<(int)g.size());
		return dep[a]+dep[b]-dep[lca(a,b)]*2;
	}
	int jump(int a,int b,int d){
		assert(0<=a&&a<(int)g.size());
		assert(0<=b&&b<(int)g.size());
		int c=lca(a,b);
		int w=dep[a]+dep[b]-dep[c]*2;
		assert(0<=d&&d<=w);
		if(d<=dep[a]-dep[c]){
			rep(i,h)if(d&1<<i)
				a=par[i][a];
			return a;
		}else{
			d=w-d;
			rep(i,h)if(d&1<<i)
				b=par[i][b];
			return b;
		}
	}
	int getpar(int v,int len)const{
		rep(i,h)if(len&1<<i)v=par[i][v];
		return v;
	}
};

void show(vi a){
	for(auto&v:a)v++;
	print(si(a),si(a)?2:1);
	print(a);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	int m;cin>>m;
	
	bool dbg=n<0;
	if(dbg){
		n=-n;
	}
	
	struct E{
		int to,idx;
		operator int()const{return to;}
	};
	vvc<E> t(n);
	rep(i,n-1){
		int a,b;
		if(!dbg){
			cin>>a>>b;
			a--;b--;
		}else{
			a=i+1,b=rand_int(0,i);
		}
		t[a].pb({b,i});
		t[b].pb({a,i});
	}
	doubling<E> db(t,0);
	
	int h=topbit(n)+1;
	int s=n*h;
	int tot=1+s+m+1;
	maxflow<int> mf(tot);
	rep(i,n){
		mf.ae(0,1+i,1);
		rng(j,1,h){
			int w=db.par[j-1][i];
			if(w!=-1){
				mf.ae(1+n*(j-1)+i,1+n*j+i,inf);
				mf.ae(1+n*(j-1)+w,1+n*j+i,inf);
			}
		}
	}
	
	auto ae=[&](int v,int p,int to){
		if(v==p)return;
		int len=db.dep[v]-db.dep[p];
		int k=topbit(len);
		mf.ae(1+n*k+v,to,inf);
		mf.ae(1+n*k+db.getpar(v,len-(1<<k)),to,inf);
	};
	
	rep(i,m){
		int to=1+s+i;
		
		int a,b;
		if(!dbg){
			cin>>a>>b;
			a--;b--;
		}else{
			a=rand_int(0,n-1);
			b=rand_int(0,n-1);
		}
		
		int c=db.lca(a,b);
		ae(a,c,to);
		ae(b,c,to);
		
		mf.ae(to,tot-1,1);
	}
	
	int f=mf.calc(0,tot-1);
	
	
	
	vi a;
	rep(i,m)if(mf.lv[1+s+i]!=-1)a.pb(i);
	vi b;
	rng(i,1,n)if(mf.lv[1+i]==-1)b.pb(db.pe[i]);
	
	dmp(a);
	dmp(b);
	
	assert(si(a)+si(b)==f);
	
	print(f);
	
	show(a);
	show(b);
}