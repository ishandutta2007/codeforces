#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	vector<int> color(n, -1);
	int cur = 0;
	for(int p = 2; p <= 40; p++){
		int used = 0;
		for(int i = 0; i < n; i++){
			if(color[i] >= 0) continue;
			if(a[i] % p == 0){
				used = 1;
				color[i] = cur;
			}
		}
		if(used) cur++;
	}
	cout << cur << '\n';
	for(int y : color){
		cout << y + 1 << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}