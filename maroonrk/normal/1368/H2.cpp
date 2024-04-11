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

//merge  inactive 
//lazy 

//get 
// min  0  1 

//VERIFY: yosupo
//KUPC2017I
//HDU 5306 Gorgeous Sequence
//findmin/max CF458E
template<class N>
struct segbeats{
	vc<N> x;
	int s;
	segbeats(){}
	template<class T>
	segbeats(const vc<T>& a){
		int n=a.size();
		s=1;
		while(s<n)s*=2;
		x.resize(s*2);
		rep(i,n)
			x[s+i]=N(a[i]);
		gnr(i,1,s)
			upd(i);
	}
	void push(int i){
		x[i].push(x[i*2],x[i*2+1]);
	}
	void upd(int i){
		x[i]=N::merge(x[i*2],x[i*2+1]);
	}
	template<class F,class... Args>
	void chr(int l,int r,int i,int b,int e,F f,Args&&... args){
		if(e<=l||r<=b)
			return;
		if(b<=l&&r<=e&&(x[i].*f)(forward<Args>(args)...))
			return;
		push(i);
		int m=(l+r)/2;
		chr(l,m,i*2,b,e,f,forward<Args>(args)...);
		chr(m,r,i*2+1,b,e,f,forward<Args>(args)...);
		upd(i);
	}
	template<class F,class... Args>
	void ch(int b,int e,F f,Args&&... args){
		assert(b<=e);
		chr(0,s,1,b,e,f,forward<Args>(args)...);
	}
	//use decltype((declval<N>().*F())()) for old-fashioned judges
	template<class F,class G,class H>
	auto getr(int l,int r,int i,int b,int e,F f,G g,H h){
		if(e<=l||r<=b)
			return h;
		if(b<=l&&r<=e)
			return (x[i].*f)();
		push(i);
		int m=(l+r)/2;
		return g(getr(l,m,i*2,b,e,f,g,h),getr(m,r,i*2+1,b,e,f,g,h));
	}
	template<class F,class G,class H>
	auto get(int b,int e,F f,G g,H h){
		assert(b<=e);
		return getr(0,s,1,b,e,f,g,h);
	}
	auto compositer(int l,int r,int i,int b,int e){
		if(e<=l||r<=b)assert(0);
		if(b<=l&&r<=e)
			return x[i];
		push(i);
		int m=(l+r)/2;
		if(e<=m)return compositer(l,m,i*2,b,e);
		if(m<=b)return compositer(m,r,i*2+1,b,e);
		return N::merge(compositer(l,m,i*2,b,e),compositer(m,r,i*2+1,b,e));
	}
	//work without identity node
	auto composite(int b,int e){
		assert(b<e);
		return compositer(0,s,1,b,e);
	}
	//return minimum index
	template<class F,class...Args>
	pair<int,N> findminr(int i,int l,int r,int b,int e,F f,Args&&...args){
		if(e<=l||r<=b)return {e,N()};
		if(b<=l&&r<=e){
			if(!(x[i].*f)(forward<Args>(args)...))return {e,N()};
			if(r-l==1)return {l,x[i]};
		}
		push(i);
		int m=(l+r)/2;
		auto a=findminr(i*2,l,m,b,e,f,forward<Args>(args)...);
		if(a.a<e)return a;
		return findminr(i*2+1,m,r,b,e,f,forward<Args>(args)...);
	}
	template<class F,class...Args>
	pair<int,N> findmin(int b,int e,F f,Args&&...args){
		assert(b<=e);
		return findminr(1,0,s,b,e,f,forward<Args>(args)...);
	}
	//return maximum index
	template<class F,class...Args>
	pair<int,N> findmaxr(int i,int l,int r,int b,int e,F f,Args&&...args){
		if(e<=l||r<=b)return {b-1,N()};
		if(b<=l&&r<=e){
			if(!(x[i].*f)(forward<Args>(args)...))return {b-1,N()};
			if(r-l==1)return {l,x[i]};
		}
		push(i);
		int m=(l+r)/2;
		auto a=findmaxr(i*2+1,m,r,b,e,f,forward<Args>(args)...);
		if(a.a>=b)return a;
		return findmaxr(i*2,l,m,b,e,f,forward<Args>(args)...);
	}
	template<class F,class...Args>
	pair<int,N> findmax(int b,int e,F f,Args&&...args){
		assert(b<=e);
		return findmaxr(1,0,s,b,e,f,forward<Args>(args)...);
	}
	void enumerater(int l,int r,int i,int b,int e,vc<N>&dst){
		if(e<=l||r<=b)
			return;
		if(l+1==r){
			dst.pb(x[i]);
			return;
		}
		push(i);
		int m=(l+r)/2;
		enumerater(l,m,i*2,b,e,dst);
		enumerater(m,r,i*2+1,b,e,dst);
	}
	void enumerate(int b,int e,vc<N>&dst){
		assert(b<=e);
		return enumerater(0,s,1,b,e,dst);
	}
	void prepare(int i){
		if(i/=2){
			prepare(i);
			push(i);
		}
	}
	//point_update  lazy 
	void point_update(int i,N w){
		i+=s;
		prepare(i);
		x[i]=w;
		while(i/=2)
			upd(i);
	}
};

struct N{
	int a[2],lz;
	N(int v=0):a{1-v,v},lz(0){}
	bool flip(){
		swap(a[0],a[1]);
		lz^=1;
		return true;
	}
	void push(N&x,N&y){
		if(lz){
			x.flip();
			y.flip();
		}
		lz=0;
	}
	static N merge(N x,N y){
		N res;
		rep(i,2)res.a[i]=x.a[i]+y.a[i];
		return res;
	}
	int get0(){return a[0];}
};

int curHeight;

struct M{
	int a[4][2][2],lz;
	M(int v=0):lz(0){
		rep(i,4){
			int x=v^i;
			rep(j,2){
				a[i][j][j]=popcount(x^(3*j));
			}
			rep(j,2)a[i][j][j^1]=inf;
		}
	}
	bool flip(int v){
		rep(i,4){
			int j=i^v;
			if(i<j)swap(a[i],a[j]);
		}
		lz^=v;
		return true;
	}
	void push(M&x,M&y){
		x.flip(lz);
		y.flip(lz);
		lz=0;
	}
	static M merge(M x,M y){
		M res;
		rep(i,4){
			rep(j,2)rep(k,2)res.a[i][j][k]=inf;
			rep(j,2)rep(k,2)rep(l,2)rep(m,2){
				chmin(res.a[i][j][m],x.a[i][j][k]+y.a[i][l][m]+abs(k-l)*curHeight);
			}
		}
		return res;
	}
};

struct slv{
	int n,m;
	segbeats<N> vert[2];
	segbeats<M> hori;
	void init(vc<string> vt,vc<string> hr){
		n=si(vt[0]);
		m=si(hr[0]);
		curHeight=n;
		
		vi z(m);
		rep(i,m)rep(j,2)
			if(hr[j][i]=='B')z[i]+=1<<j;
		hori=segbeats<M>(z);
		rep(i,2){
			vi w(n);
			rep(j,n)if(vt[i][j]=='B')
				w[j]=1;
			vert[i]=segbeats<N>(w);
		}
	}
	int getans(){
		curHeight=n;
		
		M res=hori.composite(0,m);
		int a[2][2];
		rep(i,2){
			a[i][1]=vert[i].composite(0,n).get0();
			a[i][0]=n-a[i][1];
		}
		int ans=inf;
		rep(i,2)rep(j,2){
			chmin(ans,res.a[0][i][j]+a[0][i]+a[1][j]);
		}
		return ans;
	}
	void updL(int l,int r){
		curHeight=n;
		
		vert[0].ch(l,r,&N::flip);
	}
	void updR(int l,int r){
		curHeight=n;
		
		vert[1].ch(l,r,&N::flip);
	}
	void updU(int l,int r){
		curHeight=n;
		
		hori.ch(l,r,&M::flip,1);
	}
	void updD(int l,int r){
		curHeight=n;
		
		hori.ch(l,r,&M::flip,2);
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,m;cin>>n>>m;
	int q;cin>>q;
	vc<string> vt(2),hr(2);
	rep(i,2)cin>>vt[i];
	rep(i,2)cin>>hr[i];
	
	slv ysp[2];
	ysp[0].init(vt,hr);
	ysp[1].init(hr,vt);
	
	rep(_,q+1){
		if(_){
			char t=readString()[0];
			int l,r;cin>>l>>r;
			l--;
			if(t=='U'){
				ysp[0].updU(l,r);
				ysp[1].updL(l,r);
			}else if(t=='D'){
				ysp[0].updD(l,r);
				ysp[1].updR(l,r);
			}else if(t=='L'){
				ysp[0].updL(l,r);
				ysp[1].updU(l,r);
			}else if(t=='R'){
				ysp[0].updR(l,r);
				ysp[1].updD(l,r);
			}else assert(0);
		}
		int ans=inf;
		rep(i,2){
			chmin(ans,ysp[i].getans());
		}
		print(ans);
	}
}