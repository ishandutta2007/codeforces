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

template<class t>
bool inc(t a,t b,t c){
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
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

void muri(){
	cout<<"-1 -1"<<endl;
	exit(0);
}

int ganbaruzoi(vi a,vi lw,vi up,int z){
	rep(i,z)chmin(up[i],up[z-1]);
	rep(i,z)chmax(lw[i],lw[0]);
	rep(i,z)if(lw[i]>up[i])return -1;
	
	int n=si(a);
	
	int zorg=z;
	while(z<n&&up[z]==inf)z++;
	
	int need=0,sum=0,lim=0;
	int aff=0;
	per(i,n){
		if(a[i]<lw[i]){
			need+=lw[i]-a[i];
		}else{
			int u=a[i]-lw[i];
			{
				int w=min(u,need);
				u-=w;
				need-=w;
				sum+=w;
				assert(sum<=lim);
			}
			if(need==0&&u>up[i]-lw[i]){
				int w=min(u-(up[i]-lw[i]),lim-sum);
				assert(w>=0);
				u-=w;
				sum+=w;
				assert(sum<=lim);
			}
			a[i]=lw[i]+u;
			if(a[i]>up[i])return -1;
		}
		sum+=a[i];
		lim+=up[i];
		chmin(lim,inf);
		if(i==z)aff=lim-(sum+need);
	}
	
	if(need>0)return -1;
	
	if(up[0]==inf){
		rep(i,z)chmax(a[i],lw[i]);
		int s=accumulate(a.bg,a.bg+zorg,int(0));
		int p=s/zorg,q=s%zorg;
		assert(p>=lw[0]);
		//if(p<lw[0])return -1;
		rng(i,zorg,z)aff+=p-a[i];
		if(q<=aff)return p;
		else return -1;
	}else{
		assert(lw[0]==up[0]);
		assert(lw[0]==a[0]);
		return a[0];
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,m;cin>>n>>m;
	vi a(m+1),b(m+1);
	rep(i,n){
		int l,r;cin>>l>>r;
		a[0]++;
		a[l]--;
		b[l]++;
		b[r]--;
	}
	rep(i,m)a[i+1]+=a[i];
	rep(i,m)b[i+1]+=b[i];
	
	a.pop_back();
	b.pop_back();
	
	vi lw(m,0),up(m,inf);
	
	{
		int q;cin>>q;
		rep(_,q){
			int p,s;cin>>p>>s;
			p--;
			chmax(lw[p],s);
			chmin(up[p],s);
		}
		rep(i,m-1)chmin(up[i+1],up[i]);
		per(i,m-1)chmax(lw[i],lw[i+1]);
	}
	
	{
		int t;cin>>t;
		rep(i,m)t-=a[i];
		if(t<0)muri();
		rep(i,m){
			int u=min(t,b[i]);
			a[i]+=u;
			t-=u;
		}
		if(t>0)muri();
		rep(i,m-1)assert(a[i]>=a[i+1]);
	}
	
	dmp(a);
	
	int ok=0,ng=m+1;
	while(ng-ok>1){
		const int mid=(ok+ng)/2;
		int w=ganbaruzoi(a,lw,up,mid);
		if(w!=-1)ok=mid;
		else ng=mid;
	}
	
	if(ok==0)muri();
	
	int w=ganbaruzoi(a,lw,up,ok);
	cout<<ok<<" "<<w<<endl;
}