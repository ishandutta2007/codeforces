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

template<class d>
struct maxflow{
	struct E{
		int to,rev;
		d cap;
	};
	vvc<E> g;
	vi itr,lv,q;
	maxflow(int n):g(n),itr(n),lv(n),q(n){}
	int ae(int s,int t,d c){
		g[s].pb({t,(int)g[t].size(),c});
		g[t].pb({s,(int)g[s].size()-1,0});
		return si(g[s])-1;
	}
	void bfs(int s){
		fill(all(lv),-1);
		lv[s]=0;
		int l=0,r=0;
		q[r++]=s;
		while(l<r){
			int v=q[l++];
			for(auto e:g[v])if(e.cap>0&&lv[e.to]==-1){
				lv[e.to]=lv[v]+1;
				q[r++]=e.to;
			}
		}
	}
	d dfs(int v,int t,d f){
		if(v==t)return f;
		d res=0;
		for(int&i=itr[v];i<(int)g[v].size();i++){
			E& e=g[v][i];
			if(e.cap>0&&lv[e.to]==lv[v]+1){
				d a=dfs(e.to,t,min(f,e.cap));
				if(a>0){
					e.cap-=a;
					g[e.to][e.rev].cap+=a;
					res+=a;
					f-=a;
					if(f<=0)break;
				}
			}
		}
		return res;
	}
	d calc(int s,int t,d mx=inf){
		d f=0;
		while(1){
			bfs(s);
			if(lv[t]==-1)
				return f;
			fill(all(itr),0);
			f+=dfs(s,t,mx-f);
		}
		return f;
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,m,s,t;cin>>n>>m>>s>>t;
	s--;t--;
	maxflow<int> mf(n);
	vvc<pi> g(n);
	vc<pi> es(m);
	vi tp(m);
	vc<pi> idx(m,pi(-1,-1));
	vi ans(m);
	rep(i,m){
		int a,b;cin>>a>>b>>tp[i];
		a--;b--;
		es[i]=pi(a,b);
		if(tp[i]==0){
			mf.ae(a,b,inf);
		}else{
			idx[i]=pi(a,mf.ae(a,b,1));
			mf.ae(b,a,inf);
			g[a].eb(b,i);
		}
	}
	
	vi side(n);
	
	auto add=[&](vi froms,vi tos,int md=0){
		for(auto from:froms)
			assert(side[from]==side[tos[0]]);
		for(auto to:tos)
			assert(side[froms[0]]==side[to]);
		vi dist(n,-1),pre(n,-1),use(n,-1);
		vi q(n);
		int b=0,e=0;
		auto reach=[&](int v,int d,int p,int u){
			if(side[v]!=side[froms[0]])return;
			if(dist[v]!=-1)return;
			dist[v]=d;
			pre[v]=p;
			use[v]=u;
			q[e++]=v;
		};
		vi fid(n,-1);
		rep(i,si(froms)){
			int from=froms[i];
			fid[from]=i;
			reach(from,0,-1,-1);
		}
		while(b<e){
			int v=q[b++];
			for(auto z:g[v])
				reach(z.a,dist[v]+1,v,z.b);
		}
		rep(i,si(tos)){
			int to=tos[i];
			if(dist[to]!=-1){
				while(fid[to]==-1){
					ans[use[to]]++;
					to=pre[to];
				}
				return pi(fid[to],i);
			}
		}
		if(md==0)assert(0);
		return pi(-1,-1);
	};
	
	int f=mf.calc(s,t);
	
	rep(i,n)if(mf.lv[i]==-1)side[i]=1;
	
	vi cut[2],ci;
	rep(i,m)if(tp[i]){
		int a,b;tie(a,b)=es[i];
		if(side[a]!=side[b]){
			assert(side[a]<side[b]);
			tp[i]=2;
			cut[0].pb(a);
			cut[1].pb(b);
			ci.pb(i);
		}
	}
	rep(i,m)if(tp[i]){
		ans[i]++;
		if(tp[i]==1){
			if(add({es[i].b},{es[i].a},1)!=pi(-1,-1))continue;
			if(side[es[i].a]==0){
				add({s},{es[i].a});
				int u=add({es[i].b},cut[0]).b;
				ans[ci[u]]++;
				add({cut[1][u]},{t});
			}else{
				add({es[i].b},{t});
				int u=add(cut[1],{es[i].a}).a;
				ans[ci[u]]++;
				add({s},{cut[0][u]});
			}
		}else{
			add({s},{es[i].a});
			add({es[i].b},{t});
		}
	}
	
	print(f);
	rep(i,m){
		int a=ans[i],b=ans[i];
		if(tp[i]<2)b++;
		print(a,2);
		print(b);
	}
}