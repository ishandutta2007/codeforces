#include <bits/stdc++.h>
using namespace std;

void solve(){
	long long a, b;
	cin >> a >> b;
	long long ans = (a + b) / 3;
	ans = min(ans, min(a, b));
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}