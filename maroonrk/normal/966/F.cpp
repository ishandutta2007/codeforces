#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#ifdef MAROON_LOCAL
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

ll read(){
	ll i;
	scanf("%" SCNd64,&i);
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

namespace MaxFlow{
	using CapType=long double;
	struct Edge{
		int to,rev;
		CapType cap;
	};
	vector<vector<Edge>> g;
	vi itr,level;
	void Init(int n){
		g.assign(n,vector<Edge>());
		itr.assign(n,0);
		level.assign(n,0);
	}
	void AddEdge(int from,int to,CapType cap){
		g[from].PB({to,(int)g[to].size(),cap});
		g[to].PB({from,(int)g[from].size()-1,0});
	}
	void bfs(int s){
		fill(level.begin(),level.end(),-1);
		level[s]=0;
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			int v=q.front();q.pop();
			for(auto e:g[v])if(e.cap>0&&level[e.to]==-1){
				level[e.to]=level[v]+1;
				q.push(e.to);
			}
		}
	}
	CapType dfs(int v,int t,CapType f){
		if(v==t)
			return f;
		CapType res=0;
		for(int&i=itr[v];i<(int)g[v].size();i++){
			Edge& e=g[v][i];
			if(e.cap>0&&level[e.to]==level[v]+1){
				CapType d=dfs(e.to,t,min(f,e.cap));
				if(d>0){
					e.cap-=d;
					g[e.to][e.rev].cap+=d;
					res+=d;
					f-=d;
					if(f<=0)break;
				}
			}
		}
		return res;
	}
	CapType Calc(int s,int t){
		CapType flow=0;
		while(1){
			bfs(s);
			if(level[t]==-1)
				return flow;
			fill(itr.begin(),itr.end(),0);
			flow+=dfs(s,t,inf);
		}
	}
}

const double eps=1e-7;
struct Edge{
	int u,v;
	double a,b,c,d;
};
double Get(int n,const vector<Edge>& es,double t){
	MaxFlow::Init(n+2);
	double lSum=0;
	for(auto e:es){
		double l=e.a*t+e.b;
		double r=e.c*t+e.d;
		MaxFlow::AddEdge(n,e.v,l);
		MaxFlow::AddEdge(e.u,n+1,l);
		MaxFlow::AddEdge(e.u,e.v,max(double(0),r-l));
		lSum+=l;
	}
	double f=MaxFlow::Calc(n,n+1);
	return lSum-f;
}

void Answer(double x){
	cout<<fixed<<setprecision(20)<<x<<endl;
	exit(0);
}

signed main(){
	int n=read(),m=read();
	vector<Edge> es(m);
	REP(i,m){
		es[i].u=read()-1;
		es[i].v=read()-1;
		es[i].a=read();
		es[i].b=read();
		es[i].c=read();
		es[i].d=read();
	}
	
	double l=0,r=1;
	REP(_,50){
		const double m1=(l*2+r)/3,m2=(l+r*2)/3;
		const double g1=Get(n,es,m1),g2=Get(n,es,m2);
		if(g1<g2)
			r=m2;
		else
			l=m1;
	}
	
	const double center=l;
	if(Get(n,es,center)>eps)
		Answer(0);
	
	l=0,r=center;
	REP(_,25){
		const double mid=(l+r)/2;
		const double g=Get(n,es,mid);
		if(g<eps)
			r=mid;
		else
			l=mid;
	}
	const double left=l;
	
	l=center,r=1;
	REP(_,25){
		const double mid=(l+r)/2;
		const double g=Get(n,es,mid);
		if(g<eps)
			l=mid;
		else
			r=mid;
	}
	const double right=l;
	
	Answer(right-left);
}