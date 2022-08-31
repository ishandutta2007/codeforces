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

using uint=unsigned;
using ull=unsigned long long;

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

void print(ll x,int suc=1){
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
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
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
	return __builtin_ctz(a);
}
int botbit(ll a){
	return __builtin_ctzll(a);
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

using uint=unsigned;
using ull=unsigned long long;

//const uint mod=998244353;
const uint mod=1000000007;
//uint mod=1;
struct mint{
	uint v;
	mint(ll vv=0){s(vv%mod+mod);}
	mint& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	mint operator-()const{return mint()-*this;}
	mint& operator+=(const mint&rhs){return s(v+rhs.v);}
	mint&operator-=(const mint&rhs){return s(v+mod-rhs.v);}
	mint&operator*=(const mint&rhs){
		v=ull(v)*rhs.v%mod;
		return *this;
	}
	mint&operator/=(const mint&rhs){return *this*=rhs.inv();}
	mint operator+(const mint&rhs)const{return mint(*this)+=rhs;}
	mint operator-(const mint&rhs)const{return mint(*this)-=rhs;}
	mint operator*(const mint&rhs)const{return mint(*this)*=rhs;}
	mint operator/(const mint&rhs)const{return mint(*this)/=rhs;}
	mint pow(int n)const{
		mint res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	mint inv()const{return pow(mod-2);}
	/*mint inv()const{
		int x,y;
		int g=extgcd(v,mod,x,y);
		assert(g==1);
		if(x<0)x+=mod;
		return mint(x);
	}*/
	friend ostream& operator<<(ostream&os,const mint&m){
		return os<<m.v;
	}
	bool operator<(const mint&r)const{return v<r.v;}
	bool operator==(const mint&r)const{return v==r.v;}
};

const int vmax=(1<<21)+10;
mint fact[vmax],finv[vmax],invs[vmax];
void initfact(){
	fact[0]=1;
	rng(i,1,vmax){
		fact[i]=fact[i-1]*i;
	}
	finv[vmax-1]=fact[vmax-1].inv();
	for(int i=vmax-2;i>=0;i--){
		finv[i]=finv[i+1]*(i+1);
	}
	for(int i=vmax-1;i>=1;i--){
		invs[i]=finv[i]*fact[i-1];
	}
}
mint choose(int n,int k){
	return fact[n]*finv[n-k]*finv[k];
}
mint binom(int a,int b){
	return fact[a+b]*finv[a]*finv[b];
}
mint catalan(int n){
	return binom(n,n)-(n-1>=0?binom(n-1,n+1):0);
}

template<class E,class D=ll>
vc<D> dijkstra(const vvc<E>& g,int s){
	const int n=g.size();
	using P=pair<D,int>;
	priority_queue<P,vc<P>,greater<P>> pq;
	vc<D> dist(n,inf);
	const auto ar=[&](int v,D d){
		if(dist[v]>d){
			dist[v]=d;
			pq.push(P(d,v));
		}
	};
	ar(s,0);
	while(pq.size()){
		D d;
		int v;
		tie(d,v)=pq.top();pq.pop();
		for(auto e:g[v])
			ar(e.to,d+e.cost);
	}
	return dist;
}

const int nmax=1200010;
int g[nmax][10],z[nmax][10];
int vis[nmax];
mint ans[nmax];

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,m;cin>>n>>m;
	vvc<tuple<int,int,int>> raw(n);
	struct E{int to,cost;};
	vvc<E> dg(n);
	rng(i,1,m+1){
		int x,y;cin>>x>>y;
		x--;y--;
		int v=i,cnt=0;
		while(v){
			cnt++;
			v/=10;
		}
		dg[x].pb(E{y,cnt});
		dg[y].pb(E{x,cnt});
		raw[x].eb(y,i,cnt);
		raw[y].eb(x,i,cnt);
	}
	
	vi d=dijkstra<E,int>(dg,0);
	
	int s=n;
	one(g);
	one(z);
	rep(i,n){
		for(auto e:raw[i]){
			int to,idx,cnt;tie(to,idx,cnt)=e;
			if(d[i]+cnt==d[to]){
				string str=to_string(idx);
				int x=i,y=-1,last=-1;
				for(auto cc:str){
					int c=cc-'0';
					if(g[x][c]==-1)
						g[x][c]=s++;
					tie(x,y)=pi(g[x][c],x);
					last=c;
				}
				z[y][last]=to;
			}
		}
	}
	
	const int ini=100;
	rep(i,s)vis[i]=ini;
	vvc<int> st;
	vis[0]=0;
	st.pb(vi{0});
	while(st.size()){
		vi cur=st.back();
		st.pop_back();
		mint val=ans[cur[0]]*10;
		vi ls;
		auto rc=[&](int a,int i){
			if(vis[a]==ini)ls.pb(a);
			chmin(vis[a],i);
		};
		for(auto v:cur){
			rep(i,10)if(g[v][i]!=-1){
				rc(g[v][i],i);
				if(z[v][i]!=-1)
					rc(z[v][i],i);
			}
		}
		vi nx[10];
		for(auto v:ls){
			ans[v]=val+vis[v];
			nx[vis[v]].pb(v);
		}
		per(i,10)if(nx[i].size())
			st.pb(nx[i]);
	}
	rng(i,1,n)
		cout<<ans[i]<<"\n";
}