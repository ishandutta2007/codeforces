#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, K;
	cin >> N >> K;
	vector<int> P(N);
	for(int& x : P) { cin >> x; x--; }
	const int INF = int(1e9);
	vector<vector<int> > dp(N+1, vector<int>(1 << (K+1), INF));
	dp[0][0] = 0;
	vector<int> loc(N);
	for(int i = 0; i < N; i++){
		loc[P[i]] = i;
	}
	vector<vector<int> > pref_sums(N, vector<int>(N+1));
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			pref_sums[i][j+1] = pref_sums[i][j];
			if(loc[j] > i){
				pref_sums[i][j+1] += 1;
			}
		}
	}
	for(int l = 0; l < N; l++){
		for(int mask = 0; mask < (1 << (K+1)); mask++){
			if(dp[l][mask] >= INF) continue;
			int min_unused = l;
			for(int nxt = min_unused; nxt <= min_unused + K && nxt < N; nxt++){
				int nmask = mask ^ (1 << (nxt - l));
				int nl = l;
				while(nmask & 1){
					nmask >>= 1;
					nl++;
				}
				int del = loc[nxt] - (l + __builtin_popcount(mask));
				for(int i = 0; i <= K; i++){
					if(mask & (1 << i)){
						if(loc[l + i] > loc[nxt]) del++;
					}
				}
				del += pref_sums[loc[nxt]][l];
				dp[nl][nmask] = min(dp[nl][nmask], dp[l][mask] + del);
			}
		}
	}
	cout << dp[N][0] << '\n';
}