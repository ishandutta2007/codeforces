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
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint n;
llint a[200005];
llint dp[200005][3][2][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	if(n == 1){
		cout << a[1] << endl;
		return 0;
	}
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 2; k++){
				for(int l = 0; l < 2; l++){
					dp[i][j][k][l] = -inf;
				}
			}
		}
	}
	dp[0][0][0][0] = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 2; k++){
				for(int l = 0; l < 2; l++){
					for(int m = 0; m < 2; m++){
						llint nj = j, nk = k, sgn = 1;
						if(i >= 1 && l == m) nk = 1;
						if(m == 0) nj += 2;
						else nj += 1, sgn = -1;
						chmax(dp[i+1][nj%3][nk][m], dp[i][j][k][l] + sgn*a[i+1]);
					}
				}
			}
		}
	}
	
	llint ans = max(dp[n][2][1][0], dp[n][2][1][1]);
	cout << ans << endl;
	
	return 0;
}