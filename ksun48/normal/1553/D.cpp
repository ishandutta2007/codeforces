#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s, t;
	cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	int i = 0;
	for(int k = 0; k < (int)t.size(); k++){
		while(i < (int)s.size() && (((i & 1) != (k & 1)) || t[k] != s[i])){
			i++;
		}
		if(i == (int)s.size()){
			cout << "NO" << '\n';
			return;
		}
		i++;
	}
	cout << "YES" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}