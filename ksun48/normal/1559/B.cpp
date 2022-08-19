#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0; i + 1 < n; i++){
		if(s[i] != '?' && s[i+1] == '?'){
			s[i+1] = s[i] ^ 'R' ^ 'B';
		}
	}
	if(s.back() == '?') s.back() = 'R';
	for(int i = n-2; i >= 0; i--){
		if(s[i] == '?' && s[i+1] != '?'){
			s[i] = s[i+1] ^ 'R' ^ 'B';
		}
	}
	cout << s << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}