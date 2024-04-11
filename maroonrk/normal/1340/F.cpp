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

using uint=unsigned;
using ull=unsigned long long;

struct modinfo{uint mod,root;};
template<modinfo const&ref>
struct modular{
	static constexpr uint const &mod=ref.mod;
	static modular root(){return modular(ref.root);}
	uint v;
	//modular(initializer_list<uint>ls):v(*ls.bg){}
	modular(ll vv=0){s(vv%mod+mod);}
	modular& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	modular operator-()const{return modular()-*this;}
	modular& operator+=(const modular&rhs){return s(v+rhs.v);}
	modular&operator-=(const modular&rhs){return s(v+mod-rhs.v);}
	modular&operator*=(const modular&rhs){
		v=ull(v)*rhs.v%mod;
		return *this;
	}
	modular&operator/=(const modular&rhs){return *this*=rhs.inv();}
	modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}
	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
	modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}
	modular pow(int n)const{
		modular res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	modular inv()const{return pow(mod-2);}
	/*modular inv()const{
		int x,y;
		int g=extgcd(v,mod,x,y);
		assert(g==1);
		if(x<0)x+=mod;
		return modular(x);
	}*/
	friend modular operator+(int x,const modular&y){
		return modular(x)+y;
	}
	friend modular operator-(int x,const modular&y){
		return modular(x)-y;
	}
	friend modular operator*(int x,const modular&y){
		return modular(x)*y;
	}
	friend modular operator/(int x,const modular&y){
		return modular(x)/y;
	}
	friend ostream& operator<<(ostream&os,const modular&m){
		return os<<m.v;
	}
	friend istream& operator>>(istream&is,modular&m){
		ll x;is>>x;
		m=modular(x);
		return is;
	}
	bool operator<(const modular&r)const{return v<r.v;}
	bool operator==(const modular&r)const{return v==r.v;}
	bool operator!=(const modular&r)const{return v!=r.v;}
	explicit operator bool()const{
		return v;
	}
};

//extern constexpr modinfo base{998244353,3};
extern constexpr modinfo base{1000000007,0};
//modinfo base{1,0};
using mint=modular<base>;

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

//ABC135F
//Yukicoder No.263
namespace rhash{
	const int k=2;
	vc<array<mint,k>> a,b;
	void init(int n){
		a.resize(n+1);
		b.resize(n+1);
		rep(i,k){
			a[0][i]=1;
			a[1][i]=rand_int(1,mint::mod-1);
			b[0][i]=1;
			b[1][i]=a[1][i].inv();
		}
		rng(i,1,n)
			rep(j,k){
				a[i+1][j]=a[i][j]*a[1][j];
				b[i+1][j]=b[i][j]*b[1][j];
			}
	}
	using P=pair<array<mint,k>,int>;
	P mrg(P x,P y){
		rep(i,k)
			x.a[i]+=y.a[i]*a[x.b][i];
		x.b+=y.b;
		return x;
	}
	struct gen{
		gen(){}
		vc<array<mint,k>> c;
		gen(int n):c(n+1){}
		template<class S>
		void init(S s){
			c.resize(s.size()+1);
			rep(i,s.size())
				rep(j,k)
					c[i+1][j]=c[i][j]+a[i][j]*s[i];
		}
		P get(int l,int r){
			P res;
			rep(i,k)
				res.a[i]=(c[r][i]-c[l][i])*b[l][i];
			res.b=r-l;
			return res;
		}
		P getsingle(int v){
			P res;
			rep(i,k)res.a[i]=v;
			res.b=1;
			return res;
		}
	};
}

struct Q{
	int t,x,y;
	void readQ(){
		cin>>t>>x>>y;
		x--;
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	int kind;cin>>kind;
	
	vi a=readvi(n);
	
	int q;cin>>q;
	vc<Q> qs(q);
	rep(i,q)qs[i].readQ();
	
	const int B=400;
	vi buf(kind+n);
	rep(i,kind)buf[i]=i+1;
	rhash::init(kind+n);
	rhash::gen h(kind+n);
	vc<pi> work;
	for(int i=0;i<q;i+=B){
		int j=min(q,i+B);
		vi ps{0,n};
		rng(k,i,j){
			if(qs[k].t==1){
				ps.pb(qs[k].x);
				ps.pb(qs[k].x+1);
			}else{
				ps.pb(qs[k].x);
				ps.pb(qs[k].y);
			}
		}
		mkuni(ps);
		int s=si(ps)-1;
		vc<pair<pi,pi>> see(s);
		vc<bool> ng(s);
		int head=kind;
		rep(k,s){
			if(ps[k]+1==ps[k+1])continue;
			int l=head,m=head,r=head;
			rng(x,ps[k],ps[k+1]){
				int v=a[x];
				if(v>0){
					buf[r++]=v;
				}else{
					v=-v;
					if(m<r){
						if(buf[--r]!=v){
							ng[k]=true;
							break;
						}
					}else{
						buf[m++]=v;
						r=m;
					}
				}
			}
			if(!ng[k]){
				reverse(buf.bg+m,buf.bg+r);
				see[k]=mp(pi(l,m),pi(m,r));
				head=r;
			}
		}
		dmp(ng);
		h.init(buf);
		
		rng(qid,i,j){
			auto z=qs[qid];
			if(z.t==1){
				a[z.x]=z.y;
			}else{
				dmp2(qid,a);
				dmp(ps);
				int l=lwb(ps,z.x);
				int r=lwb(ps,z.y);
				bool ok=true;
				work.clear();
				rng(k,l,r)if(ok){
					if(ng[k]){
						ok=false;
						break;
					}
					if(ps[k]+1==ps[k+1]){
						dmp(0);
						int v=a[ps[k]];
						if(v>0){
							see[k].a=pi(0,0);
							see[k].b=pi(v-1,v);
						}else{
							v=-v;
							see[k].a=pi(v-1,v);
							see[k].b=pi(0,0);
						}
					}
					dmp2(k,see[k]);
					int b,e;tie(b,e)=see[k].a;
					while(b<e){
						if(work.empty()){
							ok=false;
							break;
						}
						pi&w=work.back();
						int len=min(e-b,w.b-w.a);
						if(h.get(b,b+len)!=h.get(w.a,w.a+len)){
							ok=false;
							break;
						}
						b+=len;
						w.a+=len;
						if(w.a==w.b)work.pop_back();
					}
					tie(b,e)=see[k].b;
					if(b<e)work.eb(b,e);
					dmp(work);
				}
				if(ok&&work.empty())yes(0);
				else no(0);
			}
		}
	}
}