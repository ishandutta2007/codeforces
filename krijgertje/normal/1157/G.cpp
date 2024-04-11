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

const int MAXH=200;
const int MAXW=200;

int h,w;
int a[MAXH][MAXW];

bool invcol[MAXW];
bool invrow[MAXH];
int b[MAXH][MAXW];

bool solveb() {
	int diffrow=-1; REP(x,h) { bool allsame=true; FOR(y,1,w) if(b[x][y]!=b[x][0]) allsame=false; if(allsame) continue; if(diffrow==-1) diffrow=x; else diffrow=-2; }
	if(diffrow==-2) return false;
	if(diffrow==-1) {
		REP(x,h) invrow[x]=b[x][0]==1;
	} else {
		REP(x,h) invrow[x]=x<=diffrow?b[x][0]==1:b[x][0]==0;
	}
	return true;
}

bool solve() {
	// make first row equal
	invcol[0]=false;
	FOR(y,1,w) invcol[y]=(a[0][y]!=a[0][0]);
	REP(x,h) REP(y,w) { b[x][y]=a[x][y]; if(invcol[y]) b[x][y]=1-b[x][y]; }
	FOR(y,1,w) assert(b[0][y]==b[0][0]);
	if(solveb()) return true;
	// make second row equal
	assert(h>=2);
	invcol[0]=false;
	FOR(y,1,w) invcol[y]=(a[1][y]!=a[1][0]);
	REP(x,h) REP(y,w) { b[x][y]=a[x][y]; if(invcol[y]) b[x][y]=1-b[x][y]; }
	FOR(y,1,w) assert(b[1][y]==b[1][0]);
	if(solveb()) return true;
	// impossible
	return false;
}

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) REP(y,w) scanf("%d",&a[x][y]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(x,h) printf("%c",invrow[x]?'1':'0'); puts("");
	REP(y,w) printf("%c",invcol[y]?'1':'0'); puts("");
}

int main() {
	run();
	return 0;
}