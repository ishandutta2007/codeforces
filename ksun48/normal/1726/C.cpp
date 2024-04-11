#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = n;
	for(int i = 0; i + 1 < s.size(); i++){
		if(s[i] == ')' && s[i+1] == '(') ans--;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}