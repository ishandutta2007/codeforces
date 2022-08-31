#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	while(s.size() > 1 && t.size() > 1){
		if(s.back() != t.back()){
			cout << "NO" << '\n';
			return;
		}
		s.pop_back();
		t.pop_back();
	}
	if(t.size() != 1){
		cout << "NO" << '\n';
		return;
	}
	for(char x : s){
		if(x == t[0]){
			cout << "YES" << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}