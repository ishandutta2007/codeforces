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

const int MAXG=200000;
const int MAXQ=200000;
const int MAXN=MAXG+MAXQ+1;

typedef struct P { int x,type,qi; } P;
bool operator<(const P &a,const P &b) { return a.x<b.x; }

int tx,cap,ng,nq,n;
P p[MAXN];

int need[MAXN][3],opt[MAXN][3]; bool ok[MAXN];
int ret[MAXQ][3];



void run() {
	scanf("%d%d%d%d",&tx,&cap,&ng,&nq);
	REP(i,ng) scanf("%d%d",&p[i].type,&p[i].x),--p[i].type,p[i].qi=-1;
	REP(i,nq) scanf("%d",&p[ng+i].x),p[ng+i].type=2,p[ng+i].qi=i;
	p[ng+nq].x=tx; p[ng+nq].type=-1,p[ng+nq].qi=-1;
	n=ng+nq+1; sort(p,p+n);
	
	int to=n-1; while(p[to].type!=-1) --to; ok[to]=true;
	REP(i,3) need[to][i]=0,opt[to][i]=0;
	for(int at=to-1;at>=0;--at) {
		int dx=p[to].x-p[at].x;
		REP(i,3) opt[at][i]=opt[to][i],need[at][i]=need[to][i]; ok[at]=ok[to];
		REPE(i,p[at].type) { int cur=max(0,min(opt[at][i],cap-dx)); dx+=cur; opt[at][i]-=cur; }
		if(dx==cap) REP(i,3) need[at][i]+=opt[at][i],opt[at][i]=0; if(dx>cap) ok[at]=false; else opt[at][p[at].type]+=dx;
		if(p[at].qi!=-1) {
			REP(i,3) need[at][i]+=opt[at][i],opt[at][i]=0;
			REP(i,3) ret[p[at].qi][i]=ok[at]?need[at][i]:-1;
		} else {
			int sum=0; REP(i,3) sum+=opt[at][i];
			for(int i=2;i>=0;--i) { int cur=min(opt[at][i],sum-cap); need[at][i]+=cur; opt[at][i]-=cur; sum-=cur; }
			to=at;
		}
		//printf("\t%d: %c [%d,%d,%d] [%d,%d,%d]\n",p[at].x,ok?'V':'X',opt[at][0],opt[at][1],opt[at][2],need[at][0],need[at][1],need[at][2]);
	}
	REP(i,nq) printf("%d %d\n",ret[i][0],ret[i][1]);
}

int main() {
	run();
	return 0;
}