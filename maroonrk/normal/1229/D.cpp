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

const int v=3;
const int m=7;

int id(int k){
	int x=0;
	rep(i,k)
		x+=i*(1<<i*v);
	return x;
}

vi enumerate(int k,vi t){
	set<int> vis;
	vi q;
	int head=0;
	auto r=[&](int x){
		if(vis.count(x))return;
		vis.insert(x);
		q.pb(x);
	};
	r(id(k));
	while(head<(int)q.size()){
		int x=q[head++];
		for(auto e:t){
			int y=0;
			rep(i,k)
				y+=((e>>((x>>i*v)&m)*v)&m)<<i*v;
			r(y);
		}
	}
	return vi(all(vis));
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,k;cin>>n>>k;
	
	auto getv=[&](vi p){
		int x=0;
		rep(i,k)
			x+=p[i]<<i*v;
		return x;
	};
	vi ps;
	{
		vi p(k);
		iota(all(p),0);
		do
			ps.pb(getv(p));
		while(next_permutation(all(p)));
	}
	dmp(ps);
	map<vi,int> idx;
	vvc<int> buf;
	vvc<int> to;
	auto r=[&](vi x){
		if(idx.count(x))return idx[x]; 
		idx[x]=buf.size();
		buf.pb(x);
		to.eb(ps.size());
		return idx[x];
	};
	r({id(k)});
	int head=0;
	while(head<(int)buf.size()){
		vi cur=buf[head];
		rep(i,ps.size()){
			vi tmp=cur;tmp.pb(ps[i]);
			vi z=enumerate(k,tmp);
			to[head][i]=r(z);
		}
		head++;
	}
	
	int ans=0;
	vc<pi> st;
	rep(_,n){
		vi p(k);
		rep(i,k){
			cin>>p[i];
			p[i]--;
		}
		int x=getv(p);
		int y=find(all(ps),x)-ps.bg;
		for(auto&z:st)
			z.a=to[z.a][y];
		st.eb(to[0][y],1);
		int last=-1;
		vc<pi> nx;
		for(auto z:st){
			if(last!=z.a)
				nx.eb(z.a,0);
			last=z.a;
			nx.back().b+=z.b;
		}
		swap(nx,st);
		for(auto z:st)
			ans+=buf[z.a].size()*z.b;
		for(auto z:st){
			dmp(buf[z.a]);
			dmp(z.b);
		}
	}
	
	cout<<ans<<endl;
}