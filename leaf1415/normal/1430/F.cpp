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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint n, k;
llint l[2005], r[2005], a[2005];
llint R[2005][2005];
llint dp[2005][2005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> l[i] >> r[i] >> a[i];
	
	
	for(int i = 0; i <= n-1; i++){
		llint rem = k;
		for(int j = i+1; j <= n; j++){
			if(rem == -1){
				R[i][j] = -1;
				continue;
			}
			R[i][j] = rem;
			
			if((r[j]-l[j])*k + rem < a[j]){
				rem = -1;
				continue;
			}
			if(rem >= a[j]) rem -= a[j];
			else{
				llint t = (a[j]-rem+k-1)/k;
				rem = k * t - (a[j]-rem);
			}
		}
	}
	
	/*for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			cout << R[i][j] << " ";
		}
		cout << endl;
	}*/
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			if(R[j][i+1] == -1) continue;
			llint rem = R[j][i+1];
			
			llint t;
			if(rem >= a[i+1]) t = 0, rem -= a[i+1];
			else{
				t = (a[i+1]-rem+k-1)/k;
				rem = k * t - (a[i+1]-rem);
			}
			if(l[i+1] + t > r[i+1]) continue;
			
			chmin(dp[i+1][j], dp[i][j] + a[i+1]);
			if(i+1 < n && l[i+2] >= l[i+1] + t + 1){
				chmin(dp[i+1][i+1], dp[i][j] + a[i+1] + rem);
			}
		}
	}
	
	llint ans = inf;
	for(int i = 0; i <= n; i++) ans = min(ans, dp[n][i]);
	if(ans > inf / 2) ans = -1;
	cout << ans << endl;
	
	return 0;
}