#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<string> s(2);
	for(string& x : s) cin >> x;
	vector<int> dp(4, 1e9);
	dp[3] = 0;
	// e1, e2, conn
	int last_cell = 0;
	int first_cell = -1;
	for(int i = 0; i < n; i++){
		if(s[0][i] == '*' || s[1][i] == '*'){
			last_cell = i;
			if(first_cell == -1) first_cell = i;
		}
	}
	for(int i = first_cell; i <= last_cell; i++){
		vector<int> ndp(4, 1e9);
		for(int g = 0; g < 4; g++){
			for(int a = 0; a < 4; a++){
				if((g & a) == 0) continue;
				if(!(a & 1) && s[0][i] == '*') continue;
				if(!(a & 2) && s[1][i] == '*') continue;
				ndp[a] = min(ndp[a], dp[g] + __builtin_popcount(a));
			}
		}
		dp = ndp;
	}
	int ans = 1e9;
	for(int x : dp){
		ans = min(ans, x);
	}
	cout << (ans - 1) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}