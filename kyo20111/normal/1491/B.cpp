#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, u, v, a[100100];

void solve(){
	cin >> n >> u >> v;
	for(int i=1;i<=n;i++) cin >> a[i];

	int ans = min(u, v) + v;

	for(int i=1;i<n;i++){
		int x = abs(a[i] - a[i+1]);
		if(x > 1) ans = 0;
		else if(x == 1) ans = min({ans, v, u});
	}

	cout << ans;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1; cin >> tc;
	while(tc--) solve(), cout << "\n";
}