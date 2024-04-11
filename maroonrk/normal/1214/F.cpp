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

vc<pi> morita(vi len,vi d){
	int n=len.size();
	vi pos{0};
	for(auto&v:d){
		chmax(v,0);
		pos.pb(v);
	}
	mkuni(pos);
	int s=pos.size();
	vi sum(s);
	rep(i,n){
		sum[0]+=-len[i];
		sum[lower_bound(all(pos),d[i])-pos.bg]+=len[i]*2;
	}
	rep(i,s-1)sum[i+1]+=sum[i];
	vc<pi> res;
	rep(i,s-1)
		res.eb(sum[i],pos[i+1]-pos[i]);
	return res;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int m,n;cin>>m>>n;
	vi a=readvi(n),b=readvi(n);
	
	vi c;
	for(auto v:a)c.pb(v);
	for(auto v:b)c.pb(v);
	mkuni(c);
	int s=c.size();
	vi len(s-1),d(s-1);
	rep(i,s-1)len[i]=c[i+1]-c[i];
	int base=0;
	{
		vi buf(s);
		for(auto v:a)buf[lower_bound(all(c),v)-c.bg]--;
		for(auto v:b)buf[lower_bound(all(c),v)-c.bg]++;
		int cur=0;
		rep(i,s-1){
			cur+=buf[i];
			d[i]=cur;
			base+=len[i]*abs(cur);
		}
	}
	int sgm=m-(c.back()-c.front());
	pi ans(0,0);
	rep(_,2){
		vc<pi> x=morita(len,d);
		int res=0,am=0;
		for(auto ab:x){
			int slp=ab.a+sgm;
			if(slp>=0)continue;
			res+=slp*ab.b;
			am+=ab.b;
		}
		if(_)am=-am;
		chmin(ans,pi(res,am));
		
		reverse(all(len));
		reverse(all(d));
		for(auto&v:d)v=-v;
	}
	cout<<base+ans.a<<endl;
	int f=ans.b;
	
	vvc<int> x(s),y(s);
	vi in,out;
	rep(i,n)y[lower_bound(all(c),a[i])-c.bg].pb(i);
	rep(i,n)x[lower_bound(all(c),b[i])-c.bg].pb(i);
	int nn=n+abs(f);
	vi p(nn,-1),q(nn,-1);
	rep(i,f)y[0].pb(n+i);
	rep(i,f)x[s-1].pb(n+i);
	rep(i,-f)x[0].pb(n+i);
	rep(i,-f)y[s-1].pb(n+i);
	rep(i,s){
		for(auto j:x[i])in.pb(j);
		for(auto j:y[i])out.pb(j);
		while(in.size()&&out.size()){
			int g=in.back();in.pop_back();
			int h=out.back();out.pop_back();
			p[g]=h;
			q[h]=g;
		}
	}
	rep(i,n){
		int j=q[i];
		if(j>=n)j=q[j];
		assert(j<n);
		print(j+1,i==n-1?1:2);
	}
}