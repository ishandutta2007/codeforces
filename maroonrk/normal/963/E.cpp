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

using uint=unsigned;
using ull=unsigned long long;

struct modinfo{uint mod,root;};
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
		v=ull(v)*rhs.v%mod;
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
		int g=extgcd(v,mod,x,y);
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

//constexpr modinfo base{998244353,3};
constexpr modinfo base{1000000007,0};
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

//VERIFY: yosupo
mint det(vvc<mint> a){
	const int n=a.size();
	mint ans(1);
	rep(i,n){
		rng(j,i+1,n)if(a[j][i].v){
			ans=-ans;
			swap(a[j],a[i]);
			break;
		}
		if(!a[i][i].v)return 0;
		ans*=a[i][i];
		rng(j,i+1,n){
			mint w=-a[j][i]/a[i][i];
			rng(k,i,n)
				a[j][k]+=a[i][k]*w;
		}
	}
	return ans;
}

//csweep
//arank
//
vi sweep(vvc<mint>&a,int c=-1){
	if(a.empty())return {};
	if(c==-1)c=a[0].size();
	int h=a.size(),w=a[0].size(),r=0;
	vi res;
	rep(i,c){
		if(r==h)break;
		rng(j,r,h)if(a[j][i].v){
			swap(a[r],a[j]);
			break;
		}
		if(a[r][i].v==0)continue;
		rep(j,h)if(j!=r){
			mint z=-a[j][i]/a[r][i];
			rng(k,i,w)
				a[j][k]+=a[r][k]*z;
		}
		res.pb(i);
		r++;
	}
	return res;
}

//
//kernel
//aaw
// {} 
vc<mint> lineareq(vvc<mint> a,int w,vc<mint> b){
	int h=a.size();
	rep(i,h)a[i].pb(b[i]);
	vi idx=sweep(a,w);
	rng(i,idx.size(),h)
		if(a[i][w].v)return {};
	vc<mint> res(w);
	rep(i,idx.size())
		res[idx[i]]=a[i][w]/a[i][idx[i]];
	return res;
}

//yosupo system of linear equations
//ker(a)
//aaw
vvc<mint> kernel(const vvc<mint>&a,int w){
	int h=a.size();
	vvc<mint> b(w,vc<mint>(h+w));
	rep(i,h)rep(j,w)b[j][i]=a[i][j];
	rep(i,w)b[i][h+i]=1;
	int r=sweep(b,h).size();
	vvc<mint> res;
	rng(i,r,w)res.eb(b[i].bg+h,b[i].ed);
	return res;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int r;cin>>r;
	mint left,down,right,up;
	{
		vi a=readvi(4);
		int s=accumulate(all(a),0);
		left=mint(a[0])/s;
		down=mint(a[1])/s;
		right=mint(a[2])/s;
		up=mint(a[3])/s;
	}
	mint rinv=right.inv();
	
	vvc<vc<mint>> buf(2*r+1,vvc<mint>(2*r+1));
	vvc<int> dec(2*r+1,vi(2*r+1));
	
	int num=1;
	auto getbuf=[&](int x,int y)->vc<mint>{
		if(sq(x)+sq(y)>sq(r))return {0};
		if(!dec[x+r][y+r]){
			dec[x+r][y+r]=1;
			num++;
			vc<mint> res(num);
			res[num-1]=1;
			return buf[x+r][y+r]=res;
		}
		return buf[x+r][y+r];
	};
	auto setbuf=[&](int x,int y,const vc<mint>&v){
		assert((sq(x)+sq(y)<=sq(r)));
		assert(!dec[x+r][y+r]);
		dec[x+r][y+r]=1;
		buf[x+r][y+r]=v;
	};
	auto addvec=[&](const vc<mint>&a,const vc<mint>&b){
		int s=max(si(a),si(b));
		vc<mint> c(s);
		rep(i,s){
			if(i<si(a))c[i]+=a[i];
			if(i<si(b))c[i]+=b[i];
		}
		return c;
	};
	auto multvec=[&](vc<mint> a,mint w){
		for(auto&v:a)v*=w;
		return a;
	};
	
	vvc<mint> eq;
	rng(x,-r,r+1)rng(y,-r,r+1){
		if(sq(x)+sq(y)<=sq(r)){
			vc<mint> z=getbuf(x,y);
			z[0]-=1;
			z=addvec(z,multvec(getbuf(x-1,y),-left));
			z=addvec(z,multvec(getbuf(x,y-1),-down));
			z=addvec(z,multvec(getbuf(x,y+1),-up));
			z=multvec(z,rinv);
			if(sq(x+1)+sq(y)<=sq(r)){
				setbuf(x+1,y,z);
			}else{
				eq.pb(z);
			}
		}
	}
	
	assert(num>1);
	vvc<mint> a;
	vc<mint> b;
	for(auto v:eq){
		a.eb(num-1);
		rng(i,1,si(v))a.back()[i-1]=v[i];
		b.pb(-v[0]);
	}
	
	auto ans=lineareq(a,num-1,b);
	assert(ans.size());
	vc<mint> z=getbuf(0,0);
	mint out=z[0];
	rng(i,1,si(z))out+=z[i]*ans[i-1];
	cout<<out<<endl;
}