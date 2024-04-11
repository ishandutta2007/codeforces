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
	/*int kth(int k){
		int res=0;
		for(int i=topbit(s);i>=0;i--){
			int w=res+(1<<i);
			if(w<=s&&buf[w-1]<=k){
				k-=buf[w-1];
				res=w;
			}
		}
		return res;
	}*/
};

template<class t>
struct Point1D{
	BIT<t> bit;
	vi pos;
	void addp(int p){
		pos.pb(p);
	}
	void init(){
		mkuni(pos);
		bit.init(pos.size());
	}
	int idx(int p){
		return lwb(pos,p);
	}
	void addv(int p,t v){
		bit.add(idx(p),v);
	}
	t sum(int b,int e){
		return bit.sum(idx(b),idx(e));
	}
};

template<class t>
struct Point2D{
	vc<Point1D<t>> buf;
	vi pos,xs,ys;
	void addp(int x,int y){
		xs.pb(x);
		ys.pb(y);
	}
	int idx(int p){
		return lwb(pos,p);
	}
	void init(){
		pos=xs;
		mkuni(pos);
		buf.resize(pos.size());
		rep(i,xs.size())
			for(int j=idx(xs[i]);j<int(buf.size());j+=(j+1)&(-j-1))
				buf[j].addp(ys[i]);
		for(auto&b:buf)b.init();
	}
	void addv(int x,int y,t v){
		for(int j=idx(x);j<int(buf.size());j+=(j+1)&(-j-1))
			buf[j].addv(y,v);
	}
	//[x1,x2)*[y1,y2)
	t rect(int x1,int x2,int y1,int y2){
		t res=0;
		for(int j=idx(x1)-1;j>=0;j-=(j+1)&(-j-1))
			res-=buf[j].sum(y1,y2);
		for(int j=idx(x2)-1;j>=0;j-=(j+1)&(-j-1))
			res+=buf[j].sum(y1,y2);
		return res;
	}
};

struct query{
	int x1,y1,x2,y2,z,i;
	bool operator<(const query&rhs)const{
		return pi(z,-i)<pi(rhs.z,-rhs.i);
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int vmax[3];
	rep(k,3)cin>>vmax[k];
	int n,m,qs;cin>>n>>m>>qs;
	
	int okmn[3],okmx[3];
	rep(k,3){
		okmn[k]=inf;
		okmx[k]=-inf;
	}
	
	rep(i,n){
		rep(k,3){
			int a;cin>>a;
			chmin(okmn[k],a);
			chmax(okmx[k],a);
		}
	}
	
	Point2D<int> ysp;
	vc<query> w;
	rep(i,m){
		int pos[3];
		rep(k,3)cin>>pos[k];
		bool ok=true;
		rep(k,3){
			if(!inc(okmn[k],pos[k],okmx[k]))ok=false;
		}
		if(ok){
			cout<<"INCORRECT"<<endl;
			return 0;
		}
		int x,y,z;tie(x,y,z)=mt(pos[0],pos[1],pos[2]);
		w.pb({x,y,-1,-1,z,-1});
		ysp.addp(x,y);
	}
	ysp.init();
	vi ans(qs,-1);
	rep(i,qs){
		int mn[3],mx[3];
		int pos[3];
		rep(k,3)cin>>pos[k];
		rep(k,3){
			mn[k]=min(okmn[k],pos[k]);
			mx[k]=max(okmx[k],pos[k]);
		}
		bool ok=true;
		rep(k,3){
			if(!inc(okmn[k],pos[k],okmx[k]))ok=false;
		}
		if(ok)
			continue;
		ans[i]=0;
		w.pb({mn[0],mn[1],mx[0]+1,mx[1]+1,mn[2],i*2});
		w.pb({mn[0],mn[1],mx[0]+1,mx[1]+1,mx[2]+1,i*2+1});
	}
	
	sort(all(w));
	for(auto z:w){
		if(z.i==-1)ysp.addv(z.x1,z.y1,1);
		else{
			int t=z.i%2;
			z.i/=2;
			int c=ysp.rect(z.x1,z.x2,z.y1,z.y2);
			if(t==0)ans[z.i]-=c;
			else ans[z.i]+=c;
		}
	}
	
	cout<<"CORRECT\n";
	rep(i,qs){
		if(ans[i]==-1){
			cout<<"OPEN\n";
		}else{
			if(ans[i]){
				cout<<"CLOSED\n";
			}else{
				cout<<"UNKNOWN\n";
			}
		}
	}
}