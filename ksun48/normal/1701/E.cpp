#include <bits/stdc++.h>
using namespace std;

using B = bitset<5100>;

void solve(){
	int n, m;
	cin >> n >> m;
	string S, T;
	cin >> S >> T;
	vector<B> pref_contains(n+1);
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(j == 0){
				pref_contains[i][j] = 1;
			} else if(i == 0){
				pref_contains[i][j] = 0;
			} else {
				if(S[i-1] == T[j-1]){
					pref_contains[i][j] = pref_contains[i-1][j-1];
				} else {
					pref_contains[i][j] = pref_contains[i-1][j];
				}
			}
		}
	}
	vector<B> suff_contains(n+1);
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(j == 0){
				suff_contains[i][j] = 1;
			} else if(i == 0){
				suff_contains[i][j] = 0;
			} else {
				if(S[n-i] == T[m-j]){
					suff_contains[i][j] = suff_contains[i-1][j-1];
				} else {
					suff_contains[i][j] = suff_contains[i-1][j];
				}
			}
		}
	}
	vector<vector<int> > lc(n+1, vector<int>(m+1));
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(j == 0){
				lc[i][j] = 0;
			} else if(i == 0){
				lc[i][j] = 0;
			} else {
				if(S[i-1] == T[j-1]){
					lc[i][j] = lc[i-1][j-1] + 1;
				} else {
					lc[i][j] = 0;
				}
			}
		}
	}
	if(!pref_contains[n][m]){
		cout << -1 << '\n';
		return;
	}
	int ans = n;
	for(int x = 0; x <= m; x++){
		if(suff_contains[n-x][m-x] && lc[x][x] == x){
			ans = min(ans, n-x);
		}
	}
	for(int x = 0; x <= n; x++){
		for(int y = 0; y <= m; y++){
			int r = lc[x][y];
			if(!pref_contains[x-r][y-r]) continue;
			if(!suff_contains[n-x][m-y]) continue;
			ans = min(ans, 1 + x-r + n-x + x-y);
		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}