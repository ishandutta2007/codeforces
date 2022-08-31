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

void up(int&a,int&b,int s){
	int x=a+b;
	assert(s<=x);
	if(s<x){
		int i=topbit(s^x);
		a=(a>>i)<<i;
		b=(b>>i)<<i;
		if(a&1<<i){
			a^=1<<i;
			a+=mask(i)&s;
		}else{
			b^=1<<i;
			b+=mask(i)&s;
		}
	}
}

pi lca(int a,int b,int c,int d){
	int x=a+b,y=c+d,tar=min(x,y);
	up(a,b,tar);
	up(c,d,tar);
	if(a==c&&b==d){
		return pi(a,b);
	}else{
		int i=max(topbit(a^c),topbit(b^d));
		up(a,b,(tar>>(i+1))<<(i+1));
		return pi(a,b);
	}
}

pi lca(pi a,pi b){
	return lca(a.a,a.b,b.a,b.b);
}

bool cmp(int a,int b,int c,int d){
	int x=a+b,y=c+d,tar=min(x,y);
	up(a,b,tar);
	up(c,d,tar);
	if(a==c&&b==d){
		return y!=tar;
	}else{
		return a>c;
	}
}

bool cmppi(pi a,pi b){
	return cmp(a.a,a.b,b.a,b.b);
}

void slv(){
	int n;cin>>n;
	using P=pair<pi,pi>;
	vc<P> qs;
	vc<pi> vs{pi(0,0)};
	rep(i,n){
		pi a=readpi(),b=readpi();
		pi c=lca(a,b);
		qs.eb(a,b);
		vs.pb(a);
		vs.pb(b);
		vs.pb(c);
		{
			int s=c.a+c.b;
			if(s>0){
				up(c.a,c.b,s-1);
				vs.pb(c);
			}
		}
	}
	sort(all(vs),cmppi);
	vs.erase(unique(all(vs)),vs.ed);
	
	int k = vs.size();
	rep(i,k-1){
		vs.pb(lca(vs[i],vs[i+1]));
	}
	sort(all(vs),cmppi);
	vs.erase(unique(all(vs)),vs.ed);
	k = vs.size();
	map<pi,int> index;
	rep(i,k) index[vs[i]] = i;
	vi par(k,-1);
	vvc<int> t(k);
	rng(i,1,k){
		pi p = lca(vs[i-1],vs[i]);
		int j=index[p];
		par[i]=j;
		t[j].pb(i);
	}
	
	dmp(vs);
	dmp(t);
	
	vi sum(k);
	for(auto w:qs){
		pi a,b;tie(a,b)=w;
		pi c=lca(a,b);
		int x=index[a],y=index[b],p=index[c],q=par[p];
		sum[x]++;
		sum[y]++;
		sum[p]--;
		if(q!=-1)sum[q]--;
	}
	
	vc<pi> waf;
	
	auto rec=[&](auto self,int v,int pre)->int{
		int cur=vs[v].a+vs[v].b;
		for(auto ch:t[v])sum[v]+=self(self,ch,cur);
		if(pre<cur&&sum[v])waf.eb(pre+1,cur+1);
		return sum[v];
	};
	rec(rec,0,-1);
	
	dmp(waf);
	
	vi pos;
	for(auto w:waf){
		pos.pb(w.a);
		pos.pb(w.b);
	}
	mkuni(pos);
	int s=si(pos);
	vi dp(s);
	for(auto w:waf){
		dp[lwb(pos,w.a)]^=1;
		dp[lwb(pos,w.b)]^=1;
	}
	int ans=0;
	rng(i,1,s)ans+=dp[i];
	print(ans);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}