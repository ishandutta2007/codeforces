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
#include <cassert>
#include <climits>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

int R,C;
char g[500][500];
int cnteven[500][26];
int cntodd[500][26];

void run() {
	scanf("%d%d",&R,&C);
	REP(r,R) REP(c,C) scanf(" %c",&g[r][c]);
	REP(r,R) {
		REP(i,26) cnteven[r][i]=cntodd[r][i]=0;
		REP(c,C) if(c%2==0) ++cnteven[r][g[r][c]-'a']; else ++cntodd[r][g[r][c]-'a'];
	}
	VVVI dp(R+1,VVI(26,VI(26,INT_MAX)));
	VVVI px(R+1,VVI(26,VI(26,-1)));
	VVVI py(R+1,VVI(26,VI(26,-1)));
	REP(x,26) REP(y,26) if(x!=y) dp[0][x][y]=0;
	REP(r,R) REP(x,26) REP(y,26) if(x!=y) {
		REP(xx,26) if(xx!=x) REP(yy,26) if(yy!=y) if(dp[r][xx][yy]!=INT_MAX) {
			int cur=dp[r][xx][yy]+C-cnteven[r][x]-cntodd[r][y];
			if(cur<dp[r+1][x][y]) dp[r+1][x][y]=cur,px[r+1][x][y]=xx,py[r+1][x][y]=yy;
		}
	}
	int res=INT_MAX,cx=-1,cy=-1;
	REP(x,26) REP(y,26) if(dp[R][x][y]<res) { res=dp[R][x][y],cx=x,cy=y; }
	vector<pair<int,int> > color(R);
	for(int r=R-1;r>=0;--r) {
		color[r]=MP(cx,cy);
		int nx=px[r+1][cx][cy];
		int ny=py[r+1][cx][cy];
		cx=nx,cy=ny;
	}
	printf("%d\n",res);
	REP(r,R) { REP(c,C) printf("%c",c%2==0?'a'+color[r].first:'a'+color[r].second); puts(""); }
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}