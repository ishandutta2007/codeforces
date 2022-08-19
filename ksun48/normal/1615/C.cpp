#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s, _t;
	cin >> s >> _t;
	int ans = 3*n;
	for(int pops : {0, 1}){
		string t = _t;
		for(char& c : t) if(pops) c ^= '0' ^ '1';
		int f0 = 0, f1 = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '0' && t[i] == '1') f0++;
			if(s[i] == '1' && t[i] == '0') f1++;
		}
		if((f0 + f1 + pops) % 2 == 0){
			if(f0 == f1 || f0 + 1 == f1){
				ans = min(ans, f0 + f1);
			}
		}
	}
	if(ans == 3*n) ans = -1;
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}