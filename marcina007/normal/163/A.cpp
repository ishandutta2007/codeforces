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
#define MAXN 5007
string s,t;
int dp[MAXN][MAXN],res=0,sum[MAXN][MAXN];

int main(){ 
	//in
	cin >> s >> t;
	int n = s.size();
	int m = t.size();
	s = "!" + s;
	t = "#" + t;
	REP(i,MAXN)
		sum[i][0] = dp[i][0] = 1;
	REP(j,MAXN)
		sum[0][j] = 1;
	//sol
	FOR(i,1,n) FOR(j,1,m){
		if(s[i] == t[j])
			res += (dp[i][j] = sum[i-1][j-1]);
		sum[i][j] = (sum[i][j-1] + dp[i][j]) % MOD;
		res %= MOD;
//		cout << i << " " << j << " = " << dp[i][j] << " " << sum[i][j] << endl;
	}
	//out
	cout << res << endl;
    return 0;
}