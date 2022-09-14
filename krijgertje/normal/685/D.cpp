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
typedef struct P { int x,y; } P;
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.y<b.y; }

int n,sz;
P p[MAXN];
int yy[MAXN],nyy;

int yfst[MAXN],ynxt[MAXN];
ll ret[MAXN+1];

int cfst,cnxt[MAXN];

void cprocess(int by) {
	int cnt=0,head=cfst,tail=cfst,rgtx=INT_MIN;
	while(tail!=-1) {
		int nrgtx=tail!=head&&head!=-1?min(p[tail].x+sz,p[head].x):tail!=head?p[tail].x+sz:p[head].x;
		if(cnt!=0) ret[cnt]+=by*(nrgtx-rgtx);
		rgtx=nrgtx; while(tail!=head&&rgtx==p[tail].x+sz) tail=cnxt[tail],--cnt; while(head!=-1&&rgtx==p[head].x) head=cnxt[head],++cnt;
	}
}
void cadd(int y) {
	int* at=&cfst;
	for(int idx=yfst[y];idx!=-1;idx=ynxt[idx]) {
		while(*at!=-1&&*at<idx) at=&cnxt[*at];
		cnxt[idx]=*at; *at=idx;
	}
	//printf("added %d:",yy[y]); for(int idx=cfst;idx!=-1;idx=cnxt[idx]) printf(" (%d,%d)",p[idx].x,yy[p[idx].y]); puts("");
}
void crem(int y) {
	int* at=&cfst;
	for(int idx=yfst[y];idx!=-1;idx=ynxt[idx]) {
		while(*at!=-1&&*at<idx) at=&cnxt[*at];
		assert(*at==idx); *at=cnxt[idx];
	}
	//printf("removed %d:",yy[y]); for(int idx=cfst;idx!=-1;idx=cnxt[idx]) printf(" (%d,%d)",p[idx].x,yy[p[idx].y]); puts("");
}

void run() {
	scanf("%d%d",&n,&sz);
	REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
	sort(p,p+n);
	nyy=0; REP(i,n) yy[nyy++]=p[i].y; sort(yy,yy+nyy); nyy=unique(yy,yy+nyy)-yy; REP(i,n) p[i].y=lower_bound(yy,yy+nyy,p[i].y)-yy;
	//REP(i,n) printf("%d %d (%d)\n",p[i].x,yy[p[i].y],p[i].y);
	REP(i,nyy) yfst[i]=-1; for(int i=n-1;i>=0;--i) ynxt[i]=yfst[p[i].y],yfst[p[i].y]=i;
	//REP(i,nyy) { printf("%d:",i); for(int idx=yfst[i];idx!=-1;idx=ynxt[idx]) printf(" (%d,%d)",p[idx].x,yy[p[idx].y]); puts(""); }

	memset(ret,0,sizeof(ret));
	cfst=-1;
	int yhead=0,ytail=0,topy=yy[0]-1;
	while(ytail<nyy) {
		int ntopy=ytail<yhead&&yhead<nyy?min(yy[ytail]+sz,yy[yhead]):ytail<yhead?yy[ytail]+sz:yy[yhead];
		cprocess(ntopy-topy);
		topy=ntopy; if(ytail<yhead&&topy==yy[ytail]+sz) crem(ytail++); if(yhead<nyy&&topy==yy[yhead]) cadd(yhead++);
	}


	FORE(i,1,n) { if(i!=1) printf(" "); printf("%lld",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}