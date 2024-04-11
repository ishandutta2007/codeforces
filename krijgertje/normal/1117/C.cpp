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

const int MAXN=100000;

int sx,sy,tx,ty;
int n;
char w[MAXN+1];

int dx,dy;

ll divdn(ll num,ll den) { if(den<0) num=-num,den=-den; return num>=0?num/den:(num-den+1)/den; }
ll divup(ll num,ll den) { if(den<0) num=-num,den=-den; return num>=0?(num+den-1)/den:num/den; }

// abs(cx+k*dx-tx)+abs(cy+k*dy-ty)<=k*n+t
ll calc(int t,int cx,int cy) {
	int ax=cx-tx,bx=dx,ay=cy-ty,by=dy; // abs(ax+k*bx)+abs(ay+k*by)<=k*n+t
	if(bx<0) ax=-ax,bx=-bx;
	if(by<0) ay=-ay,by=-by;
	ll ret=LLONG_MAX;
	for(int xsgn=-1;xsgn<=+1;xsgn+=2) for(int ysgn=-1;ysgn<=+1;ysgn+=2) {
		ll lo=0,hi=LLONG_MAX;
		if(xsgn==-1) if(bx!=0) hi=min(hi,divdn(-ax,bx)); else if(ax>0) continue;
		if(xsgn==+1) if(bx!=0) lo=max(lo,divup(-ax,bx)); else if(ax<0) continue;
		if(ysgn==-1) if(by!=0) hi=min(hi,divdn(-ay,by)); else if(ay>0) continue;
		if(ysgn==+1) if(by!=0) lo=max(lo,divup(-ay,by)); else if(ay<0) continue;
		if(lo>hi) continue;
		ll u=ax*xsgn+ay*ysgn-t,v=xsgn*bx+ysgn*by-n; // u+k*v<=0, lo<=k<=hi
		u+=(ll)lo*v; hi=(hi==LLONG_MAX?hi:hi-lo); // u+k*v<=0, 0<=k<=hi
		//printf("\tabs(%d+k*%d)+abs(%d+k*%d)<=k*%d+%d -> xsgn=%+d ysgn=%+d -> %lld+k*%lld<=0 [0..%lld] <%lld>\n",ax,bx,ay,by,n,t,xsgn,ysgn,u,v,hi,lo);
		if(u<=0) ret=min(ret,lo*n+t); else if(v<0) { ll k=divup(-u,v); if(0<=k&&k<=hi) ret=min(ret,(lo+k)*n+t); }
	}
	return ret;
}

ll solve() {
	dx=0,dy=0;
	REP(i,n) { if(w[i]=='U') ++dy; else if(w[i]=='D') --dy; else if(w[i]=='L') --dx; else if(w[i]=='R') ++dx; else assert(false); }
	int cx=sx,cy=sy;
	ll ret=LLONG_MAX;
	REP(i,n) {
		ll cur=calc(i,cx,cy);
		//printf("%d: (%d,%d) -> %lld\n",i,cx,cy,cur);
		ret=min(ret,cur);
		if(w[i]=='U') ++cy; else if(w[i]=='D') --cy; else if(w[i]=='L') --cx; else if(w[i]=='R') ++cx; else assert(false);
	}
	return ret==LLONG_MAX?-1:ret;
}

void run() {
	scanf("%d%d",&sx,&sy);
	scanf("%d%d",&tx,&ty);
	scanf("%d",&n);
	scanf("%s",w);
	printf("%lld\n",solve());

}

int main() {
	run();
	return 0;
}