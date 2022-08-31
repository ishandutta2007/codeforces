#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	int i = 0;
	int n = (int)s.size();
	int ans = 0;
	while(i < n){
		ans++;
		set<char> c;
		while(i < n && (c.size() < 3 || c.count(s[i]))){
			c.insert(s[i]);
			i++;
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