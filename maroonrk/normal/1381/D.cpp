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

#define CAPITAL
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

//AGC034E
//XX Opencup GP of Korea
//CF446D
//int(E)->to
template<class N,class E>
struct treedp{
	const vvc<E>& g;
	vc<N> a,b,res,sub,bus;
	void dfs1(int v,int p){
		a[v].init(v);
		E up;
		for(auto e:g[v])
			if(e!=p){
				dfs1(e,v);
				b[e]=a[v];
				a[v]=a[v]+a[e];
			}else
				up=e;
		sub[v]=a[v];
		if(p!=-1)a[v]=a[v].up(up);
	}
	void dfs2(int v,int p,N cur){
		per(i,g[v].size()){
			auto e=g[v][i];
			if(e==p)continue;
			bus[e]=cur+b[e];
			dfs2(e,v,bus[e].up(e));
			cur=cur+a[e];
		}
		res[v]=cur;
	}
	treedp(const vvc<E>&gg):g(gg),a(si(g)),b(si(g)),res(si(g)),sub(si(g)),bus(si(g)){
		dfs1(0,-1);
		N tmp;tmp.init(0);
		dfs2(0,-1,tmp);
	}
};

int len;
struct N{
	int mx,cnt;
	void init(int){
		mx=0;
		cnt=0;
	}
	N up(int)const{
		return N{mx+1,mx+1>=len};
	}
	N operator+(const N&r)const{
		return N{max(mx,r.mx),cnt+r.cnt};
	}
};

void slv(){
	int n;cin>>n;
	vvc<int> t(n);
	int x,y;cin>>x>>y;
	x--;y--;
	rep(_,n-1){
		int a,b;cin>>a>>b;
		a--;b--;
		t[a].pb(b);
		t[b].pb(a);
	}
	len=-1;
	vi idx;
	{
		auto rec=[&](auto self,int v,int p,int d)->bool{
			if(v==y){
				len=d;
				idx.pb(v);
				return true;
			}
			for(auto to:t[v])if(to!=p)
				if(self(self,to,v,d+1)){
					idx.pb(v);
					return true;
				}
			return false;
		};
		rec(rec,x,-1,0);
		reverse(all(idx));
	}
	dmp(len);
	dmp(idx);
	vi inp(n);
	for(auto i:idx)inp[i]=1;
	int s=si(idx);
	vi tar(n);
	{
		treedp<N,int> dp(t);
		rep(i,n)if(dp.res[i].cnt>=3)tar[i]=1;
	}
	vc<array<bool,2>> vis(s);
	bool ans=false;
	queue<int> q;
	auto reach=[&](int i,int k){
		if(!inc(0,i,s-1)||vis[i][k])return;
		vis[i][k]=true;
		q.push(i*2+k);
	};
	reach(0,0);
	reach(s-1,1);
	while(!ans&&si(q)){
		int i=q.front()/2,k=q.front()%2;
		q.pop();
		auto rec=[&](auto self,int v,int p)->int{
			if(tar[v])ans=true;
			int ret=0;
			for(auto to:t[v])if(to!=p&&!inp[to]){
				chmax(ret,self(self,to,v)+1);
			}
			return ret;
		};
		if(k==0){
			if(i)reach(i-1,0);
			int d=rec(rec,idx[i],-1);
			int e=max(len-d,0LL);
			reach(i+e,1);
		}else{
			if(i+1<s)reach(i+1,1);
			int d=rec(rec,idx[i],-1);
			int e=max(len-d,0LL);
			reach(i-e,0);
		}
	}
	if(ans)yes(0);
	else no(0);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int t;cin>>t;rep(_,t)slv();
}