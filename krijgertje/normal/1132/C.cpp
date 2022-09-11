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

const int MAXSECT=5000;
const int MAXOPT=5000;

int nsect,nopt;
int optl[MAXOPT],optr[MAXOPT];

pair<int,int> o[MAXOPT];
int dp[2][3][MAXSECT+1]; // dp[i][j][k] = considering the first i options, when skipping j of them, the maximum number of painted sections, given the k-th is the last one painted so far

void upd(int &a,int b) { a=max(a,b); }
int solve() {
	REP(i,nopt) o[i]=MP(optl[i],i); sort(o,o+nopt);
	int t=0;
	REPE(j,2) REPE(k,nsect) dp[t][j][k]=INT_MIN; dp[t][0][0]=0;
	REP(i,nopt) {
		REPE(j,2) REPE(k,nsect) dp[1-t][j][k]=INT_MIN;
		REPE(j,2) REPE(k,nsect) if(dp[t][j][k]!=INT_MIN) {
			//printf("dp[%d][%d][%d]=%d\n",i,j,k,dp[t][j][k]);
			if(i==nopt) continue;
			int at=o[i].second;
			if(j+1<=2) upd(dp[1-t][j+1][k],dp[t][j][k]);
			int extra=0,nk=k;
			if(optr[at]>k) { nk=optr[at],extra+=optr[at]-max(optl[at],k); }
			upd(dp[1-t][j][nk],dp[t][j][k]+extra);
		}
		t=1-t;
	}
	int ret=INT_MIN; REPE(k,nsect) upd(ret,dp[t][2][k]); return ret;
}

void run() {
	scanf("%d%d",&nsect,&nopt);
	REP(i,nopt) scanf("%d%d",&optl[i],&optr[i]),--optl[i];
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}