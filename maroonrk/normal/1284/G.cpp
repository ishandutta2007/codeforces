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

#define CAPITAL
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

/*
//Matroid
//size(): returns size
//Get(): returns pair of
//1. indices of src(vertices that it is free to add)
//2. all (x,y) s.t. del x & add y is possible(y is not a src)
template<class LM,class RM>
struct MatroidIntersection{
	int n,m,s;
	LM& lm;
	RM& rm;
	struct Edge{
		int to,cost,id;
		friend ostream& operator<<(ostream&os,const Edge&e){
			return os<<"{T:"<<e.to<<", C:"<<e.cost<<", I:"<<e.id<<"}";
		}
	};
	vc<tuple<int,int,int>> es;
	vvc<Edge> g;
	MatroidIntersection(LM& llm,RM& rrm):lm(llm),rm(rrm){
		n=lm.size();
		m=rm.size();
		s=n+m;
	}
	void AddEdge(int a,int b,int c){
		assert(0<=a&&a<n);
		assert(0<=b&&b<m);
		assert(0<=c);
		es.eb(a,b,c);
	}
	vi h;
	vc<pi> dist,prev;
	void FindShortest(const vi&src){
		dist.assign(s,pi(inf,-1));
		prev.assign(s,pi(-1,-1));
		
		using Node=tuple<int,int,int>;
		priority_queue<Node,vc<Node>,greater<Node>> pq;
		const auto Reach=[&](int v,int d,int step,int j,int k){
			if(pi(d,step)<dist[v]){
				dist[v]=pi(d,step);
				prev[v]=pi(j,k);
				pq.push(make_tuple(d,step,v));
			}
		};
			
		for(auto i:src)
			Reach(i,0,0,-1,-1);
		
		while(!pq.empty()){
			int d,step,v;
			tie(d,step,v)=pq.top();
			pq.pop();
			if(dist[v]!=pi(d,step))
				continue;
			for(auto e:g[v]){
				assert(e.cost+h[v]-h[e.to]>=0);
				Reach(e.to,d+e.cost+h[v]-h[e.to],step+1,v,e.id);
			}
		}
	}
	int Augment(vc<bool>&use){
		g.assign(s,vc<Edge>());
		vi m1,m2;
		rep(i,es.size()){
			int a,b,c;
			tie(a,b,c)=es[i];
			if(use[i]){
				g[n+b].pb(Edge{a,-c,i});
				m1.pb(a);
				m2.pb(b);
			}else{
				g[a].pb(Edge{n+b,c,i});
			}
		}
		vi src,dst;
		{
			auto w=lm.Get(m1);
			src=w.first;
			if(src.empty())return -1;
			for(auto e:w.second)
				g[e.first].pb(Edge{e.second,0,-1});
		}
		{
			auto w=rm.Get(m2);
			dst=w.first;
			if(dst.empty())return -1;
			for(auto e:w.second)
				g[n+e.second].pb(Edge{n+e.first,0,-1});
		}
		
		FindShortest(src);
		
		pair<pi,int> w(pi(inf/2,-1),-1);
		for(auto i:dst)
			chmin(w,mp(dist[n+i],n+i));
		if(w.second==-1)
			return -1;
		int x=w.second;
		while(prev[x].first!=-1){
			int i=prev[x].second;
			if(i!=-1)
				use[i]=!use[i];
			x=prev[x].first;
		}
		int mn=w.first.first;
		rep(i,s){
			h[i]+=min(dist[i].first,mn);
			chmin(h[i],inf);
		}
		return h[w.second];
	}
	pair<int,vi> Solve(){
		h.assign(s,0);
		vc<bool> use(es.size());
		int c=0,f;
		while((f=Augment(use))>=0)
			c+=f;
		vi sol;
		rep(i,es.size())
			if(use[i])
				sol.pb(i);
		return mp(c,sol);
	}
};
*/

//Matroid
//size(): returns size
//Get(): returns pair of
//1. indices of src(vertices that it is free to add)
//2. all (x,y) s.t. del x & add y is possible(y is not a src)
template<class LM,class RM>
struct MatroidIntersection{
	int n,m,s;
	LM& lm;
	RM& rm;
	struct Edge{
		int to,cost,id;
		friend ostream& operator<<(ostream&os,const Edge&e){
			return os<<"{T:"<<e.to<<", C:"<<e.cost<<", I:"<<e.id<<"}";
		}
	};
	vc<tuple<int,int,int>> es;
	vvc<Edge> g;
	MatroidIntersection(LM& llm,RM& rrm):lm(llm),rm(rrm){
		n=lm.size();
		m=rm.size();
		s=n+m;
	}
	void AddEdge(int a,int b,int c){
		assert(0<=a&&a<n);
		assert(0<=b&&b<m);
		assert(0<=c);
		es.eb(a,b,c);
	}
	vi h;
	vc<pi> dist,prev;
	void FindShortest(const vi&src){
		dist.assign(s,pi(inf,-1));
		prev.assign(s,pi(-1,-1));
		
		using Node=tuple<int,int,int>;
		//priority_queue<Node,vc<Node>,greater<Node>> pq;
		queue<Node> pq;
		const auto Reach=[&](int v,int d,int step,int j,int k){
			if(pi(d,step)<dist[v]){
				dist[v]=pi(d,step);
				prev[v]=pi(j,k);
				pq.push(make_tuple(d,step,v));
			}
		};
			
		for(auto i:src)
			Reach(i,0,0,-1,-1);
		
		while(!pq.empty()){
			int d,step,v;
			//tie(d,step,v)=pq.top();
			tie(d,step,v)=pq.front();
			pq.pop();
			if(dist[v]!=pi(d,step))
				continue;
			for(auto e:g[v]){
				assert(e.cost+h[v]-h[e.to]>=0);
				Reach(e.to,d+e.cost+h[v]-h[e.to],step+1,v,e.id);
			}
		}
	}
	int Augment(vc<bool>&use){
		g.assign(s,vc<Edge>());
		vi m1,m2;
		rep(i,es.size()){
			int a,b,c;
			tie(a,b,c)=es[i];
			if(use[i]){
				g[n+b].pb(Edge{a,-c,i});
				m1.pb(a);
				m2.pb(b);
			}else{
				g[a].pb(Edge{n+b,c,i});
			}
		}
		vi src,dst;
		{
			auto w=lm.Get(m1);
			src=w.first;
			if(src.empty())return -1;
			for(auto e:w.second)
				g[e.first].pb(Edge{e.second,0,-1});
		}
		{
			auto w=rm.Get(m2);
			dst=w.first;
			if(dst.empty())return -1;
			for(auto e:w.second)
				g[n+e.second].pb(Edge{n+e.first,0,-1});
		}
		
		FindShortest(src);
		
		pair<pi,int> w(pi(inf/2,-1),-1);
		for(auto i:dst)
			chmin(w,mp(dist[n+i],n+i));
		if(w.second==-1)
			return -1;
		int x=w.second;
		while(prev[x].first!=-1){
			int i=prev[x].second;
			if(i!=-1)
				use[i]=!use[i];
			x=prev[x].first;
		}
		int mn=w.first.first;
		rep(i,s){
			h[i]+=min(dist[i].first,mn);
			chmin(h[i],inf);
		}
		return h[w.second];
	}
	pair<int,vi> Solve(){
		h.assign(s,0);
		vc<bool> use(es.size());
		int c=0,f;
		while((f=Augment(use))>=0)
			c+=f;
		vi sol;
		rep(i,es.size())
			if(use[i])
				sol.pb(i);
		return mp(c,sol);
	}
};

struct UnionFind{
	vi rank,par;
	void Init(int n){
		rank.assign(n,0);
		par.assign(n,-1);
	}
	int Find(int i){
		return par[i]==-1?i:(par[i]=Find(par[i]));
	}
	bool Same(int a,int b){
		return Find(a)==Find(b);
	}
	bool Unite(int a,int b){
		a=Find(a);
		b=Find(b);
		if(a==b)
			return false;
		if(rank[a]<rank[b])
			swap(a,b);
		par[b]=a;
		if(rank[a]==rank[b])
			rank[a]++;
		return true;
	}
};

struct MST{
	int n;
	vector<pi> es;
	MST(int nn){
		n=nn;
	}
	void AddEdge(int a,int b){
		assert(0<=a&&a<n);
		assert(0<=b&&b<n);
		es.eb(a,b);
	}
	int size(){
		return es.size();
	}
	UnionFind uf;
	pair<vi,vc<pi>> Get(const vi&cur){
		uf.Init(n);
		vi t(size(),0);
		for(auto i:cur){
			uf.Unite(es[i].first,es[i].second);
			t[i]=1;
		}
		vi src;
		rep(i,size())if(!t[i]){
			if(!uf.Same(es[i].first,es[i].second)){
				src.pb(i);
				t[i]=2;
			}
		}
		vc<pi> res;
		rep(i,size())if(t[i]==1){
			uf.Init(n);
			rep(j,size())if(t[j]==1&&j!=i)
				uf.Unite(es[j].first,es[j].second);
			rep(j,size())if(!t[j])
				if(!uf.Same(es[j].first,es[j].second))
					res.eb(i,j);
		}
		return mp(src,res);
	}
};

struct Matroid2{
	vi g,mx;
	int n;
	int s;
	Matroid2(vi gg,vi mm):g(gg),mx(mm),n(g.size()),s(mx.size()){}
	int size(){
		return n;
	}
	pair<vi,vc<pi>> Get(const vi&cur){
		vi cnt(s),used(n);
		vc<array<int,2>> waf(s);
		for(auto i:cur){
			used[i]=1;
			if(g[i]!=-1){
				waf[g[i]][cnt[g[i]]++]=i;
			}
		}
		vi src;
		rep(i,n)if(!used[i]&&(g[i]==-1||cnt[g[i]]<mx[g[i]]))
			src.pb(i);
		vc<pi> res;
		rep(i,n)if(!used[i]&&g[i]!=-1&&cnt[g[i]]==mx[g[i]])
			rep(j,cnt[g[i]])
				res.eb(waf[g[i]][j],i);
		return mp(src,res);
	}
};

void slv(){
	int n,m;cin>>n>>m;
	vc<string> z(n);
	rep(i,n)cin>>z[i];
	
	vvc<int> acth(n+1,vi(m)),actv(n,vi(m+1));
	vvc<int> blh(n+1,vi(m,-1)),blv(n,vi(m+1,-1));
	int bs=0;
	
	rep(i,n)rep(j,m)if(z[i][j]=='O'){
		acth[i][j]+=1;
		acth[i+1][j]+=1;
		actv[i][j]+=1;
		actv[i][j+1]+=1;
		if((i||j)&&(i+j)%2==0){
			blh[i][j]=bs;
			blh[i+1][j]=bs;
			blv[i][j]=bs;
			blv[i][j+1]=bs;
			bs++;
		}
	}
	
	UnionFind uf;
	uf.Init((n+1)*(m+1));
	vc<int> idbuf((n+1)*(m+1),-1);
	int s=0;
	auto getid=[&](int i,int j){
		int k=uf.Find(i*(m+1)+j);
		if(idbuf[k]==-1)
			idbuf[k]=s++;
		return idbuf[k];
	};
	
	rep(i,n+1)rep(j,m)if(acth[i][j]==1){
		uf.Unite(i*(m+1)+j,i*(m+1)+j+1);
	}
	rep(i,n)rep(j,m+1)if(actv[i][j]==1){
		uf.Unite(i*(m+1)+j,(i+1)*(m+1)+j);
	}
	rep(i,n+1)rep(j,m)if(acth[i][j]){
		getid(i,j);
		getid(i,j+1);
	}
	rep(i,n)rep(j,m+1)if(actv[i][j]){
		getid(i,j);
		getid(i+1,j);
	}
	
	MST mst(s);
	vc<tuple<int,int,int>> einfo;
	vi bidx;
	
	rep(i,n+1)rep(j,m)if(acth[i][j]==2){
		mst.AddEdge(getid(i,j),getid(i,j+1));
		bidx.pb(blh[i][j]);
		einfo.eb(0,i,j);
	}
	rep(i,n)rep(j,m+1)if(actv[i][j]==2){
		mst.AddEdge(getid(i,j),getid(i+1,j));
		bidx.pb(blv[i][j]);
		einfo.eb(1,i,j);
	}
	
	vi mx(bs,2);
	
	rep(i,n+1)rep(j,m)if(acth[i][j]==1&&blh[i][j]!=-1){
		mx[blh[i][j]]--;
	}
	rep(i,n)rep(j,m+1)if(actv[i][j]==1&&blv[i][j]!=-1){
		mx[blv[i][j]]--;
	}
	if(mx.size()&&*min_element(all(mx))<0){
		cerr<<"No Answer"<<endl;
		no(0);
		return;
	}
	
	Matroid2 m2(bidx,mx);
	
	MatroidIntersection<MST,Matroid2> mi(mst,m2);
	
	rep(i,bidx.size())
		mi.AddEdge(i,i,0);
	
	auto ans=mi.Solve().b;
	
	if((int)ans.size()==s-1){
		cerr<<"Found an Answer"<<endl;
		yes(0);
		
		vc<string> x(n*2-1,string(m*2-1,'#'));
		rep(i,n)rep(j,m)
			x[i*2][j*2]=z[i][j];
		rep(i,n-1)rep(j,m-1)x[i*2+1][j*2+1]='.';
		auto useedge=[&](tuple<int,int,int> e){
			int t,i,j;tie(t,i,j)=e;
			if(t==0){
				if(i==0||i==n)return;
				x[i*2-1][j*2]=' ';
			}else{
				if(j==0||j==m)return;
				x[i*2][j*2-1]=' ';
			}
		};
		for(auto e:ans){
			useedge(einfo[e]);
		}
		rep(i,n+1)rep(j,m)if(acth[i][j]==1){
			useedge(mt(0,i,j));
		}
		rep(i,n)rep(j,m+1)if(actv[i][j]==1){
			useedge(mt(1,i,j));
		}
		rep(i,n-1)rep(j,m)if(z[i][j]=='X'&&z[i+1][j]=='X')x[i*2+1][j*2]=' ';
		rep(i,n)rep(j,m-1)if(z[i][j]=='X'&&z[i][j+1]=='X')x[i*2][j*2+1]=' ';
		for(auto v:x)
			cout<<v<<endl;
	}else{
		cerr<<"No Answer"<<endl;
		no(0);
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int t;cin>>t;
	rep(_,t)slv();
}