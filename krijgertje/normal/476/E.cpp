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

char have[2001]; int havelen;
char want[501]; int wantlen;

int start[2000];

int dp[2001][2001]; // dp[i][j] = the minimum number of letters that need to be removed so that there are at least j occurrences of the pattern in the first i letters

int ret[2001];

void run() {
	scanf("%s",have); havelen=strlen(have);
	scanf("%s",want); wantlen=strlen(want);

	REP(i,havelen) start[i]=have[i]==want[0]?i:-1;
	FOR(j,1,wantlen) {
		int at=-1;
		REP(i,havelen) { int nat=at; if(start[i]!=-1) nat=max(nat,start[i]); start[i]=have[i]==want[j]?at:-1; at=nat; }
	}
//	REP(i,havelen) printf("%d ",start[i]); puts("");

	REPE(j,havelen) dp[0][j]=j==0?0:INT_MAX; 
	REP(i,havelen) {
		REPE(j,havelen) dp[i+1][j]=dp[i][j];
		if(start[i]==-1) continue;
		int cur=i-start[i]+1-wantlen;
		FORE(j,1,havelen) if(dp[start[i]][j-1]!=INT_MAX&&dp[start[i]][j-1]+cur<dp[i+1][j]) dp[i+1][j]=dp[start[i]][j-1]+cur;
	}
	//REPE(j,havelen) if(dp[havelen][j]!=INT_MAX) printf("%d: %d\n",j,dp[havelen][j]);

	REPE(i,havelen) {
		//ret[i]=max(j | dp[havelen][j]<=i && havelen-i>=j*wantlen)
		ret[i]=i==0?0:ret[i-1];
		while(havelen-i<ret[i]*wantlen) --ret[i];
		while(ret[i]+1<=havelen&&dp[havelen][ret[i]+1]<=i&&havelen-i>=(ret[i]+1)*wantlen) ++ret[i];
	}
	REPE(i,havelen) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");

}

int main() {
	run();
	return 0;
}