#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100;
const int MAXM=1000;

typedef struct MF {
	int n,m; char name;
	vector<int> ghead,flow,back;
	vector<int> id,cap,gto,gnxt;
	queue<int> q;

	void init(int _n,char _name) { n=_n; name=_name; ghead=vector<int>(n,-1); flow=vector<int>(n,0); back=vector<int>(n,-1); }
	void addedge(int a,int b,int c,int _id) {
		gnxt.PB(ghead[a]),ghead[a]=m,gto.PB(b),id.PB(_id),cap.PB(c); ++m;
		gnxt.PB(ghead[b]),ghead[b]=m,gto.PB(a),id.PB(-1 ),cap.PB(0); ++m;
	}
	int maxflow(int s,int t) {
		int ret=0;
		while(true) {
			REP(i,n) flow[i]=0,back[i]=-1; flow[s]=INT_MAX,back[s]=-2,q.push(s);
			while(!q.empty()) {
				int at=q.front(); q.pop();
				for(int x=ghead[at];x!=-1;x=gnxt[x]) {
					int to=gto[x]; if(cap[x]==0||flow[to]!=0) continue;
					flow[to]=min(flow[at],cap[x]),back[to]=x^1,q.push(to);
				}
			}
			if(flow[t]==0) return ret;
			ret+=flow[t];
			//vector<int> path;
			for(int at=t;at!=s;at=gto[back[at]]) {
				cap[back[at]]+=flow[t];
				cap[back[at]^1]-=flow[t];
				//path.PB(at);
			}
			//path.PB(s); reverse(path.begin(),path.end()); printf("%c:",name); REPSZ(i,path) printf(" %d",path[i]+1); puts("");
		}
	}
} MF;


int n,m,s,t;
int u[MAXM],v[MAXM],used[MAXM];

MF a,b;
int bal[MAXN];
int f[MAXM],c[MAXM];

void run() {
	scanf("%d%d%d%d",&n,&m,&s,&t); --s,--t;
	REP(i,m) scanf("%d%d%d",&u[i],&v[i],&used[i]),--u[i],--v[i];

	a.init(n,'A');
	REP(i,m) if(!used[i]) a.addedge(u[i],v[i],m+1,-1); else a.addedge(u[i],v[i],1,i),a.addedge(v[i],u[i],m+1,-1);
	a.maxflow(s,t);

	REP(i,n) bal[i]=0; REP(i,m) if(used[i]) --bal[u[i]],++bal[v[i]];
	b.init(n+2,'B'); int ss=n,tt=n+1;
	REP(i,m) if(used[i]) b.addedge(u[i],v[i],m,i);
	REP(i,n) if(bal[i]>0) b.addedge(ss,i,bal[i],-1);
	REP(i,n) if(bal[i]<0) b.addedge(i,tt,-bal[i],-1);
	b.addedge(t,s,m,-1);
	b.maxflow(ss,tt);

	REP(i,m) f[i]=used[i];
	REP(i,b.m) if(b.id[i]!=-1) f[b.id[i]]+=b.cap[i^1];
	REP(i,m) c[i]=f[i]+1; int nsat=0;
	REP(i,a.m) if(a.id[i]!=-1&&a.flow[a.gto[i^1]]!=0&&a.flow[a.gto[i]]==0) c[a.id[i]]=f[a.id[i]],++nsat;
	
	printf("%d\n",nsat);
	REP(i,m) printf("%d %d\n",f[i],c[i]);
}

int main() {
	run();
	return 0;
}