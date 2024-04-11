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

//strict-increasing 
struct ysp_segtree{
	struct N{
		int cut,mx;
		N(int v=0):cut(0),mx(v){}
	};
	int s;
	vc<N> x;
	ysp_segtree(vi a){
		int n=si(a);
		s=1;
		while(s<n)s*=2;
		x.resize(s*2);
		rep(i,n)x[s+i]=N(a[i]);
		gnr(i,1,s)upd(i);
	}
	pi sub(int i,int v){
		if(x[i].mx<=v)return pi(0,v);
		if(i>=s)return pi(1,x[i].mx);
		if(v<x[i*2].mx){
			return pi(sub(i*2,v).a+x[i].cut,x[i].mx);
		}else{
			return sub(i*2+1,v);
		}
	}
	void upd(int i){
		assert(i<s);
		tie(x[i].cut,x[i].mx)=sub(i*2+1,x[i*2].mx);
	}
	void point_update(int i,int v){
		i+=s;
		x[i]=N(v);
		while(i>>=1)upd(i);
	}
	pi get(int b,int e,int v,int l,int r,int i){
		if(e<=l||r<=b)return pi(0,v);
		if(b<=l&&r<=e)return sub(i,v);
		int m=(l+r)/2;
		pi a=get(b,e,v,l,m,i*2);
		pi c=get(b,e,a.b,m,r,i*2+1);
		return pi(a.a+c.a,c.b);
	}
	//cnt,mx
	pi get(int b,int e,int v){
		assert(b<=e);
		return get(b,e,v,0,s,1);
	}
};

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

//N::push
//pushclear
//N::merge

struct N{
	int mx;
	N(int v=-1):mx(v){}
	bool set(int v){
		mx=v;
		return true;
	}
	void push(N&,N&){
	}
	static N merge(N x,N y){
		return N(max(x.mx,y.mx));
	}
	bool find(int v){
		return mx>=v;
	}
};

template<class t>
struct BIT{
	vc<t> buf;
	int s;
	BIT(int n=0){init(n);}
	void init(int n){buf.assign(s=n,0);}
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


signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	vi perm=readvi(n,-1);
	vi qs(n);
	rep(i,n)qs[perm[i]]=i;
	
	vc<ll> ans(n);
	rep(_,2){
		vi a(n,-1);
		segbeats<N> seg(vi(n,-1));
		BIT<int> bit(n);
		ysp_segtree ysp(vi(n,-1));
		
		auto sub=[&](int i,int v){
			/*int res=0;
			rng(j,i,n){
				if(a[j]>v){
					res++;
					v=a[j];
				}
			}
			return res;*/
			return ysp.get(i,n,v).a;
		};
		
		ll sum=0;
		rep(i,n){
			int p=qs[i];
			sum+=bit.sum(0,p);
			sum+=sub(p,-1);
			vi left,right;
			bool useleft=true;
			{
				int l=p,r=p;
				while(1){
					l=seg.findmax(0,l,&N::find,a[l]+1).a;
					r=seg.findmin(r+1,n,&N::find,a[r]+1).a;
					if(l==-1)break;
					if(r==n){
						useleft=false;
						break;
					}
					left.pb(l);
					right.pb(r);
				}
			}
			if(useleft){
				left.pb(-1);
				int pre=p;
				for(auto j:left){
					int c=sub(p,a[pre]);
					sum-=ll(c)*bit.sum(max(j,0),pre);
					pre=j;
				}
			}else{
				for(auto j:right){
					int l=seg.findmax(0,p,&N::find,a[j]).a;
					sum-=bit.sum(max(l,0),p);
				}
			}
			ans[i]+=sum;
			seg.point_update(p,i);
			a[p]=i;
			bit.add(p,1);
			ysp.point_update(p,i);
			//dmp(sum);
		}
		
		for(auto&v:qs)v=n-1-v;
	}
	dmp(ans);
	rep(_,2){
		vi x;
		rep(i,n){
			while(si(x)&&qs[i]<x.back()){
				x.pop_back();
			}
			x.pb(qs[i]);
			ans[i]-=i+1-si(x);
		}
		for(auto&v:qs)v=n-1-v;
	}
	dmp(ans);
	rep(i,n)ans[i]+=i+1;
	for(auto v:ans)print(v);
}