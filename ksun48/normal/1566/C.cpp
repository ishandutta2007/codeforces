#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s[2];
	cin >> s[0] >> s[1];
	int ans = 0;
	int f0 = 0, f1 = 0;
	for(int i = 0; i < n; i++){
		if(s[0][i] == '0' || s[1][i] == '0'){
			if(f0){
				ans += (1 + f1);
				f0 = f1 = 0;
				if(s[0][i] == '0' || s[1][i] == '0') f0 = 1;
				if(s[0][i] == '1' || s[1][i] == '1') f1 = 1;
			} else {
				f0 = 1;
				if(s[0][i] == '0' || s[1][i] == '0') f0 = 1;
				if(s[0][i] == '1' || s[1][i] == '1') f1 = 1;
			}
		} else {
			f1 = 1;
		}
		if(f0 && f1){
			ans += 2;
			f0 = f1 = 0;
		}
	}
	if(f0) ans += (1 + f1);
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}