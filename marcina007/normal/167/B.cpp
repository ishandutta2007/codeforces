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

#define MAXN 207
int n,l,kk,p[MAXN],a[MAXN];
double dp[MAXN][MAXN][2*MAXN],res;

int main(){ 
	//in
	scanf("%d%d%d",&n,&l,&kk);
	REP(i,n) scanf("%d", &p[i]);
	REP(i,n) scanf("%d", &a[i]);
	//sol
	dp[0][0][MAXN+min(kk,n)] = 1.0;
	REP(i,n) REP(j,n+1) REP(k,MAXN+n+1) {
		double prob = p[i] / 100.0;
		dp[i+1][j+1][min(k+a[i], MAXN+n)] += dp[i][j][k] * prob;
		dp[i+1][j][k] += dp[i][j][k] * (1.0 - prob);
//		if(dp[i][j][k] > 0)
//			cout << i << " " << j << " " << k << " = " << dp[i][j][k] << endl;
	}
	FOR(j,l,n) FOR(k,MAXN,MAXN+n)
		res += dp[n][j][k];
	//out
	printf("%.9lf\n", res);
    return 0;
}