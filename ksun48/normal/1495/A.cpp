#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve(){
	int n;
	cin >> n;
	vector<ll> a, b;
	for(int i = 0; i < 2*n; i++){
		ll x, y;
		cin >> x >> y;
		if(x) a.push_back(abs(x));
		if(y) b.push_back(abs(y));
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	using ld = long double;
	ld ans = 0;
	for(int i = 0; i < n; i++){
		ans += sqrt(ld((a[i] * a[i] + b[i] * b[i])));
	}
	cout << fixed << setprecision(10);
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}