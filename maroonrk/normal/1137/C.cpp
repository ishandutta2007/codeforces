#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll=int64_t;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(x) x.begin(),x.end()
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
	REP(i,(int)v.size()){
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
	REP(i,v.size())
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

constexpr ll Ten(int n){
	return n==0?1:Ten(n-1)*10;
}

template<class T>
vector<T> Uniqued(const vector<T>&vv){
	auto v(vv);
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	return v;
}
template<class T>
void MakeUniqued(vector<T>&v){
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
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
		st.PB(v);
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
			idx.EB();
			while(1){
				int t=st.back();
				st.pop_back();
				bel[t]=c;
				idx.back().PB(t);
				if(v==t)break;
			}
		}
	}
	SCC_Result CalcSCC(){
		ord.resize(n,-1);
		low.resize(n,-1);
		bel.resize(n,-1);
		head=0;
		REP(i,n)if(ord[i]==-1)
			dfs(i);
		int s=idx.size();
		REP(i,n)
			bel[i]=s-1-bel[i];
		reverse(ALL(idx));
		vi used(s,0);
		vector<vi> graph(s);
		REP(i,s){
			for(auto v:idx[i]){
				for(auto to:g[v])if(bel[v]<bel[to]){
					if(!used[bel[to]])
						graph[bel[v]].PB(bel[to]);
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

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

signed main(){
	int n=read(),m=read(),len=read();
	vector<vi> g(n);
	REP(i,m){
		int u=read()-1,v=read()-1;
		g[u].PB(v);
	}
	vector<string> ss(n);
	REP(i,n)
		ss[i]=readString();
	
	auto scc=SCC(g).CalcSCC();
	int s=scc.s;
	vi cycle(s);
	vi dep(n,-1);
	REP(i,s){
		int root=scc.idx[i].front();
		int w=len;
		function<void(int,int)> dfs=[&](int v,int d){
			assert(dep[v]==-1);
			dep[v]=d;
			for(auto to:g[v])if(scc.bel[v]==scc.bel[to]){
				if(dep[to]==-1){
					dfs(to,d+1);
				}
				w=gcd(w,1+dep[v]-dep[to]%len+len);
			}
		};
		dfs(root,0);
		cycle[i]=w;
	}
	cerr<<dep<<endl;
	cerr<<cycle<<endl;
	
	vector<vi> dp(s);
	for(int i=s-1;i>=0;i--){
		dp[i].resize(cycle[i],0);
		REP(j,cycle[i]){
			int base=0,ad=0;
			for(auto k:scc.idx[i]){
				bool ok=false;
				for(int x=(dep[k]+j)%cycle[i];x<len;x+=cycle[i]){
					for(auto to:g[k])if(scc.bel[k]!=scc.bel[to]){
						int w=scc.bel[to];
						int y=(x+1-dep[to])%cycle[w];
						if(y<0)y+=cycle[w];
						chmax(ad,dp[w][y]);
					}
					if(ss[k][x]=='1')
						ok=true;
				}
				if(ok)
					base++;
			}
			dp[i][j]=base+ad;
		}
	}
	
	int w=scc.bel[0];
	int x=(-dep[0])%cycle[w];
	if(x<0)x+=cycle[w];
	print(dp[w][x]);
}