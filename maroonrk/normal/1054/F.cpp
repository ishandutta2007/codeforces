#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
//#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
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

namespace MaxFlow{
	using CapType=int;
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
	vi GetGroup(){
		int s=g.size();
		vi res(s,0);
		REP(i,s)
			if(level[i]==-1)
				res[i]=1;
		return res;
	}
}

struct Line{
	int a,b,c;
};

vector<Line> GetLines(const map<int,vi>& y2x){
	vector<Line> hor;
	for(auto kv:y2x){
		int y=kv.first;
		vi xs=kv.second;
		sort(ALL(xs));
		int s=xs.size();
		REP(i,s-1)
			hor.PB(Line{y,xs[i],xs[i+1]});
	}
	return hor;
}

vector<Line> GetWires(const map<int,vi>& y2x){
	vector<Line> hor;
	for(auto kv:y2x){
		int y=kv.first;
		vi xs=kv.second;
		sort(ALL(xs));
		int s=xs.size();
		for(int i=0;i<s;){
			int j=i;
			while(j+1<s&&xs[j]==xs[j+1])
				j+=3;
			hor.PB(Line{y,xs[i],xs[j]});
			i=j+1;
		}
	}
	return hor;
}

signed main(){
	int n=read();
	map<int,vi> y2x,x2y;
	REP(i,n){
		int x=read(),y=read();
		y2x[y].PB(x);
		x2y[x].PB(y);
	}
	vector<Line> hor=GetLines(y2x);
	vector<Line> ver=GetLines(x2y);
	
	int sh=hor.size();
	int sv=ver.size();
	
	MaxFlow::Init(1+sh+sv+1);
	REP(i,sh)
		MaxFlow::AddEdge(0,1+i,1);
	REP(j,sv)
		MaxFlow::AddEdge(1+sh+j,1+sh+sv,1);
	REP(i,sh)REP(j,sv){
		if(hor[i].b<ver[j].a&&ver[j].a<hor[i].c)
		if(ver[j].b<hor[i].a&&hor[i].a<ver[j].c){
			MaxFlow::AddEdge(1+i,1+sh+j,inf);
		}
	}
	
	MaxFlow::Calc(0,1+sh+sv);
	
	vi g=MaxFlow::GetGroup();
	vi uh(sh,1),uv(sv,1);
	REP(i,sh)
		if(g[1+i]==1)
			uh[i]=0;
	REP(j,sv)
		if(g[1+sh+j]==0)
			uv[j]=0;
	
	REP(i,sh)if(uh[i]){
		y2x[hor[i].a].PB(hor[i].b);
		y2x[hor[i].a].PB(hor[i].c);
	}
	REP(j,sv)if(uv[j]){
		x2y[ver[j].a].PB(ver[j].b);
		x2y[ver[j].a].PB(ver[j].c);
	}
	
	vector<Line> ansH=GetWires(y2x);
	vector<Line> ansV=GetWires(x2y);
	
	print(ansH.size());
	for(auto l:ansH){
		int x1=l.b,y1=l.a;
		int x2=l.c,y2=l.a;
		print(x1,2);
		print(y1,2);
		print(x2,2);
		print(y2);
	}
	
	print(ansV.size());
	for(auto l:ansV){
		int x1=l.a,y1=l.b;
		int x2=l.a,y2=l.c;
		print(x1,2);
		print(y1,2);
		print(x2,2);
		print(y2);
	}
}