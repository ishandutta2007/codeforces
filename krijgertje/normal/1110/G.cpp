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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN=500000;

int n;
vector<int> adj[MAXN];
char color[MAXN+1];


int path[MAXN],npath;
int q[MAXN],qhead,qtail;
int prv[MAXN];
int pathidx[MAXN];

int farthest(int s) {
	REP(i,n) prv[i]=-2; qhead=qtail=0;
	prv[s]=-1,q[qhead++]=s;
	while(qtail<qhead) { int at=q[qtail++]; REPSZ(i,adj[at]) { int to=adj[at][i]; if(prv[to]==-2) prv[to]=at,q[qhead++]=to; } }
	npath=0; int ret=q[qhead-1]; for(int at=ret;at!=-1;at=prv[at]) path[npath++]=at; reverse(path,path+npath); return ret;
}

bool solve() {
	REP(i,n) if(SZ(adj[i])>=4) return true;
	int a=farthest(0);
	int b=farthest(a);
	REP(i,n) pathidx[i]=-1; REP(i,npath) pathidx[path[i]]=i;
	//printf("path:"); REP(i,npath) printf(" %d",path[i]+1); puts("");
	bool extraleft=false,extraright=false;
	REP(i,npath) {
		int at=path[i];
		REPSZ(j,adj[at]) {
			int to=adj[at][j]; if(pathidx[to]!=-1) continue;
			if(SZ(adj[to])>=2) return true;
			if(i!=1&&i!=npath-2) return true;
			if(i==1) extraleft=true;
			if(i==npath-2) extraright=true;
		}
	}
	int nwhite=0; REP(i,n) if(color[i]=='W') ++nwhite;
	if(npath==1) return false;
	if(npath==2) return false;
	if(npath==3) return nwhite>=2||extraleft&&nwhite>=1;
	REP(i,n) if(color[i]=='W') {
		if(pathidx[i]==-1) return true;
		if(pathidx[i]!=0&&pathidx[i]!=npath-1) return true;
	}
	bool leftwhite=color[path[0]]=='W',rightwhite=color[path[npath-1]]=='W';
	if(leftwhite&&extraleft) return true;
	if(rightwhite&&extraright) return true;
	if(leftwhite&&rightwhite) return npath%2==1;
	if(leftwhite) return extraright&&npath%2==1;
	if(rightwhite) return extraleft&&npath%2==1;
	return extraleft&&extraright&&npath%2==1;
}

void run() {
	scanf("%d",&n);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b),adj[b].PB(a); }
	scanf("%s",color);
	printf("%s\n",solve()?"White":"Draw");
	REP(i,n) adj[i].clear();
}

bool wins(int mask) {
	REP(i,n) if(mask&(1<<i)) {
		int cnt=0; REPSZ(j,adj[i]) { int k=adj[i][j]; if(mask&(1<<k)) ++cnt; } if(cnt>=2) return true;
	}
	return false;
}

map<pair<int,int>,int> mem;

int rec(int mymask,int oppmask) {
	pair<int,int> key=MP(mymask,oppmask); if(mem.count(key)) return mem[key];
	int ret=-1; bool any=false;
	REP(i,n) if((mymask&(1<<i))==0&&(oppmask&(1<<i))==0) { int cur=wins(mymask|(1<<i))?+1:-rec(oppmask,mymask|(1<<i)); ret=max(ret,cur); any=true; }
	if(!any) ret=0;
	return mem[key]=ret;
}

bool solvestupid() {
	int whitemask=0,blackmask=0; REP(i,n) if(color[i]=='W') whitemask|=1<<i;
	mem.clear();
	int ans=rec(whitemask,blackmask);
	assert(ans!=-1);
	return ans==+1;
}

void stress() {
	REP(rep,100000) {
		n=rand()%10+1;
		REP(i,n) adj[i].clear(); vector<int> comp(n); REP(i,n) comp[i]=i; REP(i,n-1) while(true) { int a=rand()%n,b=rand()%n; if(comp[a]==comp[b]) continue; int old=comp[b]; REP(j,n) if(comp[j]==old) comp[j]=comp[a]; adj[a].PB(b),adj[b].PB(a); break; }
		REP(i,n) color[i]='N'; color[n]='\0';
		//int nwhite=rand()%3; REP(i,nwhite) color[rand()%n]='W';
		bool have=solve();
		bool want=solvestupid();
		if(have==want) { if(rep%100==99) printf("."); continue; }
		printf("err\n");
		printf("rep=%d have=%d want=%d\n",rep,have?1:0,want?1:0);
		printf("%d\n",n);
		REP(i,n) REPSZ(j,adj[i]) { int k=adj[i][j]; if(i<k) printf("%d %d\n",i+1,k+1); }
		printf("%s\n",color);
		break;
	}
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	//stress();
	return 0;
}