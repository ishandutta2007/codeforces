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


template<class t>
struct BIT{
	vc<t> buf;
	int s;
	BIT(int n=0){init(n);}
	void init(int n){buf.assign(s=n,0);}
	void add(int i,t v){
		for(;i<s;i+=(i+1)&(-i-1))
			buf[i]+=v;
	}
	t get(int i){
		t res=0;
		for(;i>=0;i-=(i+1)&(-i-1))
			res+=buf[i];
		return res;
	}
	t sum(int b,int e){
		return get(e-1)-get(b-1);
	}
	int kth(int k){
		int res=0;
		for(int i=topbit(s);i>=0;i--){
			int w=res+(1<<i);
			if(w<=s&&buf[w-1]<=k){
				k-=buf[w-1];
				res=w;
			}
		}
		return res;
	}
	//yukicoder No.1024
	int kth_helper(int k,int i){
		return kth(k+get(i-1));
	}
};

//
//aq(x,y) 
//
//offline
//ROI2018 day2 D
struct point2d{
	struct query{
		int x,i,y;
		bool operator<(const query&rhs)const{
			return pi(x,-i)<pi(rhs.x,-rhs.i);
		}
	};
	vi ys,ans;
	vc<query> qs;
	point2d(const vc<tuple<int,int,int>>&ps){
		for(auto p:ps){
			int x,y,c;tie(x,y,c)=p;
			if(c)ys.pb(y);
		}
		mkuni(ys);
		for(auto p:ps){
			int x,y,c;tie(x,y,c)=p;
			if(c)qs.pb({x,-c,lwb(ys,y)});
		}
	}
	void aq(int x,int y){
		int i=si(ans);
		ans.pb(0);
		y=lwb(ys,y);
		qs.pb({x,i,y-1});
	}
	vi calc(){
		sort(all(qs));
		BIT<int> bit(si(ys));
		for(auto q:qs){
			if(q.i<0){
				bit.add(q.y,-q.i);
			}else{
				ans[q.i]+=bit.get(q.y);
			}
		}
		return ans;
	}
};

//#define GEOF

#ifdef GEOF
using ld=long double;
#else
using ld=ll;
#endif
using cm=complex<ld>;
#define x real()
#define y imag()
const ld eps=1e-12;
#ifdef GEOF
const ld PI=acos(ld(-1));
#endif
int sgn(ld a){return a<-eps?-1:(a>eps?1:0);}
ld rabs(cm a){return max(abs(a.x),abs(a.y));}
ld signed_rabs(cm a){
	if(abs(a.x)>abs(a.y))return a.x;
	else return a.y;
}
ld dot(cm a,cm b){return a.x*b.x+a.y*b.y;}
ld crs(cm a,cm b){return a.x*b.y-a.y*b.x;}
ld crs(cm a,cm b,cm c){return crs(b-a,c-a);}
int ccw(cm a,cm b){return sgn(crs(a,b));}
int ccw(cm a,cm b,cm c){return ccw(b-a,c-a);}
auto cmless=[](cm a,cm b){
	int s=sgn(a.x-b.x);
	if(s)return s<0;
	else return sgn(a.y-b.y)<0;
};
bool cmeq(cm a,cm b){
	return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;
};
//(-pi,0](0,pi]
int argtype(cm a){
	if(sgn(a.y)==0)return a.x<0?1:0;
	return a.y<0?0:1;
}
int argcmp(cm a,cm b){
	int at=argtype(a),bt=argtype(b);
	if(at!=bt)return at<bt?-1:1;
	return -ccw(a,b);
};
bool argless(cm a,cm b){return argcmp(a,b)<0;}
//(-2)[a,-1](0)[b,1](2)
int bet(cm a,cm b,cm c){
	cm d=b-a;
	ld e=dot(d,c-a);
	if(sgn(e)<=0)return sgn(e)-1;
	return sgn(e-norm(d))+1;
}
//AOJ0153
//0-no,1-edge,2-in
int cont(cm a,cm b,cm c,cm d){
	if(ccw(a,b,c)==-1)
		swap(b,c);
	return min({ccw(a,b,d),ccw(b,c,d),ccw(c,a,d)})+1;
}
#ifdef GEOF
//AOJ1183
int qeq(ld a,ld b,ld c,ld&d,ld&e){
	ld f=b*b-4*a*c;
	if(sgn(f)<0)return 0;
	ld g=sqrt(max(f,ld(0)));
	d=(-b+g)/(2*a);
	e=(-b-g)/(2*a);
	return sgn(f)+1;
}
//AOJ1183
//arg between ab
//assume given lengths are valid
ld arg(ld a,ld b,ld c){
	return acos(min(max((a*a+b*b-c*c)/(2*a*b),ld(-1)),ld(1)));
}
//AOJ2233
//a->b->c 
//a-b-c0
ld turn(cm a,cm b,cm c){
	return arg((c-b)/(b-a));
}
#endif
cm rot90(cm a){
	return cm(-a.y,a.x);
}

#ifndef GEOF
int gcd(int a,int b){return b?gcd(b,a%b):a;}
cm normdir(cm a){
	if(a==cm(0,0))return a;
	int g=gcd(abs(a.x),abs(a.y));
	return cm(a.x/g,a.y/g);
}
#endif


signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int k,n,q;cin>>k>>n>>q;
	vc<cm> cv;
	{
		vc<cm> ps;
		rep(i,k){
			int a,b;cin>>a>>b;
			ps.eb(a,b);
			ps.eb(-a,-b);
		}
		sort(all(ps),argless);
		cm z;
		rng(i,k,2*k)z+=ps[i];
		rep(i,k*2){
			cv.pb(z);
			z+=ps[i]*2LL;
		}
	}
	
	vc<tuple<int,int,int>> fs;
	int tot=0;
	rep(i,n){
		int a,b,c;cin>>a>>b>>c;
		fs.eb(a,b,c);
		tot+=c;
	}
	vc<tuple<int,int,int>> qs;
	rep(i,q){
		int a,b,c;cin>>a>>b>>c;
		qs.eb(a,b,c);
	}
	vi ans(q,tot);
	rep(pos,2*k){
		cm d=cv[pos],e=cv[(pos+1)%(2*k)],f=e-d;
		{//df
			cm g=rot90(d),h=rot90(f);
			vc<tuple<int,int,int>> rw;
			rep(i,n){
				int a,b,c;tie(a,b,c)=fs[i];
				rw.eb(dot(cm(a,b),g),dot(cm(a,b),h),c);
			}
			point2d w(rw);
			rep(i,q){
				int a,b,t;tie(a,b,t)=qs[i];
				cm z=cm(a,b)+d*t;
				w.aq(dot(z,g),dot(z,h));
			}
			vi tmp=w.calc();
			rep(i,q)ans[i]+=tmp[i];
		}
		{//df
			cm g=rot90(e),h=rot90(f);
			vc<tuple<int,int,int>> rw;
			rep(i,n){
				int a,b,c;tie(a,b,c)=fs[i];
				rw.eb(dot(cm(a,b),g),dot(cm(a,b),h),c);
			}
			point2d w(rw);
			rep(i,q){
				int a,b,t;tie(a,b,t)=qs[i];
				cm z=cm(a,b)+e*t;
				w.aq(dot(z,g),dot(z,h));
			}
			vi tmp=w.calc();
			rep(i,q)ans[i]-=tmp[i];
		}
	}
	for(auto v:ans)print(v);
}