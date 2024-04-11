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

const int MAXH=1000;
const int MAXW=1000;
const int MAXQ=100000;
struct Q { int lx,ly,hx,hy; };

int h,w,nq;
char g[MAXH][MAXW+1];
Q q[MAXQ];
ll qans[MAXQ];

int	sum[MAXH+1][MAXW+1];
int invsum[MAXH+1][MAXW+1];

int getcol(int x,int y) {
	int z=x^y,ret=0; while(z!=0) z-=z&-z,++ret; return ret&1;
}

ll calc(int x,int y) {
	int ntall=x/h,nwide=y/w;
	ll ret=0;
	ll nfull=(ll)ntall*nwide;
	ll norig=nfull/2,nflipped=nfull/2; if(nfull&1) if(getcol(ntall-1,nwide-1)==0) ++norig; else ++nflipped;
	ret+=norig*sum[h][w]+nflipped*invsum[h][w];
	ll ntallorig=ntall/2,ntallflipped=ntall/2; if(ntall&1) if(getcol(ntall-1,nwide)==0) ++ntallorig; else ++ntallflipped;
	ret+=ntallorig*sum[h][y%w]+ntallflipped*invsum[h][y%w];
	ll nwideorig=nwide/2,nwideflipped=nwide/2; if(nwide&1) if(getcol(ntall,nwide-1)==0) ++nwideorig; else ++nwideflipped;
	ret+=nwideorig*sum[x%h][w]+nwideflipped*invsum[x%h][w];
	if(getcol(ntall,nwide)==0) ret+=sum[x%h][y%w]; else ret+=invsum[x%h][y%w];
	//printf("calc(%d,%d)=%lld\n",x,y,ret);
	return ret;
}

void solve() {
	REPE(x,h) REPE(y,w) if(x==0||y==0) sum[x][y]=0; else sum[x][y]=sum[x-1][y]+sum[x][y-1]-sum[x-1][y-1]+g[x-1][y-1]-'0';
	REPE(x,h) REPE(y,w) invsum[x][y]=x*y-sum[x][y];
	REP(i,nq) {
		int lx=q[i].lx,ly=q[i].ly,hx=q[i].hx,hy=q[i].hy;
		qans[i]=calc(hx,hy)-calc(lx,hy)-calc(hx,ly)+calc(lx,ly);
	}
}

void run() {
	scanf("%d%d%d",&h,&w,&nq);
	REP(x,h) scanf("%s",g[x]);
	REP(i,nq) scanf("%d%d%d%d",&q[i].lx,&q[i].ly,&q[i].hx,&q[i].hy),--q[i].lx,--q[i].ly;
	solve();
	REP(i,nq) printf("%lld\n",qans[i]);
}

int main() {
	run();
	return 0;
}