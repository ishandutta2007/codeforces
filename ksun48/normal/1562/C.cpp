#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k = n / 2;
	for(int i = k; i < n; i++){
		if(s[i] == '0'){
			cout << 1 << ' ' << (i+1) << ' ' << 1 << ' ' << (i) << '\n';
			return;
		}
	}
	if(s[k-1] == '1'){
		cout << (k) << ' ' << (n-1) << ' ' << (k+1) << ' ' << n << '\n';
	} else {
		cout << (k) << ' ' << (n) << ' ' << (k+1) << ' ' << n << '\n';		
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}