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

//CF 463 G
//Yukicoder No.263
template<class S>
struct eertree{
	struct N{
		int suf,ser,l,r;
		int len(){return r-l;}
		map<int,int> ch;
	};
	vc<N> x;
	int dist(int v){
		if(x[v].suf<=0)return -1;
		return x[v].len()-x[x[v].suf].len();
	}
	int c;
	S s;
	eertree(){
		x.pb({-1,-1,1,0,{}});
		x.pb({0,-1,0,0,{}});
		c=1;
	}
	bool chk(int v,int i){
		x[v].l+=i-x[v].r;
		x[v].r=i;
		return x[c].l>0&&s[x[v].l-1]==s[i];
	}
	template<class t>
	int extend(t z){
		int i=si(s);
		s.pb(z);
		
		while(!chk(c,i))c=x[c].suf;
		if(x[c].ch.count(s[i])==0){
			int d=x[c].suf;
			if(d!=-1)while(!chk(d,i))d=x[d].suf;
			int e=d==-1?1:x[d].ch[s[i]];
			int f=x[c].ch[s[i]]=x.size();
			x.pb({e,e,x[c].l-1,x[c].r+1,{}});
			if(dist(f)==dist(e))
				x[f].ser=x[e].ser;
		}
		return c=x[c].ch[s[i]];
	}
	N& operator[](int i){
		return x[i];
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	string s;
	{
		string buf[2];
		rep(k,2)cin>>buf[k];
		int n=si(buf[0]);
		rep(i,n){
			s+=buf[0][i];
			s+=buf[1][i];
		}
	}
	int n=si(s);
	
	vc<pi> dp(n+1,pi(inf,-1));
	dp[0]=pi(0,-1);
	
	vc<pi> buf(n*2+2,pi(inf,-1));
	
	eertree<string> t;
	
	rep(i,n){
		int v=t.extend(s[i]);
		while(t[v].len()){
			int p=i+1-t[t[v].ser].len()-t.dist(v);
			buf[v]=pi(dp[p].a+1,p);
			if(t[v].suf!=t[v].ser)
				chmin(buf[v],buf[t[v].suf]);
			if(i%2)chmin(dp[i+1],buf[v]);
			v=t[v].ser;
		}
		if(i%2&&s[i-1]==s[i]){
			chmin(dp[i+1],pi(dp[i-1].a,i-1));
		}
	}
	
	int cur=n;
	dmp(dp[cur]);
	if(dp[cur].a==inf){
		print(-1);
		return 0;
	}
	vc<pi> ans;
	while(cur){
		assert(cur%2==0);
		int nx=dp[cur].b;
		if(cur-nx>2){
			ans.eb(nx/2,cur/2);
		}
		cur=nx;
	}
	print(si(ans));
	for(auto v:ans)
		print(v.a+1,2),print(v.b);
}