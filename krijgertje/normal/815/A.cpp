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

const int MAXH=100;
const int MAXW=100;
const int MAXVAL=500;
const int MAXRET=MAXVAL*(MAXH+MAXW);

int h,w;
int a[MAXH][MAXW];
int ret[MAXRET][2],nret;

int ncol[MAXW],nrow[MAXH];

bool solve() {
	REP(y,w) ncol[y]=a[0][y]; REP(x,h) nrow[x]=a[x][0]-a[0][0];
	REP(x,h) REP(y,w) if(nrow[x]+ncol[y]!=a[x][y]) return false;
	int mnrow=nrow[0]; FOR(x,1,h) if(nrow[x]<mnrow) mnrow=nrow[x];
	REP(x,h) nrow[x]-=mnrow; REP(y,w) ncol[y]+=mnrow;
	REP(y,w) if(ncol[y]<0) return false;
	int mncol=ncol[0]; FOR(y,1,w) if(ncol[y]<mncol) mncol=ncol[y];
	if(h<w) { REP(x,h) nrow[x]+=mncol; REP(y,w) ncol[y]-=mncol; }
	//printf("row:"); REP(x,h) printf(" %d",nrow[x]); printf("\ncol:"); REP(y,w) printf(" %d",ncol[y]); puts("");
	nret=0;
	REP(x,h) REP(z,nrow[x]) ret[nret][0]=0,ret[nret][1]=x,++nret;
	REP(y,w) REP(z,ncol[y]) ret[nret][0]=1,ret[nret][1]=y,++nret;
	return true;
}

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) REP(y,w) scanf("%d",&a[x][y]);
	//h=MAXH-1,w=MAXW; REP(x,h) REP(y,w) a[x][y]=0;
	if(!solve()) { printf("-1\n"); return; }
	printf("%d\n",nret); REP(i,nret) printf("%s %d\n",ret[i][0]==0?"row":"col",ret[i][1]+1);
}

int main() {
	run();
	return 0;
}