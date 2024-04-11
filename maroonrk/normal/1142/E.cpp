#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll=int64_t;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) FOR(i,0,b)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
auto& errStream=cerr;
#ifdef LOCAL
#define cerr (cerr<<"-- line "<<__LINE__<<" -- ")
#else
class CerrDummy{}cerrDummy;
template<class T>
CerrDummy& operator<<(CerrDummy&cd,const T&){
	return cd;
}
using charTDummy=char;
using traitsDummy=char_traits<charTDummy>;
CerrDummy& operator<<(CerrDummy&cd,basic_ostream<charTDummy,traitsDummy>&(basic_ostream<charTDummy,traitsDummy>&)){
	return cd;
}
#define cerr cerrDummy
#endif
#define REACH cerr<<"reached"<<endl
#define DMP(x) cerr<<#x<<":"<<x<<endl
#define ZERO(x) memset(x,0,sizeof(x))
#define ONE(x) memset(x,-1,sizeof(x))

using pi=pair<int,int>;
using vi=vector<int>;
using ld=long double;

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	rep(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
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
	os<<"(";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<")";
}

ll read(){
	ll i;
	scanf("%"  SCNd64,&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(ll x,int suc=1){
	printf("%" PRId64,x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

template<class T>
void print(const vector<T>&v){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?1:2);
}

string readString(){
	static char buf[3341000];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341000];
	static int bufUsed=0;
	char* ret=buf+bufUsed;
	scanf("%s",ret);
	bufUsed+=strlen(ret)+1;
	return ret;
}

template<class T,class U>
void chmax(T& a,U b){
	if(a<b)
		a=b;
}

template<class T,class U>
void chmin(T& a,U b){
	if(b<a)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

#define CAPITAL
void Yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void No(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
	#endif
	if(ex)exit(0);
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

constexpr ll TEN(int n){
	return n==0?1:TEN(n-1)*10;
}

template<class T>
vector<T> Uniqued(const vector<T>&vv){
	auto v(vv);
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	return v;
}
template<class T>
void MakeUniqued(vector<T>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.end());
}

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

struct SCC_Result{
	int s;
	vi bel;
	vector<vi> idx,graph;
};
ostream& operator<<(ostream&os,const SCC_Result& scc){
	os<<scc.s<<endl;
	os<<scc.bel<<endl;
	os<<scc.idx<<endl;
	os<<scc.graph;
	return os;
}
struct SCC{
	const int n;
	const vector<vi>&g;
	vi ord,low,bel,st;
	int head;
	vector<vi> idx;
	void dfs(int v){
		ord[v]=low[v]=head++;
		st.pb(v);
		for(auto to:g[v]){
			if(ord[to]==-1){
				dfs(to);
				chmin(low[v],low[to]);
			}else{
				if(bel[to]==-1){
					chmin(low[v],ord[to]);
				}
			}
		}
		if(ord[v]==low[v]){
			int c=idx.size();
			idx.eb();
			while(1){
				int t=st.back();
				st.pop_back();
				bel[t]=c;
				idx.back().pb(t);
				if(v==t)break;
			}
		}
	}
	SCC_Result CalcSCC(){
		ord.resize(n,-1);
		low.resize(n,-1);
		bel.resize(n,-1);
		head=0;
		rep(i,n)if(ord[i]==-1)
			dfs(i);
		int s=idx.size();
		rep(i,n)
			bel[i]=s-1-bel[i];
		reverse(all(idx));
		vi used(s,0);
		vector<vi> graph(s);
		rep(i,s){
			for(auto v:idx[i]){
				for(auto to:g[v])if(bel[v]<bel[to]){
					if(!used[bel[to]])
						graph[bel[v]].pb(bel[to]);
					used[bel[to]]=1;
				}
			}
			for(auto v:idx[i])
				for(auto to:g[v])
					used[bel[to]]=0;
		}
		return SCC_Result{s,bel,idx,graph};
	}
	SCC(const vector<vi>&gg):n(gg.size()),g(gg){}
};

const int Nmax=100010;
int nx[Nmax],pr[Nmax];
bool ava[Nmax];
int Erase(int i){
	cerr<<"E "<<i<<endl;
	ava[i]=false;
	int x=pr[i],y=nx[i];
	if(x!=-1)
		nx[x]=y;
	if(y!=-1)
		pr[y]=x;
	return y;
}

void Link(int x,int y){
	if(x!=-1)
		nx[x]=y;
	if(y!=-1)
		pr[y]=x;
}

void Show(int root){
	vi idx;
	while(root!=-1){
		idx.pb(root);
		root=nx[root];
	}
	cerr<<idx<<endl;
}

int Query(int u,int v){
	cout<<"? "<<u+1<<" "<<v+1<<endl;
	int res=read();
	assert(res!=-1);
	return res;
}

signed main(){
	int n=read(),m=read();
	vector<vi> g(n);
	rep(_,m){
		int u=read()-1,v=read()-1;
		g[u].pb(v);
	}
	auto scc=SCC(g).CalcSCC();
	vector<vi> rg(n);
	{
		vector<pi> es;
		rep(i,n){
			for(auto j:g[i]){
				if(scc.bel[i]!=scc.bel[j])
					es.eb(i,j);
				else{
					es.eb(min(i,j),max(i,j));
				}
			}
		}
		for(auto e:es)
			rg[e.second].pb(e.first);
	}
	vi idx(n);
	rep(i,n)idx[i]=i;
	sort(all(idx),[&](int a,int b){
		return mp(scc.bel[a],a)<mp(scc.bel[b],b);
	});
	rep(i,n){
		sort(all(rg[i]),[&](int a,int b){
			return mp(scc.bel[a],a)<mp(scc.bel[b],b);
		});
	}
	cerr<<idx<<endl;
	ONE(nx);
	ONE(pr);
	rep(i,n)
		ava[i]=1;
	int root=idx[0];
	FOR(ii,1,n){
		//Show(root);
		int i=idx[ii];
		int f=-1;
		cerr<<i<<" "<<rg[i]<<endl;
		for(auto p:rg[i])if(ava[p])
			f=p;
		cerr<<f<<" "<<i<<endl;
		int cur=f==-1?root:nx[f];
		while(cur!=-1&&Query(cur,i)==0)
			cur=Erase(cur);
		if(cur==-1){
			Link(f,i);
			if(f==-1){
				cerr<<"R "<<i<<endl;
				root=i;
			}
		}else{
			if(f==-1)
				root=cur;
			ava[i]=false;
		}
	}
	cout<<"! "<<root+1<<endl;
}