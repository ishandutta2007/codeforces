#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=a;i--)
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
		cout<<endl;
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

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
    static random_device rd;
    static mt19937 gen(rd());
    return uniform_int_distribution<ll>(l, r)(gen);
}

int gcd(int a,int b){return b?gcd(b,a%b):a;}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,k;cin>>n>>k;
	vi a=readvi(n),e=readvi(n);
	
	int g=0;
	for(auto v:a)g=gcd(g,v);
	if(g==1){
		cout<<0<<endl;
		return 0;
	}
	
	vi p;
	for(int i=2;i*i<=g;i++){
		if(g%i==0){
			p.pb(i);
			while(g%i==0)g/=i;
		}
	}
	if(g>1)p.pb(g);
	
	vc<pi> c;
	vi xs;
	rep(i,n){
		int x=1;
		for(auto v:p)
			while(a[i]%v==0){
				a[i]/=v;
				x*=v;
			}
		c.eb(e[i],x);
		xs.pb(x);
	}
	sort(all(c));
	mkuni(xs);
	vi cnt(xs.size());
	
	int m=p.size();
	vc<int> d(1<<m,0);
	vc<pi> f;
	for(auto w:c){
		{
			int i=lower_bound(all(xs),w.b)-xs.bg;
			if(cnt[i]==m)continue;
			cnt[i]++;
		}
		
		vi z(m,1);
		rep(i,p.size()){
			int x=w.b;
			while(x%p[i]==0){
				z[i]*=p[i];
				x/=p[i];
			}
		}
		
		bool u=false;
		rng(bit,1,1<<m){
			int x=1;
			rep(i,m)if(bit&1<<i)x*=z[i];
			if(x<=k){
				if(d[bit]<m){
					d[bit]++;
					u=true;
				}
			}
		}
		if(u)
			f.pb(w);
	}
	
	vvc<int> dp(1<<m,vi(m+1,inf/m));
	dp[0][0]=0;
	for(auto w:f){
		vi z(m,1);
		rep(i,p.size()){
			int x=w.b;
			while(x%p[i]==0){
				z[i]*=p[i];
				x/=p[i];
			}
		}
		dmp(z);
		vi q;
		rng(bit,1,1<<m){
			int x=1;
			rep(i,m)if(bit&1<<i)x*=z[i];
			if(x<=k){
				q.pb(bit);
			}
		}
		
		per(bit,1<<m){
			rng(i,1,m+1){
				for(auto v:q)if((v&bit)==v)
					chmin(dp[bit][i],dp[bit-v][i-1]+w.a);
			}
		}
	}
	
	int ans=inf/m;
	rng(i,1,m+1)
		chmin(ans,dp[(1<<m)-1][i]*i);
	if(ans==inf/m)
		ans=-1;
	cout<<ans<<endl;
}