#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<string> s(n);
	for(int i = 0; i < n; i++) cin >> s[i];
	vector<vector<vector<ll> > > dp(1 << n);
	for(int mask = 1; mask < (1 << n); mask++){
		int k = __builtin_popcount(mask);
		dp[mask].assign(n, vector<ll>(1 << (k-1), 0));
		for(int j = 0; j < n; j++){
			if(((mask >> j) & 1) == 0) continue;
			int v = mask ^ (1 << j);
			if(v == 0){
				dp[mask][j][0] = 1;
			} else {
				for(int c = 0; c < n; c++){
					for(int pseq = 0; pseq < (1 << (k-2)); pseq++){
						// if(dp[v][c][pseq] > 0) cerr << mask << ' ' << j << ' ' << c << ' ' << '\n';
						dp[mask][j][pseq * 2 + (s[j][c] - '0')] += dp[v][c][pseq];
					}
				}
			}
		}
	}
	vector<ll> ans(1 << (n-1), 0);
	for(int j = 0; j < n; j++){
		for(int seq = 0; seq < (1 << (n-1)); seq++){
			ans[seq] += dp[(1 << n) - 1][j][seq];
		}
	}
	for(int seq = 0; seq < (1 << (n-1)); seq++){
		cout << ans[seq] << ' ';
	}
	cout << '\n';
}