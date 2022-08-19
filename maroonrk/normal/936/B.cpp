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

//s: the number of SCCs.
//bl[i]: SCC to which the vertex i belongs
//idx[i]: list of the vertices in the i-th SCC
//gr: DAG of SCCs
//SCCs are numbered in topological order
//VERIFY: yosupo
//AOJGRL3C(except gr)
template<class t>
struct scc{
	const int n;
	const vvc<int>&g;
	vi ord,low,bl,st;
	int s,head;
	vvc<int> idx,gr;
	void dfs(int v){
		ord[v]=low[v]=head++;
		st.pb(v);
		for(auto to:g[v]){
			if(ord[to]==-1){
				dfs(to);
				chmin(low[v],low[to]);
			}else if(bl[to]==-1)
				chmin(low[v],ord[to]);
		}
		if(ord[v]==low[v]){
			int c=idx.size();
			idx.eb();
			while(1){
				int a=st.back();
				st.pop_back();
				bl[a]=c;
				idx.back().pb(a);
				if(v==a)break;
			}
		}
	}
	scc(const vvc<t>&gg,bool cgr=true):n(gg.size()),g(gg),
		ord(n,-1),low(n,-1),bl(n,-1){
		head=0;
		rep(i,n)if(ord[i]==-1)
			dfs(i);
		s=idx.size();
		rep(i,n)
			bl[i]=s-1-bl[i];
		reverse(all(idx));
		//construct the graph
		if(cgr){
			vc<bool> u(s);
			gr.resize(s);
			rep(i,s){
				for(auto v:idx[i]){
					for(auto to:g[v])if(bl[v]<bl[to]){
						if(!u[bl[to]])
							gr[bl[v]].pb(bl[to]);
						u[bl[to]]=1;
					}
				}
				for(auto v:idx[i])
					for(auto to:g[v])
						u[bl[to]]=0;
			}
		}
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,m;cin>>n>>m;
	vi oc(n);
	vvc<int> g(n);
	rep(i,n){
		int c;cin>>c;
		rep(_,c){
			int a;cin>>a;
			a--;
			g[a].pb(i);
		}
		oc[i]=c;
	}
	
	vi score(n);
	rep(i,n)if(oc[i]==0)score[i]=2;
	
	{
		scc<int> z(g,false);
		for(auto vs:z.idx)if(si(vs)>1){
			for(auto v:vs){
				chmax(score[v],1);
			}
		}
	}
	
	vi idx(n);
	iota(all(idx),0);
	sort(all(idx),[&](int i,int j){return score[i]>score[j];});
	
	dmp(score);
	
	int tar=read()-1;
	
	vc<array<char,2>> vis(n);
	auto dfs=[&](auto self,int v,int p,vi&vs)->bool{
		if(vis[v][p])return false;
		dmp2(v,p);
		vs.pb(v);
		vis[v][p]=1;
		if(p==1&&v==tar)return true;
		for(auto to:g[v])
			if(self(self,to,p^1,vs))return true;
		vs.pop_back();
		return false;
	};
	
	for(auto i:idx){
		vi vs;
		if(dfs(dfs,i,0,vs)){
			if(score[i]==2){
				cout<<"Win"<<endl;
				reverse(all(vs));
				for(auto&v:vs)v++;
				print(vs);
			}else if(score[i]==1){
				cout<<"Draw"<<endl;
			}else{
				cout<<"Lose"<<endl;
			}
			return 0;
		}
	}
	cout<<"Lose"<<endl;
}