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
    static random_device rd;
    static mt19937_64 gen(rd());
    return uniform_int_distribution<ll>(l, r)(gen);
}

//AGC33 C
template<class E>
struct treediameter{
	const vvc<E>&g;
	int r1,r2;
	vi d1,d2;
	int dia;
	void dfs(int v,int p,int cur,vi&d){
		d[v]=cur;
		for(auto e:g[v])if(e!=p)
			dfs(e,v,cur+1,d);
	}
	treediameter(const vvc<E>&gg):g(gg),d1(g.size()),d2(g.size()){
		dfs(0,-1,0,d1);
		r1=max_element(all(d1))-d1.bg;
		dfs(r1,-1,0,d1);
		r2=max_element(all(d1))-d1.bg;
		dfs(r2,-1,0,d2);
		dia=d1[r2];
	}
};

vvc<int> g;
const int nmax=200010;
int n,k,len[nmax];
int dfs1(int v,int p){
	for(auto c:g[v])if(c!=p)
		chmax(len[v],dfs1(c,v)+1);
	return len[v];
}

void dfs2(int v,int p,int mx){
	vi x;
	if(mx!=-1)x.pb(mx);
	for(auto c:g[v])if(c!=p)
		x.pb(len[c]+1);
	sort(all(x),greater<int>());
	if(x.size()>=3&&x[1]+x[2]+1>=k)no();
	x.pb(0);
	for(auto c:g[v])if(c!=p){
		int w=x[0];
		if(w==len[c]+1)
			w=x[1];
		dfs2(c,v,w+1);
	}
}

int ans[nmax];
void out(){
	yes(0);
	rep(i,n){
		print(ans[i]+1,i==n-1?1:2);
	}
	exit(0);
}
void dfs3(int v,int w,int d){
	if(ans[v]!=-1)return;
	ans[v]=w;
	for(auto to:g[v])
		dfs3(to,(w+d)%k,d);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	one(ans);
	cin>>n>>k;
	g.resize(n);
	rep(_,n-1){
		int a,b;cin>>a>>b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	if(k==2){
		dfs3(0,0,1);
		out();
	}
	dfs1(0,-1);
	dfs2(0,-1,-1);
	auto dia=treediameter<int>(g);
	int s=dia.dia+1;
	vi idx(s);
	rep(i,n)if(dia.d1[i]+dia.d2[i]==dia.dia){
		idx[dia.d1[i]]=i;
		ans[i]=dia.d1[i]%k;
	}
	dmp(idx);
	rep(ii,s){
		int i=idx[ii];
		int tmp=ans[i];
		ans[i]=-1;
		dfs3(i,tmp,ii<(s-1-ii)?(k-1):1);
	}
	out();
}