#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	int cmax = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cmax = max(cmax, a[i]);
		if(cmax == i+1) ans++;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}