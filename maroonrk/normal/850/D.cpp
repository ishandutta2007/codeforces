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

template<class d>
struct maxflow{
	struct E{
		int to,rev;
		d cap;
	};
	vvc<E> g;
	vi itr,lv,q;
	maxflow(int n):g(n),itr(n),lv(n),q(n){}
	int ae(int s,int t,d c){
		g[s].pb({t,(int)g[t].size(),c});
		g[t].pb({s,(int)g[s].size()-1,0});
		return si(g[s])-1;
	}
	void bfs(int s){
		fill(all(lv),-1);
		lv[s]=0;
		int l=0,r=0;
		q[r++]=s;
		while(l<r){
			int v=q[l++];
			for(auto e:g[v])if(e.cap>0&&lv[e.to]==-1){
				lv[e.to]=lv[v]+1;
				q[r++]=e.to;
			}
		}
	}
	d dfs(int v,int t,d f){
		if(v==t)return f;
		d res=0;
		for(int&i=itr[v];i<(int)g[v].size();i++){
			E& e=g[v][i];
			if(e.cap>0&&lv[e.to]==lv[v]+1){
				d a=dfs(e.to,t,min(f,e.cap));
				if(a>0){
					e.cap-=a;
					g[e.to][e.rev].cap+=a;
					res+=a;
					f-=a;
					if(f<=0)break;
				}
			}
		}
		return res;
	}
	d calc(int s,int t,d mx=inf){
		d f=0;
		while(1){
			bfs(s);
			if(lv[t]==-1)
				return f;
			fill(all(itr),0);
			f+=dfs(s,t,mx-f);
		}
		return f;
	}
};

void restore_tournament(vi d){
	sort(all(d));
	
	int n=si(d);
	int m=n*(n-1)/2;
	
	{
		int s=0;
		rep(i,n){
			s+=d[i];
			assert(s>=i*(i+1)/2);
		}
		assert(s==m);
	}
	
	auto getid=[&](int i,int j){
		if(i<j)swap(i,j);
		return i*(i-1)/2+j;
	};
	
	maxflow<int> mf(1+n+m+1);
	rep(i,n)mf.ae(0,1+i,d[i]);
	vvc<int> e(n,vi(n));
	rep(i,n)rep(j,n)if(i!=j)e[i][j]=mf.ae(1+i,1+n+getid(i,j),1);
	rep(i,m)mf.ae(1+n+i,1+n+m,1);
	int fl=mf.calc(0,1+n+m);
	if(0)assert(fl==m);
	
	vc<string> res(n,string(n,'0'));
	rep(i,n)rep(j,n)if(i!=j)if(mf.g[1+i][e[i][j]].cap==0)res[i][j]='1';
	if(0){
		vi z(n);
		rep(i,n){
			assert(res[i][i]=='0');
			rep(j,n)z[i]+=res[i][j]-'0';
		}
		sort(all(z));
		assert(z==d);
	}
	print(n);
	for(auto v:res)print(v);
}

const int nmax=32;
const int vmax=200;
const int emax=vmax*vmax/2;
bitset<emax> dp[nmax][vmax];

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	vi a=readvi(n);
	sort(all(a));
	
	dp[0][0][0]=1;
	rep(i,n){
		rep(j,vmax-1){
			rng(k,max(0,(j+1)*j/2-a[i]),emax-1-a[i]){
				dp[i+1][j+1][k+a[i]]=dp[i][j][k];
			}
		}
		rep(j,vmax-1){
			rng(k,max(0,(j+1)*j/2-a[i]),emax-1-a[i]){
				dp[i+1][j+1][k+a[i]]=dp[i+1][j+1][k+a[i]]|dp[i+1][j][k];
			}
		}
	}
	
	rng(j,n,vmax)if(dp[n][j][j*(j-1)/2]){
		dmp(j);
		vi d;
		int i=n,x=j,y=j*(j-1)/2;
		while(i){
			dmp2(i,x,y);
			d.pb(a[i-1]);
			if(dp[i-1][x-1][y-a[i-1]]){
				x--;
				y-=a[i-1];
				i--;
			}else{
				x--;
				y-=a[i-1];
			}
		}
		dmp(d);
		
		restore_tournament(d);
		
		return 0;
	}
	assert(0);
	cout<<"=("<<endl;
}