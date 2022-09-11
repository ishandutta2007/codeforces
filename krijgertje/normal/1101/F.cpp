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

const int MAXN=400;
const int MAXTRUCK=250000;

int n,ntruck;
int x[MAXN];
int s[MAXTRUCK],t[MAXTRUCK],c[MAXTRUCK],r[MAXTRUCK];

int dp[MAXN][MAXN+1]; // dp[i][j][k] = minimum capacity needed for a c=1 truck to get from i to j with at most k refuellings
int act[MAXN][MAXN+1]; // act[i][j][k] = where the last refuel was

vector<int> bys[MAXN];

// dp[i][j][k]=min(jj,max(dp[i][jj][k-1],x[j]-x[jj]))
int calc(int i,int j,int k,int jj) {
	return max(dp[jj][k-1],x[j]-x[jj]);
}

ll solve() {
	REP(i,n) bys[i].clear(); REP(i,ntruck) bys[s[i]].PB(i);
	ll ret=0;
	REP(i,n) {
		REPE(k,n) dp[i][k]=0,act[i][k]=i;
		FOR(j,i+1,n) dp[j][0]=x[j]-x[i],act[j][0]=i;
		FOR(j,i+1,n) FORE(k,1,n) {
			act[j][k]=act[j-1][k]; while(act[j][k]<j&&calc(i,j,k,act[j][k]+1)<calc(i,j,k,act[j][k])) ++act[j][k];
			dp[j][k]=calc(i,j,k,act[j][k]);
		}
		REPSZ(j,bys[i]) {
			int idx=bys[i][j];
			ll cur=(ll)dp[t[idx]][r[idx]]*c[idx];
			ret=max(ret,cur);
		}
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&ntruck);
	REP(i,n) scanf("%d",&x[i]);
	REP(i,ntruck) scanf("%d%d%d%d",&s[i],&t[i],&c[i],&r[i]),--s[i],--t[i];
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}