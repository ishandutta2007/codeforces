#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=a;i--)
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

using uint=unsigned;
using ull=unsigned long long;

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
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
    static random_device rd;
    static mt19937 gen(rd());
    return uniform_int_distribution<ll>(l, r)(gen);
}

using uint=unsigned;
using ull=unsigned long long;

//const uint mod=998244353;
const uint mod=1000000007;
//uint mod=1;
struct mint{
	uint v;
	mint(ll vv=0){s(vv%mod+mod);}
	mint& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	mint operator-()const{return mint()-*this;}
	mint& operator+=(const mint&rhs){return s(v+rhs.v);}
	mint&operator-=(const mint&rhs){return s(v+mod-rhs.v);}
	mint&operator*=(const mint&rhs){
		v=ull(v)*rhs.v%mod;
		return *this;
	}
	mint&operator/=(const mint&rhs){return *this*=rhs.inv();}
	mint operator+(const mint&rhs)const{return mint(*this)+=rhs;}
	mint operator-(const mint&rhs)const{return mint(*this)-=rhs;}
	mint operator*(const mint&rhs)const{return mint(*this)*=rhs;}
	mint operator/(const mint&rhs)const{return mint(*this)/=rhs;}
	mint pow(int n)const{
		mint res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	mint inv()const{return pow(mod-2);}
	/*mint inv()const{
		int x,y;
		int g=extgcd(v,mod,x,y);
		assert(g==1);
		if(x<0)x+=mod;
		return mint(x);
	}*/
	friend ostream& operator<<(ostream&os,const mint&m){
		return os<<m.v;
	}
	bool operator<(const mint&r)const{return v<r.v;}
	bool operator==(const mint&r)const{return v==r.v;}
};

const int vcmax=(1<<21)+10;
mint fact[vcmax],finv[vcmax],invs[vcmax];
void initfact(){
	fact[0]=1;
	rng(i,1,vcmax){
		fact[i]=fact[i-1]*i;
	}
	finv[vcmax-1]=fact[vcmax-1].inv();
	for(int i=vcmax-2;i>=0;i--){
		finv[i]=finv[i+1]*(i+1);
	}
	for(int i=vcmax-1;i>=1;i--){
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

//CF Global3 H
//point update
template<class T,class F>
struct SegTree{
	vc<T> buf;
	int s;
	const F f;
	const T g;
	SegTree(const vc<T>& d,F ff,T gg):f(ff),g(gg){
		int n=d.size();
		s=1;
		while(s<n)s*=2;
		buf.resize(s*2,g);
		rep(i,n)
			buf[i+s]=d[i];
		gnr(i,1,s)
			u(i);
	}
	void u(int i){
		buf[i]=f(buf[i*2],buf[i*2+1]);
	}
	void set(int i,T t){
		i+=s;
		buf[i]=t;
		while(i>>=1)u(i);
	}
	T get(int b,int e,int l,int r,int i){
		if(e<=l||r<=b)return g;
		if(b<=l&&r<=e)return buf[i];
		int m=(l+r)/2;
		return f(get(b,e,l,m,i*2),get(b,e,m,r,i*2+1));
	}
	T get(int b,int e){
		return get(b,e,0,s,1);
	}
};
template<class T,class F>
SegTree<T,F> segtree(const vc<T>& d,F f,T g){
	return SegTree<T,F>(d,f,g);
}

//KUPC2017I
//HDU 5306 Gorgeous Sequence
template<class N>
struct segbeats{
	vc<N> x;
	int s;
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
	void chr(int l,int r,int i,int b,int e,F f,Args... args){
		if(e<=l||r<=b)
			return;
		if(b<=l&&r<=e&&(x[i].*f)(args...))
			return;
		push(i);
		int m=(l+r)/2;
		chr(l,m,i*2,b,e,f,args...);
		chr(m,r,i*2+1,b,e,f,args...);
		upd(i);
	}
	template<class F,class... Args>
	void ch(int b,int e,F f,Args... args){
		assert(b<e);
		chr(0,s,1,b,e,f,args...);
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
		assert(b<e);
		return getr(0,s,1,b,e,f,g,h);
	}
	//return minimum index
	template<class F,class...Args>
	pair<int,N> findr(int i,int l,int r,int b,int e,F f,Args&...args){
		if(e<=l||r<=b)return {e,N()};
		if(b<=l&&r<=e){
			if(!(x[i].*f)(args...))return {e,N()};
			if(r-l==1)return {l,x[i]};
		}
		push(i);
		int m=(l+r)/2;
		auto a=findr(i*2,l,m,b,e,f,args...);
		if(a.a<e)return a;
		return findr(i*2+1,m,r,b,e,f,args...);
	}
	template<class F,class...Args>
	pair<int,N> find(int b,int e,F f,Args&...args){
		assert(b<e);
		return findr(1,0,s,b,e,f,args...);
	}
};

//usage

//point set,range query sum lower_bound
struct N{
	int s;
	N(int v=0):s(v){}
	bool set(int v){
		s=v;
		return true;
	}
	void push(N&,N&){
	}
	static N merge(N x,N y){
		return N(x.gets()+y.gets());
	}
	int gets(){return s;}
	bool find(int&v){
		if(s<v){
			v-=s;
			return false;
		}
		return true;
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,q;cin>>n>>q;
	vi a=readvi(n);
	rep(i,n)a[i]-=i;
	vi w=readvi(n);
	
	segbeats<N> seg1(w);
	vc<mint> aw(n);
	rep(i,n)aw[i]=a[i]*w[i];
	auto seg2=segtree(aw,[](mint x,mint y){return x+y;},mint(0));
	
	rep(_,q){
		int x,y;cin>>x>>y;
		if(x<0){
			x=-x-1;
			aw[x]=a[x]*(w[x]=y);
			seg1.ch(x,x+1,&N::set,w[x]);
			seg2.set(x,aw[x]);
		}else{
			x--;
			dmp(x);
			dmp(y);
			dmp(accumulate(w.bg+x,w.bg+y,int(0)));
			dmp(w);
			int s=seg1.get(x,y,&N::gets,[](int p,int r){return p+r;},int(0));
			int h=(s+1)/2;
			dmp(s);
			dmp(h);
			int m=seg1.find(x,y,&N::find,h).a;
			dmp(m);
			dmp(h);
			mint lw=seg1.get(x,m+1,&N::gets,[](int p,int r){return p+r;},int(0));
			mint law=seg2.get(x,m+1);
			mint rw=seg1.get(m,y,&N::gets,[](int p,int r){return p+r;},int(0));
			mint raw=seg2.get(m,y);
			mint ans=lw*a[m]-law+raw-rw*a[m];
			print(ans.v);
			/*int ans=inf;
			rng(m,x,y){
				mint lw=seg1.get(x,m+1,&N::gets,[](int p,int r){return p+r;},int(0));
				mint law=seg2.get(x,m+1);
				mint rw=seg1.get(m,y,&N::gets,[](int p,int r){return p+r;},int(0));
				mint raw=seg2.get(m,y);
				chmin(ans,(lw*a[m]-law+raw-rw*a[m]).v);
			}
			print(ans);*/
		}
	}
}