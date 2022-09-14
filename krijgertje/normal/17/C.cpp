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

const int MOD=51123987;
int n;
char s[151];

int dp[2][52][52][150][3];
int first[151][3];

void run() {
	scanf("%d",&n); scanf("%s",s);
	memset(first,-1,sizeof(first));
	for(int i=n-1;i>=0;--i) { REP(j,3) first[i][j]=first[i+1][j]; first[i][s[i]-'a']=i; }
	
	int at=0; memset(dp[at],0,sizeof(dp[at]));
	REP(i,3) if(first[0][i]!=-1) dp[at][i==0?1:0][i==1?1:0][first[0][i]][i]++;
	
	FOR(i,1,n) {
		memset(dp[!at],0,sizeof(dp[!at]));
		REPE(a,51) REPE(b,51) REP(pos,n) REP(last,3) if(dp[at][a][b][pos][last]>0) {
			int c=i-a-b;
			REP(next,3) {
				int npos; if(last==next) npos=pos; else if(first[pos][next]!=-1) npos=first[pos][next]; else continue;
				int na=a+(next==0?1:0),nb=b+(next==1?1:0),nc=c+(next==2?1:0);
				if(na>51||nb>51||nc>51) continue;
				dp[!at][na][nb][npos][next]+=dp[at][a][b][pos][last];
				if(dp[!at][na][nb][npos][next]>=MOD) dp[!at][na][nb][npos][next]-=MOD;
			}
		}
		at=1-at;
	}
	
	int ret=0;
	REPE(a,51) REPE(b,51) REP(pos,n) REP(last,3) if(dp[at][a][b][pos][last]>0) {
		int c=n-a-b;
		if(abs(a-b)>1||abs(a-c)>1||abs(b-c)>1) continue;
		ret+=dp[at][a][b][pos][last]; if(ret>=MOD) ret-=MOD;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}