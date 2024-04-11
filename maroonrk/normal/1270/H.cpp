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

//b==e 
//b==e 
//

//KUPC2017I
//HDU 5306 Gorgeous Sequence
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
	//return minimum index
	template<class F,class...Args>
	pair<int,N> findr(int i,int l,int r,int b,int e,F f,Args&&...args){
		if(e<=l||r<=b)return {e,N()};
		if(b<=l&&r<=e){
			if(!(x[i].*f)(forward<Args>(args)...))return {e,N()};
			if(r-l==1)return {l,x[i]};
		}
		push(i);
		int m=(l+r)/2;
		auto a=findr(i*2,l,m,b,e,f,forward<Args>(args)...);
		if(a.a<e)return a;
		return findr(i*2+1,m,r,b,e,f,forward<Args>(args)...);
	}
	//NOT VERIFIED
	template<class F,class...Args>
	pair<int,N> find(int b,int e,F f,Args&&...args){
		assert(b<=e);
		return findr(1,0,s,b,e,f,forward<Args>(args)...);
	}
	//NOT VERIFIED
	/*
	//return maximum index
	template<class F,class...Args>
	pair<int,N> findr(int i,int l,int r,int b,int e,F f,Args&&...args){
		if(e<=l||r<=b)return {b-1,N()};
		if(b<=l&&r<=e){
			if(!(x[i].*f)(args...))return {b-1,N()};
			if(r-l==1)return {l,x[i]};
		}
		push(i);
		int m=(l+r)/2;
		auto a=findr(i*2+1,m,r,b,e,f,forward<Args>(args)...);
		if(a.a>=b)return a;
		return findr(i*2,l,m,b,e,f,forward<Args>(args)...);
	}
	template<class F,class...Args>
	pair<int,N> find(int b,int e,F f,Args&&...args){
		assert(b<=e);
		return findr(1,0,s,b,e,f,forward<Args>(args)...);
	}
	*/
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
};

//Range add,min,count
struct N{
	int lz,mn,cnt;
	N(int v=0):lz(0),mn(v),cnt(1){}
	bool add(int v){
		lz+=v;
		mn+=v;
		return true;
	}
	void push(N&x,N&y){
		x.add(lz);
		y.add(lz);
		lz=0;
	}
	static N merge(N x,N y){
		N res(min(x.mn,y.mn));
		res.cnt=0;
		if(res.mn==x.mn)
			res.cnt+=x.cnt;
		if(res.mn==y.mn)
			res.cnt+=y.cnt;
		return res;
	}
	int getzeros(){
		return mn==0?cnt:0;
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n=read(),q=read();
	segbeats<N> seg(vi(n,0));
	vi a=readvi(n);
	set<pi> s;
	rep(i,n)
		s.emplace(a[i],i);
	for(auto itr=s.bg;;){
		auto nx=next(itr);
		if(nx==s.ed)break;
		if(itr->b<nx->b)
			seg.ch(itr->b,nx->b,&N::add,1);
		itr=nx;
	}
	auto answer=[&](){
		int ans=seg.get(0,n-1,&N::getzeros,[](int x,int y){return x+y;},int(0));
		print(ans+1);
	};
	auto del=[&](int v,int i){
		auto itr=s.find(pi(v,i));
		int j=-1,k=-1;
		if(itr!=s.bg){
			j=prev(itr)->b;
			if(j<i)
				seg.ch(j,i,&N::add,-1);
		}
		auto nx=s.erase(itr);
		if(nx!=s.ed){
			k=nx->b;
			if(i<k)
				seg.ch(i,k,&N::add,-1);
		}
		if(j!=-1&&k!=-1&&j<k)
			seg.ch(j,k,&N::add,1);
	};
	auto add=[&](int v,int i){
		auto itr=s.lower_bound(pi(v,i));
		int j=-1,k=-1;
		if(itr!=s.bg){
			j=prev(itr)->b;
			if(j<i)
				seg.ch(j,i,&N::add,1);
		}
		if(itr!=s.ed){
			k=itr->b;
			if(i<k)
				seg.ch(i,k,&N::add,1);
		}
		if(j!=-1&&k!=-1&&j<k)
			seg.ch(j,k,&N::add,-1);
		s.emplace(v,i);
	};
	rep(_,q){
		int i=read()-1,x=read();
		del(a[i],i);
		add(a[i]=x,i);
		answer();
	}
}