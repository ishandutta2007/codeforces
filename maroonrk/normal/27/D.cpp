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

struct TwoSAT{
	static int Pack(int x,bool b){
		return (x<<1)+b;
	}
	static int Idx(int x){
		return x>>1;
	}
	static int Flag(int x){
		return x&1;
	}
	static int Not(int x){
		return x^1;
	}
	const int n;
	vector<vi> g;
	TwoSAT(const int nn):n(nn){
		g.resize(nn*2);
	}
	void Add(int x,int y){
		g[Not(x)].PB(y);
		g[Not(y)].PB(x);
	}
	void Add(int x,int xb,int y,int yb){
		Add(Pack(x,xb),Pack(y,yb));
	}
	SCC_Result scc;
	bool SAT(){
		scc=SCC(g).CalcSCC();
		REP(i,n)
			if(scc.bel[Pack(i,0)]==scc.bel[Pack(i,1)])
				return false;
		return true;
	}
	vi GetAssignment(){
		vi res(n,-1);
		for(int i=scc.s-1;i>=0;i--){
			for(auto v:scc.idx[i])
				if(res[Idx(v)]==-1)
					res[Idx(v)]=Flag(v);
		}
		return res;
	}
};

signed main(){
	int n=read(),m=read();
	vector<pi> rngs(m);
	REP(i,m){
		int a=read()-1,b=read()-1;
		if(a>b)swap(a,b);
		rngs[i]=pi(a,b);
	}
	TwoSAT ts(m);
	REP(i,m)REP(j,i){
		int a=i,b=j;
		pi x=rngs[i],y=rngs[j];
		if(x.first>y.first){
			swap(a,b);
			swap(x,y);
		}
		if(x.first<y.first&&y.first<x.second&&x.second<y.second){
			REP(k,2){
				ts.Add(a,k,b,k);
			}
		}
	}
	bool sat=ts.SAT();
	if(!sat){
		cout<<"Impossible"<<endl;
		return 0;
	}
	vi ans=ts.GetAssignment();
	REP(i,m)
		cout<<(ans[i]?'o':'i');
	cout<<endl;
}