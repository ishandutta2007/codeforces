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

const int MAXN=500;
const int MAXCOORD=2*MAXN+2;

int h,w,n;
int px[MAXN],py[MAXN];

bool onfire[MAXCOORD-1][MAXCOORD-1];
int allx[MAXCOORD],nallx;
int ally[MAXCOORD],nally;

bool allfire(int t) {
	nallx=nally=0;
	allx[nallx++]=0,allx[nallx++]=h; REP(i,n) allx[nallx++]=max(0,px[i]-t); REP(i,n) allx[nallx++]=min(h,px[i]+1+t); sort(allx,allx+nallx); nallx=unique(allx,allx+nallx)-allx;
	ally[nally++]=0,ally[nally++]=w; REP(i,n) ally[nally++]=max(0,py[i]-t); REP(i,n) ally[nally++]=min(w,py[i]+1+t); sort(ally,ally+nally); nally=unique(ally,ally+nally)-ally;
	REP(x,nallx-1) REP(y,nally-1) onfire[x][y]=false;
	REP(i,n) {
		int lx=max(0,px[i]-t); lx=lower_bound(allx,allx+nallx,lx)-allx;
		int hx=min(h,px[i]+1+t); hx=lower_bound(allx,allx+nallx,hx)-allx;
		int ly=max(0,py[i]-t); ly=lower_bound(ally,ally+nally,ly)-ally;
		int hy=min(w,py[i]+1+t); hy=lower_bound(ally,ally+nally,hy)-ally;
		FOR(x,lx,hx) FOR(y,ly,hy) onfire[x][y]=true;
	}
	{
		int lx=INT_MAX,hx=INT_MIN,ly=INT_MAX,hy=INT_MIN; bool any=false;
		REP(x,nallx-1) REP(y,nally-1) if(!onfire[x][y]) { if(x<lx) lx=x; if(x>hx) hx=x; if(y<ly) ly=y; if(y>hy) hy=y; any=true; }
		if(!any) return true; int dx=allx[hx+1]-allx[lx],dy=ally[hy+1]-ally[ly]; return dx<=2*t+1&&dy<=2*t+1;
	}
}

void run() {
	scanf("%d%d%d",&h,&w,&n);
	REP(i,n) scanf("%d%d",&px[i],&py[i]),--px[i],--py[i];

	int l=-1,h=max(h,w);
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(allfire(m)) h=m; else l=m;
	}
	printf("%d\n",h);
}

int main() {
	run();
	return 0;
}