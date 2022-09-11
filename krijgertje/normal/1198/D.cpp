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

const int MAXN=50;

int n;
char g[MAXN][MAXN+1];

int sum[MAXN+1][MAXN+1];
int dp[MAXN][MAXN][MAXN][MAXN]; // dp[lx][hx][ly][hy]

bool isempty(int lx,int ly,int hx,int hy) { return sum[hx+1][hy+1]-sum[lx][hy+1]-sum[hx+1][ly]+sum[lx][ly]==0; }

void upd(int &a,int b) { a=min(a,b); }
int solve() {
	REPE(x,n) REPE(y,n) sum[x][y]=0; REP(x,n) REP(y,n) sum[x+1][y+1]=sum[x+1][y]+sum[x][y+1]-sum[x][y]+(g[x][y]=='#'?1:0);
	FORE(dx,1,n) REPE(lx,n-dx) FORE(dy,1,n) REPE(ly,n-dy) {
		int hx=lx+dx-1,hy=ly+dy-1;
		dp[lx][hx][ly][hy]=max(dx,dy);
		FORE(mx,lx,hx) if(isempty(mx,ly,mx,hy)) { int cur=0; if(mx!=lx) cur+=dp[lx][mx-1][ly][hy]; if(mx!=hx) cur+=dp[mx+1][hx][ly][hy]; upd(dp[lx][hx][ly][hy],cur); }
		FORE(my,ly,hy) if(isempty(lx,my,hx,my)) { int cur=0; if(my!=ly) cur+=dp[lx][hx][ly][my-1]; if(my!=hy) cur+=dp[lx][hx][my+1][hy]; upd(dp[lx][hx][ly][hy],cur); }
	}
	return dp[0][n-1][0][n-1];
}

void run() {
	scanf("%d",&n);
	REP(x,n) scanf("%s",g[x]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}