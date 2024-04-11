#ifndef LOCAL
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

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

template<class T>
void print_offset(const vector<T>&v,ll off,int suc=1){
	rep(i,v.size())
		print(v[i]+off,i==int(v.size())-1?suc:2);
}

template<class T,size_t N>
void print(const array<T,N>&v,int suc=1){
	rep(i,N)
		print(v[i],i==int(N)-1?suc:2);
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
	static mt19937_64 gen;
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

const int nmax=10010;
const int smax=310;
int dp[nmax][smax*2];

//ABC221G
//CF Global16 H
//Verify
pair<bool,vi> subset_sum(vi a,int tar){
	if(tar<0||accumulate(all(a),0)<tar)return mp(false,vi{});
	if(tar==0)return mp(true,vi{});
	
	int n=si(a);assert(n<=nmax);
	int s=*max_element(all(a));assert(s<=smax);
	vi x,y;
	{
		int tot=0,tmp=tar;
		rep(i,n){
			tot+=a[i];
			if(tot<=tar){
				x.pb(a[i]);
				tmp=tar-tot;
			}else y.pb(a[i]);
		}
		tar=tmp;
	}
	int p=si(x),q=si(y);
	rep(i,p+1)rep(j,2*s)
		dp[i][j]=q+1;
	dp[0][0]=0;
	rep(i,p+1){
		rep(j,2*s){
			int mx=q;if(i)chmin(mx,dp[i-1][j]);
			rng(u,dp[i][j],mx){
				if(j+y[u]<2*s){
					chmin(dp[i][j+y[u]],u+1);
				}
			}
		}
		if(i<p){
			rep(j,2*s)dp[i+1][j]=dp[i][j];
			rng(j,x[i],2*s)chmin(dp[i+1][j-x[i]],dp[i][j]);
		}
	}
	vc<bool> used(n);
	rep(i,p)used[i]=true;
	int i=p,j=tar;
	if(dp[i][j]==q+1)return mp(false,vi{});
	while(i||j){
		if(dp[i][j]>0){
			int u=dp[i][j]-1;
			if(j>=y[u]&&dp[i][j-y[u]]<=u){
				used[p+u]=true;
				j-=y[u];
				continue;
			}
		}
		if(i>0){
			if(dp[i][j]==dp[i-1][j]){
				i--;
				continue;
			}
			if(j+x[i-1]<2*s&&dp[i][j]==dp[i-1][j+x[i-1]]){
				used[--i]=false;
				j+=x[i];
				continue;
			}
		}
		assert(false);
	}
	vi res;
	rep(k,n)if(used[k])res.pb(k);
	return mp(true,res);
}


const int vmax=ten(6)+10;
bool pri[vmax];
vi ps;
int sf[vmax]; //smallest factor, sf[1] is undefined(0)
void linear_sieve(){
	rng(i,2,vmax)
		pri[i]=1;
	rng(i,2,vmax){
		if(pri[i]){
			ps.pb(i);
			sf[i]=i;
		}
		for(int j=0;i*ps[j]<vmax;j++){
			pri[i*ps[j]]=0;
			sf[i*ps[j]]=ps[j];
			if(i%ps[j]==0)break;
		}
	}
}
int mu[vmax];
vi ms;//all m s.t. mu[m] is non-zero
void initmu(){
	mu[1]=1;
	ms.pb(1);
	rng(i,2,vmax){
		if(i/sf[i]%sf[i]==0)continue;
		mu[i]=mu[i/sf[i]]*sf[i];
		if(mu[i])ms.pb(i);
	}
}
int pf[vmax];
void initpf(){
	pf[1]=1;
	rng(i,2,vmax){
		pf[i]=pf[i/sf[i]];
		if(i/sf[i]%sf[i])pf[i]*=sf[i];
	}
}

const int L=20;
const int N=260;
using B=array<ull,(N+63)/64>;
void Bclear(int len,B&a){
	rep(i,len)a[i]=0;
}
void Bxor(int len,B&a,B b){
	rep(i,len)a[i]^=b[i];
}
void Bflip(B&a,int i){
	a[i/64]^=1LL<<(i%64);
}
int bs[L];
B idx[L];

struct LinearEquation{
	vi a;
	int b;
	vi genans(const B&u){
		vi res;
		rep(i,si(a))if(u[i/64]&1LL<<(i%64))res.pb(a[i]);
		return res;
	}
	tuple<bool,vi,vi> slv(){
		int n=si(a);
		int len=(n+63)/64;
		rep(i,L)bs[i]=0;
		rep(i,L)Bclear(len,idx[i]);
		
		myshuffle(a);
		bool has=false;
		B ker;
		
		int s=0;
		rep(i,n){
			int cur=a[i];
			B u{};Bflip(u,i);
			rep(j,s){
				if(chmin(cur,cur^bs[j])){
					Bxor(len,u,idx[j]);
				}
			}
			if(cur){
				bs[s]=cur;
				idx[s]=u;
				s++;
			}else if(!has){
				has=true;
				ker=u;
			}
		}
		
		B u{};
		int cur=b;
		rep(j,s){
			if(chmin(cur,cur^bs[j])){
				Bxor(len,u,idx[j]);
			}
		}
		assert(cur==0);
		vi x=genans(u),y;
		if(has){
			Bxor(len,u,ker);
			y=genans(u);
			if(si(x)>si(y))swap(x,y);
		}
		return mt(has,x,y);
	}
};

bool dbg=false;

void slv(){
	int c,n;cin>>c>>n;
	if(n<0){
		dbg=true;
		n=-n;
	}
	vi god;
	if(dbg){
		/*god.resize(c);iota(all(god),1);
		myshuffle(god);
		god.resize(n);
		sort(all(god));*/
		c=106;
		n=44;
		god=vi{2,3,6,7,11,19,20,23,24,25,27,29,32,34,36,40,44,45,46,52,54,59,63,66,68,71,73,74,78,80,81,84,85,88,91,92,93,95,97,101,102,103,105,106};
	}
	
	vi ysum(c+1);
	vi ls;
	rng(v,1,c+1)if(mu[v])ls.pb(v);
	if(dbg){
		/*for(auto v:ls){
			for(auto w:god){
				if(gcd(v,w)==1){
					ysum[v]^=w;
				}
			}
		}*/
		for(auto w:god)ysum[w]^=w;
		for(auto p:ps){
			if(p>c)break;
			int mx=c/p;
			gnr(i,1,mx+1)ysum[i]^=ysum[i*p];
		}
		for(auto p:ps){
			if(p>c)break;
			int mx=c/p;
			rng(i,1,mx+1)ysum[i*p]^=ysum[i];
		}
		rng(i,1,c+1)if(mu[i]==0)ysum[i]=0;
	}else{
		print(si(ls));
		print(ls);
		cout.flush();
		for(auto v:ls){
			ysum[v]=read();
		}
	}
	//dmp(ysum);
	for(auto p:ps){
		if(p>c)break;
		int mx=c/p;
		gnr(i,1,mx+1)if(mu[i*p])ysum[i*p]^=ysum[i];
	}
	//dmp(ysum);
	for(auto p:ps){
		if(p>c)break;
		int mx=c/p;
		rng(i,1,mx+1)if(mu[i*p])ysum[i]^=ysum[i*p];
	}
	
	dmp(god);
	//dmp(ysum);
	
	/*int mx=0;
	int tot=0;
	
	for(auto v:ls){
		vi a;
		for(int i=v;i<=c;i+=v)if(pf[i]==v)
			a.pb(i);
		chmax(mx,si(a));
	}
	
	cerr<<mx<<endl;*/
	
	
	vc<LinearEquation> buf;
	
	for(auto v:ls){
		vi a;
		for(int i=v;i<=c;i+=v)if(pf[i]==v)
			a.pb(i);
		buf.pb({a,ysum[v]});
		//cerr<<a<<" "<<ysum[v]<<endl;
	}
	
	//cerr<<"Unko"<<endl;
	
	while(1){
		//cerr<<0<<endl;
		vc<tuple<bool,vi,vi>> anslist(si(buf));
		rep(i,si(anslist)){
			anslist[i]=buf[i].slv();
		}
		
		while(1){
			//cerr<<1<<endl;
			//cerr<<"Baka"<<endl;
			int mn=0,mx=0;
			vi vs,is;
			rep(i,si(anslist)){
				auto&[has,x,y]=anslist[i];
				if(has&&si(x)<si(y)){
					//dmp(buf[i].b);
					//dmp2(x,y);
					vs.pb(si(y)-si(x));
					is.pb(i);
				}
				mn+=si(x);
				mx+=max(si(x),si(y));
			}
			
			int tar=n-mn;
			//cerr<<n<<" "<<mn<<" "<<mx<<" "<<tar<<" "<<vs<<endl;
			auto [can,u]=subset_sum(vs,tar);
			if(can){
				for(auto i:u){
					auto&[has,x,y]=anslist[is[i]];
					swap(x,y);
				}
				
				//dmp(anslist);
				
				vi ans;
				rep(i,si(anslist)){
					auto&[has,x,y]=anslist[i];
					ans.insert(ans.ed,all(x));
				}
				assert(si(ans)==n);
				sort(all(ans));
				print(ans);
				cout.flush();
				
				return;
			}
			
			if(inc(mn,n,mx))break;
			
			rep(i,si(anslist)){
				auto&[has,x,y]=anslist[i];
				if(has){
					auto [tmp,z,w]=buf[i].slv();
					if(si(z)<si(x))swap(x,z);
					if(si(y)<si(w))swap(y,w);
				}
			}
		}
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	linear_sieve();
	initmu();
	initpf();
	
	/*int num=0;
	rng(c,1,ten(6)+1){
		if(mu[c])num++;
		if(c>=100){
			int atmost=(c*65+99)/100;
			if(num>atmost){
				cerr<<c<<" "<<atmost<<" "<<num<<endl;
				return 0;
			}
		}
	}
	cerr<<num<<endl;*/
	
	//int t;cin>>t;rep(_,t)
	slv();
}