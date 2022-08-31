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

const int L=20;
const int M=mask(L);

/*
void clear(int&a,int i){
	a&=~(1<<i);
}
*/

int action(int i,int fix,int off){
	return ((i^off)&~fix)|(fix&off);
}

struct N{
	N*ch[2];
	int fix,off,cnt,both;
	N():ch{nullptr,nullptr},fix(0),off(0),cnt(0),both(0){}
	void work(int f,int o,int lv){
		f&=mask(lv);
		o&=mask(lv);
		off=action(off,f,o);
		fix|=f;
	}
	void update(int lv){
		fix=0;
		off=0;
		cnt=0;
		both=0;
		rep(k,2)if(ch[k]){
			cnt+=ch[k]->cnt;
			both|=ch[k]->both;
		}
		if(ch[0]&&ch[1])both|=1<<(lv-1);
	}
	void propagate(int lv){
		if(fix&1<<(lv-1)){
			int k=(off>>(lv-1))&1;
			if(ch[k^1])swap(ch[0],ch[1]);
			assert(!ch[k^1]);
		}else if(off&1<<(lv-1)){
			swap(ch[0],ch[1]);
		}
		rep(k,2)if(ch[k])ch[k]->work(fix,off,lv-1);
		fix=0;
		off=0;
	}
};

N buf[ten(7)];
using np=N*;

N* nn(){
	static int head=0;
	return buf+head++;
}

np mg(np a,np b,int lv){
	if(!a&&!b)return nullptr;
	np n=nn();
	n->ch[0]=a;
	n->ch[1]=b;
	n->update(lv);
	return n;
}

np insert(np x,int pos,int lv){
	if(!x)x=nn();
	if(lv==0){
		x->cnt=1;
		return x;
	}
	int k=(pos>>(lv-1))&1;
	x->propagate(lv);
	x->ch[k]=insert(x->ch[k],pos,lv-1);
	x->update(lv);
	return x;
}

//l,lv,ptr
vc<tuple<int,int,np>> memo;

np meld(np x,np y,int lv){
	if(!x)return y;
	if(!y)return x;
	if(lv==0){
		x->cnt|=y->cnt;
	}else{
		x->propagate(lv);
		y->propagate(lv);
		rep(k,2)x->ch[k]=meld(x->ch[k],y->ch[k],lv-1);
		x->update(lv);
	}
	return x;
}

np modify(np x,int lv){
	if(!x)return x;
	if((x->fix&x->both)==0)return x;
	assert(lv>0);
	if(x->fix&1<<(lv-1)){
		int k=(x->off>>(lv-1))&1;
		x->ch[k]=meld(x->ch[k],x->ch[k^1],lv-1);
		x->ch[k^1]=nullptr;
	}
	x->propagate(lv);
	rep(k,2)x->ch[k]=modify(x->ch[k],lv-1);
	x->update(lv);
	return x;
}

np dfs1(np x,int l,int r,int lv,int b,int e,int fix,int off){
	if(!x||e<=l||r<=b)return x;
	if(b<=l&&r<=e){
		x->work(fix,off,lv);
		int pos=(action(l,fix,off)>>lv)<<lv;
		memo.eb(pos,lv,modify(x,lv));
		return nullptr;
	}
	int m=(l+r)/2;
	x->propagate(lv);
	return mg(
		dfs1(x->ch[0],l,m,lv-1,b,e,fix,off),
		dfs1(x->ch[1],m,r,lv-1,b,e,fix,off),
		lv);
}

np dfs2(np x,int l,int r,int lv,int tarl,int tarlv,np y){
	assert(l<=tarl&&tarl<r);
	if(lv==tarlv){
		assert(l==tarl);
		return meld(x,y,lv);
	}
	if(!x)x=nn();
	x->propagate(lv);
	int m=(l+r)/2;
	if(tarl<m){
		x->ch[0]=dfs2(x->ch[0],l,m,lv-1,tarl,tarlv,y);
	}else{
		x->ch[1]=dfs2(x->ch[1],m,r,lv-1,tarl,tarlv,y);
	}
	x->update(lv);
	return x;
}

np make_change(np root,int b,int e,int fix,int off){
	root=dfs1(root,0,1<<L,L,b,e,fix,off);
	for(auto [l,lv,ptr]:memo){
		root=dfs2(root,0,1<<L,L,l,lv,ptr);
	}
	memo.clear();
	return root;
}

int query(np x,int l,int r,int lv,int b,int e){
	if(!x||e<=l||r<=b)return 0;
	if(b<=l&&r<=e)return x->cnt;
	int m=(l+r)/2;
	x->propagate(lv);
	return query(x->ch[0],l,m,lv-1,b,e)+query(x->ch[1],m,r,lv-1,b,e);
}

void slv(){
	int n,q;cin>>n>>q;
	np root=nullptr;
	rep(i,n){
		int a=read();
		root=insert(root,a,L);
	}
	rep(_,q){
		int t;cin>>t;
		int l,r;cin>>l>>r;
		r++;
		if(t<=3){
			int x=read(),fix=0,off=0;
			if(t==1)fix=mask(L)^x;
			else if(t==2)fix=x,off=x;
			else off=x;
			root=make_change(root,l,r,fix,off);
		}else{
			int ans=query(root,0,1<<L,L,l,r);
			print(ans);
		}
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}