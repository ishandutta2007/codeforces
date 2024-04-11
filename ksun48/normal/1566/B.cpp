#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	bool f0 = false, f01 = false, f010 = false;
	for(char c : s){
		if(c == '0'){
			f010 |= f01;
			f0 = true;
		} else {
			f01 |= f0;
		}
	}
	if(f010){
		cout << 2 << '\n';
	} else if(f0){
		cout << 1 << '\n';
	} else {
		cout << 0 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}