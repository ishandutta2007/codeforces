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

const int MAXLEN=20;

char s[MAXLEN+1]; int slen;

int cnt[10];

ll C[MAXLEN+1][MAXLEN+1];
ll dp[11][MAXLEN+1]; // dp[i][j] = #ways with digits >=i and length j

void run() {
	scanf("%s",s); slen=strlen(s);

	memset(C,0,sizeof(C)); REPE(i,MAXLEN) { C[i][0]=C[i][i]=1; FOR(j,1,i) C[i][j]=C[i-1][j-1]+C[i-1][j]; }
	memset(cnt,0,sizeof(cnt)); REP(i,slen) ++cnt[s[i]-'0'];
	memset(dp,0,sizeof(dp)); dp[10][0]=1;
	for(int i=9;i>=0;--i) REPE(j,slen) {
		if(cnt[i]==0) { dp[i][j]=dp[i+1][j]; continue; }
		if(j==0) continue;
		FORE(k,1,cnt[i]) if(k<=j-(i==0?1:0)) {
			int mlt=C[j-(i==0?1:0)][k];
			dp[i][j]+=mlt*dp[i+1][j-k];
		}
		//printf("%d,%d: %lld\n",i,j,dp[i][j]);
	}
	ll ret=0; REPE(j,slen) ret+=dp[0][j]; printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}