#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int tc, n;
ll a[100100];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> tc;
	while(tc--){
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i];
		vector<ll> v[2];
		int z = 0;

		for(int i=1;i<=n;i++){
			if(a[i] == 0) z = 1;
			else if(a[i] < 0) v[1].push_back(-a[i]);
			else v[0].push_back(a[i]);
		}
		sort(v[0].begin(), v[0].end(), greater<>());
		sort(v[1].begin(), v[1].end(), greater<>());

		ll ans = z ? 0 : -1e18;

		if(v[0].size() >= 5) ans = max(ans, v[0][0] * v[0][1] * v[0][2] * v[0][3] * v[0][4]);
		if(v[0].size() >= 3 && v[1].size() >= 2) ans = max(ans, v[0][0] * v[0][1] * v[0][2] * v[1][0] * v[1][1]);
		if(v[0].size() >= 1 && v[1].size() >= 4) ans = max(ans, v[0][0] * v[1][0] * v[1][1] * v[1][2] * v[1][3]);

		reverse(v[0].begin(), v[0].end());
		reverse(v[1].begin(), v[1].end());

		if(v[1].size() >= 5) ans = max(ans, - v[1][0] * v[1][1] * v[1][2] * v[1][3] * v[1][4]);
		if(v[0].size() >= 2 && v[1].size() >= 3) ans = max(ans, - v[1][0] * v[1][1] * v[1][2] * v[0][0] * v[0][1]);
		if(v[0].size() >= 4 && v[1].size() >= 1) ans = max(ans, - v[1][0] * v[0][0] * v[0][1] * v[0][2] * v[0][3]);

		cout << ans << "\n";
	}
}