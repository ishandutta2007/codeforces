#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXH=3000;
const int MAXW=3000;
const int MAXDIM=MAXH>=MAXW?MAXH:MAXW;

int h,w,a,b;
int g[MAXH][MAXW];

int c[MAXDIM],nc;
int d[MAXDIM];

int q[MAXDIM],qhead,qtail;
void calc(int sz) {
	qhead=qtail=0; int at=0;
	REP(i,nc) {
		while(qtail<qhead&&q[qtail]<i) ++qtail;
		while(at<nc&&at<i+sz) { while(qtail<qhead&&c[q[qhead-1]]>c[at]) --qhead; q[qhead++]=at++; }
		assert(qtail<qhead); d[i]=c[q[qtail]];
	}
}

int dn[MAXH][MAXW];

ll solve() {
	//REP(x,h) { REP(y,w) { if(y!=0) printf(" "); printf("%d",g[x][y]); } puts(""); }

	REP(y,w) {
		nc=0; REP(x,h) c[nc++]=g[x][y];
		calc(a); REPE(x,h-a) dn[x][y]=d[x];
	}

	ll ret=0;
	REPE(x,h-a) {
		//printf("row %d:",x); REP(y,w) printf(" %d",dn[x][y]); puts("");
		nc=0; REP(y,w) c[nc++]=dn[x][y];
		calc(b); REPE(y,w-b) ret+=d[y];
	}
	return ret;
}

void run() {
	scanf("%d%d%d%d",&h,&w,&a,&b);
	vector<int> tmp(h*w); int x,y,z; scanf("%d%d%d%d",&tmp[0],&x,&y,&z); FORSZ(i,1,tmp) tmp[i]=((ll)tmp[i-1]*x+y)%z; REP(x,h) REP(y,w) g[x][y]=tmp[x*w+y];
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}