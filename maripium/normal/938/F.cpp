#include<bits/stdc++.h>
using namespace std;

int n,k,rem;
bool dp[5005][1 << 12];
string s;
int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	string s;
	cin >> s;
	n = s.size();
	k = log2(n);
	rem = n - (1 << k) + 1;
	
	for(int mask = 0;mask < (1 << k);++mask) dp[0][mask] = true;
	
	for(int i = 1;i <= rem;++i) {
		char ans = 'z';
		for(int mask = 0;mask < (1 << k);++mask) 
			if(dp[i - 1][mask]) ans = min(ans,s[i + mask - 1]);
		cout << ans;
		for(int mask = 0;mask < (1 << k);++mask) {
			if(dp[i - 1][mask] && s[i + mask - 1] == ans) dp[i][mask] = true;
			if(dp[i][mask]){
				for(int j = 0;j < k;++j) {
					if((mask >> j) & 1) continue;
					dp[i][mask | (1 << j)] = true;
				}
			}
		}	
	}
}