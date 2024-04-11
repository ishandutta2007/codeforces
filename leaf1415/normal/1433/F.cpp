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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define pback push_back
#define inf 1e18
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint n, m, K;
llint a[75][75];
llint dp[75][75][40][75];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> K;
	rep(i, 1, n){
		rep(j, 1, m){
			cin >> a[i][j];
		}
	}
	
	rep(i, 1, n+1){
		rep(j, 0, m){
			rep(k, 0, m/2){
				rep(l, 0, K-1){
					dp[i][j][k][l] = -inf;
				}
			}
		}
	}
	dp[1][0][0][0] = 0;
	
	rep(i, 1, n){
		rep(j, 0, m-1){
			rep(k, 0, m/2){
				rep(l, 0, K-1){
					chmax(dp[i][j+1][k][l], dp[i][j][k][l]);
					if(k+1 <= m/2) chmax(dp[i][j+1][k+1][(l+a[i][j+1])%K], dp[i][j][k][l]+a[i][j+1]);
				}
			}
		}
		rep(k, 0, m/2){
			rep(l, 0, K-1){
				chmax(dp[i+1][0][0][l], dp[i][m][k][l]);
			}
		}
	}
	
	llint ans = 0;
	rep(k, 0, m/2) chmax(ans, dp[n+1][0][k][0]);
	cout << ans << endl;
	
	return 0;
}