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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXLEN=2100;

char s[MAXLEN+1]; int slen;
char want[MAXLEN+1]; int wantlen;

int lmatch[MAXLEN][MAXLEN]; // lmatch[i][j] is the maximum value so that want[i..i+lmatch[i][j])==s[j..j-lmatch[i][j])
int rmatch[MAXLEN][MAXLEN]; // rmatch[i][j] is the maximum value so that want[i..i+rmatch[i][j])==s[j..j+rmatch[i][j])
int mx[MAXLEN]; // mx[i] is the maximum value so that want[i..mx[i]) occurs in s or its reverse
int pos[MAXLEN],dir[MAXLEN];
int dp[MAXLEN+1]; // dp[i] is minimum # coatings to make want[i..]
int dpnxt[MAXLEN];

int qidx[MAXLEN],qval[MAXLEN],qhead,qtail;

void run() {
	scanf("%s%s",s,want); slen=strlen(s); wantlen=strlen(want);

	for(int i=wantlen-1;i>=0;--i) {
		REP(j,slen) lmatch[i][j]=want[i]!=s[j]?0:1+(i+1>=wantlen||j==0?0:lmatch[i+1][j-1]);
		REP(j,slen) rmatch[i][j]=want[i]!=s[j]?0:1+(i+1>=wantlen||j+1>=slen?0:rmatch[i+1][j+1]);
	}
	REP(i,wantlen) {
		mx[i]=i;
		REP(j,slen) if(i+lmatch[i][j]>mx[i]) mx[i]=i+lmatch[i][j],pos[i]=j,dir[i]=-1;
		REP(j,slen) if(i+rmatch[i][j]>mx[i]) mx[i]=i+rmatch[i][j],pos[i]=j,dir[i]=+1;
	}

	dp[wantlen]=0; qhead=qtail=0;
	for(int i=wantlen-1;i>=0;--i) {
		while(qhead<qtail&&qval[qtail-1]>=dp[i+1]) --qtail; if(dp[i+1]!=INT_MAX) qidx[qtail]=i+1,qval[qtail]=dp[i+1],++qtail;
		while(qhead<qtail&&qidx[qhead]>mx[i]) ++qhead;
		if(qhead==qtail) dp[i]=INT_MAX; else dp[i]=1+qval[qhead],dpnxt[i]=qidx[qhead];
	}
	if(dp[0]==INT_MAX) { printf("-1\n"); return; }
	printf("%d\n",dp[0]);
	for(int at=0;at!=wantlen;at=dpnxt[at]) printf("%d %d\n",1+pos[at],1+pos[at]+dir[at]*(dpnxt[at]-at-1));

}

int main() {
	run();
	return 0;
}