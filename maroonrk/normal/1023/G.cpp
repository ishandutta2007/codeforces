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

int maxflow;

struct ysp{
	map<int,int> left,right;
	priority_queue<pi,vc<pi>,greater<pi>> qs;
	int lo,ro,qo;
	ysp():lo(0),ro(0),qo(0){}
	int size(){return left.size()+right.size();}
	void addqleft(int x){
		dmp(x);
		auto itr=right.lower_bound(x+lo-ro);
		if(itr!=right.ed){
			int d=itr->a+ro-(x+lo);
			assert(d%2==0);
			assert(d>=0);
			qs.emplace(d/2-qo,x);
		}
	}
	void addqright(int x){
		dmp(x);
		auto itr=left.upper_bound(x+ro-lo);
		if(itr!=left.bg){
			--itr;
			int d=x+ro-(itr->a+lo);
			assert(d%2==0);
			assert(d>=0);
			qs.emplace(d/2-qo,itr->a);
		}
	}
	void insertleft(int x,int v){
		if(v==0)return;
		assert(v>0);
		x-=lo;
		left[x]+=v;
		addqleft(x);
	}
	void insertright(int x,int v){
		if(v==0)return;
		assert(v>0);
		x-=ro;
		right[x]+=v;
		addqright(x);
	}
	void Expand(int w){
		dmp(qo);
		dmp(qs.size());
		while(w&&qs.size()){
			pi z=qs.top();qs.pop();
			z.a+=qo;
			assert(z.a>=0);
			dmp(z);
			int u=min(w,z.a);
			dmp(u);
			w-=u;
			z.a-=u;
			qo-=u;
			lo+=u;
			ro-=u;
			if(z.a==0){
				dmp2(z.b,z.b+lo-ro);
				auto l=left.find(z.b);
				auto r=right.find(z.b+lo-ro);
				if(l!=left.ed&&r!=right.ed){
					int y=min(l->b,r->b);
					maxflow+=y;
					int f=-1;
					l->b-=y;
					if(l->b==0)left.erase(l);
					else f=0;
					r->b-=y;
					if(r->b==0)right.erase(r);
					else f=1;
					if(f==0){
						addqleft(l->a);
					}else if(f==1){
						addqright(r->a);
					}else{
						l=left.upper_bound(z.b);
						if(l!=left.bg)
							addqleft(prev(l)->a);
					}
				}
			}else
				qs.emplace(z.a-qo,z.b);
		}
		qo-=w;
		lo+=w;
		ro-=w;
	}
	void show(){
		/*dmp(lo);
		for(auto kv:left)
			//dmp(kv);
			dmp(pi(kv.a+lo,kv.b));
		dmp(ro);
		for(auto kv:right)
			//dmp(kv);
			dmp(pi(kv.a+ro,kv.b));
		*/
	}
};

void merge(ysp&a,ysp&b){
	if(a.size()<b.size())swap(a,b);
	for(auto z:b.left)
		a.insertleft(z.a+b.lo,z.b);
	for(auto z:b.right)
		a.insertright(z.a+b.ro,z.b);
}

const int nmax=100010;

vc<pi> t[nmax];
vc<pi> obs[nmax];
ysp buf[nmax];

void dfs(int v,int p){
	buf[v]=ysp();
	sort(all(obs[v]));
	for(auto z:obs[v]){
		buf[v].insertright(z.a*2,z.b);
		buf[v].insertleft(z.a*2+2,z.b);
	}
	for(auto e:t[v])if(e.a!=p){
		dfs(e.a,v);
		buf[e.a].Expand(e.b*2);
		merge(buf[v],buf[e.a]);
	}
	dmp(v);
	dmp(maxflow);
	buf[v].show();
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	const int vmax=ten(9);
	
	int n;cin>>n;
	rep(_,n-1){
		int u,v,l;cin>>u>>v>>l;
		u--;v--;
		l*=vmax;
		l-=2;
		t[u].eb(v,l);
		t[v].eb(u,l);
	}
	
	int ans=0;
	int k;cin>>k;
	rep(_,k){
		int d,f,p;cin>>d>>f>>p;
		d*=vmax;
		p--;
		obs[p].eb(d,f);
		ans+=f;
	}
	
	dfs(0,-1);
	dmp(maxflow);
	buf[0].show();
	buf[0].Expand(inf);
	dmp(maxflow);
	
	if(0){
		rep(_,10){
			int tmp=maxflow;
			maxflow=0;
			int r=rand_int(0,n-1);
			dfs(r,-1);
			buf[r].Expand(inf);
			dmp2(tmp,maxflow);
			assert(tmp==maxflow);
		}
	}
	
	cout<<ans-maxflow<<endl;
}