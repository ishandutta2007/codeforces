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

struct Waf{
	vi vs;
	BIT<int> bit,cnt;
	void prepare(){
		mkuni(vs);
		bit=BIT<int>(si(vs));
		cnt=BIT<int>(si(vs));
	}
	void insert(int v){
		int i=lwb(vs,v);
		bit.add(i,v);
		cnt.add(i,1);
	}
	void erase(int v){
		int i=lwb(vs,v);
		bit.add(i,-v);
		cnt.add(i,-1);
	}
	int query(int v){
		int i=lwb(vs,v);
		int val=bit.sum(i,si(vs));
		val-=cnt.sum(i,si(vs))*v;
		return val;
	}
};

int getmin(const multiset<int>&s){
	assert(si(s));
	return *s.bg;
}
int getmax(const multiset<int>&s){
	assert(si(s));
	return *s.rbegin();
}
void del(multiset<int>&s,int val){
	auto itr=s.find(val);
	assert(itr!=s.ed);
	s.erase(itr);
}

void slv(){
	int n,m,q;cin>>n>>m>>q;
	vi a=readvi(n);
	vi b=readvi(m);
	int asum=accumulate(all(a),int(0));
	int bsum=accumulate(all(b),int(0));
	multiset<int> as,bs,abvs;
	for(auto v:a){
		as.insert(v);
		abvs.insert(v);
	}
	for(auto v:b){
		bs.insert(v);
		abvs.insert(v);
	}
	Waf waf;
	waf.vs=b;
	struct Query{
		int t,pos,x;
		void readinit(){
			cin>>t;
			if(t<=2){
				cin>>pos>>x;
				pos--;
			}else if(t==3){
				cin>>x;
			}else{
				assert(false);
			}
		}
	};
	vc<Query> qs(q);
	rep(i,q){
		qs[i].readinit();
		if(qs[i].t==2)waf.vs.pb(qs[i].x);
	}
	waf.prepare();
	for(auto v:b)waf.insert(v);
	for(auto qq:qs){
		if(qq.t<=2){
			int pos=qq.pos,x=qq.x;
			if(qq.t==1){
				asum-=a[pos];
				del(as,a[pos]);
				del(abvs,a[pos]);
				a[pos]=x;
				asum+=a[pos];
				as.insert(a[pos]);
				abvs.insert(a[pos]);
			}else if(qq.t==2){
				bsum-=b[pos];
				del(bs,b[pos]);
				del(abvs,b[pos]);
				waf.erase(b[pos]);
				b[pos]=x;
				bsum+=b[pos];
				bs.insert(b[pos]);
				abvs.insert(b[pos]);
				waf.insert(b[pos]);
			}else assert(false);
		}else if(qq.t==3){
			int x=qq.x,ans=-inf;
			int tmp=getmin(abvs);
			{
				int top=getmax(bs);
				//dmp(waf.query(top-x));
				chmax(ans,asum-tmp*n-waf.query(top-x));
				auto upd=[&](int use){
					chmax(ans,asum-use-tmp*(n-1)-waf.query(use-x)+x);
				};
				auto itr=as.lower_bound(top+x);
				if(itr!=as.ed)upd(*itr);
				if(itr!=as.bg)upd(*prev(itr));
			}
			//dmp(ans);
			{
				const auto upd=[&](int lv){
					chmax(ans,asum-lv*n-(bsum-lv*m));
				};
				upd(tmp-x);
				auto itr=abvs.upper_bound(tmp+x);
				--itr;
				upd(*itr-x);
			}
			print(ans);
		}else{
			assert(false);
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