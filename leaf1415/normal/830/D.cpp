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
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
ll dp[405][405];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	dp[1][0] = 1, dp[1][1] = 1;
	rep(i, 2, n){
		rep(j, 0, n){
			rep(k, 0, j+1){
				ll tmp = dp[i-1][k] * dp[i-1][j+1-k] % mod;
				dp[i][j] += k*(j+1-k)*2 * tmp % mod, dp[i][j] %= mod;
				dp[i][j] += 2*k*(k-1) * tmp % mod, dp[i][j] %= mod;
			}
			rep(k, 0, j){
				ll tmp = dp[i-1][k] * dp[i-1][j-k] % mod;
				dp[i][j] += (j*2+1) * tmp % mod, dp[i][j] %= mod;
			}
			rep(k, 0, j-1){
				dp[i][j] += dp[i-1][k] * dp[i-1][j-1-k] % mod;
				dp[i][j] %= mod;
			}
		}
	}
	cout << dp[n][1] << endl;
	
	return 0;
}