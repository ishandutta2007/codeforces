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

const int MAXN=200000;
const int MOD=1000000007;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int n,l,r;

int cnt[3];
int dp[MAXN+1][3];

int solve() {
	REP(i,3) cnt[i]=(r-i+3)/3-(l-i+2)/3;
	//REP(i,3) printf("cnt%d=%d\n",i,cnt[i]);

	memset(dp,0,sizeof(dp)); dp[0][0]=1;
	REP(i,n) REP(j,3) REP(k,3) inc(dp[i+1][(j+k)%3],(ll)dp[i][j]*cnt[k]%MOD);
	return dp[n][0];
}

void run() {
	scanf("%d%d%d",&n,&l,&r);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}