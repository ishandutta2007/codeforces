#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<string> s(n);
	for(string& x : s) cin >> x;
	vector<vector<int> > A(n);
	vector<vector<vector<int> > > loc(n, vector<vector<int> >(52));
	for(int i = 0; i < n; i++){
		for(char sc : s[i]){
			if(sc >= 'a' && sc <= 'z') A[i].push_back(sc - 'a');
			if(sc >= 'A' && sc <= 'Z') A[i].push_back(sc - 'A' + 26);
		}
		for(int j = 0; j < A[i].size(); j++){
			loc[i][A[i][j]].push_back(j);
		}
		for(int c = 0; c < 52; c++){
			loc[i][c].resize(2, -1);
		}
	}
	vector<vector<vector<int> > > dp(52, vector<vector<int> >(1 << n));
	for(int c : A[0]){
		for(int j = 0; j < (1 << n); j++){
			bool has = true;
			for(int i = 0; i < n; i++){
				if(loc[i][c][1 & (j >> i)] == -1) has = false;
			}
			if(!has) continue;
			if(dp[c][j].empty()) dp[c][j] = {c};
		}
		for(int j = 0; j < (1 << n); j++){
			if(dp[c][j].empty()) continue;
			for(int nc = 0; nc < 52; nc++){
				int nmask = 0;
				for(int i = 0; i < n; i++){
					if(loc[i][c][1 & (j >> i)] < loc[i][nc][0]){
						nmask ^= 0;
					} else if(loc[i][c][1 & (j >> i)] < loc[i][nc][1]){
						nmask ^= (1 << i);
					} else {
						nmask = -1;
						break;
					}
				}
				if(nmask == -1) continue;
				vector<int> res = dp[c][j];
				res.push_back(nc);
				if(res.size() > dp[nc][nmask].size()){
					dp[nc][nmask] = res;
				}
			}
		}
	}
	vector<int> ans = {};
	for(int c = 0; c < 52; c++){
		for(vector<int> x : dp[c]){
			if(x.size() > ans.size()) ans = x;
		}
	}
	cout << ans.size() << '\n';
	for(int c : ans){
		if(c < 26){
			cout << (char)(c + 'a');
		} else {
			cout << (char)((c - 26) + 'A');			
		}
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}