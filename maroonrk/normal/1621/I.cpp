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

//VERIFY: yosupo
//AOJGRL5C
template<class t,class u>
struct sparsetable{
	vvc<t> a;
	u f;
	const t id;
	sparsetable(const vc<t>& d,u ff,t w):f(ff),id(w){
		if(d.empty())return;
		int n=d.size(),h=topbit(n);
		a.resize(h+1);
		a[0]=d;
		rng(j,1,h+1){
			a[j].resize(n-(1<<j)+1);
			rep(i,n-(1<<j)+1)
				a[j][i]=f(a[j-1][i],a[j-1][i+(1<<(j-1))]);
		}
	}
	t get(int b,int e){
		assert(b<=e);
		if(b==e)return id;
		int d=topbit(e-b);
		return f(a[d][b],a[d][e-(1<<d)]);
	}
};
const auto imin=[](int a,int b){
	return min(a,b);
};
using minst=sparsetable<int,decltype(imin)>;

//yosupo
//TKPPC G
struct SA{
	int n;
	vi sa,as,lcp;
	template<class t> SA(t s):n(s.size()),sa(n),as(n),lcp(n-1){
		rep(i,n)sa[i]=n-1-i;
		stable_sort(all(sa),[&](int a,int b){return s[a]<s[b];});
		vi c(n);
		rep(i,n)c[i]=s[i];
		for(int w=1;w<n;w*=2){
			vi d(c);
			rep(i,n){
				if(i&&sa[i-1]+w<n&&d[sa[i-1]]==d[sa[i]]&&d[sa[i-1]+w/2]==d[sa[i]+w/2])
					c[sa[i]]=c[sa[i-1]];
				else
					c[sa[i]]=i;
			}
			vi e(sa),f(n);
			iota(all(f),0);
			rep(i,n){
				int j=e[i]-w;
				if(j>=0)sa[f[c[j]]++]=j;
			}
		}
		//as
		rep(i,n)as[sa[i]]=i;
		//lcp
		int w=0;
		for(auto i:as){
			if(w)w--;
			if(i<n-1){
				while(max(sa[i],sa[i+1])+w<n&&s[sa[i]+w]==s[sa[i+1]+w])w++;
				lcp[i]=w;
			}
		}
	}
};

//Xmas2012B
template<class S>
struct string_cmp{
	S s;
	int n;
	SA sa;
	minst t;
	string_cmp(const S&ss):s(ss),n(si(s)),sa(s),t(sa.lcp,imin,inf){}
	int getlcp(int i,int j){
		if(i==n||j==n)return 0;
		if(i==j)return n-i;
		i=sa.as[i];
		j=sa.as[j];
		if(i>j)swap(i,j);
		return t.get(i,j);
	}
	int cmpchar(int i,int j){
		assert(0<=i&&i<n);
		assert(0<=j&&j<n);
		assert(s[i]!=s[j]);
		return s[i]<s[j]?-1:1;
	}
	//[a,b)<[c,d)-> -1
	//same -> 0
	//[a,b)>[c,d) -> 1
	int cmp(int a,int b,int c,int d){
		int len=min({getlcp(a,c),b-a,d-c});
		if(a+len==b&&c+len==d)return 0;
		if(a+len==b)return -1;
		if(c+len==d)return 1;
		return cmpchar(a+len,c+len);
	}
	int cmp_samelen(int a,int b,int len){
		return cmp(a,a+len,b,b+len);
	}
	//[l,r] 
	// 2  verify (Xmas2012 B)
	int cmp_list(vc<pi> a,vc<pi> b){
		int i=0,j=0;
		while(1){
			while(i<si(a)&&a[i].a==a[i].b)i++;
			while(j<si(b)&&b[j].a==b[j].b)j++;
			if(i==si(a)&&j==si(b))return 0;
			if(i==si(a))return -1;
			if(j==si(b))return 1;
			int k=min(a[i].b-a[i].a,b[j].b-b[j].a);
			int x=cmp_samelen(a[i].a,b[j].a,k);
			if(x)return x;
			a[i].a+=k;
			b[j].a+=k;
		}
		assert(0);
	}
};


//res[i]=start index of the lex-min suffix of a[:i+1]
vi lexmin_suffix(const vi&a){
	int n=si(a);
	string_cmp<vi> x(a);
	int val=inf,idx=-1;
	vi len(n),res(n);
	priority_queue<int> pq;
	rep(i,n){
		if(chmin(val,x.sa.as[i]))idx=i;
		len[i]=x.getlcp(idx,i);
		pq.push(i);
		while(1){
			int j=pq.top();
			if(i<j+len[j]){
				res[i]=j;
				break;
			}else{
				pq.pop();
			}
		}
	}
	return res;
}

vi advance(const vi&a){
	int n=si(a);
	vi ls=lexmin_suffix(a);
	vi b=a;reverse(all(b));
	string_cmp<vi> x(b);
	int pre=n;
	vc<pi> ans;
	rng(len,1,n+1){
		int mx=ls[n-len];
		int dif=(n-mx)-(len-1);
		int same=x.getlcp(len-1,n-mx)/dif;
		int mn=mx-same*dif;
		int use=pre==n-len+1?mx:mn;
		
		ans.eb(use,n-len+1);
		
		pre=use;
	}
	reverse(all(ans));
	vi res;
	int j=0;
	rep(i,n){
		while(ans[j].a==ans[j].b)j++;
		res.pb(a[ans[j].a++]);
	}
	return res;
}

void slv(){
	int n;cin>>n;
	vi a=readvi(n);
	vvc<int> b;
	while(1){
		b.pb(a);
		vi nx=advance(a);
		if(a==nx)break;
		a=nx;
	}
	int q;cin>>q;
	rep(_,q){
		int i,j;cin>>i>>j;
		chmin(i,si(b)-1);
		j--;
		print(b[i][j]);
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}