#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin();i != (x).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,w) memset((x),w,sizeof (x))
#define X first
#define Y second
typedef long long int lli;
typedef pair<int, int> P;
typedef vector<int> VI;

#define MOD 1000000007
#define MAXN 107
#define ALPHA ('z'-'a'+1)
#define MAXS (MAXN*ALPHA)

int t,n,dp[MAXN][MAXS];
char c[MAXN];

int main(){
	dp[0][0]=1;
	REP(i,ALPHA)
		dp[1][i]=1;
	FOR(n,2,MAXN-1)
		REP(s,MAXS)
			REP(i,min(s+1,ALPHA)){
				dp[n][s] += dp[n-1][s-i];
				dp[n][s] %= MOD;
			}
	//
	scanf("%d",&t);
	while(t--){
		scanf("%s",c);
		n = strlen(c);
		int s=0;
		REP(i,n)
			s += c[i]-'a';
		printf("%d\n", (dp[n][s]+MOD-1)%MOD);
	}
    return 0;
}