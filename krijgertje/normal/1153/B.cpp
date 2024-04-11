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

const int MAXROW=100;
const int MAXCOL=100;

int nrow,ncol,mxh;
int hrow[MAXROW],hcol[MAXCOL],any[MAXROW][MAXCOL];
int ans[MAXROW][MAXCOL];

void solve() {
	REP(i,nrow) REP(j,ncol) ans[i][j]=any[i][j]==0?0:min(hrow[i],hcol[j]);
}

void run() {
	scanf("%d%d%d",&nrow,&ncol,&mxh);
	REP(i,ncol) scanf("%d",&hcol[i]);
	REP(i,nrow) scanf("%d",&hrow[i]);
	REP(i,nrow) REP(j,ncol) scanf("%d",&any[i][j]);
	solve();
	REP(i,nrow) { REP(j,ncol) { if(j!=0) printf(" "); printf("%d",ans[i][j]); } puts(""); }
}

int main() {
	run();
	return 0;
}