#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define REACH cerr<<"reached line "<<__LINE__<<endl
#define DBG(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl

using pii=pair<int,int>;
using vi=vector<int>;
using ld=long double;

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"[";
	REP(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"]";
	return os;
}

int read(){
	int i;
	scanf("%lld",&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(int x,int suc=1){
	printf("%lld",x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

string readString(){
	static char buf[3341919];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341919];
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
	if(a>b)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

struct Wafrelka{
	
struct Edge{
	int to,idx;
};
vector<vector<Edge>> g;
vector<pii> ans;
vi ord,low;
vi z;

void dfs1(int v,int d,int t){
	ord[v]=low[v]=d;
	z[v]=(v==t);
	for(auto e:g[v]){
		if(ord[e.to]==-1){
			dfs1(e.to,d+1,t);
			chmin(low[v],low[e.to]);
			z[v]|=z[e.to];
		}else if(ord[e.to]<ord[v]-1)
			chmin(low[v],ord[e.to]);
	}
}

void dfs2(int v,int w,bool u){
	if(low[v]>=w){
		w=ord[v]-1;
		u^=true;
	}
	for(auto e:g[v])
		if(ord[e.to]<ord[v]){
			bool q=ord[e.to]<w;
			if(u^q)
				ans[e.idx]=MP(v,e.to);
			else
				ans[e.idx]=MP(e.to,v);
		}else if(ord[v]+1==ord[e.to])
			dfs2(e.to,w,u);
}

void Tokeru(){
	int n=read(),m=read(),s=read()-1,t=read()-1;
	g.resize(n);
	ans.resize(m,pii(-1,-1));
	REP(i,m){
		int x=read()-1,y=read()-1;
		g[x].PB(Edge{y,i});
		g[y].PB(Edge{x,i});
	}
	ord.resize(n,-1);
	low.resize(n,-1);
	z.resize(n,false);
	dfs1(s,0,t);
	REP(i,n)
		if(z[i]){
			for(auto e:g[i])if(ord[i]+1==ord[e.to]&&!z[e.to])
				if(low[e.to]>=ord[i]){
					printf("No\n");
					return;
				}
		}else if(low[i]==ord[i]){
			printf("No\n");
			return;
		}
	REP(i,n)if(z[i])
		for(auto e:g[i]){
			if(ord[i]-1>ord[e.to])
				ans[e.idx]=MP(e.to,i);
			else if(ord[i]+1==ord[e.to]){
				if(z[e.to])
					ans[e.idx]=MP(i,e.to);
				else
					dfs2(e.to,ord[i],true);
			}
		}
	vi in(n,0),out(n,0);
	REP(i,m)
		out[ans[i].first]++,in[ans[i].second]++;
	if(in[s]!=0){
		printf("No\n");
		return;
	}
	if(out[t]!=0){
		printf("No\n");
		return;
	}
	REP(i,n)if(i!=s&&i!=t){
		if(in[i]==0||out[i]==0){
			printf("No\n");
			return;
		}
	}
	printf("Yes\n");
	REP(i,m)
		print(ans[i].first+1,2),print(ans[i].second+1);
}

};

signed main(){
	int t=read();
	while(t--){
		Wafrelka w;
		w.Tokeru();
	}
}