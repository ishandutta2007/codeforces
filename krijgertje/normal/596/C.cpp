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
const int MINW=-100000;
const int MAXW=+100000;
typedef struct P { int x,y,s,t,z; } P;
bool operator<(const P &a,const P &b) { return a.z<b.z; }

int n;
P p[MAXN];
int stp[MAXN]; bool stcmp(const int &a,const int &b) { if(p[a].s!=p[b].s) return p[a].s<p[b].s; if(p[a].t!=p[b].t) return p[a].t<p[b].t; return a<b; }
int xyp[MAXN]; bool xycmp(const int &a,const int &b) { if(p[a].x!=p[b].x) return p[a].x<p[b].x; if(p[a].y!=p[b].y) return p[a].y<p[b].y; return a<b; }
int yxp[MAXN]; bool yxcmp(const int &a,const int &b) { if(p[a].y!=p[b].y) return p[a].y<p[b].y; if(p[a].x!=p[b].x) return p[a].x<p[b].x; return a<b; }
int head[MAXW-MINW+1],nxt[MAXN];




void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
	REP(i,n) p[i].s=p[i].y-p[i].x,p[i].t=p[i].y+p[i].x;
	REP(i,n) stp[i]=i; sort(stp,stp+n,stcmp);
	REPE(i,MAXW-MINW) head[i]=-1; REP(i,n) nxt[i]=-1;
	REP(i,n) if(i!=0&&p[stp[i]].s==p[stp[i-1]].s) nxt[stp[i-1]]=stp[i]; else if(MINW<=p[stp[i]].s&&p[stp[i]].s<=MAXW) head[p[stp[i]].s-MINW]=stp[i];

	bool ok=true;
	REP(i,n) {
		int w; scanf("%d",&w); w-=MINW;
		if(head[w]==-1) { ok=false; break; }
		p[head[w]].z=i; head[w]=nxt[head[w]];
	}
	REP(i,n) xyp[i]=i; sort(xyp,xyp+n,xycmp); FOR(i,1,n) if(p[xyp[i]].x==p[xyp[i-1]].x&&p[xyp[i]].z<p[xyp[i-1]].z) ok=false;
	REP(i,n) yxp[i]=i; sort(yxp,yxp+n,yxcmp); FOR(i,1,n) if(p[yxp[i]].y==p[yxp[i-1]].y&&p[yxp[i]].z<p[yxp[i-1]].z) ok=false;
	if(!ok) { printf("NO\n"); return; }

	sort(p,p+n);
	printf("YES\n");
	REP(i,n) printf("%d %d\n",p[i].x,p[i].y);
}

int main() {
	run();
	return 0;
}