#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	int k;
	cin >> k;
	const int R = 1e6;
	vector<ll> dp(R, -1e16);
	dp[0] = 0;

	const int S = 6;
	vector<ll> F(S);
	for(ll& x : F) cin >> x;
	int p10 = 1;
	for(int i = 0; i < S; i++){
		vector<ll> newdp(R, -1e16);
		for(int j = 0; j < R; j++){
			for(int x = 9*k-9; x <= j / p10 && x <= 9*k; x++){
				int d = x / 3;
				if(x % 3 != 0) d = 3 * (k-1);
				newdp[j] = max(newdp[j], dp[j - x*p10] + F[i] * d);
			}
		}

		int B = 9*k-9;
		for(int res10 = 0; res10 < p10; res10++){
			for(int res3 = 0; res3 < 3; res3++){
				multiset<ll> cvals;
				for(int j = res10; j < R; j += p10){
					int id = j / p10;
					if(id % 3 == res3){
						cvals.insert(dp[j] - F[i] * (id / 3));
					}
					if(!cvals.empty()) newdp[j] = max(newdp[j], *prev(cvals.end()) + F[i] * ((id - res3) / 3));
					if(id >= B && (id - B) % 3 == res3){
						cvals.erase(cvals.find(dp[j - p10 * B] - F[i] * ((id - B) / 3)));
					}
				}
			}
		}
		dp = newdp;
		p10 *= 10;
	}
	int Q;
	cin >> Q;
	while(Q--){
		int a;
		cin >> a;
		cout << dp[a] << '\n';
	}
}