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

const int MAXN=1000;
const int MOD=1000000007;
struct Res { int sum; bool valid; bool free; };

int n;

Res dp[2*MAXN+1][MAXN+1]; // dp[i][j] = result for trie of depth i, starting with balance of j

int solve() {
	REPE(j,n) dp[0][j].valid=false;
	dp[0][0].valid=true,dp[0][0].sum=0,dp[0][0].free=true;
	FORE(i,1,2*n) REPE(j,n) {
		vector<Res> sub;
		if(j+1<=n) sub.PB(dp[i-1][j+1]);
		if(j-1>=0) sub.PB(dp[i-1][j-1]);
		int sum=0; bool valid=false,any=false; REPSZ(k,sub) if(sub[k].valid) valid=true,sum+=sub[k].sum,any=any||sub[k].free; if(any) ++sum; if(sum>=MOD) sum-=MOD;
		dp[i][j].valid=valid; dp[i][j].sum=sum; dp[i][j].free=!any;
	}
	return dp[2*n][0].sum;
}

void run() {
	scanf("%d",&n);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}