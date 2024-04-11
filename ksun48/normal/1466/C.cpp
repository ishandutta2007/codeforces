#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	int ans = 0;
	for(char c = 'a'; c <= 'z'; c++){
		int last = -100;
		for(int i = 0; i < (int)s.size(); i++){
			if(s[i] != c) continue;
			if(i - last <= 2){
				ans++;
			} else {
				last = i;
			}
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