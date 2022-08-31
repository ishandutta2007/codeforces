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


//work without define int ll
//maxflow with small constant
//CF Global11 G
//bfs dfs 
//ae  4th argument  capacity
//
template<class d>
struct maxflow{
	struct E{
		int to,nx;
		d cap;
	};
	int n;
	vc<E> es;
	vi head,q;
	vc<pi> itr,lv;
	int curt;
	maxflow(int nn):n(nn),head(n,-1),q(n),itr(n),lv(n),curt(0){}
	int ae(int s,int t,d c,d c2=0){
		int pres=head[s];
		int pret=head[t];
		head[s]=si(es);
		es.pb({t,pres,c});
		head[t]=si(es);
		es.pb({s,pret,c2});
		return head[s];
	}
	void bfs(int s,int t=-1){
		lv[s]=pi(0,curt);
		int l=0,r=0;
		q[r++]=s;
		while(l<r){
			int v=q[l++];
			for(int id=head[v];id!=-1;id=es[id].nx){
				auto e=es[id];
				if(e.cap>0&&lv[e.to].b<curt){
					lv[e.to]=pi(lv[v].a+1,curt);
					q[r++]=e.to;
					if(e.to==t)return;
				}
			}
		}
	}
	d dfs(int v,int t,d f){
		if(v==t)return f;
		if(itr[v].b<curt)itr[v]=pi(head[v],curt);
		d res=0;
		while(itr[v].a!=-1){
			E& e=es[itr[v].a];
			E& rev=es[itr[v].a^1];
			if(rev.cap>0&&lv[e.to].a==lv[v].a-1&&lv[e.to].b==curt){
				d a=dfs(e.to,t,min(f,rev.cap));
				if(a>0){
					rev.cap-=a;
					e.cap+=a;
					res+=a;
					f-=a;
					if(f<=0)break;
				}
			}
			itr[v].a=e.nx;
		}
		return res;
	}
	d calc(int s,int t,d mx=inf){
		d f=0;
		while(f<mx){
			curt++;
			bfs(s,t);
			if(lv[t].b<curt)
				return f;
			f+=dfs(t,s,mx-f);
		}
		return f;
	}
	//s:false, t:true
	vc<bool> getcut(){
		vc<bool> res(n);
		rep(i,n)res[i]=lv[i].b<curt;
		return res;
	}
};

struct P{
	int x,y,w;
	void readinit(){
		cin>>x>>y>>w;
	}
	pi getpi(){
		return pi(x,y);
	}
};

void slv(){
	int n;cin>>n;
	vc<P> ps(n);
	map<pi,int> vid,cost;
	rep(i,n){
		ps[i].readinit();
		vid[ps[i].getpi()]=i;
		cost[ps[i].getpi()]=ps[i].w;
	}
	
	int s=1+n*2+1;
	maxflow<int> mf(s);
	rep(i,n){
		auto [x,y]=ps[i].getpi();
		if(x%2)continue;
		int cs[3]{};
		cs[1]=ps[i].w*2;
		cs[2]=cost[pi(x-1,y)]+cost[pi(x+1,y)];
		vc<tuple<int,int,int>> es;
		for(auto d:{-1,1}){
			if(vid.count(pi(x+d*2,y))){
				int j=vid[pi(x+d*2,y)];
				es.eb(1+i*2+1,1+j*2+1,cost[pi(x+d,y)]);
			}else{
				cs[2]+=cost[pi(x+d,y)];
			}
		}
		rep(k,3){
			int from=-1,to=-1;
			if(k==0){
				from=0;
			}else{
				from=1+i*2+k-1;
			}
			if(k==2){
				to=s-1;
			}else{
				to=1+i*2+k;
			}
			es.eb(from,to,cs[k]);
			es.eb(to,from,inf);
		}
		auto conv=[&](int v){
			if(v==0)return s-1;
			else if(v==s-1)return 0LL;
			else return ((v-1)^1)+1;
		};
		for(auto [from,to,c]:es){
			if(y%2){
				tie(from,to)=pi(conv(to),conv(from));
			}
			mf.ae(from,to,c);
		}
		if(y%2==0){
			for(auto z:{y-1,y+1}){
				if(vid.count(pi(x,z))){
					int j=vid[pi(x,z)];
					mf.ae(1+j*2+1,1+i*2+0,inf);
				}
			}
		}
	}
	
	int tot=0;
	rep(i,n)tot+=ps[i].w;
	print(tot-mf.calc(0,s-1)/2);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}