#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> which(n);
	for(int i = 0; i < n; i++){
		which[i] = (s[i] == '-') != (i & 1);
	}
	vector<int> psum(n+1, 0);
	for(int i = 0; i < n; i++){
		psum[i+1] = psum[i] + (which[i] ? -1 : 1);
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		l--; r--;
		if((r+1-l) & 1){
			cout << 1 << '\n';
		} else if(psum[r+1] == psum[l]){
			cout << 0 << '\n';
		} else {
			cout << 2 << '\n';
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}