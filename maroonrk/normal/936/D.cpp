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

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,m1,m2,t;cin>>n>>m1>>m2>>t;
	vi lw=readvi(m1);
	vi up=readvi(m2);
	vi pos{0,n+1};
	rep(i,m1){
		pos.pb(lw[i]);
		pos.pb(lw[i]-1);
		pos.pb(lw[i]+1);
	}
	rep(i,m2){
		pos.pb(up[i]);
		pos.pb(up[i]-1);
		pos.pb(up[i]+1);
	}
	mkuni(pos);
	int s=si(pos);
	
	vc<array<char,2>> obs(s);
	for(auto v:lw)obs[lwb(pos,v)][0]=1;
	for(auto v:up)obs[lwb(pos,v)][1]=1;
	
	vc<array<pi,2>> dp(s,{pi(-inf,-1),pi(-inf,-1)});
	dp[0][0]=pi(0,-1);
	dp[0][1]=pi(0,1);
	
	rep(i,s-1){
		rep(j,2)if(dp[i][j].a>=0){
			if(obs[i+1][j]){
				int z=max(int(0),t-dp[i][j].a);
				if(pos[i]+z<pos[i+1])
					dp[i+1][j]=pi(dp[i][j].a+pos[i+1]-pos[i]-t,0);
			}else{
				dp[i+1][j]=pi(dp[i][j].a+pos[i+1]-pos[i],0);
			}
		}
		rep(j,2){
			int w=min(t,dp[i+1][j].a);
			if(w>dp[i+1][j^1].a&&!obs[i+1][j^1]){
				dp[i+1][j^1]=pi(w,1);
			}
		}
	}
	
	if(dp[s-1][0].a>=0){
		yes(0);
		
		vi vert;
		vc<pi> shot;
		
		auto makeshot=[&](int x,int y,int c,int num){
			assert(c<=t);
			int d=t-c;
			per(i,num)
				shot.eb(x+t*i+d,y+1);
		};
		
		int x=s-1,y=0,cur=0;
		while(dp[x][y].b!=-1){
			if(dp[x][y].b==0){
				cur+=obs[x][y];
				x--;
			}else{
				makeshot(pos[x],y,dp[x][y].a,cur);
				cur=0;
				vert.pb(pos[x]);
				y^=1;
			}
		}
		makeshot(0,0,0,cur);
		
		reverse(all(vert));
		reverse(all(shot));
		
		print(si(vert));
		print(vert);
		print(si(shot));
		for(auto v:shot){
			print(v.a,2);
			print(v.b);
		}
	}else{
		no();
	}
}