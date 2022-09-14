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

const int MAXH=1000;
const int MAXW=1000;
const int MAXQ=100000;
typedef struct Q { int type,x,y;} Q;

int h,w,nq;
Q q[MAXQ+1];

bool g[MAXH][MAXW];
bool row[MAXH];
int rowcnt[MAXH];
int totalcnt;
int ret[MAXQ+1];

int thead[MAXQ+1];
int tnxt[MAXQ+1];

void dfs(int id) {
	int type=q[id].type,x=q[id].x,y=q[id].y; bool change=false;
	if(type==1) if(!(g[x][y]^row[x])) { g[x][y]=!g[x][y]; ++rowcnt[x]; ++totalcnt; change=true; }
	if(type==2) if(g[x][y]^row[x]) { g[x][y]=!g[x][y]; --rowcnt[x]; --totalcnt; change=true; }
	if(type==3) { row[x]=!row[x]; int delta=(w-rowcnt[x])-rowcnt[x]; rowcnt[x]+=delta; totalcnt+=delta; }
	ret[id]=totalcnt;
	for(int cid=thead[id];cid!=-1;cid=tnxt[cid]) dfs(cid);
	if(type==1&&change) { g[x][y]=!g[x][y]; --rowcnt[x]; --totalcnt; }
	if(type==2&&change) { g[x][y]=!g[x][y]; ++rowcnt[x]; ++totalcnt; }
	if(type==3) { row[x]=!row[x]; int delta=(w-rowcnt[x])-rowcnt[x]; rowcnt[x]+=delta; totalcnt+=delta; }
}


void run() {
	scanf("%d%d%d",&h,&w,&nq);
	memset(thead,-1,sizeof(thead));
	FORE(i,1,nq) {
		scanf("%d",&q[i].type); int t=i-1;
		if(q[i].type==1||q[i].type==2) scanf("%d%d",&q[i].x,&q[i].y),--q[i].x,--q[i].y;
		if(q[i].type==3) scanf("%d",&q[i].x),--q[i].x;
		if(q[i].type==4) scanf("%d",&t);
		tnxt[i]=thead[t]; thead[t]=i;
	}
	memset(g,false,sizeof(g)); memset(row,false,sizeof(row)); memset(rowcnt,0,sizeof(rowcnt)); totalcnt=0;
	for(int id=thead[0];id!=-1;id=tnxt[id]) dfs(id);
	FORE(i,1,nq) printf("%d\n",ret[i]);
}

int main() {
	run();
	return 0;
}