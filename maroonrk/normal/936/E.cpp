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

//Nikkei2019 Final G
//XX Opencup GP of Warsaw I
template<class E>
struct cdecomp{
	vvc<E> g;
	int n;
	vi lv,rem;
	int ts(int v,int p){
		int res=1;
		for(auto e:g[v])if(e!=p&&!rem[e])
			res+=ts(e,v);
		return res;
	}
	int fc(int v,int p,int s){
		int ret=1,mx=0;
		for(auto e:g[v])if(e!=p&&!rem[e]){
			int f=fc(e,v,s);
			if(f<=0)
				return f;
			else{
				ret+=f;
				mx=max(mx,f);
			}
		}
		mx=max(mx,s-ret);
		if(mx*2<=s)
			return -v;
		else
			return ret;
	}
	void con(int r,int d){
		r=-fc(r,-1,ts(r,-1));
		lv[r]=d;
		
		initsub(r,d);
		
		rem[r]=1;
		for(auto e:g[r])if(!rem[e])
			con(e,d+1);
	}
	cdecomp(){}
	cdecomp(const vvc<E>&gg):g(gg),n(g.size()),
		lv(n),rem(n),nd(n){
		con(0,0);
		initfin();
	}
	//
	//nd 
	//
	vc<array<pi,20>> nd;
	void dfs(int v,int p,int h,int r,int d){
		nd[v][h]={r,d};
		
		for(auto e:g[v])if(e!=p&&!rem[e])
			dfs(e,v,h,r,d+1);
	}
	void initsub(int r,int h){
		dfs(r,-1,h,r,0);
	}
	void initfin(){
	}
};

struct ysp{
	cdecomp<int> cd;
	int sz;
	vc<pi> xy;
	vi idx;
	int getid(int x,int y){
		int i=lwb(xy,pi(x,y));
		if(i<si(xy)&&xy[i]==pi(x,y))return idx[i];
		else return -1;
	}
	ysp(vc<pi> xy_):xy(xy_){
		sort(all(xy));
		int n=si(xy);
		sz=0;
		rep(i,n){
			idx.pb(sz++);
			if(i+1<n&&xy[i].a==xy[i+1].a&&xy[i].b+1==xy[i+1].b)
				sz--;
		}
		dmp(sz);
		vvc<int> t(sz);
		rep(i,n){
			int x,y;tie(x,y)=xy[i];
			int a=getid(x,y);
			int b=getid(x-1,y);
			int c=getid(x,y-1);
			int d=getid(x-1,y-1);
			if(a!=-1&&b!=-1&&(c==-1||d==-1)){
				dmp2(a,b);
				t[a].pb(b);
				t[b].pb(a);
			}
		}
		
		cd=cdecomp<int>(t);
	}
	void getvd(int x,int y,vc<pi>&z){
		z.clear();
		int i=getid(x,y);
		assert(i!=-1);
		rep(j,cd.lv[i]+1)
			z.pb(cd.nd[i][j]);
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	vc<pi> xy;
	rep(i,n){
		int x,y;cin>>x>>y;
		xy.eb(x,y);
	}
	ysp mrt(xy);
	for(auto&z:xy)swap(z.a,z.b);
	ysp khi(xy);
	for(auto&z:xy)swap(z.a,z.b);
	
	struct query{
		int x,y,d,t;
	};
	vvc<query> qs(mrt.sz);
	
	int qnum;cin>>qnum;
	vi ans;
	vc<pi> z;
	rep(_,qnum){
		int t;cin>>t;
		int x,y;cin>>x>>y;
		int tp=-1;
		if(t==2){
			tp=si(ans);
			ans.pb(inf);
		}
		mrt.getvd(x,y,z);
		for(auto w:z)
			qs[w.a].pb({y,x,w.b,tp});
	}
	vi cur(khi.sz,inf);
	rep(i,mrt.sz){
		for(auto q:qs[i]){
			khi.getvd(q.x,q.y,z);
			if(q.t==-1){
				for(auto w:z){
					dmp(0);
					chmin(cur[w.a],q.d+w.b);
				}
			}else{
				for(auto w:z){
					chmin(ans[q.t],cur[w.a]+w.b+q.d);
				}
			}
		}
		dmp(cur);
		for(auto q:qs[i]){
			khi.getvd(q.x,q.y,z);
			if(q.t==-1){
				for(auto w:z){
					cur[w.a]=inf;
				}
			}
		}
	}
	
	for(auto v:ans){
		if(v==inf)v=-1;
		print(v);
	}
}