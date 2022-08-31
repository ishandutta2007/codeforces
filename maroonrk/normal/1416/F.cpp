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

#define CAPITAL
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

template<class d>
struct maxflow{
	struct E{
		int to,rev;
		d cap;
	};
	vvc<E> g;
	vi itr,lv,q;
	maxflow(int n):g(n),itr(n),lv(n),q(n){}
	pi ae(int s,int t,d c){
		g[s].pb({t,(int)g[t].size(),c});
		g[t].pb({s,(int)g[s].size()-1,0});
		return pi(s,si(g[s])-1);
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
		while(f<mx){
			bfs(s);
			if(lv[t]==-1)
				return f;
			fill(all(itr),0);
			f+=dfs(s,t,mx-f);
		}
		return f;
	}
};

void slv(){
	int n,m;cin>>n>>m;
	vvc<int> a(n,vi(m));
	rep(i,n)a[i]=readvi(m);
	if(n*m==1){
		no(0);
		return;
	}
	{
		rep(i,n)rep(j,m){
			if(a[i][j]==1){
				no(0);
				return;
			}
		}
	}
	vvc<int> idx(n,vi(m,-1));
	int cnt[2]{};
	rep(i,n)rep(j,m){
		int p=(i+j)%2;
		idx[i][j]=cnt[p]++;
	}
	int s=cnt[0]+cnt[1];
	maxflow<int> mf(s+4);
	vc<tuple<pi,pi,pi>> match;
	vc<string> ans(n,string(m,'?'));
	const int dyx[]{-1,0,1,0,-1};
	const string dirstr="URDL";
	vvc<int> vals(n,vi(m,-1));
	rep(i,n)rep(j,m){
		rep(dir,4){
			int y=i+dyx[dir];
			int x=j+dyx[dir+1];
			if(inc(0,y,n-1)&&inc(0,x,m-1)){
				if(a[y][x]<a[i][j]){
					ans[i][j]=dirstr[dir];
					vals[i][j]=a[i][j]-a[y][x];
				}
			}
		}
		int p=(i+j)%2;
		int k=idx[i][j];
		if(ans[i][j]=='?'){
			if(p==0){
				mf.ae(s+1,k,1);
			}else{
				mf.ae(cnt[0]+k,s+3,1);
			}
		}else{
			if(p==0){
				mf.ae(s,k,1);
			}else{
				mf.ae(cnt[0]+k,s+2,1);
			}
		}
		if(p==0){
			rep(dir,4){
				int y=i+dyx[dir];
				int x=j+dyx[dir+1];
				if(inc(0,y,n-1)&&inc(0,x,m-1)&&a[i][j]==a[y][x]){
					match.eb(pi(i,j),pi(y,x),mf.ae(k,cnt[0]+idx[y][x],1));
				}
			}
		}
	}
	mf.calc(s+1,s+3);
	mf.calc(s+1,s+2);
	mf.calc(s+0,s+3);
	mf.calc(s+0,s+2);
	for(auto z:match){
		pi fr,to,e;tie(fr,to,e)=z;
		if(mf.g[e.a][e.b].cap==0){
			rep(dir,4){
				int y=fr.a+dyx[dir];
				int x=fr.b+dyx[dir+1];
				if(pi(y,x)==to){
					ans[fr.a][fr.b]=dirstr[dir];
					ans[to.a][to.b]=dirstr[dir^2];
					vals[fr.a][fr.b]=1;
					vals[to.a][to.b]=a[to.a][to.b]-1;
				}
			}
		}
	}
	rep(i,n)rep(j,m)if(ans[i][j]=='?'){
		no(0);
		return;
	}
	yes(0);
	rep(i,n)print(vals[i]);
	rep(i,n)print(vc<char>(all(ans[i])));
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int t;cin>>t;rep(_,t)slv();
}