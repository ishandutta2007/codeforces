#ifndef LOCAL
#pragma GCC optimize ("-Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

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

const int nmax=30010;
const int mmax=60;
using B=bitset<nmax>;
B tar[mmax];
B lf[mmax],rt[mmax];
B lf2[mmax],rt2[mmax];

void slv(){
	int d,m;cin>>d>>m;
	vi gen=readvi(d);
	int n;cin>>n;
	vi b=readvi(n);
	rep(i,n)rng(j,b[i]+1,m)tar[j][n-1-i]=1;
	vi w{1};
	while(w.back()<=ten(18)/d)w.pb(w.back()*d);
	vi hid(n*d),mig(n*d);
	//left
	{
		int num=w.back()-1,cur=0;
		rep(i,si(hid)){
			hid[i]=cur;
			
			int tmp=num;
			while(1){
				int p=tmp/d,q=tmp%d;
				cur-=gen[q];
				if(q){
					cur+=gen[q-1];
					break;
				}else{
					cur+=gen[d-1];
					tmp=p;
				}
			}
			cur=(cur%m+m)%m;
			num--;
		}
	}
	dmp(hid);
	//mig.resize(16);
	//right
	{
		int num=0,cur=0;
		rep(i,si(mig)){
			mig[i]=cur;
			
			int tmp=num;
			while(1){
				int p=tmp/d,q=tmp%d;
				cur-=gen[q];
				if(q+1<d){
					cur+=gen[q+1];
					break;
				}else{
					cur+=gen[0];
					tmp=p;
				}
			}
			cur=(cur%m+m)%m;
			num++;
		}
	}
	dmp(mig);
	
	auto getleft=[&](int val,int len){
		pi P(val,len);
		static map<pi,B> memo;
		if(memo.count(P))return memo[P];
		B res;
		rep(i,len)res|=tar[(hid[i]+val)%m]>>(i+1);
		return memo[P]=res;
	};
	
	auto getright=[&](int val,int len){
		pi P(val,len);
		static map<pi,B> memo;
		if(memo.count(P))return memo[P];
		B res;
		rep(i,len)res|=tar[(mig[i]+val)%m]<<i;
		return memo[P]=res;
	};
	
	rep(val,m){
		lf[val]=getleft(val,n-1);
		rt[val]=getright(val,n-1);
	}
	
	int baka=0;
	
	auto calc=[&](auto self,int len,int off)->int{
		if(len<n)return 0;
		pi P(len,off);
		static map<pi,int> memo;
		if(memo.count(P))return memo[P];
		
		int ans=0;
		int lv=lwb(w,len);
		if(lv==0){
			return b[0]>=off;
		}else{
			lv--;
			if(w[lv]<n-1){
				B msk;
				rep(i,n-1)msk[i]=true;
				//cerr<<len<<endl;
				baka+=len;
				assert(len<=n*d);
				int e=(w[lv]*d+n-2)/(n-1);
				vc<B> buf(e);
				auto add=[&](int x,const B&u){
					int q=(x%(n-1)+n-1)%(n-1),p=(x-q)/(n-1);
					if(p>=0){
						buf[p]|=u<<q;
					}
					if(q>0){
						p++;
						assert(p<e);
						buf[p]|=u>>(n-1-q);
					}
				};
				rep(i,d){
					add(i*w[lv]-(n-1),getright((off+gen[i])%m,w[lv])&msk);
					add((i+1)*w[lv]-(n-1),getleft((off+gen[i]+gen[d-1]*lv)%m,w[lv])&msk);
				}
				rep(i,len-n+1){
					if(!buf[i/(n-1)][i%(n-1)])ans++;
				}
			}else{
				for(int i=0;i*w[lv]<len;i++){
					ans+=self(self,min(len-i*w[lv],w[lv]),(off+gen[i])%m);
					if(i>0){
						/*if(len==16&&off==0){
							dmp(ans);
						}*/
						//dmp2(len,off,ans,i);
						auto z=lf[(off+gen[i-1]+lv*gen[d-1])%m]|rt[(off+gen[i])%m];
						//dmp2((off+gen[i-1])%m,lf[(off+gen[i-1])%m][0]);
						//dmp2(rt[(off+gen[i])%m][0]);
						rep(j,n-1)if(!z[j]&&i*w[lv]+1+j<=len)
							ans++;
					}
				}
			}
		}
		
		/*if(len<=si(mig)){
			int cnt=0;
			rep(i,len-n+1){
				bool ok=true;
				rep(j,n)if(b[j]<(mig[i+j]+off)%m){
					ok=false;
				}
				if(ok)cnt++;
			}
			if(cnt!=ans){
				dmp2(len,off);
				dmp2("correct",cnt);
				dmp2("ans",ans);
				assert(false);
			}
		}*/
		
		dmp2(len,off,ans);
		return memo[P]=ans;
	};
	
	int ans=0;
	{
		int v;cin>>v;v--;
		v+=n-1;
		ans-=calc(calc,v,0);
	}
	{
		int v;cin>>v;
		ans+=calc(calc,v,0);
	}
	cerr<<baka<<endl;
	print(ans);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}