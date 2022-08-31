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

//find the indices of row maxima
//the smallest index is used in case of tie
//f 
//-inf 
//VERIFY
//Codechef CHEFAOR (needs optimization!)
//Petrozavodsk Camp 2010S Kyiv NU Contest I (D=long double,double )
//GCJ 2020 WF D (D=long double)
//template<class F,class D=typename invoke_result<F,int,int>::type>
//f  WA  RE 
template<class F,class D>
vi smawk(F f,int n,int m){
	vi ans(n,-1);
	auto rec=[&](auto self,int*const rs,int x,int*const cs,int y)->void{
		const int t=8;
		if(x<=t||y<=t){
			rep(i,x){
				int r=rs[i];
				D mx;
				rep(j,y){
					int c=cs[j];
					D w=f(r,c);
					if(ans[r]==-1||w>mx){
						ans[r]=c;
						mx=w;
					}
				}
			}
			return;
		}
		if(x<y){
			int s=0;
			rep(i,y){
				int c=cs[i];
				while(s&&f(rs[s-1],cs[s-1])<f(rs[s-1],c))
					s--;
				if(s<x)
					cs[s++]=c;
			}
			y=s;
		}
		auto a=rs+x,b=cs+y;
		int z=0;
		for(int i=1;i<x;i+=2)
			a[z++]=rs[i];
		rep(i,y)
			b[i]=cs[i];
		self(self,a,z,b,y);
		int k=0;
		for(int i=0;i<x;i+=2){
			int to=i+1<x?ans[rs[i+1]]:cs[y-1];
			D mx;
			while(1){
				D w=f(rs[i],cs[k]);
				if(ans[rs[i]]==-1||w>mx){
					ans[rs[i]]=cs[k];
					mx=w;
				}
				if(cs[k]==to)break;
				k++;
			}
		}
	};
	int*rs=new int[n*2];
	rep(i,n)rs[i]=i;
	int*cs=new int[max(m,n*2)];
	rep(i,m)cs[i]=i;
	rec(rec,rs,n,cs,m);
	delete[] rs;
	delete[] cs;
	return ans;
}

using A=array<int,2>;

void slv(){
	int n;cin>>n;
	vc<A> ps(n);
	rep(i,n)rep(j,2)cin>>ps[i][j];
	int ans=inf;
	rep(_,2){
		sort(all(ps));
		{
			vi buf(n);
			{
				A mn{inf,inf},mx{-inf,-inf};
				per(i,n){
					rep(j,2){
						chmin(mn[j],ps[i][j]);
						chmax(mx[j],ps[i][j]);
					}
					buf[i]=(mx[0]-mn[0])*(mx[1]-mn[1]);
				}
			}
			{
				A mn{inf,inf},mx{-inf,-inf};
				rep(i,n-1){
					rep(j,2){
						chmin(mn[j],ps[i][j]);
						chmax(mx[j],ps[i][j]);
					}
					chmin(ans,buf[i+1]+(mx[0]-mn[0])*(mx[1]-mn[1]));
				}
			}
		}
		A mn{inf,inf},mx{-inf,-inf};
		per(i,n){
			rep(j,2){
				chmin(mn[j],ps[i][j]);
				chmax(mx[j],ps[i][j]);
			}
		}
		int tot=(mx[0]-mn[0])*(mx[1]-mn[1]);
		vc<A> lf,rt;
		rep(i,n){
			if(lf.empty()||lf.back()[1]>ps[i][1])
				lf.pb(ps[i]);
		}
		per(i,n){
			if(rt.empty()||rt.back()[1]<ps[i][1])
				rt.pb(ps[i]);
		}
		{
			vc<A> tmp;
			rep(i,si(lf)-1){
				tmp.pb({lf[i+1][0],lf[i][1]});
			}
			lf=tmp;
		}
		reverse(all(rt));
		{
			vc<A> tmp;
			rep(i,si(rt)-1){
				tmp.pb({rt[i][0],rt[i+1][1]});
			}
			rt=tmp;
		}
		//reverse(all(rt));
		dmp(lf);
		dmp(rt);
		auto lowerleft=[&](const A&p){
			return (p[0]-mn[0])*(p[1]-mn[1]);
		};
		auto upperright=[&](const A&p){
			return (mx[0]-p[0])*(mx[1]-p[1]);
		};
		int val=0;
		if(si(lf)&&si(rt)){
			//cerr<<lf<<endl;
			//cerr<<rt<<endl;
			vi waf(si(lf)),relka(si(rt));
			rep(i,si(lf))waf[i]=lowerleft(lf[i]);
			rep(i,si(rt))relka[i]=upperright(rt[i]);
			auto func=[&](int i,int j){
				assert(lf[i][0]<=rt[j][0]);
				assert(lf[i][1]<=rt[j][1]);
				return waf[i]+relka[j]-(rt[j][0]-lf[i][0])*(rt[j][1]-lf[i][1]);
			};
			auto upd=[&](int i,int j){
				if(lf[i][0]<=rt[j][0]
				&& lf[i][1]<=rt[j][1])
					chmax(val,func(i,j));
			};
			const int K=2;
			auto rec2=[&](auto self,int l,int r,int b,int e)->void{
				if(r-l<=K||e-b<=K){
					rng(i,l,r)rng(j,b,e)upd(i,j);
					return;
				}
				const int m=(l+r)/2;
				int t=lf[m][1];
				int z=upper_bound(rt.bg+b,rt.bg+e,A{-inf,t},[](const A&x,const A&y){return x[1]>y[1];})-rt.bg;
				if(b<z){
					auto gunc=[&](int i,int j){
						return func(m+i,z-1-j);
					};
					vi idx=smawk<decltype(gunc),int>(gunc,r-m,z-b);
					rep(i,r-m)chmax(val,gunc(i,idx[i]));
				}
				self(self,l,m,b,z);
				self(self,m,r,z,e);
			};
			auto rec=[&](auto self,int l,int r,int b,int e)->void{
				if(r-l<=K||e-b<=K){
					rng(i,l,r)rng(j,b,e)upd(i,j);
					return;
				}
				const int m=(l+r)/2;
				int t=lf[m][0];
				int z=lower_bound(rt.bg+b,rt.bg+e,A{t,-inf})-rt.bg;
				rec2(rec2,l,m,z,e);
				self(self,l,m,b,z);
				self(self,m,r,z,e);
			};
			rec(rec,0,si(lf),0,si(rt));
		}
		chmin(ans,tot-val);
		for(auto&p:ps){
			p={-p[1],p[0]};
		}
	}
	{
		sort(all(ps));
		A mn{inf,inf},mx{-inf,-inf};
		per(i,n){
			rep(j,2){
				chmin(mn[j],ps[i][j]);
				chmax(mx[j],ps[i][j]);
			}
		}
		vc<A> lf,rt;
		vc<pi> waf,relka;
		{
			pi cur(ps[0][1],ps[0][1]);
			rep(i,n){
				lf.pb(ps[i]);
				waf.pb(cur);
				if(ps[i][1]==mn[1]||ps[i][1]==mx[1])break;
				chmin(cur.a,ps[i][1]);
				chmax(cur.b,ps[i][1]);
			}
		}
		{
			pi cur(ps[0][1],ps[0][1]);
			per(i,n){
				rt.pb(ps[i]);
				relka.pb(cur);
				if(ps[i][1]==mn[1]||ps[i][1]==mx[1])break;
				chmin(cur.a,ps[i][1]);
				chmax(cur.b,ps[i][1]);
			}
		}
		auto func=[&](int i,int j){
			int sum=(rt[j][0]-lf[i][0])*(mx[1]-mn[1]);
			sum+=(mx[0]-mn[0])*(max(waf[i].b,relka[j].b)-min(waf[i].a,relka[j].a));
			return -sum;
		};
		vi idx=smawk<decltype(func),int>(func,si(lf),si(rt));
		rep(i,si(lf))chmin(ans,-func(i,idx[i]));
	}
	print(ans);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int t;cin>>t;rep(_,t)
	slv();
}