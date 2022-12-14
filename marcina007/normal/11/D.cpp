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
typedef unsigned long long int lli;
typedef pair<int, int> P;
typedef vector<int> VI;

#define MAXN 19
lli dp[1<<MAXN][MAXN],res;
int n,m,a,b;
bool edge[MAXN][MAXN];


int main(){ 
	//in
	cin >> n >> m;
	while(m--){
		cin >> a >> b;
		a--; b--;
		edge[a][b] = edge[b][a] = true;
	}
	//sol
	REP(i,n) {
		CLR(dp, 0);
		dp[1<<i][i] = 1;
		REP(m,1<<n) REP(j,n)
			if(j >= i && dp[m][j]) {
				if(__builtin_popcount(m) >= 3 && edge[i][j])
					res += dp[m][j];
//				cout << m << " " << j << " = " << dp[m][j] << "   i " << i << " count " << __builtin_popcount(m) <<  "  res  " << res << endl;
				FOR(k,i+1,n-1)
					if(!((1<<k) & m)) if(edge[j][k])
						dp[m | (1<<k)][k] += dp[m][j];
			}
	}
	//out
	cout << res / 2;
    return 0;
}