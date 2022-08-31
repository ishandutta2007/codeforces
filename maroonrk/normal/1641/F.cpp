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

//copied from yosupo's library
//PARTLY VERIFIED

//USACO 2022 January Platinum C

#define GEOF

#ifdef GEOF
//using ld=long double;
using ld=double;
const ld PI=acos(ld(-1));
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
istream& operator<<(istream& is, P& p){
	return is>>p.x>>p.y;
}
ostream& operator<<(ostream& os, const P& p) {
    return os << "P(" << p.x << ", " << p.y << ")";
}
ld norm(const P&a){
	return a.norm();
}
#ifdef GEOF
ld abs(const P&a){
	return sqrt(norm(a));
}
#endif
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

using cr=pair<P,ld>;
//AOJ2423
cr circumc(P a,P b,P c){
	b-=a;
	c-=a;
	P r=c*norm(b)-b*norm(c);
	r=P(r.y,-r.x)/(2*crs(b,c));
	return cr(a+r,abs(r));
}
//AOJ2423
cr mindisc(const vc<P>& p,array<P,3> q,int i,int j){
	if(i==int(p.size())){
		if(j==0)
			return {{0,0},-1};
		else if(j==1)
			return {q[0],0};
		else if(j==2)
			return {(q[0]+q[1])*ld(0.5),abs(q[0]-q[1])/2};
		else if(j==3)
			return circumc(q[0],q[1],q[2]);
		else
			assert(false);
	}
	cr c=mindisc(p,q,i+1,j);
	if(sgn(abs(c.a-p[i])-c.b)==1){
		assert(j<3);
		q[j]=p[i];
		return mindisc(p,q,i+1,j+1);
	}else
		return c;
}
cr mindisc(vc<P> p){
	shuffle(all(p),mt19937());
	return mindisc(p,array<P,3>(),0,0);
}

const int nmax=210;
ld dbuf[nmax][nmax],abuf[nmax][nmax];

ld sub(ld ans,vc<P> p,int k){
	int n=si(p);
	if(k>n)return inf;
	assert(n<=nmax);
	
	sort(all(p));
	ld muri=inf;
	rng(i,k-1,n)chmin(muri,p[i].x-p[i-(k-1)].x);
	muri/=2;
	rep(i,n)rep(j,i){
		P z=p[j]-p[i];
		dbuf[i][j]=dbuf[j][i]=abs(z);
		ld a=z.arg();
		abuf[i][j]=a;
		abuf[j][i]=a<0?a+PI:a-PI;
	}
	
	static vc<ld> vs;
	static vc<pair<ld,int>> qs;
	auto add=[&](ld l,ld r){
		qs.eb(l,1);
		qs.eb(r,-1);
	};
	auto check=[&](ld tar,int root){
		if(tar<muri)return false;
		vs.clear();
		qs.clear();
		int cur=0;
		rep(i,n)if(root!=i){
			ld d=dbuf[root][i];
			if(d<tar*2){
				ld theta=acos(d/(tar*2));
				ld a=abuf[root][i];
				ld l=a-theta,r=a+theta;
				if(l<-PI){
					l+=2*PI;
				}
				if(PI<r){
					r-=2*PI;
				}
				if(l>r)cur++;
				add(l,r);
			}
		}
		sort(all(qs));
		int mx=cur;
		for(auto [a,v]:qs){
			cur+=v;
			chmax(mx,cur);
		}
		return mx>=k-1;
	};
	
	static vi idx;
	idx.resize(n);iota(all(idx),0);
	myshuffle(idx);
	
	for(auto i:idx){
		if(check(ans,i)){
			ld lw=0,up=ans;
			rep(_,40){
				ld mid=(lw+up)/2;
				if(check(mid,i)){
					up=mid;
				}else{
					lw=mid;
				}
			}
			ans=up;
		}
	}
	
	return ans;
}

void slv(){
	int n,L,k;cin>>n>>L>>k;
	vc<pi> ps(n);
	rep(i,n){
		ps[i]=readpi();
		ps[i].a+=ten(8);
		ps[i].b+=ten(8);
	}
	int W=2*ten(8)/sqrt(8*L);
	int D=2*ten(8)/W+1;
	using T=tuple<ld,int,int>;
	vc<T> difs((2*D+1)*(2*D+1));
	rng(xd,-D,D+1)rng(yd,-D,D+1){
		int a=max(abs(xd),1LL)-1;
		int b=max(abs(yd),1LL)-1;
		difs[(xd+D)*(2*D+1)+(yd+D)]=T(sqrt(sq(a*W)+sq(b*W)),xd,yd);
	}
	sort(all(difs));
	vvc<vi> idx(D,vvc<int>(D));
	rep(step,n){
		int p=ps[step].a/W;
		int q=ps[step].b/W;
		idx[p][q].pb(step);
	}
	vvc<int> head(D,vi(D));
	vvc<int> tail(D,vi(D));
	ld ans=2*ten(8);
	vc<P> work;
	auto add=[&](int u,int v){
		if(inc(0,u,D-1)&&inc(0,v,D-1)){
			rng(i,head[u][v],tail[u][v]){
				auto [x,y]=ps[idx[u][v][i]];
				work.eb(x,y);
			}
		}
	};
	rep(phase,2){
		rep(step,n){
			if(step>=L){
				int p=ps[step-L].a/W;
				int q=ps[step-L].b/W;
				head[p][q]++;
			}
			int p=ps[step].a/W;
			int q=ps[step].b/W;
			tail[p][q]++;
			
			if(step>=k-1){
				int dist=0;
				work.clear();
				while(dist<si(difs)&&(si(work)<k||phase)){
					auto [d,u,v]=difs[dist++];
					if(d>=ans*2)break;
					add(p+u,q+v);
				}
				chmin(ans,sub(ans,work,k));
			}
		}
		rep(i,D)rep(j,D){
			head[i][j]=0;
			tail[i][j]=0;
		}
	}
	cout<<ans<<endl;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int t;cin>>t;rep(_,t)
	slv();
}