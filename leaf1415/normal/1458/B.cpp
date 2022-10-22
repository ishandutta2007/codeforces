#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
int cap[105], x[105];
int dp[2][105][20005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> cap[i] >> x[i], cap[i] *= 2, x[i] *= 2;
	
	rep(j, 0, n) rep(k, 0, 20000) dp[0][j][k] = dp[1][j][k] = -1e9;
	dp[0][0][0] = 0;
	
	rep(i, 0, n-1){
		rep(j, 0, n) rep(k, 0, 20000) dp[(i+1)&1][j][k] = -1e9;
		rep(j, 0, i){
			rep(k, 0, 20000){
				chmax(dp[(i+1)&1][j][k], dp[i&1][j][k] + x[i+1]/2);
				if(k+cap[i+1] <= 20000)  chmax(dp[(i+1)&1][j+1][k+cap[i+1]], dp[i&1][j][k] + x[i+1]);
			}
		}
	}
	
	rep(i, 1, n){
		double ans = 0;
		rep(j, 0, 20000) chmax(ans, (double)min(j, (ll)dp[n&1][i][j]));
		printf("%.11f ", ans/2);
	}
	cout << endl;
	
	return 0;
}