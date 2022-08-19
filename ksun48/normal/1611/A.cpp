#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	if(s.back() % 2 == 0){
		cout << 0 << '\n';
		return;
	}
	if(s.front() % 2 == 0){
		cout << 1 << '\n';
		return;
	}
	for(char c : s){
		if(c % 2 == 0){
			cout << 2 << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}