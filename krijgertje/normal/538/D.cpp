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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=50;

int n;
char g[MAXN][MAXN+1];
char ret[2*MAXN-1][2*MAXN];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%s",g[i]);
	REP(i,2*n-1) { REP(j,2*n-1) ret[i][j]='x'; ret[i][2*n]='\0'; } ret[n-1][n-1]='o';
	REP(i,n) REP(j,n) if(g[i][j]=='o') REP(ii,n) REP(jj,n) if(g[ii][jj]=='.') { ret[n+ii-i-1][n+jj-j-1]='.'; }
	bool ok=true; REP(i,n) REP(j,n) if(g[i][j]=='x') { bool found=false; REP(ii,n) REP(jj,n) if(g[ii][jj]=='o'&&ret[n+i-ii-1][n+j-jj-1]=='x') found=true; if(!found) ok=false; }
	if(!ok) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i,2*n-1) printf("%s\n",ret[i]);
}

int main() {
	run();
	return 0;
}