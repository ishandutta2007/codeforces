#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	int n;
	cin >> n;
	vector<int> h(n);
	for(int& a : h) cin >> a;
	vector<ll> b(n);
	for(ll& a : b) cin >> a; 

	const ll INF = 1e16;
	vector<ll> dp(n+1, -INF);
	dp[0] = 0;
	// height, cost
	vector<tuple<int, int, ll> > stk;
	stk.push_back({0, -1, -INF});

	multiset<ll> gos;
	gos.insert(-INF);
	for(int i = 1; i <= n; i++){
		ll cbest = -INF;
		while(true){
			auto [a, idx, cost] = stk.back();
			if(a >= h[i-1]){
				gos.erase(gos.find(cost + b[idx]));
				cbest = max(cbest, cost);
				stk.pop_back();
			} else {
				break;
			}
		}
		cbest = max(cbest, dp[i-1]);
		{
			stk.push_back({h[i-1], i-1, cbest});
			gos.insert(cbest + b[i-1]);
		}
		dp[i] = *prev(gos.end());
	}
	cout << dp[n] << '\n';
}