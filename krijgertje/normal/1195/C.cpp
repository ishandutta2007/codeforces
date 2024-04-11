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

const int MAXN=100000;

int n;
int a[2][MAXN];

ll dp[2][MAXN];

ll solve() {
	for(int j=n-1;j>=0;--j) REP(i,2) {
		dp[i][j]=a[i][j];
		if(j+1<n) dp[i][j]=max(dp[i][j],dp[i][j+1]);
		if(j+1<n) dp[i][j]=max(dp[i][j],a[i][j]+dp[1-i][j+1]);
	}
	return max(dp[0][0],dp[1][0]);
}

void run() {
	scanf("%d",&n);
	REP(i,2) REP(j,n) scanf("%d",&a[i][j]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}