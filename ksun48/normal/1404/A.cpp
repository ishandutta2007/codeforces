#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int c0 = 0;
	int c1 = 0;
	int cq = 0;
	for(int i = 0; i < k; i++){
		int f0 = 0;
		int f1 = 0;
		for(int j = i; j < n; j += k){
			if(s[j] == '0') f0 = 1;
			if(s[j] == '1') f1 = 1;
		}
		if(f0 && f1){
			cout << "NO" << '\n';
			return;
		} else if(f0){
			c0++;
		} else if(f1){
			c1++;
		} else {
			cq++;
		}
	}
	if(c0 + cq < c1 || c1 + cq < c0){
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}