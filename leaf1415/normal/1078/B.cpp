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
#define rep(x, s, t) for(int (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

int n;
int a[105], b[105];
int dp[2][10005][105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i], b[a[i]]++;
	
	int kind = 0;
	rep(i, 1, 100) if(b[i]) kind++;
	
	rep(i, 0, 1){
		rep(j, 0, 10000){
			rep(k, 0, n){
				dp[i][j][k] = 0;
			}
		}
	}
	dp[0][0][0] = 1;
	
	rep(i, 0, 99){
		rep(j, 0, 10000){
			rep(k, 0, n){
				dp[(i+1)&1][j][k] = 0;
			}
		}
		rep(j, 0, 10000){
			rep(k, 0, n){
				rep(l, 0, b[i+1]){
					if(j+l*(i+1) > 10000 || k+l > n) break;
					dp[(i+1)&1][j+l*(i+1)][k+l] += dp[i&1][j][k];
					chmin(dp[(i+1)&1][j+l*(i+1)][k+l], 2);
				}
			}
		}
	}
	
	int ans = 0;
	rep(i, 1, 100){
		rep(j, 1, b[i]){
			if(dp[0][j*i][j] == 1){
				chmax(ans, j);
				if(kind == 2 && j == b[i]) ans = n;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}