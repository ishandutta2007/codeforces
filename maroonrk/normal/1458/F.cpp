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

//Ofast,unroll-loops 

//VERIFY:
//spaceships
//do_use_segment_tree
//CF679D
//CF564E
//TTPC2019M

//splay tree 
//
//light edge 
// LCT  (c[0],c[1])
//c[2]  light edges 
//light edge light edge  splay tree  (c[0],c[2])
// c[1] 
template<class N>
struct toptree{
	struct node{
		//t==0 vertex
		//t==1 path edge
		//t==2 light edge
		N d;
		bool rev;
		int c[3],p;
		node(char tt=-1):rev(false),c{-1,-1,-1},p(-1){d.t=tt;}
		void show(){
			cerr<<int(d.t)<<" "<<"("<<c[0]<<","<<c[1]<<","<<c[2]<<") "<<p<<endl;
		}
	};
	using np=node*;
	int n;
	vc<node> x;
	//unused  clean 
	vi unused;
	toptree(int nn):n(nn),x(n*2-1){
		gnr(i,n,n*2-1)unused.pb(i);
	}
	//reverse  path node 
	//light edge  rev  false
	inline void reverse(int v){
		assert(v!=-1);
		assert(x[v].d.t<2);
		x[v].rev^=1;
		x[v].d.reverse();
		swap(x[v].c[0],x[v].c[1]);
	}
	//v  valid
	//link  update 
	inline void set_child(int v,int k,int c){
		assert(v!=-1);
		assert(inc(0,k,2));
		x[v].c[k]=c;
		if(c!=-1)x[c].p=v;
	}
	inline void set_light_left(int v,int c){set_child(v,0,c);}
	inline void set_light_right(int v,int c){set_child(v,2,c);}
	inline void set_path_left(int v,int c){set_child(v,0,c);}
	inline void set_path_right(int v,int c){set_child(v,1,c);}
	//v,c  valid
	//link  update 
	inline void insert_light(int v,int c){
		assert(v!=-1);
		assert(x[v].d.t==0);
		assert(c!=-1);
		assert(x[c].d.t==2);
		set_light_right(c,x[v].c[2]);
		x[v].c[2]=c;
		x[c].p=v;
	}
	inline void make_path_vertex(int v){assert(inc(0,v,n-1));x[v].d.t=0;}
	inline void make_path_edge(int v){assert(inc(n,v,n*2-2));x[v].d.t=1;}
	inline void make_light(int v){assert(inc(n,v,n*2-2));assert(!x[v].rev);x[v].d.t=2;}
	void update(int v){
		assert(v!=-1);
		assert(!x[v].rev);
		x[v].d.single();
		if(x[v].d.t<2){
			if(x[v].c[2]!=-1)x[v].d.update_light(x[x[v].c[2]].d);
			rep(k,2)if(x[v].c[k]!=-1)x[v].d.update_path(k,x[x[v].c[k]].d);
		}else if(x[v].d.t==2){
			assert(x[v].c[1]!=-1);
			x[v].d.update_path(1,x[x[v].c[1]].d);
			for(int k=0;k<3;k+=2)if(x[v].c[k]!=-1)x[v].d.update_light(x[x[v].c[k]].d);
		}else{
			assert(false);
		}
	}
	void downdate(int v){
		assert(v!=-1);
		if(x[v].d.t<2){
			if(x[v].rev){
				x[v].rev=false;
				rep(k,2)if(x[v].c[k]!=-1)reverse(x[v].c[k]);
			}
			if(x[v].c[2]!=-1)x[v].d.push_light(x[x[v].c[2]].d);
			rep(k,2)if(x[v].c[k]!=-1)x[v].d.push_path(k,x[x[v].c[k]].d);
		}else if(x[v].d.t==2){
			assert(!x[v].rev);
			assert(x[v].c[1]!=-1);
			x[v].d.push_path(1,x[x[v].c[1]].d);
			for(int k=0;k<3;k+=2)if(x[v].c[k]!=-1)x[v].d.push_light(x[x[v].c[k]].d);
		}else{
			assert(false);
		}
		x[v].d.clear_lazy();
	}
	//0,z  rotate
	void rotate(int v,int z){
		assert(v!=-1);
		int p=x[v].p,c;
		assert(p!=-1);
		if(x[p].c[0]==v){
			c=x[v].c[z];
			x[v].c[z]=p;
			x[p].c[0]=c;
		}else{
			c=x[v].c[0];
			x[v].c[0]=p;
			x[p].c[z]=c;
		}
		if(c!=-1)x[c].p=p;
		x[v].p=x[p].p;
		x[p].p=v;
		if(x[v].p!=-1){
			rep(k,3)if(x[x[v].p].c[k]==p)
				x[x[v].p].c[k]=v;
		}
		update(p);
		//cerr<<"After Rotate "<<v<<endl;
		//show();
	}
	//void rotate_path(int v){rotate(v,1);}
	//void rotate_light(int v){rotate(v,2);}
	//downdate 
	// v 
	void prepare(int v){
		assert(v!=-1);
		if(x[v].p!=-1)prepare(x[v].p);
		downdate(v);
	}
	//prepare 
	//path/light 
	//
	void splay(int v){
		assert(v!=-1);
		int z=x[v].d.t<2?1:2;
		while(1){
			int p=x[v].p;
			if(p==-1||(x[p].d.t<2)^(x[v].d.t<2))break;
			int q=x[p].p;
			if(q==-1||(x[q].d.t<2)^(x[v].d.t<2)){
				rotate(v,z);
			}else{
				if((x[p].c[0]==v&&x[q].c[0]==p)||(x[p].c[z]==v&&x[q].c[z]==p))
					rotate(p,z);
				else
					rotate(v,z);
				rotate(v,z);
			}
		}
		update(v);
	}
	int go_deep(int v,int k){
		assert(v!=-1);
		while(1){
			downdate(v);
			if(x[v].c[k]!=-1)v=x[v].c[k];
			else return v;
		}
		assert(false);
	}
	void expose(int v){
		assert(v!=-1);
		prepare(v);
		for(int a=v;a!=-1;a=x[a].p)
			splay(a);
		for(int a=v;a!=-1;a=x[a].p){
			if(x[a].d.t==2){
				int b=x[a].p;
				assert(b!=-1);
				if(x[b].c[1]==-1){
					int l=x[a].c[0],r=x[a].c[2];
					if(l!=-1){
						x[l].p=-1;
						l=go_deep(l,2);
						splay(l);
						set_light_right(l,r);
						update(l);
					}else{
						l=r;
					}
					set_light_right(b,l);
				}else{
					int c=x[b].c[1];
					x[c].p=-1;
					c=go_deep(c,0);
					splay(c);
					assert(!x[c].rev);
					make_light(c);
					set_light_left(c,x[a].c[0]);
					set_light_right(c,x[a].c[2]);
					set_light_right(b,c);
					//b,c 
					update(c);
					//c 
				}
				x[a].c[0]=x[a].c[2]=-1;
				make_path_edge(a);
				set_path_right(b,a);
			}
		}
		//cerr<<"Before Splay "<<v<<endl;
		//show();
		splay(v);
		//cerr<<"After Expose "<<v<<endl;
		//show();
	}
	template<class...Args>
	void init_vertex(int v,Args&&...args){
		assert(inc(0,v,n-1));
		x[v]=node(0);
		x[v].d.init_vertex(v,forward<Args>(args)...);
	}
	template<class...Args>
	void init_edge(int v,char t,int a,int b,Args&&...args){
		x[v]=node(t);
		x[v].d.init_edge(a,b,forward<Args>(args)...);
	}
	void evert(int v){
		assert(inc(0,v,n-1));
		expose(v);
		if(x[v].c[0]!=-1){
			int c=x[v].c[0];
			x[v].c[0]=-1;
			x[c].p=-1;
			c=go_deep(c,1);
			splay(c);
			reverse(c);
			assert(x[c].rev);
			x[c].rev=false;
			reverse(x[c].c[1]);
			make_light(c);
			insert_light(v,c);
			//v,c 
			update(c);
			update(v);
			//v,c 
		}
	}
	//a  b  (a ) index 
	//-1 
	template<class...Args>
	int link(int a,int b,Args&&...args){
		assert(inc(0,a,n-1));
		assert(inc(0,b,n-1));
		expose(a);
		evert(b);
		if(x[a].p==-1){
			assert(si(unused));
			int e=unused.back();unused.pop_back();
			init_edge(e,2,a,b,forward<Args>(args)...);
			set_path_right(e,b);
			insert_light(a,e);
			//a,e 
			update(e);
			update(a);
			//a,e 
			return e;
		}else{
			return -1;
		}
	}
	//cut ()
	pi cut(int e){
		assert(inc(n,e,n*2-2));
		expose(e);
		pi res(x[e].c[0],x[e].c[1]);
		if(res.a!=-1)x[res.a].p=-1;
		if(res.b!=-1)x[res.b].p=-1;
		x[e].d.t=-1;
		unused.pb(e);
		return res;
	}
	int lca(int a,int b){
		assert(inc(0,a,n-1));
		assert(inc(0,b,n-1));
		expose(a);
		expose(b);
		if(x[a].p==-1)return -1;
		int d=a;
		while(a!=b){
			int p=x[a].p;
			if(x[a].d.t==2&&x[p].d.t<2)d=p;
			else if(p==b&&x[p].c[1]==a)d=b;
			a=p;
		}
		assert(inc(0,d,n-1));
		return d;
	}
	void expose_path(int a,int b){
		assert(inc(0,a,n-1));
		assert(inc(0,b,n-1));
		evert(a);
		expose(b);
		int c=x[b].c[1];
		if(c!=-1){
			x[b].c[1]=-1;
			x[c].p=-1;
			c=go_deep(c,0);
			splay(c);
			assert(!x[c].rev);
			make_light(c);
			insert_light(b,c);
			update(c);
			update(b);
		}
	}
	N&operator[](int i){return x[i].d;}
	void show(){
		rep(i,n*2-1)if(x[i].d.t!=-1){
			cerr<<i<<" ";
			x[i].show();
		}
	}
	//init_vertex 
	//E.idx  id 
	template<class H> void init_from_hld(const H&hld){
		unused.clear();
		auto subtree=[&](auto subtree_self,int root)->int{
			auto path=[&](auto path_self,int l,int r)->int{
				if(r<l)return -1;
				const int m=(l+r)/2;
				int v=hld.ni[(m+1)/2],z;
				if(m%2==0){
					z=v;
					auto light=[&](auto light_self,int a,int b)->int{
						if(b<a)return -1;
						const int c=(a+b)/2;
						int u=hld.g[v][c],w=hld.pe[u].idx+n;
						init_edge(w,2,v,u,hld.pe[u]);
						set_path_right(w,subtree_self(subtree_self,u));
						set_light_left(w,light_self(light_self,a,c-1));
						set_light_right(w,light_self(light_self,c+1,b));
						update(w);
						return w;
					};
					set_light_right(z,light(light,1,si(hld.g[v])-1));
				}else{
					z=hld.pe[v].idx+n;
					init_edge(z,1,hld.par[v],v,hld.pe[v]);
				}
				set_path_left(z,path_self(path_self,l,m-1));
				set_path_right(z,path_self(path_self,m+1,r));
				update(z);
				return z;
			};
			return path(path,hld.in[root]*2,(hld.in[root]+hld.hei[root]-1)*2);
		};
		subtree(subtree,hld.rt);
	}
};

// in,out 
//hei[v] -> heavy edge 
//VERIFY: yosupo
//CF530F
//CodeChef Persistent Oak
//AOJ GRL5C
template<class E>
struct HLD{
	vvc<E> g;
	int n,rt,cnt;
	vi sub,in,out,par,head,dep,hei,ni;
	vc<E> pe;
	int dfs1(int v,int p,int d){
		par[v]=p;
		dep[v]=d;
		for(auto itr=g[v].bg;itr!=g[v].ed;itr++)
			if(*itr==p){
				pe[v]=*itr;
				g[v].erase(itr);
				break;
			}
		for(auto&e:g[v]){
			sub[v]+=dfs1(e,v,d+1);
			if(sub[g[v][0]]<sub[e])
				swap(g[v][0],e);
		}
		return sub[v];
	}
	void dfs2(int v,int h){
		in[v]=cnt++;
		head[v]=h;
		for(int to:g[v])
			dfs2(to,to==g[v][0]?h:to);
		out[v]=cnt;
		if(si(g[v]))hei[v]=hei[g[v][0]]+1;
	}
	HLD(){}
	HLD(const vvc<E>&gg,int rr):g(gg),n(g.size()),rt(rr),cnt(0),
		sub(n,1),in(n),out(n),par(n,-1),head(n),dep(n),hei(n,1),ni(n),
		pe(n){
		dfs1(rt,-1,0);
		dfs2(rt,rt);
		rep(i,n)ni[in[i]]=i;
	}
	int lca(int a,int b){
		while(head[a]!=head[b]){
			if(dep[head[a]]>dep[head[b]])
				swap(a,b);
			b=par[head[b]];
		}
		if(dep[a]>dep[b])
			swap(a,b);
		return a;
	}
	int len(int a,int b){
		return dep[a]+dep[b]-dep[lca(a,b)]*2;
	}
	bool asde(int a,int b){
		return in[a]<=in[b]&&out[b]<=out[a];
	}
	//XX Opencup GP of Korea
	//CF625 F
	//2020 Multi-Uni Contest Day5 G
	//CF415E
	vi index;
	//vs  virtual tree 
	// virtual tree 
	//virtual tree 
	// virtual tree index 
	// ch->par 
	//virtual tree 
	// 0 
	pair<vi,vc<pi>> tree_compress(vi vs){
		if(si(index)==0)index.resize(n);
		assert(index.size());
		auto comp = [&](int x,int y){
			return in[x] < in[y];
		};
		sort(all(vs),comp);
		vs.erase(unique(all(vs)),vs.ed);
		int k = vs.size();
		rep(i,k-1){
			vs.pb(lca(vs[i],vs[i+1]));
		}
		sort(all(vs),comp);
		vs.erase(unique(all(vs)),vs.ed);
		k = vs.size();
		rep(i,k) index[vs[i]] = i;
		vc<pi> es;
		rng(i,1,k){
			int p = lca(vs[i-1],vs[i]);
			es.eb(i,index[p]);
		}
		return mp(vs,es);
	}
};

//Lyft Level 5 Challenge 2018 - Final F
//CF635F
template<class E>
struct doubling{
	const vvc<E>&g;
	const int n,h;
	int cnt;
	vvc<int> par;
	vi dep,in,out;
	void dfs(int v,int p,int d){
		par[0][v]=p;
		dep[v]=d;
		in[v]=cnt++;
		for(auto e:g[v])if(e!=p)
			dfs(e,v,d+1);
		out[v]=cnt;
	}
	doubling(const vvc<E>&gg,int r):g(gg),n(g.size()),h(__lg(n)+1),
		cnt(0),par(h,vi(n,-1)),dep(n),in(n),out(n){
		dfs(r,-1,0);
		rng(i,1,h){
			rep(j,n)
				if(par[i-1][j]!=-1)
					par[i][j]=par[i-1][par[i-1][j]];
		}
	}
	int lca(int a,int b){
		assert(0<=a&&a<(int)g.size());
		assert(0<=b&&b<(int)g.size());
		if(dep[a]>dep[b])swap(a,b);
		int w=dep[b]-dep[a];
		rep(i,h)if(w&1<<i)
			b=par[i][b];
		if(a==b)return a;
		per(i,h){
			int x=par[i][a],y=par[i][b];
			if(x!=y)tie(a,b)=pi(x,y);
		}
		return par[0][a];
	}
	int len(int a,int b){
		assert(0<=a&&a<(int)g.size());
		assert(0<=b&&b<(int)g.size());
		return dep[a]+dep[b]-dep[lca(a,b)]*2;
	}
	int jump(int a,int b,int d){
		assert(0<=a&&a<(int)g.size());
		assert(0<=b&&b<(int)g.size());
		int c=lca(a,b);
		int w=dep[a]+dep[b]-dep[c]*2;
		assert(0<=d&&d<=w);
		if(d<=dep[a]-dep[c]){
			rep(i,h)if(d&1<<i)
				a=par[i][a];
			return a;
		}else{
			d=w-d;
			rep(i,h)if(d&1<<i)
				b=par[i][b];
			return b;
		}
	}
	int getpar(int v,int len)const{
		rep(i,h)if(len&1<<i)v=par[i][v];
		return v;
	}
};

struct E{
	int to,idx;
	operator int()const{return to;}
};
//init_from_hld(HLD<E>(t,0)) 

// rep(i,n)t.init_vertex(i) 

//init_vertex(v,...): 
//init_edge(a,b,...): a 
//single(): ()
//reverse(): 
//update_path(k,N): path (k==0?:) path 
//=compress
//update_light: light 
//=rake
//
//
//push_path(k,N), push_light(N): push update 
//clear_lazy(): lazy  clear  

//
//
//vertex , light -> path 
//light edge path -> light 

//t 
//
//t==0 vertex
//t==1 path edge
//t==2 light edge

//CF691F
//active
// static 
//flip  update 
struct N{
	char t;
	int rw,cnt,len[2];
	ll ans,s[2];
	void init_vertex(int){
		rw=0;
		single();
	}
	void init_edge(int,int){
		rw=0;
		single();
	}
	void init_edge(int a,int b,const E&){
		init_edge(a,b);
	}
	void single(){
		if(t==0){
			cnt=rw;
			len[0]=len[1]=0;
			ans=0;
			s[0]=s[1]=0;
		}
		else{
			cnt=rw;
			len[0]=len[1]=1;
			ans=0;
			s[0]=s[1]=cnt;
		}
	}
	void reverse(){assert(false);}
	void update_path(int dir,const N&x_){
		N x[2]{x_,*this};
		if(dir)swap(x[0],x[1]);
		cnt=x[0].cnt+x[1].cnt;
		rep(k,2)len[k]=x[k].len[k];
		len[dir]+=x[0].len[1]+x[1].len[0];
		ans+=x[dir].s[dir^1]+ll(x[dir^1].len[dir])*x[dir].cnt;
		rep(k,2)s[k]=x[k].s[k]+x[k^1].s[k]+ll(x[k].len[0]+x[k].len[1])*x[k^1].cnt;
	}
	void update_light(const N& x){
		cnt+=x.cnt;
		ans+=x.s[0]+ll(len[0])*x.cnt;
		s[0]+=x.s[0];
		s[1]+=x.s[0]+ll(len[0]+len[1])*x.cnt;
	}
	void push_path(int,N&){
	}
	void push_light(N&){
	}
	void clear_lazy(){
	}
	
	void add(int v){
		rw+=v;
	}
};

void slv(){
	int n;cin>>n;
	vvc<E> t(n);
	vvc<int> dt(n*2-1);
	rep(i,n-1){
		int a,b;cin>>a>>b;
		a--;b--;
		t[a].pb({b,i});
		t[b].pb({a,i});
		dt[a].pb(n+i);
		dt[b].pb(n+i);
		dt[n+i].pb(a);
		dt[n+i].pb(b);
	}
	doubling<int> dd(dt,0);
	toptree<N> x(n);
	rep(i,n)x.init_vertex(i);
	x.init_from_hld(HLD<E>(t,0));
	ll ans=0;
	auto mg=[&](pi a,pi b){
		int d=dd.len(a.a,b.a);
		if(a.b>=d+b.b)return a;
		if(b.b>=d+a.b)return b;
		int w=d+a.b+b.b;
		assert(w%2==0);
		w/=2;
		int z=w-a.b;
		return pi(dd.jump(a.a,b.a,z),w);
	};
	auto getmax=[&](pi a,pi b){
		int d=dd.len(a.a,b.a);
		return max({a.b*2,b.b*2,a.b+d+b.b});
	};
	vi unko(n*2-1);
	auto upd=[&](int v,int w){
		unko[v]+=w;
		
		x.expose(v);
		x[v].add(w);
		x.update(v);
	};
	auto getsum=[&](int v){
		x.expose(v);
		
		#ifdef LOCAL
		int res=0;
		{
			auto rec=[&](auto self,int i,int p,int d)->void{
				if(unko[i])res+=d*unko[i];
				for(auto to:dt[i])if(to!=p)
					self(self,to,i,d+1);
			};
			rec(rec,v,-1,0);
		}
		assert(res==x[v].ans);
		#endif
		
		return x[v].ans;
	};
	vc<pi> w(n);
	vc<ll> sum(n+1);
	auto rec=[&](auto self,int l,int r)->void{
		if(l+1==r)return;
		int m=(l+r)/2;
		w[m]=pi(m,0);
		rng(i,m+1,r)w[i]=mg(pi(i,0),w[i-1]);
		sum[m]=0;
		rng(i,m,r)sum[i+1]=sum[i]+w[i].b;
		pi cur;
		int b=m,e=m;
		gnr(i,l,m){
			if(i==m-1){
				cur=pi(i,0);
			}else{
				cur=mg(pi(i,0),cur);
			}
			while(e<r){
				if(getmax(cur,w[e])>w[e].b*2){
					upd(w[e++].a,1);
				}else{
					break;
				}
			}
			while(b<e){
				if(cur.b*2>=getmax(cur,w[b])){
					upd(w[b++].a,-1);
				}else{
					break;
				}
			}
			ans+=cur.b*2*ll(b-m);
			ans+=cur.b*ll(e-b);
			ans+=sum[e]-sum[b];
			ans+=getsum(cur.a);
			ans+=(sum[r]-sum[e])*2;
			/*vi baka(n*2-1);
			rng(j,m,r){
				int val=getmax(cur,w[j]);
				ans+=val;
				if(j<b){
					assert(val==cur.b*2);
				}else if(j<e){
					int tmp=cur.b+w[j].b+dd.len(cur.a,w[j].a);
					assert(val==tmp);
					ans-=+dd.len(cur.a,w[j].a);
					baka[w[j].a]=1;
				}else{
					assert(val==w[j].b*2);
				}
			}
			if(unko!=baka){
				dmp2(b,e);
				dmp(unko);
				dmp(baka);
			}
			assert(unko==baka);*/
		}
		while(b<e)upd(w[b++].a,-1);
		self(self,l,m);
		self(self,m,r);
	};
	rec(rec,0,n);
	print(ans/2);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}