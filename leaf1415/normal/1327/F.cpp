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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define mod 998244353

using namespace std;

llint n, k, m;
int l[500005], r[500005], x[500005];
int b[500005], dif[500005];
llint dp[500005], sum[500005];
vector<int> vec[500005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> m;
	for(int i = 1; i <= m; i++){
		cin >> l[i] >> r[i] >> x[i];
	}

	for(int i = 0; i < k; i++){
		for(int j = 1; j <= n; j++) dif[j] = 0;
		for(int j = 1; j <= m; j++){
			if((x[j] & (1<<i)) == 0) continue;
			dif[l[j]]++;
			dif[r[j]+1]--;
		}
		for(int j = 1; j <= n; j++) dif[j] += dif[j-1];
		for(int j = 1; j <= n; j++){
			if(dif[j]) b[j] |= 1<<i;
		}
	}
	
	/*for(int j = 1; j <= n; j++) cout << b[k] << " ";
	cout << endl;*/
	
	llint ans = 1;
	dp[0] = sum[0] = 1;
	for(int i = 0; i < k; i++){
		
		for(int j = 1; j <= n; j++) vec[j].clear();
		for(int j = 1; j <= m; j++){
			if(x[j] & (1<<i)) continue;
			vec[r[j]].push_back(l[j]);
		}
		
		int lb = 0;
		for(int j = 1; j <= n; j++){
			dp[j] = 0;
			if((b[j] & (1<<i)) == 0){
				dp[j] = sum[j-1];
				if(lb > 0){
					dp[j] += mod - sum[lb-1];
					if(dp[j] >= mod) dp[j] -= mod;
				}
			}
			sum[j] = sum[j-1] + dp[j];
			if(sum[j] >= mod) sum[j] -= mod;
			for(int k = 0; k < vec[j].size(); k++) lb = max(lb, vec[j][k]);
		}
		//for(int j = 1; j <= n; j++) cout << sum[j] << " "; cout << endl;
		
		llint tmp = sum[n];
		if(lb > 0) tmp += mod - sum[lb-1], tmp %= mod;
		ans *= tmp, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}