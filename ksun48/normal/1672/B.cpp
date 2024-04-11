#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	if(s.back() == 'A'){
		cout << "NO" << '\n';
		return;
	}
	int v = 0;
	for(char c : s){
		v += (c == 'B' ? -1 : 1);
		if(v < 0){
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}