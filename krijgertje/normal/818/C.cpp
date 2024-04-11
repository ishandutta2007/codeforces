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


const int MAXN=100000;
const int MAXDIM=100000;

int n,h,w;
int px[MAXN][2],py[MAXN][2];


int lx[MAXN],hx[MAXN],ly[MAXN],hy[MAXN];

int wlx,whx,wly,why;

void calc(int l[MAXN],int h[MAXN],int p[MAXN][2],int dim) {
	static int cnta[MAXDIM+1],cntb[MAXDIM+1];
	memset(cnta,0,sizeof(cnta)); memset(cntb,0,sizeof(cntb)); int na=0,nb=0;
	REP(i,n) if(p[i][0]==p[i][1]) ++cnta[p[i][0]+1],++na; else { int mn=min(p[i][0],p[i][1]),mx=max(p[i][0],p[i][1]); assert(mx-mn==1); ++cntb[mn+1],++nb; }
	FORE(i,1,dim) cnta[i]+=cnta[i-1],cntb[i]+=cntb[i-1];
	REP(i,n) if(p[i][0]==p[i][1]) {
		int x=p[i][0]; l[i]=cnta[x]+cntb[x]; h[i]=na-cnta[x+1]+nb-cntb[x];
	} else {
		int mn=min(p[i][0],p[i][1]),mx=max(p[i][0],p[i][1]); assert(mx-mn==1);
		l[i]=cnta[mx]+cntb[mx]-1; h[i]=na-cnta[mn+1]+nb-cntb[mn]-1;
	}
}

void run() {
	scanf("%d%d%d",&n,&h,&w);
	REP(i,n) scanf("%d%d%d%d",&px[i][0],&py[i][0],&px[i][1],&py[i][1]),--px[i][0],--py[i][0],--px[i][1],--py[i][1];
	scanf("%d%d%d%d",&wlx,&whx,&wly,&why);
	
	calc(lx,hx,px,h);
	calc(ly,hy,py,w);
	//REP(i,n) printf("%d: %d %d %d %d\n",i,lx[i],hx[i],ly[i],hy[i]);
	REP(i,n) if(lx[i]==wlx&&hx[i]==whx&&ly[i]==wly&&hy[i]==why) { printf("%d\n",i+1); return; }
	printf("-1\n");
}

int main() {
	run();
	return 0;
}