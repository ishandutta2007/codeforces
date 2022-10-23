#ifndef LOCAL
#pragma GCC optimize ("Ofast")
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

template<class t,class u>
void print_offset(const pair<t,u>&p,ll off,int suc=1){
	print(p.a+off,2);
	print(p.b+off,suc);
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

void YES(bool ex=true){
	cout<<"YES\n";
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void NO(bool ex=true){
	cout<<"NO\n";
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void Yes(bool ex=true){
	cout<<"Yes\n";
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void No(bool ex=true){
	cout<<"No\n";
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
//#define CAPITAL
/*
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
}*/
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
int botbit(ull a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
int popcount(ull t){
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

vc<ll> presum(const vi&a){
	vc<ll> s(si(a)+1);
	rep(i,si(a))s[i+1]=s[i]+a[i];
	return s;
}

bool dbg=false;
int ansx;
int num;

bool ask(vi ls){
	num++;
	if(dbg){
		static int pre;
		int cur=pre==1?0:rand_int(0,1);
		bool res=find(all(ls),ansx)!=ls.ed;
		res^=cur;
		pre=cur;
		return res;
	}else{
		cout<<"? "<<si(ls)<<" ";
		print_offset(ls,1);
		cout.flush();
		string s;cin>>s;
		return s[0]=='Y';
	}
}

int gnum=0;
bool guess(int x){
	gnum++;
	if(dbg){
		return ansx==x;
	}else{
		cout<<"! "<<x+1<<endl;
		string s;cin>>s;
		return s[1]==')';
	}
}

bool good(int a,int b,int p,int q){
	if(a+b>p+q)return true;
	if(a>p)return true;
	return false;
}

map<pi,int> memo;
map<pi,pi> sol;
const int smax=30;
int getcost(int a,int b){
	if(a<=2&&b<=1)return 0;
	if(memo.count(pi(a,b)))return memo[pi(a,b)];
	//cerr<<a<<" "<<b<<endl;
	int x=a/2,y=(b+1)/2;
	if(a<=smax&&b<=smax){
		int val=inf;
		rep(i,a+1)rep(j,b+1){
			int p=i+j,q=a-i;
			int r=(a-i)+(b-j),s=i;
			if(good(a,b,p,q)&&good(a,b,r,s)){
				int u=getcost(p,q);
				int v=getcost(r,s);
				if(chmin(val,max(u,v)+1)){
					x=i,y=j;
				}
			}
		}
	}
	assert(good(a,b,x,y));
	int u=getcost(x+y,a-x);
	int v=getcost((a-x)+(b-y),x);
	sol[pi(a,b)]=pi(x,y);
	return memo[pi(a,b)]=max(u,v)+1;
}

pair<vi,vi> make_half(vi a,int len){
	return mp(vi(a.bg,a.bg+len),vi(a.bg+len,a.ed));
}

void slv(){
	int n;
	if(dbg){
		n=ten(5);
		ansx=rand_int(0,n-1);
		dmp(ansx);
		//cerr<<ansx<<endl;
	}else{
		cin>>n;
	}
	
	vi a(n);iota(all(a),0);
	myshuffle(a);
	vi b;
	while(si(a)>2||si(b)>1){
		dmp2(a,b);
		//if(si(a)==3&&si(b)==1){
		if(0){
			a.pb(b.back());
			b.pop_back();
		}
		getcost(si(a),si(b));
		auto [alen,blen]=sol[pi(si(a),si(b))];
		auto [x,y]=make_half(a,alen);
		auto [p,q]=make_half(b,blen);
		a.clear();
		b.clear();
		
		p.insert(p.ed,all(x));
		q.insert(q.ed,all(y));
		
		bool res=ask(p);
		if(res){
			//true
			a=p;
			//false
			b=y;
		}else{
			//true
			a=q;
			//false
			b=x;
		}
	}
	//cerr<<num<<endl;
	//assert(num<=51);
	dmp(a);
	dmp(b);
	if(si(a)+si(b)<=2){
		for(auto v:a)if(guess(v))return;
		for(auto v:b)if(guess(v))return;
		assert(false);
	}
//	dmp(a);
	//dmp(b);
	bool res=ask(b);
	if(res){
		if(guess(b[0]))return;
		bool ok=false;
		if(ask(vi{a[0]}))ok=guess(a[0]);
		else ok=guess(a[1]);
		assert(ok);
	}else{
		for(auto v:a)if(guess(v))return;
		assert(false);
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	//slv();
	if(0){
		int a=ten(5),b=0;
		cout<<getcost(a,b)<<endl;
		rep(step,55){
			if(a<=2&&b<=1)break;
			/*if(a==3&&b==1){
				a++;
				b--;
			}*/
			/*if(b%2==1){
				a++;
				b--;
			}*/
			//tie(a,b)=getsol(a,b);
			//cerr<<step+1<<" "<<a<<" "<<b<<endl;
		}
		return 0;
	}
	
	if(dbg){
		int mx=0,cnt=0;
		rep(_,1000){
			cerr<<_<<endl;
			slv();
			assert(gnum<=2);
			//cerr<<num<<endl;
			chmax(mx,num);
			if(num==54)cnt++;
			num=0;
			gnum=0;
		}
		cerr<<mx<<" "<<cnt<<endl;
	}else{
		slv();
	}
}