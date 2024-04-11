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

const int MAXB=2000;
const int MAXP=MAXB+2;
const int MAXCOORD=100000;
const int MAXFAC=MAXCOORD+MAXCOORD;
const int MOD=1000000007;

typedef struct P { int x,y; } P;
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.y<b.y; }

int h,w,nb,np;
P p[MAXP];

int ways[MAXP];

int fac[MAXFAC+1];
int inv[MAXFAC+1];
int invfac[MAXFAC+1];

int calc(int a,int b) {
	int dx=p[b].x-p[a].x,dy=p[b].y-p[a].y;
	if(dx<0||dy<0) return 0;
	int ret=(ll)fac[dx+dy]*invfac[dx]%MOD*invfac[dy]%MOD;
//	printf("(%d,%d)->(%d,%d) [%d,%d] = %d\n",p[a].x,p[a].y,p[b].x,p[b].y,dx,dy,ret);
	return ret;
}

void run() {
	fac[0]=1; FORE(i,1,MAXFAC) fac[i]=(ll)fac[i-1]*i%MOD;
	inv[1]=1; FORE(i,2,MAXFAC) inv[i]=(MOD-(ll)(MOD/i)*inv[MOD%i]%MOD)%MOD;
	invfac[0]=inv[1]; FORE(i,1,MAXFAC) invfac[i]=(ll)invfac[i-1]*inv[i]%MOD;

	scanf("%d%d%d",&h,&w,&nb);
	REP(i,nb) { scanf("%d%d",&p[i].x,&p[i].y); --p[i].x,--p[i].y; }
	np=nb; p[np].x=0,p[np].y=0; ++np; p[np].x=h-1,p[np].y=w-1; ++np; 
	sort(p,p+np);

	for(int i=np-1;i>=0;--i) {
		ways[i]=calc(i,np-1);
		FOR(j,i+1,np-1) ways[i]=(ways[i]+MOD-(ll)calc(i,j)*ways[j]%MOD)%MOD;
	}
//	REP(i,np) printf("%d: %d\n",i,ways[i]);
	printf("%d\n",ways[0]);
}

int main() {
	run();
	return 0;
}