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

const int MAXLEN=100000;

char s[2*MAXLEN+1]; int slen;

int dp[2*MAXLEN]; // dp[i]=longest alternating suffix of s[0..i]

void run() {
	scanf("%s",s); slen=strlen(s);

	REP(i,slen) s[slen+i]=s[i]; s[2*slen]='\0';
	REP(i,2*slen) dp[i]=1+(i-1>=0&&s[i-1]!=s[i]?dp[i-1]:0);
	//printf("%s\n",s);
	//printf("dp:"); REP(i,2*slen) printf(" %d",dp[i]); puts("");
	int ret=0;
	REP(i,2*slen) ret=max(ret,dp[i]);
	ret=min(ret,slen);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}