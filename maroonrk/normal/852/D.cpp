#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
//#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define EB emplace_back
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
}

const int Vmax=610;
struct Edge{
	int to,cost;
};
vector<Edge> g[Vmax];
vi waf(int n,int root){
	vi dist(n,inf);
	priority_queue<pi,vector<pi>,greater<pi>> pq;
	const auto Reach=[&](int v,int cost){
		if(dist[v]>cost){
			dist[v]=cost;
			pq.push(pi(cost,v));
		}
	};
	Reach(root,0);
	while(!pq.empty()){
		int c=pq.top().first;
		int v=pq.top().second;
		pq.pop();
		for(auto e:g[v])
			Reach(e.to,c+e.cost);
	}
	return dist;
}

signed main(){
	int v=read(),e=read(),n=read(),k=read();
	vi st(n);
	REP(i,n)st[i]=read()-1;
	REP(_,e){
		int a=read()-1,b=read()-1,c=read();
		g[a].PB(Edge{b,c});
		g[b].PB(Edge{a,c});
	}
	vector<vi> dss(n);
	REP(i,n)
		dss[i]=waf(v,st[i]);
	int low=-1,up=1731311+1;
	while(up-low>1){
		const int mid=(low+up)/2;
		MaxFlow::Init(1+n+v+1);
		REP(i,n){
			MaxFlow::AddEdge(0,1+i,1);
		}
		REP(i,v){
			MaxFlow::AddEdge(1+n+i,1+n+v,1);
		}
		REP(i,n)REP(j,v)if(dss[i][j]<=mid){
			MaxFlow::AddEdge(1+i,1+n+j,1);
		}
		if(MaxFlow::Calc(0,1+n+v)>=k)
			up=mid;
		else
			low=mid;
	}
	if(up<=1731311){
		print(up);
	}else
		print(-1);
}