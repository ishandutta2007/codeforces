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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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

int n,m;
double dp[2001][2001];
bool haverow[2001],havecol[2001];

void run() {
	scanf("%d%d",&n,&m);
	memset(haverow,false,sizeof(haverow));
	memset(havecol,false,sizeof(havecol));
	REP(i,m) { int r,c; scanf("%d%d",&r,&c); --r,--c; haverow[r]=true; havecol[c]=true; }
	int R=0; REP(i,n) if(!haverow[i]) ++R;
	int C=0; REP(i,n) if(!havecol[i]) ++C;
	dp[0][0]=0;
	FORE(r,1,R) { double pr=1.0*r/n; dp[r][0]=(1+pr*dp[r-1][0])/(1-(1-pr)); }
	FORE(c,1,C) { double pc=1.0*c/n; dp[0][c]=(1+pc*dp[0][c-1])/(1-(1-pc)); }
	FORE(r,1,R) FORE(c,1,C) {
		double pr=1.0*r/n,pc=1.0*c/n;
		dp[r][c]=(1+pr*pc*dp[r-1][c-1]+pr*(1-pc)*dp[r-1][c]+(1-pr)*pc*dp[r][c-1])/(1-(1-pr)*(1-pc));
	}
//	REPE(r,R) { REPE(c,C) printf("%5.2lf ",dp[r][c]); puts(""); }
	printf("%.9lf\n",dp[R][C]);
}

int main() {
	run();
	return 0;
}