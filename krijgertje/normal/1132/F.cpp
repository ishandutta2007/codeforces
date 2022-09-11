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

const int MAXN=500;

int n;
char s[MAXN+1];

int dp[MAXN+1][MAXN+1];
int dp2[MAXN+1][MAXN+1];

void upd(int &a,int b) { a=min(a,b); }
int solve() {
	REPE(i,n) REPE(j,n) dp[i][j]=dp2[i][j]=n+1;
	REPE(i,n) dp[i][i]=dp2[i][i]=0;
	FORE(len,1,n) REPE(i,n-len) {
		int j=i+len;
		FOR(k,i,j) upd(dp[i][j],1+dp[i][k]+dp2[k+1][j]);
		dp2[i][j]=dp[i][j];
		if(i!=0) FOR(k,i,j) if(s[k]==s[i-1]) upd(dp2[i][j],dp[i][k]+dp2[k+1][j]);
	}
	return dp[0][n];
}

void run() {
	scanf("%d",&n);
	scanf("%s",s);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}