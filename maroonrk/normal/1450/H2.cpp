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

//#define DYNAMIC_MOD

struct modinfo{uint mod,root;
#ifdef DYNAMIC_MOD
ull im;
void set_mod(uint m){
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
	modular pow(int n)const{
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
#else
modinfo base{1,0,0};
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

template<class Query>
struct chronological_segtree{
	int n,s;
	vvc<Query> qs;
	chronological_segtree(int nn){
		n=nn;
		s=1;
		while(s<n)s*=2;
		qs.resize(s*2);
	}
	void add(int l,int r,Query q){
		dmp2(l,r,q);
		for(l+=s,r+=s;l<r;l>>=1,r>>=1){
			if (l&1){
				qs[l].pb(q);
				l++;
			}
			if (r&1){
				r--;
				qs[r].pb(q);
			}
		}
	}
	template<class F,class G,class H,class I>
	void solve(F f,G snapshot,H rollback,I getans){
		auto rec=[&](auto self,int i,int l,int r)->void{
			auto ss=snapshot();
			for(const auto&q:qs[i])
				f(q);
			if(i<s){
				self(self,i*2,l,(l+r)/2);
				self(self,i*2+1,(l+r)/2,r);
			}else if(i-s<n){
				getans(i-s);
			}
			rollback(ss);
		};
		rec(rec,1,0,s);
	};
};

//using A=array<array<int,4>,2>;

void slv(){
	int n,m;cin>>n>>m;
	string str;cin>>str;
	vi z;
	for(auto c:str){
		if(c=='w')z.pb(0);
		else if(c=='b')z.pb(1);
		else z.pb(-1);
	}
	int off=-n/2,w=0;
	rep(i,n){
		if(z[i]==-1){
			w++;
		}else{
			if(z[i]==i%2)off++;
		}
	}
	//00
	//even,odd
	//way,ans
	//mint a[2][2][2];
	using A=array<array<array<mint,2>,2>,2>;
	A a;
	a[0][0][0]=1;
	a[0][0][1]=n/2;
	auto output_answer=[&](int i){
		dmp2(i,w,off);
		mint ans,way;
		rep(k,2){
			way+=a[k][off&1][0];
			ans+=a[k][off&1][1];
		}
		ans*=invs[2];
		print(ans/way);
	};
	//00
	//even,odd
	//way,ans
	/*auto decrement_off=[&](){
		int k=-off;
		if(inc(0,k,w)){
			a[0][k&1][0]+=choose(w,k);
			a[1][k&1][0]-=choose(w,k);
		}
		rep(j,2)a[0][j][1]+=a[0][j][0];
		rep(j,2)a[1][j][1]-=a[1][j][0];
		off--;
	};*/
	//00
	//even,odd
	//way,ans
	auto increment_off=[&](){
		off++;
		rep(j,2)a[0][j][1]-=a[0][j][0];
		rep(j,2)a[1][j][1]+=a[1][j][0];
		int k=-off;
		if(inc(0,k,w)){
			a[0][k&1][0]-=choose(w,k);
			a[1][k&1][0]+=choose(w,k);
		}
	};
	//00
	//even,odd
	//way,ans
	auto increment_w=[&](){
		w++;
		A b;
		rep(i,2)rep(j,2){
			rep(k,2)b[i][j][k]+=a[i][j][k];
			rep(k,2)b[i][j^1][k]+=a[i][j][k];
			if(i==0)b[i][j^1][1]-=a[i][j][0];
			else b[i][j^1][1]+=a[i][j][0];
		}
		int k=-off;
		if(inc(1,k,w)){
			mint way=choose(w-1,k-1);
			b[0][k&1][0]-=way;
			b[1][k&1][0]+=way;
		}
		swap(b,a);
	};
	vi win(n,0),oin(n);
	chronological_segtree<int> seg(m+1);
	//output_answer();
	dmp(z);
	rng(pos,1,m+1){
		int i;cin>>i;i--;
		char cccc=readString()[0];
		int c=cccc=='w'?0:(cccc=='b'?1:-1);
		if(z[i]==-1){
			//decrement_w();
			w--;
			seg.add(win[w],pos,0);
		}else{
			if(z[i]==i%2){
				//decrement_off();
				off--;
				seg.add(oin[off+n/2],pos,1);
			}
		}
		z[i]=c;
		if(z[i]==-1){
			//increment_w();
			win[w]=pos;
			w++;
		}else{
			if(z[i]==i%2){
				//increment_off();
				oin[off+n/2]=pos;
				off++;
			}
		}
		//output_answer();
		dmp2(i,z);
	}
	while(w>0){
		w--;
		seg.add(win[w],seg.s,0);
	}
	while(off>-n/2){
		off--;
		seg.add(oin[off+n/2],seg.s,1);
	}
	using T=tuple<A,int,int>;
	seg.solve([&](int t){
		if(t==0)increment_w();
		else increment_off();
	},[&](){
		return mt(a,w,off);
	},[&](T t){
		tie(a,w,off)=t;
	},output_answer);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	initfact();
	//int t;cin>>t;rep(_,t)
	slv();
}