#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	int ans = max(0, n-2);
	for(int& x : a) cin >> x;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			int save = 0;
			for(int k = 0; k < n; k++){
				if((a[j] - a[i]) * (k-i) == (a[k] - a[i]) * (j-i)) save++;
			}
			ans = min(ans, n - save);
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