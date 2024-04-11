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

//mint107  verify 
//#define DYNAMIC_MOD

struct modinfo{uint mod,root;
#ifdef DYNAMIC_MOD
constexpr modinfo(uint m,uint r):mod(m),root(r),im(0){set_mod(m);}
ull im;
constexpr void set_mod(uint m){
	mod=m;
	im=ull(-1)/m+1;
}
uint product(uint a,uint b)const{
	ull z=ull(a)*b;
	uint x=((unsigned __int128)z*im)>>64;
	uint v=uint(z)-x*mod;
	return v<mod?v:v+mod;
}
#endif
};
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
		#ifndef DYNAMIC_MOD
		v=ull(v)*rhs.v%mod;
		#else
		v=ref.product(v,rhs.v);
		#endif
		return *this;
	}
	modular&operator/=(const modular&rhs){return *this*=rhs.inv();}
	modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}
	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
	modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}
	modular pow(ll n)const{
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
		int g=extgcd<ll>(v,mod,x,y);
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

#ifndef DYNAMIC_MOD
extern constexpr modinfo base{998244353,3};
//extern constexpr modinfo base{1000000007,0};
//modinfo base{1,0};
#ifdef USE_GOOD_MOD
static_assert(base.mod==998244353);
#endif
#else
modinfo base(1,0);
extern constexpr modinfo base107(1000000007,0);
using mint107=modular<base107>;
#endif
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

/*
const int vmax=110;
mint binbuf[vmax][vmax];
mint choose(int n,int k){
	return binbuf[n-k][k];
}
mint binom(int a,int b){
	return binbuf[a][b];
}
void initfact(){
	binbuf[0][0]=1;
	rep(i,vmax)rep(j,vmax){
		if(i)binbuf[i][j]+=binbuf[i-1][j];
		if(j)binbuf[i][j]+=binbuf[i][j-1];
	}
}
*/

//copy-constructor 
//find  lazy  (Petrozavodsk 2020w Day9 C)
//reverse 
//erase,insert 

//AOJ DSL2G
template<class N>
struct splaytree{
	struct Node{
		using np=Node*;
		np l,r,p;
		bool rev;
		N x;
		Node():l(0),r(0),p(0),rev(false),x(){}
		void clear(){
			l=0;
			r=0;
			p=0;
			rev=0;
		}
		void reverse(){
			rev^=true;
			swap(l,r);
			x.reverse();
		}
		void push(){
			if(rev){
				if(l)l->reverse();
				if(r)r->reverse();
				rev=false;
			}
			if(l)x.push(l->x);
			if(r)x.push(r->x);
			x.clear();
		}
		np update(){
			x.single();
			if(l)x.updatel(l->x);
			if(r)x.updater(r->x);
			return this;
		}
		int pos(){
			if(p&&p->l==this)return -1;
			if(p&&p->r==this)return 1;
			return 0;
		}
		void prepare(){
			if(pos())
				p->prepare();
			push();
		}
		void rotate(){
			np q=p,c;
			if(pos()==1){
				c=l;
				l=p;
				p->r=c;
			}else{
				c=r;
				r=p;
				p->l=c;
			}
			if(c)c->p=p;
			p=p->p;
			q->p=this;
			if(p&&p->l==q)p->l=this;
			if(p&&p->r==q)p->r=this;
			q->update();
		}
		np splay(){
			prepare();
			while(pos()){
				int a=pos(),b=p->pos();
				if(b&&a==b)p->rotate();
				if(b&&a!=b)rotate();
				rotate();
			}
			return update();
		}
		template<class F,class...Args>
		np find(F f,Args&&...args){
			if(!(x.*f)(forward<Args>(args)...))return 0;
			push();
			x.single();
			np a=0;
			if(l)a=l->find(f,forward<Args>(args)...);
			if(a)return a;
			if((x.*f)(forward<Args>(args)...))return splay();
			return r->find(f,forward<Args>(args)...);
		}
		np left(){
			if(l)return l->left();
			else return splay();
		}
		np right(){
			if(r)return r->right();
			else return splay();
		}
		np root(){
			if(p)return p->root();
			else return this;
		}
		np cutl(){
			if(l){
				l->p=0;
				l=0;
			}
			return update();
		}
		np linkl(np c){
			assert(!l);
			l=c;
			if(c)c->p=this;
			return update();
		}
		np cutr(){
			if(r){
				r->p=0;
				r=0;
			}
			return update();
		}
		//XIX Opencup GP of Zhejiang A
		np get_next(){
			splay();
			if(!r)return 0;
			else return r->left();
		}
	}*buf;
	using np=Node*;
	vc<np> ps;
	splaytree(int n){
		buf=new Node[n];
		rep(i,n)ps.pb(buf+i);
	}
	~splaytree(){delete[] buf;}
	int head=0;
	template<class...Args>
	np nn(Args&&...args){
		np a=ps.back();
		ps.pop_back();
		a->l=0;
		a->r=0;
		a->p=0;
		a->x=N(forward<Args>(args)...);
		return a;
	}
	//XX Opencup GP of Wroclaw D
	pair<np,np> erase_sub(np x){
		x->splay();
		if(x->l)x->l->p=0;
		if(x->r)x->r->p=0;
		ps.pb(x);
		return mp(x->l,x->r);
	}
	//not verified
	np erase(np x){
		np a,b;
		tie(a,b)=erase_sub(x);
		return merge(a,b);
	}
	//Petrozavodsk 2020w Day9 H
	np isolate(np x){
		x->splay();
		if(x->l)x->l->p=0;
		if(x->r)x->r->p=0;
		np res=merge(x->l,x->r);
		x->x.single();
		x->clear();
		return res;
	}
	//Petrozavodsk 2020w Day9 H
	template<class F>
	np insert(np r,np x,F f){
		np a,b;tie(a,b)=split(r,f,x->x);
		return merge(merge(a,x),b);
	}
	template<class F,class...Args>
	np insert(np r,F f,Args&&...args){
		np x=nn(forward<Args>(args)...);
		np a,b;tie(a,b)=split(r,f,x->x);
		return merge(merge(a,x),b);
	}
	//XX Opencup GP of Wroclaw D
	template<class F,class...Args>
	np insert_cmp(np r,F f,Args&&...args){
		np x=nn(forward<Args>(args)...);
		np a,b;tie(a,b)=split_cmp(r,f,x->x);
		return merge(merge(a,x),b);
	}
	//XIX Opencup GP of Zhejiang A
	template<class F>
	np insert_cmp(np r,np x,F f){
		np a,b;tie(a,b)=split_cmp(r,f,x->x);
		return merge(merge(a,x),b);
	}
	template<class t>
	np build(vc<t> v){
		vc<np> cur;
		for(auto z:v)cur.pb(nn(z));
		while(cur.size()>1){
			int s=cur.size();
			vc<np> nx((s+1)/2);
			for(int i=0;i<s;i+=2){
				if(i+1<s)nx[i/2]=merge(cur[i],cur[i+1]);
				else nx[i/2]=cur[i];
			}
			swap(nx,cur);
		}
		return cur[0];
	}
	np merge(np a,np b){
		if(!a)return b;
		if(!b)return a;
		return b->splay()->left()->linkl(a->splay());
	}
	//
	//
	template<class F,class...Args>
	pair<np,np> split(np a,F f,Args&&...args){
		if(!a)return {0,0};
		np b=a->find(f,forward<Args>(args)...);
		if(b){
			np c=b->l;
			return {c,b->cutl()};
		}
		return {a,0};
	}
	//XX Opencup GP of Wroclaw D
	//
	template<class F>
	pair<np,np> split_cmp(np a,F cmp,N v){
		if(!a)return {0,0};
		np x=0,y=0;
		while(a){
			a->push();
			if(cmp(a->x,v)){
				x=a;
				a=a->r;
			}else{
				y=a;
				a=a->l;
			}
		}
		if(x)x->splay();
		if(y){
			y->splay();
			y->cutl();
		}
		return mp(x,y);
	}
	//XIX Opencup GP of Zhejiang A
	//a-b x,y(a-b),z 
	//a  b a  b 
	tuple<np,np,np> split_range(np a,np b){
		{//debug
			a->splay();
			b->splay();
			int lastpos;
			auto c=a;
			while(c&&c!=b){
				lastpos=c->pos();
				c=c->p;
			}
			assert(c==b);
			assert(lastpos==-1);
		}
		a->splay();
		np x=a->l;
		a->cutl();
		b->splay();
		np z=b->r;
		b->cutr();
		return mt(x,b,z);
	}
	//Petrozavodsk 2020w Day9 C
	template<class F>
	np weighted_merge_rec(np x,np tar,F f){
		if(!x)return tar;
		x->push();
		tar=weighted_merge_rec(x->l,tar,f);
		tar=weighted_merge_rec(x->r,tar,f);
		x->x.single();
		x->clear();
		return insert(tar,x,f);
	}
	//Petrozavodsk 2020w Day9 C
	template<class F>
	np weighted_merge(np a,np b,F f){
		if(!a)return b;
		if(!b)return a;
		if(a->x.sz<b->x.sz)swap(a,b);
		return weighted_merge_rec(b,a,f);
	}
	//Petrozavodsk 2020w Day9 C
	void enumerate(np x,vc<N>&dst){
		if(!x)return;
		x->push();
		enumerate(x->l,dst);
		dst.pb(x->x);
		enumerate(x->r,dst);
	}
};
//N::reverse
//N::push
//,push
//N::clear
//lazy tag
//N::single
//
//N::updatel,updater
//N::find
//find 
//split  find  left 
//split_cmp  cmp(x,v)  true  x 
// a<b  lower_bound 

//range
struct N{
	int lz,val;
	N(int v=0):lz(0),val(v){}
	void add(int v){
		lz+=v;
		val+=v;
	}
	void reverse(){}
	void push(N&x){
		x.add(lz);
	}
	void clear(){
		lz=0;
	}
	void single(){
		assert(lz==0);
	}
	void upd(const N&x){
		assert(lz==0);
	}
	void updatel(const N&x){
		upd(x);
	}
	void updater(const N&x){
		upd(x);
	}
	static bool cmp(const N&a,const N&b){
		return a.val<b.val;
	}
};

void slv(){
	int n,m;cin>>n>>m;
	
	splaytree<N> st(m);
	using np=splaytree<N>::np;
	np root=nullptr;
	
	int cut=0;
	rep(_,m){
		int x,y;cin>>x>>y;
		x--;y--;
		auto [a,b]=st.split_cmp(root,&N::cmp,N(y-1));
		if(b){
			b->x.add(1);
			b=b->left();
			if(y<b->x.val){
				cut++;
				b=st.merge(st.nn(y),b);
			}
		}else{
			cut++;
			b=st.nn(y);
		}
		root=st.merge(a,b);
	}
	
	print(binom(n,n-1-cut));
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	initfact();
	int t;cin>>t;rep(_,t)
	slv();
}