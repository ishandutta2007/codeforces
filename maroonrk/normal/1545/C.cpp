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

//mint107  verify 
//#define DYNAMIC_MOD

struct modinfo{uint mod,root;
#ifdef DYNAMIC_MOD
constexpr modinfo(uint m,uint r):mod(m),root(r),im(0){set_mod(m);}
ull im;
constexpr void set_mod(uint m){
	mod=m;
	im=ull(-1)/m+1;
}
uint product(uint a,uint b)const{
	ull z=ull(a)*b;
	uint x=((unsigned __int128)z*im)>>64;
	uint v=uint(z)-x*mod;
	return v<mod?v:v+mod;
}
#endif
};
template<modinfo const&ref>
struct modular{
	static constexpr uint const &mod=ref.mod;
	static modular root(){return modular(ref.root);}
	uint v;
	//modular(initializer_list<uint>ls):v(*ls.bg){}
	modular(ll vv=0){s(vv%mod+mod);}
	modular& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	modular operator-()const{return modular()-*this;}
	modular& operator+=(const modular&rhs){return s(v+rhs.v);}
	modular&operator-=(const modular&rhs){return s(v+mod-rhs.v);}
	modular&operator*=(const modular&rhs){
		#ifndef DYNAMIC_MOD
		v=ull(v)*rhs.v%mod;
		#else
		v=ref.product(v,rhs.v);
		#endif
		return *this;
	}
	modular&operator/=(const modular&rhs){return *this*=rhs.inv();}
	modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}
	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
	modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}
	modular pow(ll n)const{
		modular res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	modular inv()const{return pow(mod-2);}
	/*modular inv()const{
		int x,y;
		int g=extgcd<ll>(v,mod,x,y);
		assert(g==1);
		if(x<0)x+=mod;
		return modular(x);
	}*/
	friend modular operator+(int x,const modular&y){
		return modular(x)+y;
	}
	friend modular operator-(int x,const modular&y){
		return modular(x)-y;
	}
	friend modular operator*(int x,const modular&y){
		return modular(x)*y;
	}
	friend modular operator/(int x,const modular&y){
		return modular(x)/y;
	}
	friend ostream& operator<<(ostream&os,const modular&m){
		return os<<m.v;
	}
	friend istream& operator>>(istream&is,modular&m){
		ll x;is>>x;
		m=modular(x);
		return is;
	}
	bool operator<(const modular&r)const{return v<r.v;}
	bool operator==(const modular&r)const{return v==r.v;}
	bool operator!=(const modular&r)const{return v!=r.v;}
	explicit operator bool()const{
		return v;
	}
};

#ifndef DYNAMIC_MOD
extern constexpr modinfo base{998244353,3};
//extern constexpr modinfo base{1000000007,0};
//modinfo base{1,0};
#ifdef USE_GOOD_MOD
static_assert(base.mod==998244353);
#endif
#else
modinfo base(1,0);
extern constexpr modinfo base107(1000000007,0);
using mint107=modular<base107>;
#endif
using mint=modular<base>;

const int vmax=(1<<21)+10;
mint fact[vmax],finv[vmax],invs[vmax];
void initfact(){
	fact[0]=1;
	rng(i,1,vmax){
		fact[i]=fact[i-1]*i;
	}
	finv[vmax-1]=fact[vmax-1].inv();
	for(int i=vmax-2;i>=0;i--){
		finv[i]=finv[i+1]*(i+1);
	}
	for(int i=vmax-1;i>=1;i--){
		invs[i]=finv[i]*fact[i-1];
	}
}
mint choose(int n,int k){
	return fact[n]*finv[n-k]*finv[k];
}
mint binom(int a,int b){
	return fact[a+b]*finv[a]*finv[b];
}
mint catalan(int n){
	return binom(n,n)-(n-1>=0?binom(n-1,n+1):0);
}

/*
const int vmax=110;
mint binbuf[vmax][vmax];
mint choose(int n,int k){
	return binbuf[n-k][k];
}
mint binom(int a,int b){
	return binbuf[a][b];
}
void initfact(){
	binbuf[0][0]=1;
	rep(i,vmax)rep(j,vmax){
		if(i)binbuf[i][j]+=binbuf[i-1][j];
		if(j)binbuf[i][j]+=binbuf[i][j-1];
	}
}
*/

//sz: size of the matching
//mt[i]: matching mate of the vertex i
//VERIFY: yosupo
//NEERC2018B
//Petrozavodsk 2019w Day1 A
struct maxmatching{
	struct E{int a,b;};
	const vvc<int>&g;
	int n,sz;
	vi p,t,mt;
	vc<E> f;
	int non(int v){
		return t[v]!=sz||p[v]==-1?v:(p[v]=non(p[v]));
	}
	void R(int a,int b){
		int d=mt[a];
		mt[a]=b;
		if(d==-1||mt[d]!=a)return;
		if(f[a].b==-1){
			mt[d]=f[a].a;
			R(f[a].a,d);
		}else{
			R(f[a].a,f[a].b);
			R(f[a].b,f[a].a);
		}
	}
	bool arg(int rt){
		queue<int> q;
		t[rt]=sz;
		p[rt]=-1;
		f[rt]=E{-1,-1};
		q.push(rt);
		while(!q.empty()){
			int a=q.front();q.pop();
			for(auto b:g[a]){
				if(b==rt)continue;
				if(mt[b]==-1){
					mt[b]=a;
					R(a,b);
					return true;
				}
				if(t[b]==sz){
					int x=non(a),y=non(b);
					if(x==y)continue;
					int z=rt;
					while(x!=rt||y!=rt){
						if(y!=rt)swap(x,y);
						if(f[x].a==a&&f[x].b==b){
							z=x;
							break;
						}
						f[x]=E{a,b};
						x=non(f[mt[x]].a);
					}
					for(auto v:{non(a),non(b)}){
						while(v!=z){
							t[v]=sz;
							p[v]=z;
							q.push(v);
							v=non(f[mt[v]].a);
						}
					}
					continue;
				}
				if(t[mt[b]]==sz)continue;
				f[b]=E{-1,-1};
				t[mt[b]]=sz;
				p[mt[b]]=b;
				f[mt[b]]=E{a,-1};
				q.push(mt[b]);
			}
		}
		return false;
	}
	maxmatching(const vvc<int>&gg):g(gg),n(g.size()),sz(0),
		p(n),t(n,-1),mt(n,-1),f(n){
		rep(i,n)if(mt[i]==-1)
			sz+=arg(i);
	}
	//codechef HAMILG
	//res[i]= 1,  0
	vi need(){
		rep(i,n)if(mt[i]==-1)
			arg(i);
		vi res(n);
		rep(i,n)res[i]=(mt[i]!=-1&&t[i]!=sz);
		return res;
	}
};

//s: the number of SCCs.
//bl[i]: SCC to which the vertex i belongs
//idx[i]: list of the vertices in the i-th SCC
//da: DAG of SCCs
//SCCs are numbered in topological order
//VERIFY: yosupo
//AOJGRL3C(except gr)
template<class t>
struct scc{
	const int n;
	const vvc<t>&g;
	vi ord,low,bl,st;
	int s,head;
	vvc<int> idx,da;
	void dfs(int v){
		ord[v]=low[v]=head++;
		st.pb(v);
		for(auto to:g[v]){
			if(ord[to]==-1){
				dfs(to);
				chmin(low[v],low[to]);
			}else if(bl[to]==-1)
				chmin(low[v],ord[to]);
		}
		if(ord[v]==low[v]){
			int c=idx.size();
			idx.eb();
			while(1){
				int a=st.back();
				st.pop_back();
				bl[a]=c;
				idx.back().pb(a);
				if(v==a)break;
			}
		}
	}
	scc(const vvc<t>&gg,bool cgr=true):n(gg.size()),g(gg),
		ord(n,-1),low(n,-1),bl(n,-1){
		head=0;
		rep(i,n)if(ord[i]==-1)
			dfs(i);
		s=idx.size();
		rep(i,n)
			bl[i]=s-1-bl[i];
		reverse(all(idx));
		//construct the graph
		if(cgr){
			vc<bool> u(s);
			da.resize(s);
			rep(i,s){
				for(auto v:idx[i]){
					for(auto to:g[v])if(bl[v]<bl[to]){
						if(!u[bl[to]])
							da[bl[v]].pb(bl[to]);
						u[bl[to]]=1;
					}
				}
				for(auto v:idx[i])
					for(auto to:g[v])
						u[bl[to]]=0;
			}
		}
	}
};
struct E{
	int to,cost;
	operator int()const{return to;}
};

struct twosat{
	int n;
	vvc<int> g;
	twosat(int nn):n(nn),g(n*2){}
	//x/2 x%2  0,1 
	// x,y 
	void add(int x,int y){
		g[x^1].pb(y);
		g[y^1].pb(x);
	}
	//solve the 2-sat
	// 0/1 
	// {} 
	vi solve(){
		scc<int> s(g,false);
		rep(i,n)if(s.bl[i*2]==s.bl[i*2+1])return {};
		vi res(n,-1);
		per(i,s.s)
			for(auto j:s.idx[i])
				if(res[j/2]==-1)
					res[j/2]=j%2;
		return res;
	}
};

//VERIFY: yosupo
//KUPC2017J
//AOJDSL1A
//without rank
struct unionfind{
	vi p,s;
	int c;
	unionfind(int n):p(n,-1),s(n,1),c(n){}
	int find(int a){
		return p[a]==-1?a:(p[a]=find(p[a]));
	}
	//set b to a child of a
	bool unite(int a,int b){
		a=find(a);
		b=find(b);
		if(a==b)return false;
		p[b]=a;
		s[a]+=s[b];
		c--;
		return true;
	}
	bool same(int a,int b){
		return find(a)==find(b);
	}
	int sz(int a){
		return s[find(a)];
	}
};

void slv(){
	int n;cin>>n;
	vvc<int> ps(2*n);
	rep(i,2*n)ps[i]=readvi(n,-1);
	vvc<bool> col(2*n,vc<bool>(2*n));
	rep(i,2*n)rep(j,i){
		bool z=false;
		rep(k,n)if(ps[i][k]==ps[j][k]){
			z=true;
			break;
		}
		col[i][j]=col[j][i]=z;
	}
	n*=2;
	/*{//counting
		unionfind uf(n),bp(2*n);
		rep(i,n)rep(j,i)if(col[i][j]){
			uf.unite(i,j);
			bp.unite(i*2,j*2+1);
			bp.unite(i*2+1,j*2);
			if(10<=i)dmp2(i,j);
		}
		mint ans=1;
		rep(i,n)if(uf.find(i)==i&&!bp.same(i*2,i*2+1))ans*=2;
		print(ans);
	}*/
	{
		vvc<int> g(n);
		rep(i,n)rep(j,i)if(col[i][j]){
			g[i].pb(j);
			g[j].pb(i);
		}
		maxmatching mm(g);
		vc<array<int,2>> ls;
		rep(i,n)if(i<mm.mt[i]){
			ls.pb({i,mm.mt[i]});
		}
		assert(si(ls)==n/2);
		
		twosat ts(n/2);
		rep(i,n/2)rep(j,i)rep(a,2)rep(b,2){
			if(col[ls[i][a]][ls[j][b]]){
				ts.add(i*2+(1-a),j*2+(1-b));
			}
		}
		auto res=ts.solve();
		assert(si(res));
		rep(i,n/2)if(res[i])swap(ls[i][0],ls[i][1]);
		
		dmp(ls);
		
		{
			mint ans=1;
			vvc<int> h(n/2);
			rep(i,n/2)rep(j,n/2)if(i!=j){
				bool has=false;
				rep(k,n/2){
					if(ps[ls[i][0]][k]!=ps[ls[i][1]][k]&&ps[ls[i][1]][k]==ps[ls[j][0]][k])
						has=true;
				}
				if(has){
					dmp2(i,j);
					h[i].pb(j);
				}
			}
			scc<int> z(h);
			rep(i,z.s){
				if(z.da[i].empty()){
					const vi&idx=z.idx[i];
					dmp(idx);
					vi cnt(n/2);
					int nonzero=0;
					auto ch=[&](int val,int w){
						nonzero-=bool(cnt[val]);
						cnt[val]+=w;
						nonzero+=bool(cnt[val]);
					};
					bool ok=true;
					rep(pos,n/2){
						for(auto j:idx){
							ch(ps[ls[j][0]][pos],1);
							ch(ps[ls[j][1]][pos],-1);
						}
						if(nonzero)ok=false;
						for(auto j:idx){
							ch(ps[ls[j][0]][pos],-1);
							ch(ps[ls[j][1]][pos],1);
						}
					}
					if(ok){
						ans*=2;
						dmp(idx);
					}
				}
			}
			print(ans);
		}
		
		{
			vi sol(n/2);
			rep(i,n/2)sol[i]=ls[i][0];
			print_offset(sol,1);
		}
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int t;cin>>t;rep(_,t)
	slv();
}