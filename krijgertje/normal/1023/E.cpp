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

const int MAXN=500;

int n;
char g[MAXN][MAXN];

char a[MAXN]; int na;
char b[MAXN]; int nb;

char ret[2*MAXN+1]; int nret;

bool query(int sx,int sy,int ex,int ey) {
	printf("? %d %d %d %d\n",sx+1,sy+1,ex+1,ey+1); fflush(stdout);
	char buff[10]; scanf("%s",buff); return strcmp(buff,"YES")==0;
}

void solve() {
	REP(i,n) REP(j,n) g[i][j]='?'; g[0][0]=g[n-1][n-1]='.';

	{ int x=n-1,y=n-1; nb=0; while(x+y>n-1) { if(query(0,0,x,y-1)) --y,g[x][y]='.',b[nb++]='R'; else g[x][y-1]='#',--x,g[x][y]='.',b[nb++]='D'; } }
	{ int x=0,y=0; na=0; while(x+y<n-1) { if(query(x+1,y,n-1,n-1)) ++x,g[x][y]='.',a[na++]='D'; else g[x+1][y]='#',++y,g[x][y]='.',a[na++]='R'; } }
	reverse(b,b+nb); nret=0; REP(i,na) ret[nret++]=a[i]; REP(i,nb) ret[nret++]=b[i]; ret[nret]='\0';
	printf("! %s\n",ret); fflush(stdout);
}

void run() {
	scanf("%d",&n);
	solve();
}

int main() {
	run();
	return 0;
}