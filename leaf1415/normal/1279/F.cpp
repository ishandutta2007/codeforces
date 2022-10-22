#include <iostream>
#include <string>
#include <utility>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n, k, l;
string s;
llint a[1000005], sum[1000005];
P dp[1000005];

P calc(llint x)
{
	for(int i = 1; i <= n; i++) dp[i] = P(inf, inf);
	dp[0] = P(0LL, 0LL);
	
	for(int i = 0; i < n; i++){
		dp[i+1] = min(dp[i+1], dp[i]);
		llint r = min(i+l, n);
		dp[r] = min(dp[r], P(dp[i].first-(sum[r]-sum[i])+x, dp[i].second+1) );
	}
	dp[n].first += min(0LL, k*x);
	return dp[n];
}

llint solve()
{
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
	//for(int i = 1; i <= n; i++) cout << a[i]; cout << endl;
	
	llint ub = 1e13, lb = -1e13, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		P res = calc(mid);
		if(res.second <= k) ub = mid;
		else lb = mid;
		//cout << mid << " " << res.first << " " << res.second << endl;
	}
	
	P res = calc(ub);
	//cout << ub << " " << res.first << " " << res.second << endl;
	
	llint ret = res.first - k * ub;
	ret += sum[n];
	//cout << ret << endl;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> l;
	cin >> s;
	s = "#" + s;
	
	if((n+l-1)/l <= k){
		cout << 0 << endl;
		return 0;
	}
	
	for(int i = 1; i <= n; i++){
		if(s[i] >= 'a') a[i] = 1;
		else a[i] = 0;
	}
	llint ans = solve();
	
	for(int i = 1; i <= n; i++){
		if(s[i] >= 'a') a[i] = 0;
		else a[i] = 1;
	}
	ans = min(ans, solve());
	
	cout << ans << endl;
	
	return 0;
}