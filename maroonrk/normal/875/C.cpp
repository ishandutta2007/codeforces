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

//s: the number of SCCs.
//bl[i]: SCC to which the vertex i belongs
//idx[i]: list of the vertices in the i-th SCC
//gr: DAG of SCCs
//SCCs are numbered in topological order
//VERIFY: yosupo
//AOJGRL3C(except gr)
template<class t>
struct scc{
	const int n;
	const vvc<int>&g;
	vi ord,low,bl,st;
	int s,head;
	vvc<int> idx,gr;
	void dfs(int v){
		ord[v]=low[v]=head++;
		st.pb(v);
		for(auto to:g[v]){
			if(ord[to]==-1){
				dfs(to);
				chmin(low[v],low[to]);
			}else if(bl[to]==-1)
				chmin(low[v],ord[to]);
		}
		if(ord[v]==low[v]){
			int c=idx.size();
			idx.eb();
			while(1){
				int a=st.back();
				st.pop_back();
				bl[a]=c;
				idx.back().pb(a);
				if(v==a)break;
			}
		}
	}
	scc(const vvc<t>&gg,bool cgr=true):n(gg.size()),g(gg),
		ord(n,-1),low(n,-1),bl(n,-1){
		head=0;
		rep(i,n)if(ord[i]==-1)
			dfs(i);
		s=idx.size();
		rep(i,n)
			bl[i]=s-1-bl[i];
		reverse(all(idx));
		//construct the graph
		if(cgr){
			vc<bool> u(s);
			gr.resize(s);
			rep(i,s){
				for(auto v:idx[i]){
					for(auto to:g[v])if(bl[v]<bl[to]){
						if(!u[bl[to]])
							gr[bl[v]].pb(bl[to]);
						u[bl[to]]=1;
					}
				}
				for(auto v:idx[i])
					for(auto to:g[v])
						u[bl[to]]=0;
			}
		}
	}
};

struct twosat{
	int n;
	vvc<int> g;
	twosat(int nn):n(nn),g(n*2){}
	//x/2 x%2  0,1 
	// x,y 
	void add(int x,int y){
		g[x^1].pb(y);
		g[y^1].pb(x);
	}
	//solve the 2-sat
	// 0/1 
	// {} 
	vi solve(){
		scc<int> s(g,false);
		rep(i,n)if(s.bl[i*2]==s.bl[i*2+1])return {};
		vi res(n,-1);
		per(i,s.s)
			for(auto j:s.idx[i])
				if(res[j/2]==-1)
					res[j/2]=j%2;
		return res;
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,m;cin>>n>>m;
	vvc<int> a(n);
	rep(i,n){
		int k;cin>>k;
		a[i]=readvi(k,-1);
	}
	twosat x(m);
	rep(i,n-1){
		int f=-1;
		rep(j,min(si(a[i]),si(a[i+1])))if(a[i][j]!=a[i+1][j]){
			f=j;
			break;
		}
		if(f==-1){
			if(si(a[i])>si(a[i+1])){
				no();
			}
		}else{
			dmp2(i,f);
			x.add(a[i][f]*2+1,a[i+1][f]*2);
			if(a[i][f]>a[i+1][f]){
				dmp(i);
				x.add(a[i][f]*2+1,a[i][f]*2+1);
				x.add(a[i+1][f]*2,a[i+1][f]*2);
			}
		}
	}
	vi y=x.solve();
	if(si(y)==0)no();
	vi ans;
	rep(i,m)if(y[i])ans.pb(i+1);
	yes(0);
	print(si(ans));
	print(ans);
}