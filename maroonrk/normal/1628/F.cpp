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

#define CAPITAL
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

//copied from yosupo's library
//PARTLY VERIFIED

//USACO 2022 January Platinum C

//#define GEOF

#ifdef GEOF
using ld=long double;
#else
using ld=ll;
#endif
const ld eps=1e-9;
int sgn(ld a){return a<-eps?-1:(a>eps?1:0);}
int sgn(ld a,ld b){return sgn(a-b);}
struct P {
    ld x, y;
    P(ld _x = ld(0), ld _y = ld(0)) : x(_x), y(_y) {}
    P operator+(const P& r) const { return {x + r.x, y + r.y}; }
    P operator-(const P& r) const { return {x - r.x, y - r.y}; }
    P operator*(const P& r) const {
        return {x * r.x - y * r.y, x * r.y + y * r.x};
    }

    P operator*(const ld& r) const { return {x * r, y * r}; }
    P operator/(const ld& r) const { return {x / r, y / r}; }

    P& operator+=(const P& r) { return *this = *this + r; }
    P& operator-=(const P& r) { return *this = *this - r; }
    P& operator*=(const P& r) { return *this = *this * r; }
    P& operator*=(const ld& r) { return *this = *this * r; }
    P& operator/=(const ld& r) { return *this = *this / r; }

    P operator-() const { return {-x, -y}; }

    bool operator<(const P& r) const {
        return 2 * sgn(x, r.x) + sgn(y, r.y) < 0;
    }
    bool operator==(const P& r) const { return sgn((*this - r).rabs()) == 0; }
    bool operator!=(const P& r) const { return !(*this == r); }

    ld norm() const { return x * x + y * y; }
    ld rabs() const { return max(std::abs(x), std::abs(y)); }  // robust abs
    pair<ld, ld> to_pair() const { return {x, y}; }
    #ifdef GEOF
    ld abs() const { return sqrt(norm()); }
    ld arg() const { return atan2(y, x); }
    static P polar(ld le, ld th) { return {le * cos(th), le * sin(th)}; }
	#endif
};
istream& operator>>(istream& is, P& p){
	return is>>p.x>>p.y;
}
ostream& operator<<(ostream& os, const P& p) {
    return os << "P(" << p.x << ", " << p.y << ")";
}
ld norm(const P&a){
	return a.norm();
}
ld norm(const P&a,const P&b){
	return (a-b).norm();
}
ld dot(const P&a,const P&b){return a.x*b.x+a.y*b.y;}
ld crs(const P& a,const P& b){return a.x*b.y-a.y*b.x;}
ld crs(const P& a,const P& b,const P& c){return crs(b-a,c-a);}
int ccw(const P& a,const P& b){return sgn(crs(a,b));}
int ccw(const P& a,const P& b,const P& c){return ccw(b-a,c-a);}
//(-pi,0](0,pi]
int argtype(const P&a){
	if(sgn(a.y)==0)return a.x<0?1:0;
	return a.y<0?0:1;
}
int argcmp(const P&a,const P&b){
	int at=argtype(a),bt=argtype(b);
	if(at!=bt)return at<bt?-1:1;
	return -ccw(a,b);
};
bool argless(const P&a,const P&b){return argcmp(a,b)<0;}
//(-2)[a,-1](0)[b,1](2)
int bet(P a,P b,P c){
	P d=b-a;
	ld e=dot(d,c-a);
	if(sgn(e)<=0)return sgn(e)-1;
	return sgn(e-norm(d))+1;
}
P rot90(P a){
	return P(-a.y,a.x);
}

using ln=pair<P,P>;
P dir(ln a){return a.b-a.a;}

//AOJ1157
//0-no,1-yes(endpoint),2-yes(innner),3-overelap
//if the two line touch like this
// x----x----x
//it returns 1
int iss(ln a,ln b){
	int c1=ccw(a.a,a.b,b.a),c2=ccw(a.a,a.b,b.b);
	int d1=ccw(b.a,b.b,a.a),d2=ccw(b.a,b.b,a.b);
	if(c1||c2||d1||d2)return 1-max(c1*c2,d1*d2);
	int f=bet(a.a,a.b,b.a),g=bet(a.a,a.b,b.b);
	if(max(f,g)==-2||min(f,g)==2)return 0;
	if(max(f,g)==-1||min(f,g)==1)return 1;
	return 3;
}

ll fdiv(ll a, ll b) { // floored division
	return a / b - ((a ^ b) < 0 && a % b); }

bool check45(P a,P b){
	int v=dot(a,b);//|a||b|cos^2(theta)
	int s=v*v;
	return s*2>norm(a)*norm(b);
}

int cury;

struct N{
	P a,b;
	int i;
};

pi getxfrac(const N&z){
	const P&a=z.a;
	const P&b=z.b;
	int num=a.x*(b.y-cury)+b.x*(cury-a.y);
	int den=b.y-a.y;
	if(den<0){
		num=-num;
		den=-den;
	}
	return pi(num,den);
}

bool cmp(const N&a,const N&b){
	auto [an,ad]=getxfrac(a);
	auto [bn,bd]=getxfrac(b);
	return an*bd<bn*ad;
}

void slv(){
	int n;cin>>n;
	vc<ln> ls(n);
	rep(i,n)cin>>ls[i].a>>ls[i].b;
	int qnum;cin>>qnum;
	vc<P> qs(qnum);
	rep(i,qnum)cin>>qs[i];
	
	vc<bool> ans(qnum);
	
	rep(i,qnum){
		bool ok=true;
		rep(j,n)if(iss(ls[j],ln(P(),qs[i]))){
			ok=false;
			break;
		}
		if(ok)ans[i]=true;
	}
	
	vc<pi> z;
	vi par(n),look(qnum),val(n);
	
	rep(taridx,n){
		auto [tar,unko]=ls[taridx];
		if(norm(tar)>norm(unko))swap(tar,unko);
		if(!check45(tar,unko-tar))continue;
		{
			bool ok=true;
			rep(i,n)if(i!=taridx){
				if(iss(ln(P(),tar),ls[i])){
					ok=false;
					break;
				}
			}
			if(!ok)continue;
		}
		P vert=rot90(tar);
		auto trans=[&](P p){
			return P(dot(tar,p),dot(vert,p));
		};
		z.clear();
		z.eb(0,-1);
		z.eb(2,-1);
		rep(i,n){
			P a=trans(ls[i].a),b=trans(ls[i].b);
			if(a.y==b.y)continue;
			if(a.y>b.y)swap(a,b);
			z.eb(a.y*3+0,i);
			z.eb(b.y*3+2,i);
			if(a.x<b.x)z.eb(a.y*3+1,i);
			else z.eb(b.y*3+1,i);
		}
		//dmp(z);
		rep(i,qnum)z.eb(trans(qs[i]).y*3+1,i+n);
		sort(all(z));
		
		fill(all(par),-1);
		fill(all(look),-1);
		set<N,decltype(cmp)*> s(cmp);
		cury=-inf;
		for(auto [y,i]:z){
			cury=fdiv(y,3);
			int tp=y-cury*3;
			if(tp==0){
				if(i==-1)s.insert(N{P(),P(0,1),-2});
				else s.insert(N{trans(ls[i].a),trans(ls[i].b),i});
			}else if(tp==1){
				P a,b;
				if(i<n){
					a=trans(ls[i].a);
					b=trans(ls[i].b);
				}else{
					a=trans(qs[i-n]);
					b=a;b.y++;
				}
				auto itr=s.lower_bound(N{a,b,-1});
				if(itr!=s.bg){
					itr--;
					if(i<n)par[i]=itr->i;
					else look[i-n]=itr->i;
				}
			}else if(tp==2){
				if(i==-1)s.erase(N{P(),P(0,1),-2});
				else s.erase(N{trans(ls[i].a),trans(ls[i].b),i});
			}else{
				exit(0);
				assert(false);
			}
		}
		
		dmp(tar);
		dmp(par);
		dmp(look);
		
		fill(all(val),-1);
		auto calc=[&](auto self,int i)->int{
			if(val[i]!=-1)return val[i];
			if(!check45(tar,dir(ls[i])))return val[i]=0;
			if(par[i]==-2)return val[i]=1;
			if(par[i]==-1)return val[i]=0;
			return val[i]=self(self,par[i]);
		};
		rep(i,qnum){
			if(look[i]==-2)ans[i]=true;
			else if(look[i]!=-1&&calc(calc,look[i]))ans[i]=true;
		}
	}
	rep(i,qnum)
		if(ans[i])yes(0);
		else no(0);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}