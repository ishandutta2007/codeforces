#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N;
	cin >> N;
	vector<int> a(N);
	for(int& x : a) cin >> x;
	int ans = -1e7;
	for(int i = 0; i < N; i++){
		ans = max(ans, a[i] - a[(i+1) % N]);
	}
	for(int i = 1; i < N; i++){
		ans = max(ans, a[i] - a[0]);
	}
	for(int i = 0; i < N-1; i++){
		ans = max(ans, a[N-1] - a[i]);
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}