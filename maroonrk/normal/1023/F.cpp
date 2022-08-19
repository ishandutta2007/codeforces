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
#define dmp2(...) dmpr(cerr,"Line:",__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif

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

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

struct Node{
	typedef Node* NP;
	NP l,r,p;
	bool rev;
	int mn,lz;
	Node():l(NULL),r(NULL),p(NULL),rev(false),mn(inf),lz(inf){}
	void Propagate(){
		if(rev){
			swap(l,r);
			if(l) l->rev^=true;
			if(r) r->rev^=true;
			rev=false;
		}
		if(l)chmin(l->lz,lz);
		if(r)chmin(r->lz,lz);
		chmin(mn,lz);
		lz=inf;
	}
	void Update(){
		assert(lz==inf);
	}
	int Pos(){
		if(p&&p->l==this) return -1;
		if(p&&p->r==this) return 1;
		return 0;
	}
	void Prepare(){
		if(Pos())
			p->Prepare();
		Propagate();
	}
	void Rotate(){
		NP q=p,c;
		if(Pos()==1){
			c=l;
			l=p;
			p->r=c;
		}else{
			c=r;
			r=p;
			p->l=c;
		}
		if(c) c->p=p;
		p=p->p;
		q->p=this;
		if(p&&p->l==q) p->l=this;
		if(p&&p->r==q) p->r=this;
		q->Update();
	}
	void Splay(){
		Prepare();
		while(Pos()){
			int a=Pos(),b=p->Pos();
			if(b&&a==b) p->Rotate();
			if(b&&a!=b) Rotate();
			Rotate();
		}
		Update();
	}
	void Expose(){
		for(NP x=this;x;x=x->p) x->Splay();
		for(NP x=this;x->p;x=x->p){
			x->p->r=x;
			x->p->Update();
		}
		Splay();
	}
	void Evert(){
		Expose();
		if(l){
			l->rev^=true;
			l=NULL;
			Update();
		}
	}
	void Link(NP x){
		Evert();
		p=x;
	}
	void ChminVal(int q){
		Expose();
		r=NULL;
		chmin(lz,q);
	}
	void Cut() {
		Expose();
		assert(l);
		l->p = NULL;
		l = NULL;
		Update();
	}
};

const int nmax=500010;
Node buf[nmax*2];
using np=Node*;

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,k,m;cin>>n>>k>>m;
	rep(i,k){
		int a,b;cin>>a>>b;
		a--;b--;
		buf[a].Link(buf+n+i);
		buf[b].Link(buf+n+i);
	}
	rep(i,m){
		int a,b,c;cin>>a>>b>>c;
		a--;b--;
		buf[a].Evert();
		buf[b].Expose();
		if(!buf[a].p){
			buf[a].p=buf+b;
		}else{
			dmp2(a,b,c);
			buf[b].ChminVal(c);
		}
	}
	ll ans=0;
	rep(i,k){
		buf[n+i].Expose();
		int c=buf[n+i].mn;
		if(c==inf){
			cout<<-1<<endl;
			return 0;
		}
		ans+=c;
	}
	cout<<ans<<endl;
}