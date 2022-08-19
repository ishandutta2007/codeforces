#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int r = 0;
	for(char c : s) if(c == '1') r++;
	if(s.front() != '1' || s.back() != '1' || (r & 1)){
		cout << "NO" << '\n';
		return;
	}
	string x, y;
	
	int d = 0;
	int f = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			if(d < r/2){
				x += '(';
				y += '(';
			} else {
				x += ')';
				y += ')';
			}
			d++;
		} else {
			x += "()"[f];
			y += ")("[f];
			f ^= 1;
		}
	}
	cout << "YES" << '\n';
	cout << x << '\n';
	cout << y << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}