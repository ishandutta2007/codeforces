#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	for(int& x : a) cin >> x;
	for(int& x : b) cin >> x;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int best = 0;
	for(int i = 0; i <= k; i++){
		int cur = 0;
		for(int j = 0; j < i; j++) cur += b[n-1-j];
		for(int j = 0; j < n-i; j++) cur += a[n-1-j];
		best = max(best, cur);
	}
	cout << best << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}