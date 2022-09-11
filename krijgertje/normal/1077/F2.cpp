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

const int MAXN=5000;

int n,sz,lim;
int a[MAXN];

ll dp[MAXN+1][MAXN];

int q[MAXN],qhead,qtail;

ll solve() {
	REPE(i,lim) REP(j,n) dp[i][j]=LLONG_MIN;
	REP(j,sz) dp[1][j]=a[j];
	FORE(i,2,lim) {
		qhead=qtail=0;
		REP(j,n) {
			if(j-1>=0&&dp[i-1][j-1]!=LLONG_MIN) {
				while(qtail<qhead&&dp[i-1][j-1]>=dp[i-1][q[qhead-1]]) --qhead;
				q[qhead++]=j-1;
			}
			while(qtail<qhead&&q[qtail]<j-sz) ++qtail;
			//if(i==2&&j==3) { printf("%d %d -> q:",i,j); FOR(k,qtail,qhead) printf(" %d=%lld",q[k],dp[i-1][q[k]]); puts(""); }
			dp[i][j]=qtail<qhead?dp[i-1][q[qtail]]+a[j]:LLONG_MIN;
		}
	}
	//REPE(i,lim) REP(j,n) if(dp[i][j]!=LLONG_MIN) printf("dp[%d][%d]=%lld\n",i,j,dp[i][j]);
	ll ret=LLONG_MIN;
	FOR(j,n-sz,n) ret=max(ret,dp[lim][j]);
	return ret==LLONG_MIN?-1:ret;
}

void run() {
	scanf("%d%d%d",&n,&sz,&lim);
	REP(i,n) scanf("%d",&a[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}